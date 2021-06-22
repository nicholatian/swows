/****************************************************************************\
 *                              POKeMON SwowS!                              *
 *                                                                          *
 *                   Copyright (C) 2021 Alexander Nicholi                   *
 *                       Released under BSD-0-Clause.                       *
\****************************************************************************/

/** BEGIN #INCLUDES */

#include <uni/err.h>
#include <uni/memory.h>
#include <uni/str.h>
#include <uni/types/int.h>
#include <uni/types/bound.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/** END #INCLUDES */

/** BEGIN #DEFINES */

#define BLOCKTILE_GET_TILE(_tile) \
	((_tile) & 0x3FF)
#define BLOCKTILE_GET_PAL(_tile) \
	(((_tile) >> 12) & 0xF)
#define BLOCKTILE_GET_XFLIP(_tile) \
	(((_tile) >> 10) & 1)
#define BLOCKTILE_GET_YFLIP(_tile) \
	(((_tile) >> 11) & 1)

#define BLOCKTILE_SET_TILE(_tile, _n) \
	((_tile) = (((_tile) & 0xFC00) | ((_n) & 0x3FF)))
#define BLOCKTILE_SET_PAL(_tile, _n) \
	((_tile) = (((_tile) & 0xFFF) | (((_n) & 0xF) << 12)))
#define BLOCKTILE_SET_XFLIP(_tile, _n) \
	((_tile) = (((_tile) & 0xFBFF) | (((_n) & 1) << 10)))
#define BLOCKTILE_SET_YFLIP(_tile, _n) \
	((_tile) = (((_tile) & 0xF7FF) | (((_n) & 1) << 11)))

#define BLOCK_GET_TILE(_block) \
	((_block) & 0x3FF)
#define BLOCK_GET_MOVE(_block) \
	(((_block) >> 10) & 0x3F)

#define BLOCK_SET_TILE(_block, _n) \
	((_block) = (((_block) & 0xFC00) | ((_n) & 0x3FF)))
#define BLOCK_SET_MOVE(_block, _n) \
	((_block) = (((_block) & 0x3FF) | (((_n) & 0x3F) << 10)))

#if defined( CFG_BIGENDIAN )
#define MASK_R (255 << 24)
#define MASK_G (255 << 16)
#define MASK_B (255 << 8)
#define MASK_A (255)
#elif defined( CFG_LILENDIAN )
#define MASK_R (255)
#define MASK_G (255 << 8)
#define MASK_B (255 << 16)
#define MASK_A (255 << 24)
#endif

/** END #DEFINES */

/** BEGIN ENUMERATION DEFINITIONS */

enum
{
	ERR_MOD_SABLMAP = UNI_MAX_ERR_MOD,
	FBUF_W = 960,
	FBUF_L = 416,
	BUF_SZ = 4096
};

/** END ENUMERATION DEFINITIONS */

/** BEGIN TYPEDEFS */

/* block tile bitfield
 * a := palette number
 * b := yflip
 * c := xflip
 * d := tile number
 * aaaa bcdd dddd dddd */
typedef u16 blocktile_t;

/* use MASK_{R,G,B,A} to access colours (see above) */
typedef u32 col_t;

/** END TYPEDEFS */

/** BEGIN STRUCTURE DEFINITIONS */

/* INI config keypair */
struct ini_pair
{
	char * key;
	char * value;
};

/* INI config section */
struct ini_sect
{
	char * name;
	struct ini_pair * pairs;
	ptri pairs_sz;
};

/* a parsed INI file config */
struct ini
{
	struct ini_pair * gpairs;
	struct ini_sect * sects;
	ptri sects_sz;
};

/* block data, comprised of tiles + metadata and stored in a blockset */
struct block
{
	unsigned behav : 8;
	unsigned type : 2;
	blocktile_t tiles[8];
	blocktile_t tlt_tiles[4];
};

/* 4-bit tile pixel data, stored according to GBATek */
struct tile
{
	/* always stored as 4bpp */
	u8 pixels[32];
};

/* tileset image, broken up into tiles */
struct tileset
{
	struct tile * tiles;
	ptri tiles_sz;
};

/* tileset palette, 4-bit */
struct tileset_pal
{
	col_t cols[16];
};

/* blockset data */
struct blockset
{
	struct tileset tileset;
	struct tileset_pal pals[16];
	struct block * blocks;
	ptri blocks_sz;
};

/* map data */
struct map
{
	u16 w, l;
	/* array of blocks by block ID, keying a struct blockset */
	u16 * blocks;
};

/* map metadata */
struct map_props
{
	u32 flash : 1;
	u32 bike : 1;
	u32 run : 1;
	u32 rope : 1;
	u32 showname : 1;
	u32 weather : 4;
	u32 scene : 4;
	u32 type : 3;
	u32 bgm : 16;
	u8 bankid, mapid;
};

/* map connection */
struct conn
{
	s32 dir : 2;
	s32 bankid : 7;
	s32 mapid : 7;
	s32 offs : 16;
};

/* person OBJ */
struct person
{
	u16 gfxid;
	u16 flag;
	u8 movement;
	u8 x_range;
	u8 y_range;
	u8 los;
	u32 script;
};

/* warp OBJ */
struct warp
{
	u8 bank, map, warp;
};

/* signpost OBJ */
struct sign
{
	u32 script;
};

/* hidden item (vern. "hitem") OBJ */
struct hitem
{
	u16 id;
	u16 flag;
};

/* overworld OBJ (event) */
struct owobj
{
	u32 x : 14;
	u32 y : 14;
	u32 elev : 4;
	union
	{
		struct person person;
		struct warp warp;
		struct sign sign;
		struct hitem hitem;
	};
};

/* SABLMAP business state */
struct program
{
	SDL_Window * win;
	SDL_Renderer * ren;
	SDL_Surface * fbuf;
};

/* SABLMAP application state */
struct state
{
	/* the two blocksets */
	struct blockset prima, secunda;
	/* map data */
	struct map map;
	/* map metadata */
	struct map_props props;
	/* other data for SABLMAP */
	struct program program;
};

/** END STRUCTURE DEFINITONS */

/** BEGIN FORWARD DECLARATIONS */

/* debug printer. does printf-style formatting and sends to stderr.
 * if silent is non-zero, this function is silent. */
static void dprint( const char *, ... );

/* parse ASCII text into an INI config object */
static uni_err_t ini_parse( const char *, struct ini * );

/* take a config and obtain the blockset data from it */
static uni_err_t ini2blockset(
	const struct ini *,
	const u8 *,
	const u8 *,
	struct blockset * );

/* render a block */
static uni_err_t block2surf(
	const struct blockset *,
	u16,
	u32,
	SDL_Surface * );

/* render a tile using a given palette, from 4-bit to 32-bit RGBA */
static uni_err_t raster_tile(
	const struct tile *,
	const col_t[16],
	u32,
	const u32[64] );

/* render the visible part of the map for the window */
static uni_err_t render_map_view(
	const struct blockset *,
	const struct blockset *,
	const struct map *,
	b32d2,
	SDL_Surface * );

/* render the visible part of the blockset for the window */
static uni_err_t render_blockset_view(
	const struct blockset *,
	const struct blockset *,
	u32,
	SDL_Surface * );

/* render the whole window */
static uni_err_t render_win(
	SDL_Surface *,
	SDL_Surface *,
	SDL_Surface * );

static int mainloop( struct state * );

static int gfx_main( u16, u16, const char *, const char *, int );

int main( int, char *[] );

/** END FORWARD DECLARATIONS */

/** BEGIN STATIC CONSTANT DATA */

static const char * const k_block_keys[2 + 32] = {
	"behav",
	"type",
	"l0tl_tile",
	"l0tl_pal",
	"l0tl_xf",
	"l0tl_yf",
	"l0tr_tile",
	"l0tr_pal",
	"l0tr_xf",
	"l0tr_yf",
	"l0bl_tile",
	"l0bl_pal",
	"l0bl_xf",
	"l0bl_yf",
	"l0br_tile",
	"l0br_pal",
	"l0br_xf",
	"l0br_yf",
	"l1tl_tile",
	"l1tl_pal",
	"l1tl_xf",
	"l1tl_yf",
	"l1tr_tile",
	"l1tr_pal",
	"l1tr_xf",
	"l1tr_yf",
	"l1bl_tile",
	"l1bl_pal",
	"l1bl_xf",
	"l1bl_yf",
	"l1br_tile",
	"l1br_pal",
	"l1br_xf",
	"l1br_yf"
};

static const char * const k_tlt_block_keys[16] = {
	"l2tl_tile",
	"l2tl_pal",
	"l2tl_xf",
	"l2tl_yf",
	"l2tr_tile",
	"l2tr_pal",
	"l2tr_xf",
	"l2tr_yf",
	"l2bl_tile",
	"l2bl_pal",
	"l2bl_xf",
	"l2bl_yf",
	"l2br_tile",
	"l2br_pal",
	"l2br_xf",
	"l2br_yf"
};

/** END STATIC CONSTANT DATA */

/** BEGIN STATIC DATA */

/* whether the debug printer should work */
static int silent = 0;

/** END STATIC DATA */

/** BEGIN FUNCTION DEFINITIONS */

static void dprint( const char * fmt, ... )
{
	va_list args;

	if(silent)
	{
		return;
	}

	va_start( args, fmt );
	vfprintf( stderr, fmt, args );
	va_end( args );
	fprintf( stderr, "\n" );
	fflush( stderr );
}

static uni_err_t ini_parse( const char * in, struct ini * out );

static uni_err_t ini2blockset(
	const struct ini * in_cfg,
	const u8 * in_tileset_img,
	const u8 * in_tileset_pal,
	struct blockset * out );

static uni_err_t block2surf(
	const struct blockset * in_blockset,
	u16 in_blockid,
	u32 in_flags,
	SDL_Surface * out );

static uni_err_t raster_tile(
	const struct tile * in_tile,
	const col_t in_pal[16],
	u32 in_flags,
	const u32 out[64] );

static uni_err_t render_map_view(
	const struct blockset * prima,
	const struct blockset * secunda,
	const struct map * map,
	b32d2 mapclip,
	SDL_Surface * out );

static uni_err_t render_blockset_view(
	const struct blockset * prima,
	const struct blockset * secunda,
	u32 row_offs,
	SDL_Surface * out );

static uni_err_t render_win(
	SDL_Surface * map,
	SDL_Surface * blockset,
	SDL_Surface * out );

static int mainloop( struct state * state )
{
	return 0;
}

static int gfx_main( u16 map_w,
u16 map_l,
const char * owb_fpath,
const char * owm_fpath,
int silent )
{
	struct state state;
}

int main( int ac, char * av[] )
{
	int silent = 0, dim_i = -1, i;
	u16 map_w = 0, map_l = 0;
	const char * owb_fpath = NULL;
	const char * owm_fpath = NULL;
	const char * ini_fpath = NULL;
	char buf[BUF_SZ];

	uni_memset( buf, 0, BUF_SZ );

	for( i = 0; i < ac; ++i )
	{
		const ptri arg_sz = uni_strlen( av[i] );

		if(arg_sz > BUF_SZ) {
			dprint( "argument %lu exceeded buffer size of %u", i, BUF_SZ );

			return 127;
		}

		if( arg_sz >= 1 && av[i][0] == '-' )
		{
			/* is a flag */
			if( arg_sz >= 2 && av[i][1] == '-' )
			{
				/* is a long flag */
				uni_memcpy( buf, (const void *)&(av[i][2]), arg_sz - 2 );

				if( uni_strequ( buf, "dimensions" ) )
				{
					dim_i = i;
				}
				else if( !silent )
				{
					dprint( "WARNING: Unrecognised flag \"%s\"", av[i] );
				}
			}
		}
	}

	return 0;
}

/** END FUNCTION DEFINITIONS */

/** EOF */
