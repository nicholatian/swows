#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined( _WIN32 )
#define PSEP ";"
#define DSEP "\\"
#define LSEP "\r\n"
#else
#define PSEP ":"
#define DSEP "/"
#define LSEP "\n"
#endif /* defined(_WIN32) */

const char* help_text =
	"Binary to assembly converter\n\nUsage:\n    \n    bin2asm.py [options] <input> [output]\n    Takes the binary file <input> and converts it to its GNU assembly equivalent.\n    If <input> is - then standard input is read.\n\nOptions:\n    -s <sym>  Specify symbol name to assign the data. Useful when reading from stdin.\n";

const char* const_str[] = {
	"\n.balign 4, 0\n.globl ", ":\n\t.byte ", "\n\t.byte "};

static void convert(
	void* in, size_t in_sz, const char* sym, char* out, size_t* out_sz )
{
	char* o;
	unsigned char* in_impl;
	size_t i, o_i, o_sz, li;
	const size_t sym_sz     = strlen( sym ),
					 const_sz[] = {strlen( const_str[0] ),
						 strlen( const_str[1] ),
						 strlen( const_str[2] )};

	assert( in && sym );

	in_impl = (unsigned char*)( in );

	o_sz = ( sym_sz * 2 ) + const_sz[0] + const_sz[1] + ( in_sz * 6 ) +
		( ( in_sz / 10 ) * 8 ) + 3;
	o = malloc( o_sz );
	assert( o != NULL );
	o_i = 0;
	memcpy( o + o_i, const_str[0], const_sz[0] );
	o_i += const_sz[0];
	memcpy( o + o_i, sym, sym_sz );
	o_i += sym_sz;
	o[o_i++] = '\n';
	memcpy( o + o_i, sym, sym_sz );
	o_i += sym_sz;
	memcpy( o + o_i, const_str[1], const_sz[1] );
	o_i += const_sz[1];

	li = 0;

	for( i = 0; i < in_sz; ++i )
	{
		unsigned char digit[2];

		if( o_i >= o_sz )
		{
			fprintf( stderr, "conversion output array overflow\n" );

			break;
		}

		if( li >= 10 )
		{
			/* "\n\t.byte " */
			memcpy( o + o_i, const_str[2], const_sz[2] );

			o_i += const_sz[2];

			li = 0;
		}
		else if( li > 0 )
		{
			o[o_i++] = ',';
			o[o_i++] = ' ';
		}

		li++;

		digit[0] = ( in_impl[i] & 0xF0 ) >> 4;
		digit[1] = in_impl[i] & 0xF;

		o[o_i++] = '0';
		o[o_i++] = 'x';
		o[o_i++] = (char)( digit[0] + ( digit[0] > 9 ? 0x37 : 0x30 ) );
		o[o_i++] = (char)( digit[1] + ( digit[1] > 9 ? 0x37 : 0x30 ) );
	}

	o[o_sz - 2] = '\n';
	o[o_sz - 1] = '\0';

	if( !out )
	{
		assert( out_sz != NULL );
		*out_sz = o_sz;
	}
	else
	{
		memcpy( out, o, o_sz );
	}

	free( o );
}

int main( int ac, char* av[] )
{
	char *sym, *fname, *out;
	size_t i, r, d_sz, blk_sz, out_sz;
	void *d, *d_tmp;
	FILE* f;

	if( ac < 2 ||
		( ac == 2 &&
			( !strcmp( av[1], "--help" ) || ( !strcmp( av[1], "-h" ) ) ) ) )
	{
		printf( "%s", help_text );

		return 0;
	}

	if( strcmp( av[1], "-" ) )
	{
		/* <input> is not ‘-’ */
		r = strlen( av[1] );

		/* the symbol defaults to the file name, sans the extension */
		sym = malloc( r - 3 );
		assert( sym != NULL );
		memcpy( sym, av[1], r - 4 );
		sym[r - 4] = '\0';

		/* replace all directory separators with underscores */
#if defined( _WIN32 )
		if( isalnum( sym[0] ) && sym[1] == ':' && sym[2] == '\\' )
#else
		if( sym[0] == '/' )
#endif /* defined(_WIN32) */
		{
			fprintf( stderr,
				"Error: absolute path detected for symbol string: %s\n",
				sym );
			return 2;
		}

		/* Copy over the file name */
		fname = malloc( r + 1 );
		assert( fname != NULL );
		memcpy( fname, av[1], r );
		fname[r] = '\0';
	}
	else
	{
		/* <input> is ‘-’, meaning stdin */
		/* We need to scan for ‘-s <sym>’ positional arg */
		sym = NULL;

		for( i = 2; i < ac; ++i )
		{
			if( !strcmp( av[i], "-s" ) )
			{
				if( i + 1 >= ac )
				{
					fprintf( stderr, "No positional arg provided for -s\n" );
					return 2;
				}

				r = strlen( av[i + 1] );

				sym = malloc( r + 1 );
				assert( sym != NULL );
				memcpy( sym, av[i + 1], r );
				sym[r] = '\0';

				break;
			}
		}

		if( !sym )
		{
			fprintf( stderr, "No symbol name specified!\n" );

			return 2;
		}

		/* Later code takes this to mean stdin */
		fname = NULL;
	}

	if( !fname )
	{
		f = stdin;
	}
	else
	{
		f = fopen( fname, "rb" );
		assert( f != NULL );
	}

	free( fname );
	fname = NULL;

	blk_sz = 16;
	d_sz   = 0;

	d = NULL;

	do
	{
		blk_sz <<= 1; /* *= 2 */
		/* include the previous blk_sz for previously read data */
		d_tmp = realloc( d, d_sz + blk_sz );
		assert( d_tmp != NULL );
		d = d_tmp;
		r = fread( d + d_sz, 1, blk_sz, f );
		/* keep track of total size read */
		d_sz += r;
	} while( r == blk_sz && !feof( f ) );

	convert( d, d_sz, (const char*)sym, NULL, &out_sz );
	out = malloc( out_sz );
	assert( out != NULL );
	convert( d, d_sz, (const char*)sym, out, NULL );

	free( d );
	free( sym );
	free( out );

	fprintf( f, "%s\n", out );
	fclose( f );

	return 0;
}
