#include <lv2/lv2.h>
#include <lv2/error.h>
#include <lv2/io.h>
#include <lv2/memory.h>
#include <lv2/modules.h>
#include <lv2/object.h>
#include <lv2/thread.h>
#include <lv2/synchronization.h>
#include <lv2/time.h>
#include <lv2/libc.h>
#include <lv2/patch.h>
#include <lv1/patch.h>
#include "common.h"
#include "psp.h"
#include "modulespatch.h"


uint32_t psp_tag;
uint8_t psp_keys[16];
uint8_t psp_code;
char pspemu_path[36];
char psptrans_path[37];

#define SPRX_NUM		90
#define NUM_SCE_PSP_MODULES	5

static char *sce_psp_modules[NUM_SCE_PSP_MODULES] =
{
	"sceFont_Library",
	"scePsmfP_library",
	"sceHeap_Library",
	"sceMpeg_library",
	"sceATRAC3plus_Library",
};

static char *umd_file;
static mutex_t mutex;
static int user_mutex;
static int umd_fd=-1;
static char psp_id[11];
static uint64_t pemucorelib_base;
static uint64_t emulator_api_base;
static uint32_t *savedata_param;

/* vsh.self */
SprxPatch psp_drm_patches[] =
{
	{ psp_drm_patch1, LI(R3, 0) 	},
	{ psp_drm_patch2, LI(R3, 0) 	},
	{ psp_drm_patch3, LI(R3, 0) 	},
	{ psp_drm_patch4, LI(R0, 0) 	},
	{ psp_drm_patchA, LI(R0, 0) 	},
	{ psp_drm_patchB, LI(R31, 0) 	},
	{ psp_drm_patchC, LI(R3, 0) 	},	
	{ psp_drm_patchD, NOP 			},
	{ psp_drm_patchE, LI(R3, 0) 	},
	{ psp_drm_patchF, LI(R3, 0) 	},
	{ 0 }
};

SprxPatch *patches_backup;
uint64_t psp_extra_drm_fix = 0xDEADFACE;

static INLINE void psp_patches_type()
{	
	#ifdef psp_extra_drm_patch
	psp_extra_drm_fix = psp_extra_drm_patch;
	#endif
	
	if(vsh_type == 0xCE)
	{
		//REBUG REX lv2 DEX and vsh CEX
		#ifdef cex_psp_drm_patch1
		psp_drm_patches[0].offset = cex_psp_drm_patch1;
		psp_drm_patches[1].offset = cex_psp_drm_patch2;
		psp_drm_patches[2].offset = cex_psp_drm_patch3;
		psp_drm_patches[3].offset = cex_psp_drm_patch4;
		psp_drm_patches[4].offset = cex_psp_drm_patchA;
		psp_drm_patches[5].offset = cex_psp_drm_patchB;
		psp_drm_patches[6].offset = cex_psp_drm_patchC;
		psp_drm_patches[7].offset = cex_psp_drm_patchD;
		psp_drm_patches[8].offset = cex_psp_drm_patchE;
		psp_drm_patches[9].offset = cex_psp_drm_patchF;
		#ifdef cex_psp_extra_drm_patch //in cfw rebug the patch is harcoded in the vsh, anyway.. 
		psp_extra_drm_fix = cex_psp_extra_drm_patch;
		#endif
		#endif
	}
	else if(vsh_type == 0xDE)
	{
		//REBUG REX lv2 CEX and vsh DEX
		#ifdef dex_psp_drm_patch1
		psp_drm_patches[0].offset = dex_psp_drm_patch1;
		psp_drm_patches[1].offset = dex_psp_drm_patch2;
		psp_drm_patches[2].offset = dex_psp_drm_patch3;
		psp_drm_patches[3].offset = dex_psp_drm_patch4;
		psp_drm_patches[4].offset = dex_psp_drm_patchA;
		psp_drm_patches[5].offset = dex_psp_drm_patchB;
		psp_drm_patches[6].offset = dex_psp_drm_patchC;
		psp_drm_patches[7].offset = dex_psp_drm_patchD;
		psp_drm_patches[8].offset = dex_psp_drm_patchE;
		psp_drm_patches[9].offset = dex_psp_drm_patchF;
		#endif
	}
}

int patches_found;

static INLINE int get_psp_patches()
{
	if(patches_found == 10)
		return 0;
	
	patches_found = 0;

	int i = 0, n = 0, mv_offset = 0;
	uint64_t value = 0, value2 = 0, addr = 0;
	
	psp_patches_type();
	
	#ifdef DEBUG
	DPRINTF("[PSP VSH PATCHES] Trying to find patches offsets..\n");
	#endif
	
	//static offset
	for(mv_offset = 0; mv_offset < 0x2000000; mv_offset += 0x100000)
	{	
		#ifdef DEBUG
		DPRINTF("Move offset +0x%x\n", mv_offset);
		#endif
		
		//psp_extra_drm_patch fix to 4.75/4.76/4.78 CEX by habib
		if(psp_extra_drm_fix != 0xDEADFACE)
		{
			addr = (vsh_offset + psp_extra_drm_fix + mv_offset);
			value = lv1_peekd(addr);
			value2 = lv1_peekd(addr + 8);	
			if(value == 0x7FE307B4EB8101E0ULL && value2 == 0xEBA101E87C0803A6ULL)
			{
				#ifdef DEBUG
				DPRINTF("[Extra Fix] Found psp_extra_drm_patch with static offset at address: 0x%lx\n", addr);
				#endif
			
				lv1_pokew(addr, 0x38600000);
				
				#ifdef DEBUG
				value = lv1_peekw(addr);
				DPRINTF("[Extra Fix] Poked 0x%lx at address: 0x%lx\n", value, addr);
				#endif
			}
		}
		//psp_drm_patch1
		addr = (vsh_offset + psp_drm_patches[0].offset + mv_offset);
		value = lv1_peekd(addr + 4);
		value2 = lv1_peekd(addr + 4 + 8);	
		if(value == 0x2F8300007C6B1B78ULL && value2 == 0x419E000C3D608002ULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patch1 with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[0].offset = addr;
			patches_found++;
		}
		//psp_drm_patch2
		addr = (vsh_offset + psp_drm_patches[1].offset + mv_offset);
		value = lv1_peekd(addr - 8);
		if(value == 0x7FC4F37838A00098ULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patch2 with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[1].offset = addr;
			patches_found++;
		}
		//psp_drm_patch3
		addr = (vsh_offset + psp_drm_patches[2].offset + mv_offset);
		value = lv1_peekw(addr);
		if(value == 0x7C6307B4 || value == 0x7D6307B4) //i don't found a good pattern for this
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patch3 with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[2].offset = addr;
			patches_found++;
		}
		//psp_drm_patch4
		addr = (vsh_offset + psp_drm_patches[3].offset + mv_offset);
		value = lv1_peekd(addr);
		if(value == 0x6000951379290020ULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patch4 with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[3].offset = addr;
			patches_found++;
		}
		//psp_drm_patchA
		addr = (vsh_offset + psp_drm_patches[4].offset + mv_offset);
		value = lv1_peekd(addr);
		if(value == 0x600095147C0307B4ULL) //NO 3.55
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchA with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[4].offset = addr;
			patches_found++;
		}
		//psp_drm_patchB
		addr = (vsh_offset + psp_drm_patches[5].offset + mv_offset);
		value = lv1_peekd(addr);
		if(value == 0x63FF95144BFFFF2CULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchB with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[5].offset = addr;
			patches_found++;
		}
		//psp_drm_patchC
		addr = (vsh_offset + psp_drm_patches[6].offset + mv_offset);
		value = lv1_peekd(addr - 4);
		if(value == 0x3800000060630601ULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchC with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[6].offset = addr;
			patches_found++;
		}
		//psp_drm_patchD
		addr = (vsh_offset + psp_drm_patches[7].offset + mv_offset);
		value = lv1_peekd(addr - 8);
		if(value == 0x7FE3FB7860009513ULL) //NO 3.55
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchD with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[7].offset = addr;
			patches_found++;
		}
		//psp_drm_patchE
		addr = (vsh_offset + psp_drm_patches[8].offset + mv_offset);
		value = lv1_peekd(addr - 8);
		if(value == 0x60009513409E001CULL) //NO 3.55
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchE with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[8].offset = addr;
			patches_found++;
		}
		//psp_drm_patchF
		addr = (vsh_offset + psp_drm_patches[9].offset + mv_offset);
		value = lv1_peekd(addr - 12);
		value2 = lv1_peekd(addr - 12 + 8); 
		if(value == 0x7F83E3787FE4FB78ULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchF with static offset at address: 0x%lx\n", addr);
			#endif
			psp_drm_patches[9].offset = addr;
			patches_found++;
		}
		if(patches_found == 10)
		{
			#ifdef DEBUG
			DPRINTF("All psp_drm_patch found with static offset!\n");
			#endif
			return 0;
		}
	}
	
	#ifdef DEBUG
	DPRINTF("psp_drm_patches not found with static offset, trying with bruteforce..\n");
	#endif
	patches_found = 0;
	
	//bruteforce
	mv_offset = (vsh_offset + 0x700);
	
	for(i = 0; i < 0x2000000; i += 4)
	{
		value = lv1_peekd(mv_offset + i);
		
		//psp_extra_drm_patch extra fix to 4.75/4.76/4.78 CEX by habib
		if(value == 0x7FE307B4EB8101E0ULL && psp_extra_drm_fix != 0xDEADFACE)
		{
			if(lv1_peekd(mv_offset + i + 8) == 0xEBA101E87C0803A6ULL)
			{
				#ifdef DEBUG
				DPRINTF("[Extra Fix] Found psp_extra_drm_patch with bruteforce at address 0x%x\n", mv_offset + i);
				#endif
			
				lv1_pokew(mv_offset + i, 0x38600000);
				
				#ifdef DEBUG
				value = lv1_peekw(mv_offset + i);
				DPRINTF("[Extra Fix] Poked 0x%lx at address: 0x%d\n", value, mv_offset + i);
				#endif
			}
		}
		//psp_drm_patch1
		if(value == 0x2F8300007C6B1B78ULL)
		{
			if(lv1_peekd(mv_offset + i + 8) == 0x419E000C3D608002ULL)
			{
				#ifdef DEBUG
				DPRINTF("Found psp_drm_patch1 with bruteforce at address 0x%x\n", mv_offset + i - 4);
				#endif
				psp_drm_patches[0].offset = (mv_offset + i - 4);
				patches_found++;
			}
		}
		//psp_drm_patch2
		if(value == 0x7FC4F37838A00098ULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patch2 with bruteforce at address 0x%x\n", mv_offset + i + 8);
			#endif
			psp_drm_patches[1].offset = (mv_offset + i + 8);
			patches_found++;
		}
		//psp_drm_patch3
		if(value == 0xF821FAC17C0802A6ULL)
		{
			if(lv1_peekd(mv_offset + i + 8) == 0xFAC104F0FAE104F8ULL)
			{
				for(n = 0; n < 0x30; n += 4)
				{
					if(lv1_peekw(mv_offset + i - n) == 0x7C6307B4 || lv1_peekw(mv_offset + i - n) == 0x7D6307B4) //i don't found a good pattern to this
					{
						#ifdef DEBUG
						DPRINTF("Found psp_drm_patch3 with bruteforce at address 0x%x\n", mv_offset + i - n);
						#endif
						psp_drm_patches[2].offset = (mv_offset + i - n);
						patches_found++;
						break;
					}
				}
			}
		}
		//psp_drm_patch4
		if(value == 0x6000951379290020ULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patch4 with bruteforce at address 0x%x\n", mv_offset + i);
			#endif
			psp_drm_patches[3].offset = (mv_offset + i);
			patches_found++;	
		}
		//psp_drm_patchA
		if(value == 0x600095147C0307B4ULL) //NO 3.55
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchA with bruteforce at address 0x%x\n", mv_offset + i);
			#endif
			psp_drm_patches[4].offset = (mv_offset + i);
			patches_found++;	
		}
		//psp_drm_patchB
		if(value == 0x63FF95144BFFFF2CULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchB with bruteforce at address 0x%x\n", mv_offset + i);
			#endif
			psp_drm_patches[5].offset = (mv_offset + i);
			patches_found++;	
			}
		//psp_drm_patchC
		if(value == 0x3800000060630601ULL)
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchC with bruteforce at address 0x%x\n", mv_offset + i + 4);
			#endif
			psp_drm_patches[6].offset = (mv_offset + i + 4);
			patches_found++;	
		}
		//psp_drm_patchD
		if(value == 0x7FE3FB7860009513ULL) //NO 3.55
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchD with bruteforce at address 0x%x\n", mv_offset + i + 8);
			#endif
			psp_drm_patches[7].offset = (mv_offset + i + 8);
			patches_found++;	
		}
		//psp_drm_patchE
		if(value == 0x60009513409E001CULL) //NO 3.55
		{
			#ifdef DEBUG
			DPRINTF("Found psp_drm_patchE with bruteforce at address 0x%x\n", mv_offset + i + 8);
			#endif
			psp_drm_patches[8].offset = (mv_offset + i + 8);
			patches_found++;	
		}
		//psp_drm_patchF
		if(value == 0x7F83E3787FE4FB78ULL)
		{
			if(lv1_peekw(mv_offset + i + 8) == 0x38A01038)
			{
				#ifdef DEBUG
				DPRINTF("Found psp_drm_patchF with bruteforce at address 0x%x\n", mv_offset + i + 12);
				#endif
				psp_drm_patches[9].offset = (mv_offset + i + 12);
				patches_found++;
			}
		}
		if(patches_found == 10)
		{
			#ifdef DEBUG
			DPRINTF("Found all psp_drm_patch with bruteforce!\n");
			#endif
			return 0;
		}
	}
	
	#ifdef DEBUG
	DPRINTF("WARNING!! Offsets not found!!\n");
	#endif
	return EINVAL;
}

static INLINE uint32_t swap32(uint32_t data)
{
	uint32_t ret = (((data) & 0xff) << 24);
	ret |= (((data) & 0xff00) << 8);
	ret |= (((data) & 0xff0000) >> 8);
	ret |= (((data) >> 24) & 0xff);
	
	return ret;
}

static INLINE uint16_t swap16(uint16_t data)
{
	uint32_t ret = (data<<8)&0xFF00;
	ret |= ((data>>8)&0xFF);
	
	return ret;
}

static INLINE __attribute__((unused)) int is_sce_psp_module(char *name)
{
	for (int i = 0; i < NUM_SCE_PSP_MODULES; i++)
	{
		if (strcmp(sce_psp_modules[i], name) == 0)
			return 1;
	}
	
	return 0;
}

int sys_psp_read_header(int fd, char *buf, uint64_t nbytes, uint64_t *nread)
{
	int ret;
	uint32_t n, unk2;
	uint64_t umd_size;
	sys_prx_id_t *list;
	uint32_t *unk;
	process_t process;
	
	#ifdef DEBUG
	DPRINTF("umd read header: %p %lx\n", buf, nbytes);
	#endif
	
	buf = get_secure_user_ptr(buf);
	nread = get_secure_user_ptr(nread);
		
	if (!umd_file || nbytes != 0x100)
		return EABORT;
	
	pemucorelib_base = 0;
	emulator_api_base = 0;
	list = alloc(SPRX_NUM*sizeof(sys_prx_module_info_t), 0x35);
	unk = alloc(SPRX_NUM*sizeof(uint32_t), 0x35);
	process = get_current_process();	
	
	ret = prx_get_module_list(process, list, unk, SPRX_NUM, &n, &unk2);
	if (ret == 0)
	{
		char *filename = alloc(256, 0x35);
		sys_prx_segment_info_t *segments = alloc(sizeof(sys_prx_segment_info_t), 0x35);
		
		for (int i = 0; i < SPRX_NUM; i++)
		{
			sys_prx_module_info_t modinfo;
			
			memset(&modinfo, 0, sizeof(sys_prx_module_info_t));
			modinfo.filename_size = 256;
			modinfo.segments_num = 1;
			
			if (prx_get_module_info(process, list[i], &modinfo, filename, segments) == 0)
			{
				if (strstr(filename, "/emulator_api.sprx"))
				{
					emulator_api_base = segments[0].base;
					#ifdef DEBUG
					DPRINTF("emulator_api base = %08lx\n", emulator_api_base);
					#endif	
				}
				else if (strstr(filename, "/PEmuCoreLib.sprx"))
				{
					pemucorelib_base = segments[0].base;						
					#ifdef DEBUG
					DPRINTF("PEmuCoreLib base = %08lx\n", pemucorelib_base);
					#endif
				}
			}
		}
		
		if (pemucorelib_base == 0 || emulator_api_base == 0)
			ret = EABORT;
		
		dealloc(filename, 0x35);
		dealloc(segments, 0x35);
	}
	
	dealloc(list, 0x35);
	dealloc(unk, 0x35);
	
	if (ret != 0)
		return ret;
		
	ret = cellFsOpen(umd_file, CELL_FS_O_RDONLY, &umd_fd, 0, NULL, 0);
	if (ret != 0)
		return ret;
	
	cellFsLseek(umd_fd, 0, SEEK_END, &umd_size);
	// Fake header. We will write only values actually used
	memset(buf, 0, 0x100);
	*(uint32_t *)(buf+0x0c) = 0x10;
	*(uint32_t *)(buf+0x64) = (umd_size/0x800)-1; // Last sector of umd	
	strncpy(buf+0x70, psp_id, 10);
						
	#ifdef DEBUG
	DPRINTF("ID: %s\n", psp_id);
	#endif
	
	if (mutex && user_mutex)
	{
		mutex = NULL;
		user_mutex = 0;
	}
	
	*nread = 0x100;
	return 0;
}

int sys_psp_read_umd(int unk, void *buf, uint64_t sector, uint64_t ofs, uint64_t size)
{
	uint64_t offset, dummy;
	int ret;
							
	#ifdef DEBUG
	DPRINTF("umd read %lx %lx %lx\n", sector, ofs, size);
	#endif

	if (!mutex)
	{
		object_handle_t obj_handle;
		void *object_table = get_current_process()->object_table;
		
		int ret = open_kernel_object(object_table, *(uint32_t *)(emulator_api_base+umd_mutex_offset), (void **)&mutex, &obj_handle, SYS_MUTEX_OBJECT);
				
		if (ret != 0)
		{
			#ifdef DEBUG
			DPRINTF("Cannot open user mutex, using an own one\n");
			#endif
			mutex_create(&mutex, SYNC_PRIORITY, SYNC_NOT_RECURSIVE);
			user_mutex = 0;
		}
		else
		{
			#ifdef DEBUG
			DPRINTF("user mutex opened succesfully\n");
			#endif
			user_mutex = 1;
			close_kernel_object_handle(object_table, obj_handle);
		}
	}
	
	mutex_lock(mutex, 0);
	offset = sector*0x800;
	
	if (ofs != 0)
	{
		offset = offset+0x800-ofs;
	}
	
	ret = cellFsLseek(umd_fd, offset, SEEK_SET, &dummy);
	if (ret != 0)
	{
		mutex_unlock(mutex);
		return ret;
	}
	
	ret = cellFsRead(umd_fd, get_secure_user_ptr(buf), size, &dummy);
	mutex_unlock(mutex);
	
	if (ret == 0)
		ret = (int)size;
	
	return ret;
}

int sys_psp_set_umdfile(char *file, char *id, int prometheus)
{
	if(vsh_offset == 0)
		return EINVAL;
	
	int ret;
	
	file = get_secure_user_ptr(file);
	id = get_secure_user_ptr(id);
	
	if (file == NULL)
	{
		if (umd_file)
		{
			dealloc(umd_file, 0x27);
			umd_file = NULL;			
		}
		if (mutex)
		{
			if (user_mutex)
			{
				user_mutex = 0;
			}
			else
			{
				mutex_destroy(mutex);
			}
				
			mutex = NULL;
		}
		if (patches_backup)
		{
			#ifdef DEBUG
			DPRINTF("[PSP VSH PATCHES] Restore original data\n");
			#endif
			
			for (int i = 0; patches_backup[i].offset != 0; i++)
			{
				lv1_pokew(patches_backup[i].offset, patches_backup[i].data);
				#ifdef DEBUG
				DPRINTF("%d) poke 0x%x at address 0x%x\n", i + 1, patches_backup[i].data, patches_backup[i].offset);
				#endif
			}
			
			dealloc(patches_backup, 0x27);
			patches_backup = NULL;
		}
		
		condition_psp_iso = 0;
		condition_psp_dec = 0;
		condition_psp_keys = 0;	
		condition_psp_prometheus = 0;
		return 0;
	}
	
	strncpy(psp_id, id, 10);
	psp_id[10] = 0;
	
	if (strlen(psp_id) != 10)
		return EINVAL;
	
	ret = pathdup_from_user(file, &umd_file);
	if (ret != 0)
		return ret;
	
	condition_psp_iso = 1;
	condition_psp_prometheus = prometheus;
	
#ifdef DEBUG
	if (prometheus)
	{
		DPRINTF("Using prometheus patch.\n");
	}
#endif

	if(get_psp_patches())
		return EINVAL;
		
	if (!patches_backup)
	{
		patches_backup = alloc(sizeof(psp_drm_patches), 0x27);
		memcpy(patches_backup, &psp_drm_patches, sizeof(psp_drm_patches));
		
		#ifdef DEBUG
		DPRINTF("Making patches..\n");
		#endif
		
		for (int i = 0; psp_drm_patches[i].offset != 0; i++)
		{	
			patches_backup[i].data = lv1_peekw(patches_backup[i].offset);
			lv1_pokew(psp_drm_patches[i].offset, psp_drm_patches[i].data);
			
			#ifdef DEBUG
			DPRINTF("Offset: 0x%08X | Poked Data: 0x%08X | Original Data: 0x%08X\n", (uint32_t)psp_drm_patches[i].offset, (uint32_t)psp_drm_patches[i].data, (uint32_t)patches_backup[i].data);
			#endif
		}
	}
	return 0;
}

int sys_psp_set_decrypt_options(int decrypt_patch, uint32_t tag, uint8_t *keys, uint8_t code, uint32_t tag2, uint8_t *keys2, uint8_t code2)
{
	if (!umd_file)
		return EABORT;
	
	keys = get_secure_user_ptr(keys);
	
	if (keys)
	{
		if (copy_from_user(keys, psp_keys, 0x10) == 0)
		{
			psp_tag = tag;
			psp_code = code;
			condition_psp_keys = 1;			
		}
	}
	
	condition_psp_dec = decrypt_patch;	
	return 0;
}

int sys_psp_prx_patch(uint32_t *unk, uint8_t *elf_buf, void *link_register)
{
	unk = get_secure_user_ptr(unk);
	elf_buf = get_secure_user_ptr(elf_buf);
	
#ifdef DEBUG
	
	//DPRINTF("link_register = %p\n", link_register);
	
	if (link_register == (void *)(pemucorelib_base+prx_patch_call_lr))
	{		
		if (*(uint32_t *)&elf_buf[0] == 0x7F454C46)
		{
			Elf32_Ehdr *ehdr;
			Elf32_Phdr *phdr;
			PspModuleInfo *modinfo;
		
			ehdr = (Elf32_Ehdr *)elf_buf;
			phdr = (Elf32_Phdr *)(elf_buf+swap32(ehdr->e_phoff));
			modinfo = (PspModuleInfo *)(elf_buf+swap32(phdr[0].p_paddr));
			DPRINTF("Module %s (elf_buf=%p)\n", modinfo->modname, elf_buf);			
		}		
	}
	
#endif
		
	psp_func1(unk, elf_buf);
	return 0;
}

int sys_psp_set_emu_path(char *path)
{
	if (!path)
	{
		condition_psp_change_emu = 0;
		return 0;
	}
	
	#ifdef DEBUG
	//DPRINTF("sys_psp_set_emu_path has been deleted\n");
	#endif
	
	/*DPRINTF("pspemu path set to %s\n", path);
	
	path = get_secure_user_ptr(path);
	condition_psp_change_emu = 1;
	
	snprintf(pspemu_path, sizeof(pspemu_path), "%s/psp_emulator.self", path);
	snprintf(psptrans_path, sizeof(psptrans_path), "%s/psp_translator.self", path);*/
	
	return 0;
}

int sys_psp_post_savedata_initstart(int result, void *param)
{
	#ifdef DEBUG
	DPRINTF("Savedata init start\n");
	#endif
	
	if (result == 0)
	{
		savedata_param = get_secure_user_ptr(param);
	}
	
	return result;
}

int sys_psp_post_savedata_shutdownstart(void)
{
	#ifdef DEBUG
	DPRINTF("Savedata shutdown start\n");
	#endif
	
	if (savedata_param)
	{
		#ifdef DEBUG
		DPRINTF("Original bind: %08X\n", savedata_param[0x34/4]);
		#endif
		savedata_param[0x34/4] = swap32(1); // SCE_UTILITY_SAVEDATA_BIND_OK
		savedata_param = NULL;
	}
	
	return 0;
}

#ifdef DEBUG

/* mips_registers actually contains much more than mips registers 
Known values:

0460 -> PC or current block to process
0478 -> PC too?
04D0 -> PC too?
0090 -> text offset in elf
0098 -> text size
*/

int sys_psp_sony_bug(uint32_t *mips_registers, void *unk, uint32_t mips_PC)
{
	DPRINTF("sys_psp_sony_bug, game is gonna crash\n");
	DPRINTF("PSP registers info:\n");
	DPRINTF("PC: %08X\n", mips_PC);
	DPRINTF("zr: %08X   at: %08X\n", mips_registers[0], mips_registers[1]);
	DPRINTF("v0: %08X   v1: %08X\n", mips_registers[2], mips_registers[3]);
	DPRINTF("a0: %08X   a1: %08X\n", mips_registers[4], mips_registers[5]);
	DPRINTF("a2: %08X   a3: %08X\n", mips_registers[6], mips_registers[7]);
	DPRINTF("t0: %08X   t1: %08X\n", mips_registers[8], mips_registers[9]);
	DPRINTF("t2: %08X   t3: %08X\n", mips_registers[10], mips_registers[11]);
	DPRINTF("t4: %08X   t5: %08X\n", mips_registers[12], mips_registers[13]);
	DPRINTF("t6: %08X   t7: %08X\n", mips_registers[14], mips_registers[15]);
	DPRINTF("s0: %08X   s1: %08X\n", mips_registers[16], mips_registers[17]);
	DPRINTF("s2: %08X   s3: %08X\n", mips_registers[18], mips_registers[19]);
	DPRINTF("s4: %08X   s5: %08X\n", mips_registers[20], mips_registers[21]);
	DPRINTF("s6: %08X   s7: %08X\n", mips_registers[22], mips_registers[23]);
	DPRINTF("t8: %08X   t9: %08X\n", mips_registers[24], mips_registers[25]);
	DPRINTF("k0: %08X   k1: %08X\n", mips_registers[26], mips_registers[27]);
	DPRINTF("gp: %08X   sp: %08X\n", mips_registers[28], mips_registers[29]);
	DPRINTF("s8: %08X   ra: %08X\n", mips_registers[30], mips_registers[31]);
		
	/*for (int i = 32; i < 1024; i += 2)
	{
		DPRINTF("%04X: %08X %08X\n", i*4, mips_registers[i], mips_registers[i+1]);
	}*/
	
	return 0;
}

#endif

