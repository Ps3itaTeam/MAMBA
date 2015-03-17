#ifndef __MODULESPATCH_H__
#define __MODULESPATCH_H__

#include <lv2/process.h>
#include <lv2/thread.h>
#include <lv2/modules.h>

// BIG WARNING: self offsets need to add 0x10000 for address shown in IDA, but not sprxs!


#define vmode_patch_offset		0x0 // undefined
#define vsh_text_size			0x0 // undefined
#define revision_offset			0x0
#define revision_offset2		0x0 /* In data section */
#define spoof_version_patch		0x0


typedef struct
{
	uint32_t offset;
	uint32_t data;
	uint8_t *condition;
} SprxPatch;

extern uint8_t condition_ps2softemu;
extern uint8_t condition_apphome;
extern uint8_t condition_psp_iso;
extern uint8_t condition_psp_dec;
extern uint8_t condition_psp_keys;
extern uint8_t condition_psp_change_emu;
extern uint8_t condition_psp_prometheus;

extern uint8_t block_peek;

extern process_t vsh_process;

///////////// NzV BEGIN //////////////

process_t get_vsh_process(void);

///////////// NzV END //////////////

extern uint8_t safe_mode;

/* Functions for kernel */
void modules_patch_init(void);
#if 0
void do_spoof_patches(void);
void load_boot_plugins(void);
#endif
int prx_load_vsh_plugin(unsigned int slot, char *path, void *arg, uint32_t arg_size);
int prx_unload_vsh_plugin(unsigned int slot);

/* Syscalls */
#if 0
int sys_vsh_spoof_version(char *version_str);
#endif
int sys_prx_load_vsh_plugin(unsigned int slot, char *path, void *arg, uint32_t arg_size);
int sys_prx_unload_vsh_plugin(unsigned int slot);
int sys_thread_create_ex(sys_ppu_thread_t *thread, void *entry, uint64_t arg, int prio, uint64_t stacksize, uint64_t flags, const char *threadname);

///////////// PS3MAPI END //////////////

void unhook_all_modules(void);
int ps3mapi_unload_vsh_plugin(char* name);
int ps3mapi_get_vsh_plugin_info(unsigned int slot, char *name, char *filename);
///////////// PS3MAPI END //////////////

#endif /* __MODULESPATCH_H__ */

