
#include <stdio.h>
#include <stdlib.h>

#include "lodepng.c"

unsigned decode( unsigned char ** pels,
	unsigned * w,
	unsigned * h,
	const char * fname )
{
	const unsigned r = lodepng_decode32_file( pels, w, h, fname );

	if(r)
	{
		fprintf( stderr, "Error %u: %s\n", r,
			lodepng_error_text( r ) );

		if(pels != NULL)
		{
			free( pels );
		}

		return 1;
	}

	return 0;
}

unsigned encode( const char * fname,
	const unsigned char * pels,
	unsigned w,
	unsigned h )
{
	unsigned r;
	LodePNGState s;
	unsigned char * png = NULL;
	size_t png_sz;

	lodepng_state_init( &s );

	s.info_raw.bitdepth = 8;
	s.info_raw.colortype = LCT_RGBA;
	s.encoder.add_id = 0;
	s.encoder.filter_strategy = LFS_ENTROPY;
	s.encoder.zlibsettings.btype = 2;
	s.encoder.zlibsettings.lazymatching = 1;
	s.encoder.zlibsettings.minmatch = 6;
	s.encoder.zlibsettings.nicematch = 258;
	s.encoder.zlibsettings.use_lz77 = 1;
	s.encoder.zlibsettings.windowsize = 32768;

	r = lodepng_encode( &png, &png_sz, pels, w, h, &s );

	if(r)
	{
		fprintf( stderr, "Error %u: %s\n", r,
			lodepng_error_text( r ) );

		if(png != NULL)
		{
			free( png );
		}

		return 1;
	}

	r = lodepng_save_file( png, png_sz, fname );

	if(r)
	{
		fprintf( stderr, "Error %u: %s\n", r,
			lodepng_error_text( r ) );

		if(png != NULL)
		{
			free( png );
		}

		return 1;
	}

	lodepng_state_cleanup( &s );
	free( png );

	return 0;
}

int main( int ac, char * av[] )
{
	unsigned r, w, h;
	unsigned char * pels = NULL;

	if(ac < 2)
	{
		fprintf( stderr, "No input filename specified\n" );

		return 127;
	}
	else if(ac > 3)
	{
		fprintf( stderr, "No output filename specified\n" );

		return 127;
	}

	r = decode( &pels, &w, &h, av[1] );

	if(r)
	{
		return 1;
	}

	r = encode( av[2], pels, w, h );

	if(r)
	{
		return 2;
	}

	return 0;
}
