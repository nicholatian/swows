/****************************************************************************\
 *                              POKeMON SwowS!                              *
 *                                                                          *
 *                   Copyright (C) 2021 Alexander Nicholi                   *
 *                       Released under BSD-0-Clause.                       *
\****************************************************************************/

/** BEGIN #INCLUDES */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <errno.h>
#include <string.h>
#include <uni/err.h>
#include <uni/memory.h>
#include <uni/str.h>
#include <uni/types/bound.h>
#include <uni/types/int.h>

/** END #INCLUDES */

/** BEGIN #DEFINES */

#define BLOCKTILE_GET_TILE( _tile ) ( (_tile)&0x3FF )
#define BLOCKTILE_GET_PAL( _tile ) ( ( ( _tile ) >> 12 ) & 0xF )
#define BLOCKTILE_GET_XFLIP( _tile ) ( ( ( _tile ) >> 10 ) & 1 )
#define BLOCKTILE_GET_YFLIP( _tile ) ( ( ( _tile ) >> 11 ) & 1 )

#define BLOCKTILE_SET_TILE( _tile, _n ) \
	( ( _tile ) = ( ( (_tile)&0xFC00 ) | ( (_n)&0x3FF ) ) )
#define BLOCKTILE_SET_PAL( _tile, _n ) \
	( ( _tile ) = ( ( (_tile)&0xFFF ) | ( ( (_n)&0xF ) << 12 ) ) )
#define BLOCKTILE_SET_XFLIP( _tile, _n ) \
	( ( _tile ) = ( ( (_tile)&0xFBFF ) | ( ( (_n)&1 ) << 10 ) ) )
#define BLOCKTILE_SET_YFLIP( _tile, _n ) \
	( ( _tile ) = ( ( (_tile)&0xF7FF ) | ( ( (_n)&1 ) << 11 ) ) )

#define BLOCK_GET_TILE( _block ) ( (_block)&0x3FF )
#define BLOCK_GET_MOVE( _block ) ( ( ( _block ) >> 10 ) & 0x3F )

#define BLOCK_SET_TILE( _block, _n ) \
	( ( _block ) = ( ( (_block)&0xFC00 ) | ( (_n)&0x3FF ) ) )
#define BLOCK_SET_MOVE( _block, _n ) \
	( ( _block ) = ( ( (_block)&0x3FF ) | ( ( (_n)&0x3F ) << 10 ) ) )

#if defined( CFG_BIGENDIAN )
#define MASK_R ( 255 << 24 )
#define MASK_G ( 255 << 16 )
#define MASK_B ( 255 << 8 )
#define MASK_A ( 255 )
#elif defined( CFG_LILENDIAN )
#define MASK_R ( 255 )
#define MASK_G ( 255 << 8 )
#define MASK_B ( 255 << 16 )
#define MASK_A ( 255 << 24 )
#endif

/** END #DEFINES */

/** BEGIN ENUMERATION DEFINITIONS */

enum
{
	ERR_MOD_SABLMAP = UNI_MAX_ERR_MOD,
	FBUF_W          = 960,
	FBUF_L          = 416,
	BUF_SZ          = 4096,
	INI_BOOLSTRS_SZ = 11
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
	ptri gpairs_sz;
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
	u32 biking : 1;
	u32 running : 1;
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

/* check if a string from an INI key value is boolean and falsey. */
static int ini_falsey( const char * );

/* check if a string from an INI key value is boolean and truthy. */
static int ini_truthy( const char * );

/* coerce an INI key into boolean and return its value. */
static int ini_bool( const char * );

/* debug printer. does printf-style formatting and sends to stderr.
 * if silent is non-zero, this function is silent. */
static void dprint( const char *, ... );

/* parse ASCII text into an INI config object */
static uni_err_t ini_parse( const char *, struct ini * );

/* take a config and obtain the blockset data from it */
static uni_err_t ini2blockset(
	const struct ini *, const u8 *, const u8 *, struct blockset * );

/* render a block */
static uni_err_t block2surf(
	const struct blockset *, u16, u32, SDL_Surface * );

/* render a tile using a given palette, from 4-bit to 32-bit RGBA */
static uni_err_t raster_tile(
	const struct tile *, const col_t[16], u32, const u32[64] );

/* render the visible part of the map for the window */
static uni_err_t render_map_view( const struct blockset *,
	const struct blockset *,
	const struct map *,
	b32d2,
	SDL_Surface * );

/* render the visible part of the blockset for the window */
static uni_err_t render_blockset_view(
	const struct blockset *, const struct blockset *, u32, SDL_Surface * );

/* render the whole window */
static uni_err_t render_win( SDL_Surface *, SDL_Surface *, SDL_Surface * );

/* initialise application state */
static uni_err_t state_init(
	struct state *, const char *, const char *, const char * );

/* finalised application state */
static void state_fini( struct state * );

static int mainloop( struct state * );

static int gfx_main( const char *, const char *, const char * );

int main( int, char *[] );

/** END FORWARD DECLARATIONS */

/** BEGIN STATIC CONSTANT DATA */

static const char * const k_help_text =
	"SABLMAP map editor\n"
	"Copyright \302\251 2021 Alexander Nicholi.\n"
	"Released under BSD 0-Clause licence, a.k.a. the public domain.\n"
	"\n"
	"Usage:-\n"
	"\tsablmap [flags] <map.ini> <map.owb> <map.owm>\n"
	"\n"
	"If -s or --silent is provided, the program will not send\n"
	"anything to stdout nor stderr. Otherwise, it will print status\n"
	"info as it works to stderr. stdin and stdout are never used.";

static const char * const k_block_keys[2 + 32] = { "behav",
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
	"l1br_yf" };

static const char * const k_tlt_block_keys[16] = { "l2tl_tile",
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
	"l2br_yf" };

static const char * const k_truthy_strs[INI_BOOLSTRS_SZ] = { "true",
	"True",
	"TRUE",
	"y",
	"Y",
	"yes",
	"Yes",
	"YES",
	"on",
	"On",
	"ON" };

static const char * const k_falsey_strs[INI_BOOLSTRS_SZ] = { "false",
	"False",
	"FALSE",
	"n",
	"N",
	"no",
	"No",
	"NO",
	"off",
	"Off",
	"OFF" };

/** END STATIC CONSTANT DATA */

/** BEGIN STATIC DATA */

/* whether the debug printer should be quiet actually */
static int silent;

/** END STATIC DATA */

/** BEGIN FUNCTION DEFINITIONS */

static int ini_falsey( const char * in )
{
	ptri i;

	for( i = 0; i < INI_BOOLSTRS_SZ; ++i )
	{
		if( uni_strequ( k_falsey_strs[i], in ) )
		{
			return 1;
		}
	}

	return strtoul( in, NULL, 0 ) == 0 ? 1 : 0;
}

static int ini_truthy( const char * in )
{
	ptri i;

	for( i = 0; i < INI_BOOLSTRS_SZ; ++i )
	{
		if( uni_strequ( k_truthy_strs[i], in ) )
		{
			return 1;
		}
	}

	return strtoul( in, NULL, 0 ) == 1 ? 1 : 0;
}

static int ini_bool( const char * in )
{
	return ini_falsey( in ) ? 0 : ini_truthy( in ) ? 1 : -1;
}

static void dprint( const char * fmt, ... )
{
	va_list args;

	if( silent )
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

static uni_err_t ini2blockset( const struct ini * in_cfg,
	const u8 * in_tileset_img,
	const u8 * in_tileset_pal,
	struct blockset * out );

static uni_err_t block2surf( const struct blockset * in_blockset,
	u16 in_blockid,
	u32 in_flags,
	SDL_Surface * out );

static uni_err_t raster_tile( const struct tile * in_tile,
	const col_t in_pal[16],
	u32 in_flags,
	const u32 out[64] );

static uni_err_t render_map_view( const struct blockset * prima,
	const struct blockset * secunda,
	const struct map * map,
	b32d2 mapclip,
	SDL_Surface * out );

static uni_err_t render_blockset_view( const struct blockset * prima,
	const struct blockset * secunda,
	u32 row_offs,
	SDL_Surface * out );

static uni_err_t render_win(
	SDL_Surface * map, SDL_Surface * blockset, SDL_Surface * out );

static int mainloop( struct state * state ) { return 0; }

static uni_err_t state_init( struct state * state,
	const char * ini_fpath,
	const char * owb_fpath,
	const char * owm_fpath )
{
#if 0
	uni_err_t r;
	struct ini ini;
	ptri i;

	r = ini_parse( ini_fpath, &ini );

	if( r )
	{
		return r;
	}

	for( i = 0; i < ini.gpairs_sz; ++i )
	{
		char * const key   = ini.gpairs[i].key;
		char * const value = ini.gpairs[i].value;
		unsigned long n    = strtoul( value, NULL, 0 );

		if( uni_strequ( key, "bankid" ) )
		{
			if( errno == ERANGE )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADINPUT,
					UNI_ERR_LVL_PERM );
			}

			n = n > U8_MAX ? U8_MAX : n;

			state->props.bankid = (u8)n;
		}
		else if( uni_strequ( key, "mapid" ) )
		{
			if( errno == ERANGE )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADINPUT,
					UNI_ERR_LVL_PERM );
			}

			n = n > U8_MAX ? U8_MAX : n;

			state->props.mapid = (u8)n;
		}
		else if( uni_strequ( key, "bgm" ) )
		{
			if( errno == ERANGE )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADINPUT,
					UNI_ERR_LVL_PERM );
			}

			n = n > U16_MAX ? U16_MAX : n;

			state->props.bgm = n;
		}
		else if( uni_strequ( key, "scene" ) )
		{
			if( errno == ERANGE )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADINPUT,
					UNI_ERR_LVL_PERM );
			}

			n = n > 0xF ? 0xF : n;

			state->props.scene = n;
		}
		else if( uni_strequ( key, "xlen" ) )
		{
			if( errno == ERANGE )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADINPUT,
					UNI_ERR_LVL_PERM );
			}

			n = n > U16_MAX ? U16_MAX : n;

			state->map.w = (u16)n;
		}
		else if( uni_strequ( key, "ylen" ) )
		{
			if( errno == ERANGE )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADINPUT,
					UNI_ERR_LVL_PERM );
			}

			n = n > U16_MAX ? U16_MAX : n;

			state->map.l = (u16)n;
		}
		else if( uni_strequ( key, "flash" ) )
		{
			r = ini_bool( value );

			if( r == -1 )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADSTATE,
					UNI_ERR_LVL_PERM );
			}

			state->props.flash = r;
		}
		else if( uni_strequ( key, "running" ) )
		{
			r = ini_bool( value );

			if( r == -1 )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADSTATE,
					UNI_ERR_LVL_PERM );
			}

			state->props.running = r;
		}
		else if( uni_strequ( key, "biking" ) )
		{
			r = ini_bool( value );

			if( r == -1 )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADSTATE,
					UNI_ERR_LVL_PERM );
			}

			state->props.biking = r;
		}
		else if( uni_strequ( key, "rope" ) )
		{
			r = ini_bool( value );

			if( r == -1 )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADSTATE,
					UNI_ERR_LVL_PERM );
			}

			state->props.rope = r;
		}
		else if( uni_strequ( key, "showname" ) )
		{
			r = ini_bool( value );

			if( r == -1 )
			{
				return UNI_ERRCODE_MAKE( UNI_MAX_ERR_DESC,
					ERR_MOD_SABLMAP,
					UNI_ERR_EFLAG_BADSTATE,
					UNI_ERR_LVL_PERM );
			}

			state->props.showname = r;
		}
	}
#endif /* 0 */

	return 0;
}

static void state_fini( struct state * state ) {}

static int gfx_main( const char * ini_fpath,
	const char * owb_fpath,
	const char * owm_fpath )
{
	struct state state;
	uni_err_t r;

	r = state_init( &state, ini_fpath, owb_fpath, owm_fpath );

	if( r )
	{
		/* TODO: Parse and print error */
		return 1;
	}

	while( !mainloop( &state ) )
		;

	state_fini( &state );

	return 0;
}

int main( int ac, char * av[] )
{
	int done_flags = 0, dim_i = -1, i;
	u16 map_w = 0, map_l = 0;
	char * owb_fpath = NULL;
	char * owm_fpath = NULL;
	char * ini_fpath = NULL;

	if( ac == 1 )
	{
		dprint( "\n%s\n", k_help_text );

		return 0;
	}

	silent = 0;

	for( i = 1; i < ac; ++i )
	{
		const ptri arg_sz = uni_strlen( av[i] );

		/* skip over the flag value */
		if( i == dim_i )
		{
			continue;
		}

		if( !done_flags && arg_sz >= 1 && av[i][0] == '-' )
		{
			/* is a flag */
			if( arg_sz == 1 )
			{
				dprint( "SABLMAP cannot accept stdin. Exiting..." );

				return 127;
			}
			else if( av[i][1] == 's' )
			{
				silent = 1;
			}
			else if( av[i][1] == 'h' )
			{
				dprint( "\n%s\n", k_help_text );

				return 0;
			}
			else if( av[i][1] == '-' )
			{
				if( arg_sz == 2 )
				{
					done_flags = 1;
				}
				else if( uni_strequ( av[i], "--silent" ) )
				{
					silent = 1;
				}
				else if( uni_strequ( av[i], "--help" ) )
				{
					dprint( "\n%s\n", k_help_text );

					return 0;
				}
				else
				{
					dprint( "WARNING: Unrecognised flag \"%s\"",
						av[i] );
				}
			}
			else
			{
				dprint( "WARNING: Unrecognised flag \"%s\"",
					av[i] );
			}
		}
		else
		{
			ptri sz = uni_strlen( av[i] );

			if( ini_fpath == NULL )
			{
				ini_fpath = uni_alloc(
					sizeof( char ) * ( sz + 1 ) );

				uni_memcpy( ini_fpath, av[i], sz );
				ini_fpath[sz] = '\0';
			}
			else if( owb_fpath == NULL )
			{
				owb_fpath = uni_alloc(
					sizeof( char ) * ( sz + 1 ) );

				uni_memcpy( owb_fpath, av[i], sz );
				owb_fpath[sz] = '\0';
			}
			else if( owm_fpath == NULL )
			{
				owm_fpath = uni_alloc(
					sizeof( char ) * ( sz + 1 ) );

				uni_memcpy( owm_fpath, av[i], sz );
				owm_fpath[sz] = '\0';
			}
			else
			{
				dprint( "WARNING: Excess parameter \"%s\"",
					av[i] );
			}
		}
	}

	if( ini_fpath == NULL || owb_fpath == NULL || owm_fpath == NULL )
	{
		dprint( "Insufficient parameters. Exiting..." );

		return 127;
	}

	return gfx_main( ini_fpath, owb_fpath, owm_fpath );
}

/** END FUNCTION DEFINITIONS */

/** EOF */
