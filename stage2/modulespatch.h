#ifndef __MODULESPATCH_H__
#define __MODULESPATCH_H__

#include <lv2/process.h>
#include <lv2/thread.h>

// BIG WARNING: self offsets need to add 0x10000 for address shown in IDA, but not sprxs!

/** PATCHES **/

// EXPLORE_PLUGIN.SPRX
// ps2_nonbw_offset 

// EXPLORE_CATEGORY_GAME.SPRX
// ps2_nonbw_offset2 

// GAME_EXT_PLUGIN.SPRX
// ps2_nonbw_offset3

// RAM - the offset in ram is not always the same, anyway set it helps..
// vsh_pos_in_ram

// NOTE ON VSH PATCHES
// The vsh patches are found with bruteforce if you set them to 0x0 (aside vmode_patch_offset)

#if defined(FIRMWARE_3_55) 

#define EXPLORE_PLUGIN_HASH		0x8c0a948c000db78d
#define EXPLORE_PLUGIN_REBUG_HASH		0x8c0a948c000dbd9b //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0xa2bc18fa00052c74
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0xa2bc1e5e00052fd7 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0x3bebd0440001dd6b
#define GAME_EXT_PLUGIN_REBUG_HASH		0x3bebc61c0001deeb //rebug rex
#define LIBFS_EXTERNAL_HASH			0x4437cd5500000000


//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x4637F4

#define ps2_nonbw_offset       0xD7708
#define ps2_nonbw_offset2		0x7544C
#define ps2_nonbw_offset3		0x14314

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

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0

#define ps2_nonbw_offset       0xD7E64
#define ps2_nonbw_offset2		0x75C48
#define ps2_nonbw_offset3		0x14624

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
#define BASIC_PLUGINS_HASH		0xd725f80c0001f4fc
#define BASIC_PLUGINS_REBUG_HASH	0xd72295740001fbe4 //rebug REX
#define PSP_EMULATOR_HASH		0x7be65d6d00023702 
#define PEMUCORELIB_HASH		0xf349a563000bfcc8
#define EMULATOR_API_HASH		0xa9f5b2320001e7c6
#define EMULATOR_DRM_HASH		0xd2c7f3e20000538f
#define EMULATOR_DRM_DATA_HASH		0xb4f919590001b6e7
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003210

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x43EA78
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDAB88
#define ps2_nonbw_offset2		0x75724
#define ps2_nonbw_offset3		0x16498

/* basic_plugins */
#define pspemu_path_offset		0x49da8
#define psptrans_path_offset		0x4a9e0

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1be0

/* emulator_api */
#define psp_read			0xfc64
#define psp_read_header			0x10be8
#define psp_drm_patch5			0x10a0c
#define psp_drm_patch6			0x10a3c
#define psp_drm_patch7			0x10a54
#define psp_drm_patch8			0x10a58
#define psp_drm_patch9			0x10b98
#define psp_drm_patch11			0x10b9c
#define psp_drm_patch12			0x10bac
#define psp_product_id_patch1		0x10cac
#define psp_product_id_patch3		0x10f84
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e35c
#define psp_prx_patch			0x57478
#define psp_savedata_bind_patch1	0x79810
#define psp_savedata_bind_patch2	0x79868
#define psp_savedata_bind_patch3	0x79384
#define psp_extra_savedata_patch	0x851a8
#define psp_prometheus_patch		0x12e870
#define prx_patch_call_lr		0x585cc

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c64
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

//rebug rex
#define dex_ps2_nonbw_offset       0xDAFBC
#define dex_ps2_nonbw_offset2		0x75460
#define dex_ps2_nonbw_offset3		0x16788
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x446650
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0 
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4af28
#define dex_psptrans_path_offset		0x4bb98

#elif defined(FIRMWARE_4_21DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000e71cf
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3c54a00057710
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001d89e
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430
#define BASIC_PLUGINS_HASH		0xd72295740001fbe4
#define PSP_EMULATOR_HASH		0x7be65d6d00023702
#define PEMUCORELIB_HASH		0xf349a563000bfcc8
#define EMULATOR_API_HASH		0xa9f5b2320001e7c6
#define EMULATOR_DRM_HASH		0xd2c7f3e20000538f
#define EMULATOR_DRM_DATA_HASH		0xb4f919590001b6e7
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003210

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x446650
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDAFBC
#define ps2_nonbw_offset2		0x75460
#define ps2_nonbw_offset3		0x16788

/* basic_plugins */
#define pspemu_path_offset		0x4af28
#define psptrans_path_offset		0x4bb98

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1be0

/* emulator_api */
#define psp_read			0xfc64
#define psp_read_header			0x10be8
#define psp_drm_patch5			0x10a0c
#define psp_drm_patch6			0x10a3c
#define psp_drm_patch7			0x10a54
#define psp_drm_patch8			0x10a58
#define psp_drm_patch9			0x10b98
#define psp_drm_patch11			0x10b9c
#define psp_drm_patch12			0x10bac
#define psp_product_id_patch1		0x10cac
#define psp_product_id_patch3		0x10f84
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e35c
#define psp_prx_patch			0x57478
#define psp_savedata_bind_patch1	0x79810
#define psp_savedata_bind_patch2	0x79868
#define psp_savedata_bind_patch3	0x79384
#define psp_extra_savedata_patch	0x851a8
#define psp_prometheus_patch		0x12e870
#define prx_patch_call_lr		0x585cc

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c64
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x43EA78
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0 
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0

#elif defined(FIRMWARE_4_30) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eaf86
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ec258 //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3986200057cc4
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3cb3900057221 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001dd1d
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001dd6f //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430
#define BASIC_PLUGINS_HASH		0xd72209580001f769
#define PSP_EMULATOR_HASH		0x7be646f50002371e
#define PEMUCORELIB_HASH		0xf349a563000bfd70
#define EMULATOR_API_HASH		0xa9f5b37a0001b739
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDDA04
#define ps2_nonbw_offset2		0x755AC
#define ps2_nonbw_offset3		0x167D8

/* basic_plugins */
#define pspemu_path_offset		0x4a4c8
#define psptrans_path_offset		0x4b0e8

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c10

/* emulator_api */
#define psp_read			0xfb24
#define psp_read_header			0x10aa8
#define psp_drm_patch5			0x108cc
#define psp_drm_patch6			0x108fc
#define psp_drm_patch7			0x10914
#define psp_drm_patch8			0x10918
#define psp_drm_patch9			0x10a58
#define psp_drm_patch11			0x10a5c
#define psp_drm_patch12			0x10a6c
#define psp_product_id_patch1		0x10b6c
#define psp_product_id_patch3		0x10e44
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e340
#define psp_prx_patch			0x5745c
#define psp_savedata_bind_patch1	0x79810
#define psp_savedata_bind_patch2	0x79868
#define psp_savedata_bind_patch3	0x79384
#define psp_extra_savedata_patch	0x85194
#define psp_prometheus_patch		0x12e870
#define prx_patch_call_lr		0x585b0

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

//rebug rex
#define dex_ps2_nonbw_offset       0xDE1F4
#define dex_ps2_nonbw_offset2		0x6989C
#define dex_ps2_nonbw_offset3		0x16AC8
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x0
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0 
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4a4c8
#define dex_psptrans_path_offset		0x4b0e8

#elif defined(FIRMWARE_4_30DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec258
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3cb3900057221
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001dd6f
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430
#define BASIC_PLUGINS_HASH		0xd72285240001ffb7
#define BASIC_PLUGINS_REBUG_HASH	0xd72209580001f769 //weird rebug drex with cex basic_plugins
#define PSP_EMULATOR_HASH		0x7be646f50002371e
#define PEMUCORELIB_HASH		0xf349a563000bfd70
#define EMULATOR_API_HASH		0xa9f5b37a0001b739
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDE1F4
#define ps2_nonbw_offset2		0x6989C
#define ps2_nonbw_offset3		0x16AC8

/* basic_plugins */
#define pspemu_path_offset		0x4b708
#define psptrans_path_offset		0x4c360

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c10

/* emulator_api */
#define psp_read			0xfb24
#define psp_read_header			0x10aa8
#define psp_drm_patch5			0x108cc
#define psp_drm_patch6			0x108fc
#define psp_drm_patch7			0x10914
#define psp_drm_patch8			0x10918
#define psp_drm_patch9			0x10a58
#define psp_drm_patch11			0x10a5c
#define psp_drm_patch12			0x10a6c
#define psp_product_id_patch1		0x10b6c
#define psp_product_id_patch3		0x10e44
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e340
#define psp_prx_patch			0x5745c
#define psp_savedata_bind_patch1	0x79810
#define psp_savedata_bind_patch2	0x79868
#define psp_savedata_bind_patch3	0x79384
#define psp_extra_savedata_patch	0x85194
#define psp_prometheus_patch		0x12e870
#define prx_patch_call_lr		0x585b0

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x0
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0 
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0
#define cex_pspemu_path_offset		0x4a4c8
#define cex_psptrans_path_offset		0x4b0e8

#elif defined(FIRMWARE_4_31) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eba56
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3ccad00056f02
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001dd1d
#define LIBFS_EXTERNAL_HASH			0x5bc7bec80000643
#define BASIC_PLUGINS_HASH		0xd72209580001f769
#define PSP_EMULATOR_HASH		0x7be65d6d00023702
#define PEMUCORELIB_HASH		0xf349a563000bfd6f 
#define EMULATOR_API_HASH		0xa9f5b37a0001b739
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDDDC8
#define ps2_nonbw_offset2		0x69B68
#define ps2_nonbw_offset3		0x167D8

/* basic_plugins */
#define pspemu_path_offset		0x4a4c8
#define psptrans_path_offset		0x4b0e8

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1be0

/* emulator_api */
#define psp_read			0xfb24
#define psp_read_header			0x10aa8
#define psp_drm_patch5			0x108cc
#define psp_drm_patch6			0x108fc
#define psp_drm_patch7			0x10914
#define psp_drm_patch8			0x10918
#define psp_drm_patch9			0x10a58
#define psp_drm_patch11			0x10a5c
#define psp_drm_patch12			0x10a6c
#define psp_product_id_patch1		0x10b6c
#define psp_product_id_patch3		0x10e44
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e340
#define psp_prx_patch			0x5745c
#define psp_savedata_bind_patch1	0x79810
#define psp_savedata_bind_patch2	0x79868
#define psp_savedata_bind_patch3	0x79384
#define psp_extra_savedata_patch	0x85194
#define psp_prometheus_patch		0x12e870
#define prx_patch_call_lr		0x585b0

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

#elif defined(FIRMWARE_4_40) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec812
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb2345100056f13
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001de0e
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430
#define BASIC_PLUGINS_HASH		0xd72209580001f772
#define PSP_EMULATOR_HASH		0x7be6413100023720
#define PEMUCORELIB_HASH		0xf349a563000c0a42
#define EMULATOR_API_HASH		0xa9f5b55a0001b7c2
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDE5F0
#define ps2_nonbw_offset2		0x69B6C
#define ps2_nonbw_offset3		0x167F8

/* basic_plugins */
#define pspemu_path_offset		0x4a4c8
#define psptrans_path_offset		0x4b0e8

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1bf4

/* emulator_api */
#define psp_read			0xfc60
#define psp_read_header			0x10be4
#define psp_drm_patch5			0x10a08
#define psp_drm_patch6			0x10a38
#define psp_drm_patch7			0x10a50
#define psp_drm_patch8			0x10a54
#define psp_drm_patch9			0x10b94
#define psp_drm_patch11			0x10b98
#define psp_drm_patch12			0x10ba8
#define psp_product_id_patch1		0x10ca8
#define psp_product_id_patch3		0x10f80
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6b0
#define psp_prx_patch			0x577cc
#define psp_savedata_bind_patch1	0x7a4b0
#define psp_savedata_bind_patch2	0x7a508
#define psp_savedata_bind_patch3	0x7a024
#define psp_extra_savedata_patch	0x87520
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x58920

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

#elif defined(FIRMWARE_4_41) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec7fb
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ed19e //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3c7f100056fe5
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3caf10005734a
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001de0e
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001de56 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430
#define BASIC_PLUGINS_HASH		0xd72209580001f772
#define BASIC_PLUGINS_REBUG_HASH		0xd72285240001ffa8 //rebug rex
#define PSP_EMULATOR_HASH		0x7be6413100023721
#define PEMUCORELIB_HASH		0xf349a563000c0a38
#define EMULATOR_API_HASH		0xa9f5b55a0001b7c2
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDE7A0
#define ps2_nonbw_offset2		0x69D2C
#define ps2_nonbw_offset3		0x167F8

/* basic_plugins */
#define pspemu_path_offset		0x4a4c8
#define psptrans_path_offset		0x4b0e8

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1bf4

/* emulator_api */
#define psp_read			0xfc60
#define psp_read_header			0x10be4
#define psp_drm_patch5			0x10a08
#define psp_drm_patch6			0x10a38
#define psp_drm_patch7			0x10a50
#define psp_drm_patch8			0x10a54
#define psp_drm_patch9			0x10b94
#define psp_drm_patch11			0x10b98
#define psp_drm_patch12			0x10ba8
#define psp_product_id_patch1		0x10ca8
#define psp_product_id_patch3		0x10f80
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6b0
#define psp_prx_patch			0x577cc
#define psp_savedata_bind_patch1	0x7a4b0
#define psp_savedata_bind_patch2	0x7a508
#define psp_savedata_bind_patch3	0x7a024
#define psp_extra_savedata_patch	0x87520
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x58920

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

//rebug rex
#define dex_ps2_nonbw_offset       0xDEBC8
#define dex_ps2_nonbw_offset2		0x69A64
#define dex_ps2_nonbw_offset3		0x16AE8
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x0
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0 
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4b708
#define dex_psptrans_path_offset		0x4c360

#elif defined(FIRMWARE_4_41DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ed19e
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3caf10005734a
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001de56
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006430
#define BASIC_PLUGINS_HASH		0xd72285240001ffa8
#define PSP_EMULATOR_HASH		0x7be6413100023721
#define PEMUCORELIB_HASH		0xf349a563000c0a38
#define EMULATOR_API_HASH		0xa9f5b55a0001b7c2
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDEBC8
#define ps2_nonbw_offset2		0x69A64
#define ps2_nonbw_offset3		0x16AE8

/* basic_plugins */
#define pspemu_path_offset		0x4b708
#define psptrans_path_offset		0x4c360

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1bf4

/* emulator_api */
#define psp_read			0xfc60
#define psp_read_header			0x10be4
#define psp_drm_patch5			0x10a08
#define psp_drm_patch6			0x10a38
#define psp_drm_patch7			0x10a50
#define psp_drm_patch8			0x10a54
#define psp_drm_patch9			0x10b94
#define psp_drm_patch11			0x10b98
#define psp_drm_patch12			0x10ba8
#define psp_product_id_patch1		0x10ca8
#define psp_product_id_patch3		0x10f80
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6b0
#define psp_prx_patch			0x577cc
#define psp_savedata_bind_patch1	0x7a4b0
#define psp_savedata_bind_patch2	0x7a508
#define psp_savedata_bind_patch3	0x7a024
#define psp_extra_savedata_patch	0x87520
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x58920

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x0
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0 
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0

#elif defined(FIRMWARE_4_46) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec8a6
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ed168 //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3c7f100056faa
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3cafd000572dd //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001ddfd
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001de6b //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006433
#define BASIC_PLUGINS_HASH		0xd72209580001f7a2
#define BASIC_PLUGINS_REBUG_HASH		0xd72285240001ffa7 //rebug rex
#define PSP_EMULATOR_HASH		0x7be645a900023721
#define PEMUCORELIB_HASH		0xf349a563000c0cf3
#define EMULATOR_API_HASH		0xa9f5b55a0001b7c2
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xC4D64
#define ps2tonet_size_patch	    0xC4D58
#define vmode_patch_offset			0x442D68
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDE81C
#define ps2_nonbw_offset2		0x69D28
#define ps2_nonbw_offset3		0x167F8

/* basic_plugins */
#define pspemu_path_offset		0x4a4d8
#define psptrans_path_offset		0x4b0f8

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1bf8

/* emulator_api */
#define psp_read			0xfc60
#define psp_read_header			0x10be4
#define psp_drm_patch5			0x10a08
#define psp_drm_patch6			0x10a38
#define psp_drm_patch7			0x10a50
#define psp_drm_patch8			0x10a54
#define psp_drm_patch9			0x10b94
#define psp_drm_patch11			0x10b98
#define psp_drm_patch12			0x10ba8
#define psp_product_id_patch1		0x10ca8
#define psp_product_id_patch3		0x10f80
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6b0
#define psp_prx_patch			0x577cc
#define psp_savedata_bind_patch1	0x7a4b0
#define psp_savedata_bind_patch2	0x7a508
#define psp_savedata_bind_patch3	0x7a024
#define psp_extra_savedata_patch	0x87530
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x58920

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

//rebug rex
#define dex_ps2_nonbw_offset       0xDEC48
#define dex_ps2_nonbw_offset2		0x69A5C
#define dex_ps2_nonbw_offset3		0x16AE8
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x44A970
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0 
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4b708
#define dex_psptrans_path_offset		0x4c360

#elif defined(FIRMWARE_4_46DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ed168
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3cafd000572dd
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001de6b
#define LIBFS_EXTERNAL_HASH			0x5bc7bec800006433
#define BASIC_PLUGINS_HASH		0xd72285240001ffa7
#define PSP_EMULATOR_HASH		0x7be645a900023721
#define PEMUCORELIB_HASH		0xf349a563000c0cf3
#define EMULATOR_API_HASH		0xa9f5b55a0001b7c2
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x44A970
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDEC48
#define ps2_nonbw_offset2		0x69A5C
#define ps2_nonbw_offset3		0x16AE8

/* basic_plugins */
#define pspemu_path_offset		0x4b708
#define psptrans_path_offset		0x4c360

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1bf8

/* emulator_api */
#define psp_read			0xfc60
#define psp_read_header			0x10be4
#define psp_drm_patch5			0x10a08
#define psp_drm_patch6			0x10a38
#define psp_drm_patch7			0x10a50
#define psp_drm_patch8			0x10a54
#define psp_drm_patch9			0x10b94
#define psp_drm_patch11			0x10b98
#define psp_drm_patch12			0x10ba8
#define psp_product_id_patch1		0x10ca8
#define psp_product_id_patch3		0x10f80
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6b0
#define psp_prx_patch			0x577cc
#define psp_savedata_bind_patch1	0x7a4b0
#define psp_savedata_bind_patch2	0x7a508
#define psp_savedata_bind_patch3	0x7a024
#define psp_extra_savedata_patch	0x87530
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x58920

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD5B4

//rebug rex
#define cex_ps2tonet_patch			0xC4D64
#define cex_ps2tonet_size_patch	    0xC4D58
#define cex_vmode_patch_offset		0x442D68
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0 
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0

#elif defined(FIRMWARE_4_50) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec573
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3259a00056db7
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2a0
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5982e3a0001f6c7
#define PSP_EMULATOR_HASH		0x7be641f500023793
#define PEMUCORELIB_HASH		0xf349a563000c0d00
#define EMULATOR_API_HASH		0xa9f5bc7a0001baac
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDD8F0
#define ps2_nonbw_offset2		0x685CC
#define ps2_nonbw_offset3		0x16814

/* basic_plugins */
#define pspemu_path_offset		0x4a4a0
#define psptrans_path_offset		0x4b0c0

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x10198
#define psp_read_header			0x1111c
#define psp_drm_patch5			0x10f40
#define psp_drm_patch6			0x10f70
#define psp_drm_patch7			0x10f88
#define psp_drm_patch8			0x10f8c
#define psp_drm_patch9			0x110cc
#define psp_drm_patch11			0x110d0
#define psp_drm_patch12			0x110e0
#define psp_product_id_patch1		0x111e0
#define psp_product_id_patch3		0x114b8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x8753c
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_50DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ecdf3
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb333060005707b
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2ba
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5989f8a0001fefa
#define PSP_EMULATOR_HASH		0x7be641f500023793
#define PEMUCORELIB_HASH		0xf349a563000c0d00 
#define EMULATOR_API_HASH		0xa9f5bc7a0001baac
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xCA18C
#define ps2tonet_size_patch	    0xCA080
#define vmode_patch_offset			0x449B6C
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDDD18
#define ps2_nonbw_offset2		0x682F0
#define ps2_nonbw_offset3		0x16B04

/* basic_plugins */
#define pspemu_path_offset		0x4b688
#define psptrans_path_offset		0x4c2e0

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x10198
#define psp_read_header			0x1111c
#define psp_drm_patch5			0x10f40
#define psp_drm_patch6			0x10f70
#define psp_drm_patch7			0x10f88
#define psp_drm_patch8			0x10f8c
#define psp_drm_patch9			0x110cc
#define psp_drm_patch11			0x110d0
#define psp_drm_patch12			0x110e0
#define psp_product_id_patch1		0x111e0
#define psp_product_id_patch3		0x114b8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x8753c
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_53) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec3a6
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ecbbb //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3205600056c47
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb325e600056e4c //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2c8
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e2cf //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477	
#define BASIC_PLUGINS_HASH		0xb5982e3a0001f6c7
#define BASIC_PLUGINS_REBUG_HASH		0xb5989f8a0001fcf2 //rebug rex
#define PSP_EMULATOR_HASH		0x7be641f500023794
#define PEMUCORELIB_HASH		0xf349a563000c0cfc
#define EMULATOR_API_HASH		0xa9f5b37a0001bb36
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong. 
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x4422FC
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDD754
#define ps2_nonbw_offset2		0x68430
#define ps2_nonbw_offset3		0x16850

/* basic_plugins */
#define pspemu_path_offset		0x4a4a0
#define psptrans_path_offset		0x4b0c0

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x8753c
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define dex_ps2_nonbw_offset       0xDD6D0
#define dex_ps2_nonbw_offset2		0x68244
#define dex_ps2_nonbw_offset3		0x16B40
#define dex_ps2tonet_patch			0x0
#define dex_ps2tonet_size_patch	    0x0
#define dex_vmode_patch_offset		0x0
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4b688
#define dex_psptrans_path_offset		0x4c2e0

#elif defined(FIRMWARE_4_53DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ecbbb
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb325e600056e4c
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2cf
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5989f8a0001fcf2
#define PSP_EMULATOR_HASH		0x7be641f500023794
#define PEMUCORELIB_HASH		0xf349a563000c0cfc
#define EMULATOR_API_HASH		0xa9f5b37a0001bb36
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDD6D0
#define ps2_nonbw_offset2		0x68244
#define ps2_nonbw_offset3		0x16B40

/* basic_plugins */
#define pspemu_path_offset		0x4b688
#define psptrans_path_offset		0x4c2e0

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x8753c
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define cex_ps2tonet_patch			0x0
#define cex_ps2tonet_size_patch	    0x0
#define cex_vmode_patch_offset		0x4422FC
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0

#elif defined(FIRMWARE_4_55) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec3a6
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3205600056c47
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2c8
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5982e3a0001f6c7
#define PSP_EMULATOR_HASH		0x7be641f500023794
#define PEMUCORELIB_HASH		0xf349a563000c0cfc
#define EMULATOR_API_HASH		0xa9f5b37a0001bb36
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x442FD8
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDD754
#define ps2_nonbw_offset2		0x68430
#define ps2_nonbw_offset3		0x16850

/* basic_plugins */
#define pspemu_path_offset		0x4a4a0
#define psptrans_path_offset		0x4b0c0

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x8753c
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_55DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ecbbd
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb325e600056e4c
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e2cf
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5989f8a0001fef8
#define PSP_EMULATOR_HASH		0x7be641f500023794
#define PEMUCORELIB_HASH		0xf349a563000c0cfc
#define EMULATOR_API_HASH		0xa9f5b37a0001bb36
#define EMULATOR_DRM_HASH		0xa324dc4a0000539c
#define EMULATOR_DRM_DATA_HASH		0x1d8d2da00001b6e4
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc04800003207

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/*vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

//explore_plugin
#define ps2_nonbw_offset       0xDD6D0 //88 1E 00 00 54 00 06 B4  2F 80 00 00
//explore_category_game
#define ps2_nonbw_offset2		0x68244 //88 1E 00 00 54 00 06 B4  2F 80 00 00
//game_ext_plugin
#define ps2_nonbw_offset3		0x16B40 //3B 80 00 02 54 00 06 B4  2F 80 00 00

/* basic_plugins */
#define pspemu_path_offset		0x4b688
#define psptrans_path_offset		0x4c2e0

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x8753c
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27580-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_60)

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec8c2
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb322b600056e97
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e76a
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb59827ee0001f7ed
#define PSP_EMULATOR_HASH		0x7be641f500023793
#define PEMUCORELIB_HASH		0xf349a563000c0d6b
#define EMULATOR_API_HASH		0xa9f5b37a0001bb3c
#define EMULATOR_DRM_HASH		0xa324dc4a00005399
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDD978
#define ps2_nonbw_offset2		0x68354
#define ps2_nonbw_offset3		0x17004

/* basic_plugins */
#define pspemu_path_offset		0x4a810
#define psptrans_path_offset		0x4b440

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_60DEX)

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ed045
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb337a200056fad
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e7c3
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5988016000200a4
#define PSP_EMULATOR_HASH		0x7be641f500023793
#define PEMUCORELIB_HASH		0xf349a563000c0d6b
#define EMULATOR_API_HASH		0xa9f5b37a0001bb3c
#define EMULATOR_DRM_HASH		0xa324dc4a00005399
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDDD88
#define ps2_nonbw_offset2		0x68294
#define ps2_nonbw_offset3		0x172F4

/* basic_plugins */
#define pspemu_path_offset		0x4b9f0
#define psptrans_path_offset		0x4c658

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_65)

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec8c7
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ed047	 //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb322b600056e97
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb337a200056fad //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e76a
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e7c3 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb59827ee0001f7ed
#define BASIC_PLUGINS_REBUG_HASH	0xb59880160001fec1 //rebug rex
#define PSP_EMULATOR_HASH		0x7be641f500023794
#define PEMUCORELIB_HASH		0xf349a563000c0d66
#define EMULATOR_API_HASH		0xa9f5b37a0001bb3c
#define EMULATOR_DRM_HASH		0xa324dc4a00005399
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xC4C24
#define ps2tonet_size_patch	    0xC4C18
#define vmode_patch_offset			0x444E28
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDD978
#define ps2_nonbw_offset2		0x68354
#define ps2_nonbw_offset3		0x17004

/* basic_plugins */
#define pspemu_path_offset		0x4a810
#define psptrans_path_offset		0x4b440

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define dex_ps2_nonbw_offset       0xDDD88
#define dex_ps2_nonbw_offset2		0x68294
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA170
#define dex_ps2tonet_size_patch	    0xCA164
#define dex_vmode_patch_offset		0x44CA1C
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4b9f0
#define dex_psptrans_path_offset		0x4c658

#elif defined(FIRMWARE_4_65DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ed047
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb337a200056fad
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e7c3
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5988016000200a4
#define BASIC_PLUGINS_REBUG_HASH	0xb59880160001fec1
#define PSP_EMULATOR_HASH		0x7be641f500023794
#define PEMUCORELIB_HASH		0xf349a563000c0d66
#define EMULATOR_API_HASH		0xa9f5b37a0001bb3c
#define EMULATOR_DRM_HASH		0xa324dc4a00005399
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xCA170
#define ps2tonet_size_patch	    0xCA164
#define vmode_patch_offset			0x44CA1C
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDDD88
#define ps2_nonbw_offset2		0x68294
#define ps2_nonbw_offset3		0x172F4

/* basic_plugins */
#define pspemu_path_offset		0x4b9f0
#define psptrans_path_offset		0x4c658

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define cex_ps2tonet_patch			0xC4C24
#define cex_ps2tonet_size_patch	    0xC4C18
#define cex_vmode_patch_offset		0x444E28
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0

#elif defined(FIRMWARE_4_66) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec8c7
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb322b600056e97
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e76a
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb59827ee0001f7ed
#define PSP_EMULATOR_HASH		0x7be641f500023793 
#define PEMUCORELIB_HASH		0xf349a563000c0d66 
#define EMULATOR_API_HASH		0xa9f5b37a0001bb3c
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x444E28
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDD978
#define ps2_nonbw_offset2		0x68354
#define ps2_nonbw_offset3		0x17004

/* basic_plugins */
#define pspemu_path_offset		0x4a810
#define psptrans_path_offset		0x4b440

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_66DEX) // NO CFW EXIST

#define EXPLORE_PLUGIN_HASH		0x0
#define EXPLORE_CATEGORY_GAME_HASH	0x0
#define GAME_EXT_PLUGIN_HASH		0x0
#define LIBFS_EXTERNAL_HASH			0x0
#define BASIC_PLUGINS_HASH		0x0
#define PSP_EMULATOR_HASH		0x7be641f500023793 
#define PEMUCORELIB_HASH		0xf349a563000c0d66 
#define EMULATOR_API_HASH		0xa9f5b37a0001bb3c
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0x0
#define ps2tonet_size_patch	    0x0
#define vmode_patch_offset			0x44CA1C
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0x0
#define ps2_nonbw_offset2		0x0
#define ps2_nonbw_offset3		0x0

/* basic_plugins */
#define pspemu_path_offset		0x0
#define psptrans_path_offset		0x0

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x0

/* emulator_api */
#define psp_read			0x0
#define psp_read_header			0x0
#define psp_drm_patch5			0x0
#define psp_drm_patch6			0x0
#define psp_drm_patch7			0x0
#define psp_drm_patch8			0x0
#define psp_drm_patch9			0x0
#define psp_drm_patch11			0x0
#define psp_drm_patch12			0x0
#define psp_product_id_patch1		0x0
#define psp_product_id_patch3		0x0
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x0
#define psp_prx_patch			0x0
#define psp_savedata_bind_patch1	0x0
#define psp_savedata_bind_patch2	0x0
#define psp_savedata_bind_patch3	0x0
#define psp_extra_savedata_patch	0x0
#define psp_prometheus_patch		0x0
#define prx_patch_call_lr		0x0

/* emulator_drm */
#define psp_drm_tag_overwrite		0x0
#define psp_drm_key_overwrite		(0x0-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

#elif defined(FIRMWARE_4_70) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec54e
#define EXPLORE_PLUGIN_REBUG_HASH	0xacf4af2b000ecceb //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb378e600056add
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3396e00056ce1 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6c9
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e733 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb59824e20001f848
#define BASIC_PLUGINS_REBUG_HASH	0xb5988de200020143 //rebug rex
#define PSP_EMULATOR_HASH		0x7be641f500023793 
#define PEMUCORELIB_HASH		0xf349a563000c0d6c
#define EMULATOR_API_HASH		0xa9f5b37a0001bb45
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xC4B14
#define ps2tonet_size_patch	    0xC4B08
#define vmode_patch_offset			0x445630
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDD97C
#define ps2_nonbw_offset2		0x68324
#define ps2_nonbw_offset3		0x17004

/* basic_plugins */
#define pspemu_path_offset		0x4a9a8
#define psptrans_path_offset		0x4b5d8

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define dex_ps2_nonbw_offset       0xDDD8C
#define dex_ps2_nonbw_offset2		0x68264
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA060
#define dex_ps2tonet_size_patch	    0xCA054
#define dex_vmode_patch_offset		0x44D224
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0 
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4bb70
#define dex_psptrans_path_offset		0x4c7d8

#elif defined(FIRMWARE_4_70DEX)

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ecceb
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3396e00056ce1
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e733
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5988de200020143
#define PSP_EMULATOR_HASH		0x7be641f500023793 
#define PEMUCORELIB_HASH		0xf349a563000c0d6c
#define EMULATOR_API_HASH		0xa9f5b37a0001bb45
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xCA060
#define ps2tonet_size_patch	    0xCA054
#define vmode_patch_offset			0x44D224
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDDD8C
#define ps2_nonbw_offset2		0x68264
#define ps2_nonbw_offset3		0x172F4

/* basic_plugins */
#define pspemu_path_offset		0x4bb70
#define psptrans_path_offset		0x4c7d8

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define cex_ps2tonet_patch			0xC4B14
#define cex_ps2tonet_size_patch	    0xC4B08
#define cex_vmode_patch_offset		0x445630
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0 
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0

#elif defined(FIRMWARE_4_75) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec55b
#define EXPLORE_PLUGIN_REBUG_HASH 	0xacf4af2b000eccf7 //rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb378e600056ae1
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3396e00056ce1 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6c1
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e6e8 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb598277a0001f870
#define BASIC_PLUGINS_REBUG_HASH	0xb5988dba00020162 	//rebug rex
#define PSP_EMULATOR_HASH		0x7be641f500023794
#define PEMUCORELIB_HASH		0xf349a563000c0d66 
#define EMULATOR_API_HASH		0xa9f5b37a0001bb45
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xC4B14
#define ps2tonet_size_patch	    0xC4B08
#define vmode_patch_offset			0x445BEC
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0
#define psp_extra_drm_patch 0x0

#define ps2_nonbw_offset       0xDD97C
#define ps2_nonbw_offset2		0x68324
#define ps2_nonbw_offset3		0x17004

/* basic_plugins */
#define pspemu_path_offset		0x4a9f8
#define psptrans_path_offset		0x4b628

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define dex_ps2_nonbw_offset       0xDDD8C
#define dex_ps2_nonbw_offset2		0x68264
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA060
#define dex_ps2tonet_size_patch	    0xCA054
#define dex_vmode_patch_offset		0x44D7E0
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0 
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4bbc8
#define dex_psptrans_path_offset		0x4c830

#elif defined(FIRMWARE_4_75DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eccf7	
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3396e00056ce1
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6e8
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5988dba00020162
#define PSP_EMULATOR_HASH		0x7be641f500023794
#define PEMUCORELIB_HASH		0xf349a563000c0d66 
#define EMULATOR_API_HASH		0xa9f5b37a0001bb45
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x530000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xCA060
#define ps2tonet_size_patch	    0xCA054
#define vmode_patch_offset			0x44D7E0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDDD8C
#define ps2_nonbw_offset2		0x68264
#define ps2_nonbw_offset3		0x172F4

/* basic_plugins */
#define pspemu_path_offset		0x4bbc8
#define psptrans_path_offset		0x4c830

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define cex_ps2tonet_patch			0xC4B14
#define cex_ps2tonet_size_patch	    0xC4B08
#define cex_vmode_patch_offset		0x445BEC
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0
#define cex_psp_extra_drm_patch 0x0

#elif defined(FIRMWARE_4_76) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec55b
#define EXPLORE_PLUGIN_REBUG_HASH	 0xacf4af2b000eccf8//rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb378e600056ae1
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3396e00056ce1 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6c1
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e6e8	//rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb598277a0001f870
#define BASIC_PLUGINS_REBUG_HASH 	0xb5988dba00020162
#define PSP_EMULATOR_HASH		0x7be641f500023793 
#define PEMUCORELIB_HASH		0xf349a563000c0d66 
#define EMULATOR_API_HASH		0xa9f5b37a0001bb45
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
/* vsh */
#define ps2tonet_patch			0xC4B14
#define ps2tonet_size_patch	    0xC4B08
#define vsh_pos_in_ram			0x840000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
#define vmode_patch_offset			0x445BEC
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0
#define psp_extra_drm_patch	0x2452AC

#define ps2_nonbw_offset       0xDD97C
#define ps2_nonbw_offset2		0x68324
#define ps2_nonbw_offset3		0x17004

/* basic_plugins */
#define pspemu_path_offset		0x4a9f8
#define psptrans_path_offset		0x4b628

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define dex_ps2_nonbw_offset       0xDDD8C
#define dex_ps2_nonbw_offset2		0x68264
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA060
#define dex_ps2tonet_size_patch	    0xCA054
#define dex_vmode_patch_offset		0x44D7E0
#define dex_psp_drm_patch1		0x0
#define dex_psp_drm_patch2		0x0
#define dex_psp_drm_patch3		0x0
#define dex_psp_drm_patch4		0x0
#define dex_psp_drm_patchA		0x0
#define dex_psp_drm_patchB		0x0
#define dex_psp_drm_patchC		0x0
#define dex_psp_drm_patchD		0x0 
#define dex_psp_drm_patchE		0x0
#define dex_psp_drm_patchF		0x0
#define dex_pspemu_path_offset		0x4bbc8
#define dex_psptrans_path_offset		0x4c830

#elif defined(FIRMWARE_4_76DEX) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eccf8
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3396e00056ce1
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6e8
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5988dba00020162
#define PSP_EMULATOR_HASH		0x7be641f500023793 
#define PEMUCORELIB_HASH		0xf349a563000c0d66 
#define EMULATOR_API_HASH		0xa9f5b37a0001bb45
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xCA060
#define ps2tonet_size_patch	    0xCA054
#define vmode_patch_offset			0x44D7E0
#define psp_drm_patch1		0x0
#define psp_drm_patch2		0x0
#define psp_drm_patch3		0x0
#define psp_drm_patch4		0x0
#define psp_drm_patchA		0x0
#define psp_drm_patchB		0x0
#define psp_drm_patchC		0x0
#define psp_drm_patchD		0x0 
#define psp_drm_patchE		0x0
#define psp_drm_patchF		0x0

#define ps2_nonbw_offset       0xDDD8C
#define ps2_nonbw_offset2		0x68264
#define ps2_nonbw_offset3		0x172F4

/* basic_plugins */
#define pspemu_path_offset		0x4bbc8
#define psptrans_path_offset		0x4c830

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define cex_ps2tonet_patch			0xC4B14
#define cex_ps2tonet_size_patch	    0xC4B08
#define cex_vmode_patch_offset		0x445BEC
#define cex_psp_drm_patch1		0x0
#define cex_psp_drm_patch2		0x0
#define cex_psp_drm_patch3		0x0
#define cex_psp_drm_patch4		0x0
#define cex_psp_drm_patchA		0x0
#define cex_psp_drm_patchB		0x0
#define cex_psp_drm_patchC		0x0
#define cex_psp_drm_patchD		0x0 
#define cex_psp_drm_patchE		0x0
#define cex_psp_drm_patchF		0x0
#define cex_psp_extra_drm_patch	0x2452AC

#elif defined(FIRMWARE_4_78) 

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000ec41a
#define EXPLORE_PLUGIN_REBUG_HASH	 0xacf4af2b000eccfd		//rebug rex
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb378e600056ae1
#define EXPLORE_CATEGORY_GAME_REBUG_HASH	0x9cb3396e00056ce1 //rebug rex
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6c1
#define GAME_EXT_PLUGIN_REBUG_HASH		0xe274af7b0001e6e8 //rebug rex
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb598277a0001f870
#define BASIC_PLUGINS_REBUG_HASH	0xb5988dba00020162 //rebug rex
#define PSP_EMULATOR_HASH		0x7be641f500023793    
#define PEMUCORELIB_HASH		0xf349a563000c0d66 
#define EMULATOR_API_HASH		0xa9f5b37a0001bb45
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xC4B14
#define ps2tonet_size_patch	    0xC4B08
#define vmode_patch_offset		0x445BEC
#define psp_drm_patch1		0x242C74
#define psp_drm_patch2		0x243714
#define psp_drm_patch3		0x243350
#define psp_drm_patch4		0x243B5C
#define psp_drm_patchA		0x242D90
#define psp_drm_patchB		0x243630
#define psp_drm_patchC		0x2427C8
#define psp_drm_patchD		0x242D78
#define psp_drm_patchE		0x242D7C
#define psp_drm_patchF		0x243748
#define psp_extra_drm_patch		0x2457A4

#define ps2_nonbw_offset       0xDD9B4
#define ps2_nonbw_offset2		0x68324
#define ps2_nonbw_offset3		0x17004

/* basic_plugins */
#define pspemu_path_offset		0x4a9f8 
#define psptrans_path_offset		0x4b628

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1c18

/* emulator_api */
#define psp_read			0x102d8
#define psp_read_header			0x1125c
#define psp_drm_patch5			0x11080
#define psp_drm_patch6			0x110b0
#define psp_drm_patch7			0x110c8
#define psp_drm_patch8			0x110cc
#define psp_drm_patch9			0x1120c
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115f8
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */
#define psp_eboot_dec_patch		0x5e6bc
#define psp_prx_patch			0x577d8
#define psp_savedata_bind_patch1	0x7a4bc
#define psp_savedata_bind_patch2	0x7a514
#define psp_savedata_bind_patch3	0x7a030
#define psp_extra_savedata_patch	0x87540
#define psp_prometheus_patch		0x12ea28
#define prx_patch_call_lr		0x5892c

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4c68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define dex_ps2_nonbw_offset       0xDDDC4
#define dex_ps2_nonbw_offset2		0x68264
#define dex_ps2_nonbw_offset3		0x172F4
#define dex_ps2tonet_patch			0xCA060
#define dex_ps2tonet_size_patch	    0xCA054
#define dex_vmode_patch_offset		0x44AA50
#define dex_psp_drm_patch1		0x24A49C
#define dex_psp_drm_patch2		0x24AF3C
#define dex_psp_drm_patch3		0x24AB78
#define dex_psp_drm_patch4		0x24B384
#define dex_psp_drm_patchA		0x24A5B8
#define dex_psp_drm_patchB		0x24AE58
#define dex_psp_drm_patchC		0x249FF0
#define dex_psp_drm_patchD		0x24A5A0 
#define dex_psp_drm_patchE		0x24A5A4 
#define dex_psp_drm_patchF		0x24AF70
#define dex_pspemu_path_offset		0x4BBC8
#define dex_psptrans_path_offset		0x4C830

#elif defined(FIRMWARE_4_78DEX)

#define EXPLORE_PLUGIN_HASH		0xacf4af2b000eccfd
#define EXPLORE_CATEGORY_GAME_HASH	0x9cb3396e00056ce1
#define GAME_EXT_PLUGIN_HASH		0xe274af7b0001e6e8
#define LIBFS_EXTERNAL_HASH			0x5bc7bce800006477
#define BASIC_PLUGINS_HASH		0xb5988dba00020162 //
#define PSP_EMULATOR_HASH		0x7be641f500023793 // same as 4.76
#define PEMUCORELIB_HASH		0xf349a563000c0d66 // same as 4.75
#define EMULATOR_API_HASH		0xa9f5b37a0001bb45 // same as 4.75
#define EMULATOR_DRM_HASH		0xa324dc4a00005399 // same as 4.66
#define EMULATOR_DRM_DATA_HASH		0x75c390860001b75f // same as 4.66
#define LIBSYSUTIL_SAVEDATA_PSP_HASH	0x57bbc3b800003212 // same as 4.66

//WARNING: search this address in RAM!
//The offset is found with bruteforce if you set it to 0x0 or wrong.
#define vsh_pos_in_ram			0x930000 //Search in RAM 0xF821FF917C0802A6F80100804800039D or use socat ;)
//---------------------//
/* vsh */
#define ps2tonet_patch			0xCA060
#define ps2tonet_size_patch	    0xCA054
#define vmode_patch_offset		0x44AA50
#define psp_drm_patch1		0x24A49C // 0x249FA4 (4.76) 
#define psp_drm_patch2		0x24AF3C // 0x24AA44 (4.76) 
#define psp_drm_patch3		0x24AB78 // 0x24A680 (4.76)
#define psp_drm_patch4		0x24B384 // 0x24AE8C (4.76) 
#define psp_drm_patchA		0x24A5B8 // 0x24A0C0 (4.76) 
#define psp_drm_patchB		0x24AE58 // 0x241364 (4.76) 
#define psp_drm_patchC		0x249FF0 // 0x249AF8 (4.76) 
#define psp_drm_patchD		0x24A5A0 // 0x24A0A8 (4.76)   
#define psp_drm_patchE		0x24A5A4 // 0x24A0AC (4.76)  
#define psp_drm_patchF		0x24AF70 // 0x24AA78 (4.76)

#define ps2_nonbw_offset        0xDDDC4
#define ps2_nonbw_offset2		0x68264
#define ps2_nonbw_offset3		0x172F4

/* basic_plugins */
#define pspemu_path_offset		0x4BBC8
#define psptrans_path_offset		0x4C830

/* psp_emulator */
#define psp_set_psp_mode_offset 	0x1C18 

/* emulator_api */
#define psp_read			0x102D8 
#define psp_read_header			0x1125C
#define psp_drm_patch5			0x11080 
#define psp_drm_patch6			0x110B0 
#define psp_drm_patch7			0x110C8 
#define psp_drm_patch8			0x110CC 
#define psp_drm_patch9			0x1120C
#define psp_drm_patch11			0x11210
#define psp_drm_patch12			0x11220
#define psp_product_id_patch1		0x11320
#define psp_product_id_patch3		0x115F8 
#define umd_mutex_offset		(0x64480+0x38C)

/* pemucorelib */ // same as 4.66
#define psp_eboot_dec_patch		0x5E6BC
#define psp_prx_patch			0x577D8
#define psp_savedata_bind_patch1	0x7A4BC
#define psp_savedata_bind_patch2	0x7A514
#define psp_savedata_bind_patch3	0x7A030
#define psp_extra_savedata_patch	0x87540 
#define psp_prometheus_patch		0x12EA28
#define prx_patch_call_lr		0x5892C

/* emulator_drm */
#define psp_drm_tag_overwrite		0x4C68
#define psp_drm_key_overwrite		(0x27600-0xBE80)

/* libsysutil_savedata_psp */
#define psp_savedata_patch1		0x46CC
#define psp_savedata_patch2		0x46A4
#define psp_savedata_patch3		0x4504
#define psp_savedata_patch4		0x453C
#define psp_savedata_patch5		0x4550
#define psp_savedata_patch6		0x46B8

/* libfs */
#define aio_copy_root_offset		0xD658

//rebug rex
#define cex_ps2tonet_patch			0xC4B14
#define cex_ps2tonet_size_patch	    0xC4B08
#define cex_vmode_patch_offset		0x445BEC
#define cex_psp_drm_patch1		0x242C74
#define cex_psp_drm_patch2		0x243714
#define cex_psp_drm_patch3		0x243350
#define cex_psp_drm_patch4		0x243B5C
#define cex_psp_drm_patchA		0x242D90
#define cex_psp_drm_patchB		0x243630
#define cex_psp_drm_patchC		0x2427C8
#define cex_psp_drm_patchD		0x242D78
#define cex_psp_drm_patchE		0x242D7C
#define cex_psp_drm_patchF		0x243748
#define cex_psp_extra_drm_patch		0x2457A4	

#endif /* FIRMWARE */

extern uint8_t condition_ps2softemu;
extern uint8_t condition_psp_iso;
extern uint8_t condition_psp_dec;
extern uint8_t condition_psp_keys;
extern uint8_t condition_psp_change_emu;
extern uint8_t condition_psp_prometheus;
extern uint8_t condition_apphome; //needed libfs patch (JB FORMAT GAME)

typedef struct
{
	uint32_t offset;
	uint32_t data;
	uint8_t *condition;
} SprxPatch;

extern process_t vsh_process;
process_t get_vsh_process(void); //NzV
extern int vsh_type;

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

