#include "global.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "task.h"

static EWRAM_DATA u8 sEscalatorAnim_TaskId = 0;

static void sub_80E12E8( u8 taskId, const s16* list, u16 isImpassableFlag )
{
	s16 r5 = gTasks[taskId].data[4] - 1;
	s16 r3 = gTasks[taskId].data[5] - 1;
	s16 r4 = gTasks[taskId].data[1];
	s16 y;
	s16 x;

	if( gTasks[taskId].data[2] == 0 )
	{
		for( y = 0; y < 3; y++ )
		{
			for( x = 0; x < 3; x++ )
			{
				s16 metatileId = MapGridGetMetatileIdAt(
					r5 + x, r3 + y );

				if( list[r4] == metatileId )
				{
					if( r4 != 2 )
						MapGridSetMetatileIdAt( r5 + x,
							r3 + y,
							isImpassableFlag |
								list[r4 + 1] );
					else
						MapGridSetMetatileIdAt( r5 + x,
							r3 + y,
							isImpassableFlag |
								list[0] );
				}
			}
		}
	}
	else
	{
		for( y = 0; y < 3; y++ )
		{
			for( x = 0; x < 3; x++ )
			{
				s16 metatileId = MapGridGetMetatileIdAt(
					r5 + x, r3 + y );

				if( list[2 - r4] == metatileId )
				{
					if( r4 != 2 )
						MapGridSetMetatileIdAt( r5 + x,
							r3 + y,
							isImpassableFlag |
								list[1 - r4] );
					else
						MapGridSetMetatileIdAt( r5 + x,
							r3 + y,
							isImpassableFlag |
								list[2] );
				}
			}
		}
	}
}

static const u16 gEscalatorTiles[][3] = {
	// (original) left-moving escalators
	// up
	{0x284, 0x282, 0x280},
	{0x285, 0x283, 0x281},
	{0x28C, 0x28A, 0x288},
	{0x28D, 0x28B, 0x289},
	// down
	{0x2A0, 0x2A2, 0x2A4},
	{0x2A1, 0x2A3, 0x2A5},
	{0x2A8, 0x2AA, 0x2AC},
	// right-moving escalators
	// up
	{0x305, 0x303, 0x301},
	{0x304, 0x302, 0x300},
	{0x30D, 0x30B, 0x309},
	{0x30C, 0x30A, 0x308},
	// down
	{0x2F1, 0x2F3, 0x2F5},
	{0x2F0, 0x2F2, 0x2F4},
	{0x2F9, 0x2FB, 0x2FD},
};

static void sub_80E1444( u8 taskId )
{
	s16* data = gTasks[taskId].data;
	s16 add   = data[2] >= 2 ? 7 : 0;

	data[3] = 1;

	sub_80E12E8( taskId,
		gEscalatorTiles[data[0] + add],
		( data[0] == 2 || data[0] == 4 ) ? METATILE_COLLISION_MASK
						 : 0 );

	data[0]++;
	data[0] &= 0x7;

	if( !data[0] )
	{
		DrawWholeMapView( );
		data[1] = ( data[1] + 1 ) % 3;
		data[3] = 0;
	}
}

static u8 createEscalatorAnimTask( u16 var )
{
	u8 taskId = CreateTask( sub_80E1444, 0 );
	s16* data = gTasks[taskId].data;

	PlayerGetDestCoords( &data[4], &data[5] );
	data[0] = 0;
	data[1] = 0;
	data[2] = var; // behaviour
	sub_80E1444( taskId );
	return taskId;
}

void InitEscalatorAnimTask( u8 var )
{
	sEscalatorAnim_TaskId = createEscalatorAnimTask( var );
}

void FiniEscalatorAnimTask( void ) { DestroyTask( sEscalatorAnim_TaskId ); }

bool8 sub_80E1584( void )
{
	if( gTasks[sEscalatorAnim_TaskId].data[3] == 0 &&
		gTasks[sEscalatorAnim_TaskId].data[1] == 2 )
		return FALSE;
	else
		return TRUE;
}
