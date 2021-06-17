/****************************************************************************\
 *                                  SwowS™                                  *
 *                                                                          *
 *                    Copyright © 2021 Alexander Nicholi                    *
 *                       Released under BSD-0-Clause.                       *
\****************************************************************************/

#include "types.h"
#include "hgend.h"
#include "savblock.h"

extern const u8 * const egBlendanSnip;
extern const u8 * const egMayleneSnip;

void hnam_sd( u8 which )
{
	const u8 * const name = hgend_get( ) ? egMayleneSnip : egBlendanSnip;

	/* discard it. we have to keep it to match the old function signature */
	(void)which;

	{
		ptri i;

		for(i = 0; i < 7; ++i) {
			*(u8 *)(SAVBLOCK2PTR + i) = name[i];
		}

		*(u8 *)(SAVBLOCK2PTR + 7) = 0xFF;
	}
}
