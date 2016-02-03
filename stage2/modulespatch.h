#ifndef __MODULESPATCH_H__
#define __MODULESPATCH_H__

#include <lv2/process.h>
#include <lv2/thread.h>

// BIG WARNING: self offsets need to add 0x10000 for address shown in IDA, but not sprxs!

/** PATCHES **/

// VSH.SELF
// ps2tonet_patch, ps2tonet_size_patch, vmode_patch_offset

// EXPLORE_PLUGIN.SPRX
// ps2_nonbw_offset 

// EXPLORE_CATEGORY_GAME.SPRX
// ps2_nonbw_offset2 

// GAME_EXT_PLUGIN.SPRX
// ps2_nonbw_offset3

// LIBFS.SPRX
// aio_copy_root_offset

// RAM - the offset in ram is not always the same, anyway set it helps..
// vsh_pos_in_ram

#if defined(FIRMWARE_3_55) 

#define EXPLORE_PLUGIN_HASH		0x8c0a948c000db78d
#define EXPLORE_PLUGIN_REBUG_HASH		0x8c0a948c000dbd9b //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0xa2bc18fa00052c74
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0xa2bc1e5e00052fd7 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0x3bebd0440001dd6b
#define GAME_EXT_PLUGIN_REBUG_HASH		0x3bebc61c0001deeb //rebug rex
#define LIBFS_EXTERNAL_HASH			0x4437cd5500000000

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xD7708
#define ps2_nonbw_offset2		0x7544C
#define ps2_nonbw_offset3		0x14314
#define vmode_patch_offset			0x4637F4
#define aio_copy_root_offset		0xD37C
//rebug rex
#define dex_ps2_nonbw_offset       0xD7E64
#define dex_ps2_nonbw_offset2		0x75C48
#define dex_ps2_nonbw_offset3		0x14624
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x0

#elif defined(FIRMWARE_3_55DEX) 

#define EXPLORE_PLUGIN_HASH		0x8c0a948c000dbd9b
#define EXPLORE_CATEGORY_GAME_HASH	0xa2bc1e5e00052fd7
#define GAME_EXT_PLUGIN_HASH		0x3bebc61c0001deeb
#define LIBFS_EXTERNAL_HASH			0x5bc7bad800005fa4

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xD7E64
#define ps2_nonbw_offset2		0x75C48
#define ps2_nonbw_offset3		0x14624
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD37C
//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x4637F4

#elif defined(FIRMWARE_4_21) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000e6988
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000e71cf	//rebug REX, Rogero
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3b0be000574c3
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3c54a00057710 //rebug REX
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001d8ef
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001d89e //rebug REX
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDAB88
#define ps2_nonbw_offset2		0x75724
#define ps2_nonbw_offset3		0x16498
#define vmode_patch_offset			0x43EA78
#define aio_copy_root_offset		0xD5B4
//rebug rex
#define dex_ps2_nonbw_offset       0xDAFBC
#define dex_ps2_nonbw_offset2		0x75460
#define dex_ps2_nonbw_offset3		0x16788
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x446650

#elif defined(FIRMWARE_4_21DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000e71cf
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3c54a00057710
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001d89e
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDAFBC
#define ps2_nonbw_offset2		0x75460
#define ps2_nonbw_offset3		0x16788
#define vmode_patch_offset			0x446650
#define aio_copy_root_offset		0xD5B4
//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x43EA78

#elif defined(FIRMWARE_4_30) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eaf86
#define EXPLORE_PLUGIN_ROGERO_HASH	0xacf4af2b000eba57
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ec258 //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3986200057cc4
#define EXPLORE_CATEGORY_GAME_ROGERO_HASH	0x9cb3ccad00056f02
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3cb3900057221 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001dd1d
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001dd6f //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDDA04
#define ps2_nonbw_offset2		0x755AC
#define ps2_nonbw_offset3		0x167D8
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD5B4
//rebug rex
#define dex_ps2_nonbw_offset       0xDE1F4
#define dex_ps2_nonbw_offset2		0x6989C
#define dex_ps2_nonbw_offset3		0x16AC8
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x0

#elif defined(FIRMWARE_4_30DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec258
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3cb3900057221
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001dd6f
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDE1F4
#define ps2_nonbw_offset2		0x6989C
#define ps2_nonbw_offset3		0x16AC8
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD5B4
//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x0

#elif defined(FIRMWARE_4_31) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eba56
#define EXPLORE_PLUGIN_MIRA_HASH	0xacf4af2b000eba58 //miralatijera
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3ccad00056f02
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001dd1d
#define LIBFS_EXTERNAL_HASH			0x5bc7bec80000643

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDDDC8
#define ps2_nonbw_offset2		0x69B68
#define ps2_nonbw_offset3		0x167D8
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD5B4

#elif defined(FIRMWARE_4_40) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec812
#define EXPLORE_PLUGIN_MIRA_HASH	0xacf4af2b000eba45 //miralatijera, rogero
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb2345100056f13
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001de0e
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDE5F0
#define ps2_nonbw_offset2		0x69B6C
#define ps2_nonbw_offset3		0x167F8
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD5B4

#elif defined(FIRMWARE_4_41) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec7fb
#define EXPLORE_PLUGIN_REBUG_LITE_HASH	0xacf4af2b000ec7f3 //rebug lite
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ed19e //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3c7f100056fe5
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3caf10005734a
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001de0e
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001de56 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDE7A0
#define ps2_nonbw_offset2		0x69D2C
#define ps2_nonbw_offset3		0x167F8
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD5B4
//rebug rex
#define dex_ps2_nonbw_offset       0xDEBC8
#define dex_ps2_nonbw_offset2		0x69A64
#define dex_ps2_nonbw_offset3		0x16AE8
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x0

#elif defined(FIRMWARE_4_41DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ed19e
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3caf10005734a
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001de56
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDEBC8
#define ps2_nonbw_offset2		0x69A64
#define ps2_nonbw_offset3		0x16AE8
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD5B4
//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x0

#elif defined(FIRMWARE_4_46) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec8a6
#define EXPLORE_PLUGIN_HABIB_HASH	0xacf4af2b000ec8a7 //habib, ferrox, rogero, arc
#define EXPLORE_PLUGIN_REBUG_LITE_HASH	 0xacf4af2b000ec8a3 //rebug lite
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ed168 //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3c7f100056faa
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3cafd000572dd //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001ddfd
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001de6b //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006433

#define ps2tonet_patch			0xC4D64
#define ps2tonet_size_patch	    0xC4D58
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDE81C
#define ps2_nonbw_offset2		0x69D28
#define ps2_nonbw_offset3		0x167F8
#define vmode_patch_offset			0x442D68
#define aio_copy_root_offset		0xD5B4
//rebug rex
#define dex_ps2_nonbw_offset       0xDEC48
#define dex_ps2_nonbw_offset2		0x69A5C
#define dex_ps2_nonbw_offset3		0x16AE8
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x44A970

#elif defined(FIRMWARE_4_46DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ed168
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3cafd000572dd
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001de6b
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006433

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDEC48
#define ps2_nonbw_offset2		0x69A5C
#define ps2_nonbw_offset3		0x16AE8
#define vmode_patch_offset			0x44A970
#define aio_copy_root_offset		0xD5B4
//rebug rex
#define cex_ps2tonet_patch			0xC4D64
#define cex_ps2tonet_size_patch	    0xC4D58
#define cex_vmode_patch_offset		0x442D68

#elif defined(FIRMWARE_4_50) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec573
#define EXPLORE_PLUGIN_HABIB_HASH		0xacf4af2b000ec575
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3259a00056db7
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2a0
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD8F0
#define ps2_nonbw_offset2		0x685CC
#define ps2_nonbw_offset3		0x16814
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_50DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ecdf3
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb333060005707b
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2ba
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xCA18C
#define ps2tonet_size_patch	    0xCA080
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDDD18
#define ps2_nonbw_offset2		0x682F0
#define ps2_nonbw_offset3		0x16B04
#define vmode_patch_offset			0x449B6C
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_53) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec3a6
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ecbbb //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3205600056c47
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb325e600056e4c //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2c8
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e2cf //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong. 
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD754
#define ps2_nonbw_offset2		0x68430
#define ps2_nonbw_offset3		0x16850
#define vmode_patch_offset			0x4422FC
#define aio_copy_root_offset		0xD658
//rebug rex
#define dex_ps2_nonbw_offset       0xDD6D0
#define dex_ps2_nonbw_offset2		0x68244
#define dex_ps2_nonbw_offset3		0x16B40
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x0

#elif defined(FIRMWARE_4_53DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ecbbb
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb325e600056e4c
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2cf
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD6D0
#define ps2_nonbw_offset2		0x68244
#define ps2_nonbw_offset3		0x16B40
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD658
//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x4422FC

#elif defined(FIRMWARE_4_55) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec3a6
#define EXPLORE_PLUGIN_HABIB_HASH		0xacf4af2b000ec3a7
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3205600056c47
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2c8
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD754
#define ps2_nonbw_offset2		0x68430
#define ps2_nonbw_offset3		0x16850
#define vmode_patch_offset			0x442FD8
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_55DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ecbbd
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb325e600056e4c
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2cf
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
//explore_plugin
#define ps2_nonbw_offset       0xDD6D0 //88 1E 00 00 54 00 06 B4  2F 80 00 00
//explore_category_game
#define ps2_nonbw_offset2		0x68244 //88 1E 00 00 54 00 06 B4  2F 80 00 00
//game_ext_plugin
#define ps2_nonbw_offset3		0x16B40 //3B 80 00 02 54 00 06 B4  2F 80 00 00
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_60) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec8c2
#define EXPLORE_PLUGIN_HABIB_HASH		0xacf4af2b000ec8c5 //habib
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb322b600056e97
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e76a
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD978
#define ps2_nonbw_offset2		0x68354
#define ps2_nonbw_offset3		0x17004
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_60DEX) //NO CFW EXIST

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ed045
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb337a200056fad
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e7c3
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDDD88
#define ps2_nonbw_offset2		0x68294
#define ps2_nonbw_offset3		0x172F4
#define vmode_patch_offset			0x0
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_65)  //MISS HASH CFW

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec8c7
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ed047	 //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb322b600056e97
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb337a200056fad //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e76a
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e7c3 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xC4C24
#define ps2tonet_size_patch	    0xC4C18
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD978
#define ps2_nonbw_offset2		0x68354
#define ps2_nonbw_offset3		0x17004
#define vmode_patch_offset			0x444E28
#define aio_copy_root_offset		0xD658
//rebug rex
#define dex_ps2_nonbw_offset       0xDDD88
#define dex_ps2_nonbw_offset2		0x68294
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA170
#define dex_ps2tonet_size_patch	    0xCA164
#define dex_vmode_patch_offset		0x44CA1C

#elif defined(FIRMWARE_4_65DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ed047
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb337a200056fad
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e7c3
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xCA170
#define ps2tonet_size_patch	    0xCA164
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDDD88
#define ps2_nonbw_offset2		0x68294
#define ps2_nonbw_offset3		0x172F4
#define vmode_patch_offset			0x44CA1C
#define aio_copy_root_offset		0xD658
//rebug rex
#define cex_ps2tonet_patch			0xC4C24
#define cex_ps2tonet_size_patch	    0xC4C18
#define cex_vmode_patch_offset		0x444E28

#elif defined(FIRMWARE_4_66) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec8c7
#define EXPLORE_PLUGIN_HABIB_HASH	0xacf4af2b000ec8cb //habib, ferrox, darknet	
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb322b600056e97
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e76a
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD978
#define ps2_nonbw_offset2		0x68354
#define ps2_nonbw_offset3		0x17004
#define vmode_patch_offset			0x444E28
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_66DEX) // NO CFW EXIST

#define EXPLORE_PLUGIN_HASH		0x0
#define EXPLORE_CATEGORY_GAME_HASH	0x0
#define GAME_EXT_PLUGIN_HASH		0x0
#define LIBFS_EXTERNAL_HASH			0x0

#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0x0
#define ps2_nonbw_offset2		0x0
#define ps2_nonbw_offset3		0x0
#define vmode_patch_offset			0x44CA1C
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_70) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec54e
#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec54f //habib. ferrox, darknet
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ecceb //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb378e600056add
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3396e00056ce1 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6c9
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e733 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xC4B14
#define ps2tonet_size_patch	    0xC4B08
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD97C
#define ps2_nonbw_offset2		0x68324
#define ps2_nonbw_offset3		0x17004
#define vmode_patch_offset			0x445630
#define aio_copy_root_offset		0xD658
//rebug rex
#define dex_ps2_nonbw_offset       0xDDD8C
#define dex_ps2_nonbw_offset2		0x68264
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA060
#define dex_ps2tonet_size_patch	    0xCA054
#define dex_vmode_patch_offset		0x44D224

#elif defined(FIRMWARE_4_70DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ecceb
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3396e00056ce1
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e733
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xCA060
#define ps2tonet_size_patch	    0xCA054
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDDD8C
#define ps2_nonbw_offset2		0x68264
#define ps2_nonbw_offset3		0x172F4
#define vmode_patch_offset			0x44D224
#define aio_copy_root_offset		0xD658
//rebug rex
#define cex_ps2tonet_patch			0xC4B14
#define cex_ps2tonet_size_patch	    0xC4B08
#define cex_vmode_patch_offset		0x445630

#elif defined(FIRMWARE_4_75) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec55b
#define EXPLORE_PLUGIN_HABIB_HASH 	0xacf4af2b000ec55c  //Habib, Ferrox..
#define EXPLORE_PLUGIN_REBUG_HASH 	0xacf4af2b000eccf7 //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb378e600056ae1
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3396e00056ce1 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6c1
#define GAME_EXT_PLUGIN_HABIB_HASH		0xe274af7b0001e6c0 //habib cobra
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e6e8 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xC4B14
#define ps2tonet_size_patch	    0xC4B08
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDD97C
#define ps2_nonbw_offset2		0x68324
#define ps2_nonbw_offset3		0x17004
#define vmode_patch_offset			0x445BEC
#define aio_copy_root_offset		0xD658
//rebug rex
#define dex_ps2_nonbw_offset       0xDDD8C
#define dex_ps2_nonbw_offset2		0x68264
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA060
#define dex_ps2tonet_size_patch	    0xCA054
#define dex_vmode_patch_offset		0x44D7E0

#elif defined(FIRMWARE_4_75DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eccf7	
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3396e00056ce1
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6e8
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xCA060
#define ps2tonet_size_patch	    0xCA054
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x530000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDDD8C
#define ps2_nonbw_offset2		0x68264
#define ps2_nonbw_offset3		0x172F4
#define vmode_patch_offset			0x44D7E0
#define aio_copy_root_offset		0xD658
//rebug rex
#define cex_ps2tonet_patch			0xC4B14
#define cex_ps2tonet_size_patch	    0xC4B08
#define cex_vmode_patch_offset		0x445BEC

#elif defined(FIRMWARE_4_76) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec55b
#define EXPLORE_PLUGIN_HABIB_HASH	0xacf4af2b000ec554 //habib, rebug lite
#define EXPLORE_PLUGIN_FERROX_HASH	 0xacf4af2b000ec55c //ferrox
#define EXPLORE_PLUGIN_REBUG_HASH	 0xacf4af2b000eccf8//rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb378e600056ae1
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3396e00056ce1 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6c1
#define GAME_EXT_PLUGIN_REBUG_LITE_HASH		0xe274af7b0001e6c0 //rebug lite
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e6e8	//rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xC4B14
#define ps2tonet_size_patch	    0xC4B08
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x840000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
#define ps2_nonbw_offset       0xDD97C
#define ps2_nonbw_offset2		0x68324
#define ps2_nonbw_offset3		0x17004
#define vmode_patch_offset			0x445BEC
#define aio_copy_root_offset		0xD658
//rebug rex
#define dex_ps2_nonbw_offset       0xDDD8C
#define dex_ps2_nonbw_offset2		0x68264
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA060
#define dex_ps2tonet_size_patch	    0xCA054
#define dex_vmode_patch_offset		0x44D7E0

#elif defined(FIRMWARE_4_76DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eccf8
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3396e00056ce1
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6e8
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define ps2tonet_patch			0xCA060
#define ps2tonet_size_patch	    0xCA054
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset       0xDDD8C
#define ps2_nonbw_offset2		0x68264
#define ps2_nonbw_offset3		0x172F4
#define vmode_patch_offset			0x44D7E0
#define aio_copy_root_offset		0xD658
//rebug rex
#define cex_ps2tonet_patch			0xC4B14
#define cex_ps2tonet_size_patch	    0xC4B08
#define cex_vmode_patch_offset		0x445BEC

#elif defined(FIRMWARE_4_78) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec41a
#define EXPLORE_PLUGIN_FERROX_HASH	 0xacf4af2b000ec41c //ferrox, Playerkp420
#define EXPLORE_PLUGIN_REBUG_HASH	 0xacf4af2b000eccfd		//rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb378e600056ae1
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3396e00056ce1 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6c1
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e6e8 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477

#define ps2tonet_patch			0xC4B14
#define ps2tonet_size_patch	    0xC4B08
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
#define ps2_nonbw_offset       0xDD9B4
#define ps2_nonbw_offset2		0x68324
#define ps2_nonbw_offset3		0x17004
#define vmode_patch_offset			0x445BEC
#define aio_copy_root_offset		0xD658
//rebug rex
#define dex_ps2_nonbw_offset       0xDDDC4
#define dex_ps2_nonbw_offset2		0x68264
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA060
#define dex_ps2tonet_size_patch	    0xCA054
#define dex_vmode_patch_offset		0x44AA50

#elif defined(FIRMWARE_4_78DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eccfd
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3396e00056ce1
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6e8
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define ps2tonet_patch			0xCA060
#define ps2tonet_size_patch	    0xCA054
//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
#define ps2_nonbw_offset        0xDDDC4
#define ps2_nonbw_offset2		0x68264
#define ps2_nonbw_offset3		0x172F4
#define vmode_patch_offset		0x44AA50	
#define aio_copy_root_offset		0xD658
//rebug rex
#define cex_ps2tonet_patch			0xC4B14
#define cex_ps2tonet_size_patch	    0xC4B08
#define cex_vmode_patch_offset		0x445BEC

#endif /* FIRMWARE */

#ifdef DO_PATCH_PS2
extern uint8_t condition_ps2softemu;
#endif
extern uint8_t condition_apphome; //needed libfs patch (JB FORMAT GAME)

extern process_t vsh_process;

process_t get_vsh_process(void); //NzV

void get_vsh_type();

/* Functions for kernel */
void modules_patch_init(void);
#ifdef PS3M_API
void unhook_all_modules(void);
#endif
int prx_load_vsh_plugin(unsigned int slot, char *path, void *arg, uint32_t arg_size);
int prx_unload_vsh_plugin(unsigned int slot);

/* Syscalls */
int sys_prx_load_vsh_plugin(unsigned int slot, char *path, void *arg, uint32_t arg_size);
int sys_prx_unload_vsh_plugin(unsigned int slot);
int sys_thread_create_ex(sys_ppu_thread_t *thread, void *entry, uint64_t arg, int prio, uint64_t stacksize, uint64_t flags, const char *threadname);

#ifdef PS3M_API
int ps3mapi_unload_vsh_plugin(char* name);
int ps3mapi_get_vsh_plugin_info(unsigned int slot, char *name, char *filename);
#endif

#endif /* __MODULESPATCH_H__ */

