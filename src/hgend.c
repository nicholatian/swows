/****************************************************************************\
 *                                  SwowS™                                  *
 *                                                                          *
 *                    Copyright © 2021 Alexander Nicholi                    *
 *                       Released under BSD-0-Clause.                       *
\****************************************************************************/

#include "hgend.h"

#include "savblock.h"

bool32 hgend_get( void )
{
	return (u8 *)(SAVBLOCK2PTR + 0x8) == 0 ? 0 : 1;
}
