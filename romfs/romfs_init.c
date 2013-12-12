/*
 Copyright (c) 2013, Ivan Ostres
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright notice, this
 list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.
 
 * Neither the name of the {organization} nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <mach/mach_types.h>
#include <sys/mount.h>
#include <sys/vnode.h>
#include <sys/systm.h>
#include <sys/param.h>

/*
 * VFS Operations callback definitions
 */
int romfs_vfs_mount(struct mount *mp, vnode_t devvp, user_addr_t data, vfs_context_t context);
int romfs_vfs_start(struct mount *mp, int flags, vfs_context_t context);
int romfs_vfs_unmount(struct mount *mp, int mntflags, vfs_context_t context);
int romfs_vfs_root(struct mount *mp, struct vnode **vpp, vfs_context_t context);
int romfs_vfs_getattr(struct mount *mp, struct vfs_attr *attr, vfs_context_t context);
int romfs_vfs_sync(struct mount *mp, int waitfor, vfs_context_t context);
int romfs_vfs_init(struct vfsconf *vc);
int romfs_vfs_setattr(struct mount *mp, struct vfs_attr *attr, vfs_context_t context);

/* Filled by vfs_fsadd. */
static vfstable_t romfs_vfsconf;

/* Filesystem operations. */
struct vfsops romfs_vfsops = {
	romfs_vfs_mount,     /* vfs_mount */
	romfs_vfs_start,     /* vfs_start */
	romfs_vfs_unmount,   /* vfs_unmount */
	romfs_vfs_root,      /* vfs_root */
	NULL,                /* vfs_quotactl */
	romfs_vfs_getattr,   /* vfs_getattr */
	romfs_vfs_sync,      /* vfs_sync */
	NULL,                /* vfs_vget */
	NULL,				 /* vfs_fhtovp */
	NULL,				 /* vfs_vptofh */
	romfs_vfs_init,		 /* vfs_init */
	NULL,				 /* vfs_sysctl */
	romfs_vfs_setattr,   /* vfs_setattr */
	{0}
};

/*
 * VNODE callback definitions
 */
int romfs_vnop_create(struct vnop_create_args *ap);
int romfs_vnop_mknod(struct vnop_mknod_args *ap);
int romfs_vnop_open(struct vnop_open_args *ap);
int romfs_vnop_close(struct vnop_close_args *ap);
int romfs_vnop_getattr(struct vnop_getattr_args *ap);
int romfs_vnop_setattr(struct vnop_setattr_args *ap);
int romfs_vnop_getxattr(struct vnop_getxattr_args *ap);
int romfs_vnop_setxattr(struct vnop_setxattr_args *ap);
int romfs_vnop_removexattr(struct vnop_removexattr_args *ap);
int romfs_vnop_listxattr(struct vnop_listxattr_args *ap);
int romfs_vnop_read(struct vnop_read_args *ap);
int romfs_vnop_write(struct vnop_write_args *ap);
int romfs_vnop_pagein(struct vnop_pagein_args *ap);
int romfs_vnop_fsync(struct vnop_fsync_args *ap);
int romfs_vnop_remove(struct vnop_remove_args *ap);
int romfs_vnop_rename(struct vnop_rename_args *ap);
int romfs_vnop_mkdir(struct vnop_mkdir_args *ap);
int romfs_vnop_rmdir(struct vnop_rmdir_args *ap);
int romfs_vnop_readdir(struct vnop_readdir_args *ap);
int romfs_vnop_strategy(struct vnop_strategy_args *ap);
int romfs_vnop_pathconf(struct vnop_pathconf_args *ap);
int romfs_vnop_symlink(struct vnop_symlink_args *ap);
int romfs_vnop_readlink(struct vnop_readlink_args *ap);
int romfs_vnop_ioctl(struct vnop_ioctl_args *ap);
int romfs_vnop_pageout(struct vnop_pageout_args *ap);
int romfs_vnop_lookup(struct vnop_lookup_args *ap);
int romfs_vnop_inactive(struct vnop_inactive_args *ap);
int romfs_vnop_reclaim(struct vnop_reclaim_args *ap);
int romfs_vnop_blktooff(struct vnop_blktooff_args *ap);
int romfs_vnop_offtoblk(struct vnop_offtoblk_args *ap);
int romfs_vnop_blockmap(struct vnop_blockmap_args *ap);

/* 
 * VNODE related structures 
 */

typedef int     vnop_t(void *);

int (**romfs_vnodeop_p)(void *);
static struct vnodeopv_entry_desc romfs_vnodeop_entries[] = {
	{ &vnop_default_desc,		(vnop_t *) vn_default_error },
	{ &vnop_lookup_desc,		(vnop_t *) romfs_vnop_lookup },
	{ &vnop_create_desc,		(vnop_t *) romfs_vnop_create },
	{ &vnop_mknod_desc,			(vnop_t *) romfs_vnop_mknod },
	{ &vnop_open_desc,			(vnop_t *) romfs_vnop_open },
	{ &vnop_close_desc,			(vnop_t *) romfs_vnop_close },
	{ &vnop_getattr_desc,		(vnop_t *) romfs_vnop_getattr },
	{ &vnop_setattr_desc,		(vnop_t *) romfs_vnop_setattr },
	{ &vnop_getxattr_desc,		(vnop_t *) romfs_vnop_getxattr },
	{ &vnop_setxattr_desc,		(vnop_t *) romfs_vnop_setxattr },
	{ &vnop_removexattr_desc,	(vnop_t *) romfs_vnop_removexattr },
	{ &vnop_listxattr_desc,		(vnop_t *) romfs_vnop_listxattr },
	{ &vnop_read_desc,			(vnop_t *) romfs_vnop_read },
	{ &vnop_write_desc,			(vnop_t *) romfs_vnop_write },
	{ &vnop_fsync_desc,			(vnop_t *) romfs_vnop_fsync },
	{ &vnop_remove_desc,		(vnop_t *) romfs_vnop_remove },
	{ &vnop_rename_desc,		(vnop_t *) romfs_vnop_rename },
	{ &vnop_mkdir_desc,			(vnop_t *) romfs_vnop_mkdir },
	{ &vnop_rmdir_desc,			(vnop_t *) romfs_vnop_rmdir },
	{ &vnop_readdir_desc,		(vnop_t *) romfs_vnop_readdir },
	{ &vnop_inactive_desc,		(vnop_t *) romfs_vnop_inactive },
	{ &vnop_reclaim_desc,		(vnop_t *) romfs_vnop_reclaim },
	{ &vnop_pathconf_desc,		(vnop_t *) romfs_vnop_pathconf },
	{ &vnop_pagein_desc,		(vnop_t *) romfs_vnop_pagein },
	{ &vnop_pageout_desc,		(vnop_t *) romfs_vnop_pageout },
	{ &vnop_blktooff_desc,		(vnop_t *) romfs_vnop_blktooff },
	{ &vnop_offtoblk_desc,		(vnop_t *) romfs_vnop_offtoblk },
  	{ &vnop_blockmap_desc,		(vnop_t *) romfs_vnop_blockmap },
	{ &vnop_strategy_desc,		(vnop_t *) romfs_vnop_strategy },
	{ &vnop_symlink_desc,		(vnop_t *) romfs_vnop_symlink },
	{ &vnop_readlink_desc,		(vnop_t *) romfs_vnop_readlink },
	{ &vnop_ioctl_desc, 		(vnop_t *) romfs_vnop_ioctl},
	{ &vnop_bwrite_desc,		(vnop_t *) vn_bwrite },
	{ NULL, NULL }
};

struct vnodeopv_desc romfs_vnodeop_opv_desc =
{ &romfs_vnodeop_p, romfs_vnodeop_entries };

struct vnodeopv_desc *romfs_vnodeop_opv_desc_list[1] =
{
	&romfs_vnodeop_opv_desc
};

/*
 * KEXT entry point
 */
kern_return_t romfs_start (kmod_info_t * ki, void * d) {
	
	errno_t error;
	struct vfs_fsentry vfe;
	
	printf("Loading ROMFS.\n");
	
	/* VFS callbacks. */
	vfe.vfe_vfsops = &romfs_vfsops;
	
	/* We just have vnode operations for regular files and directories */
	vfe.vfe_vopcnt = 1;				
	vfe.vfe_opvdescs = romfs_vnodeop_opv_desc_list;
	strncpy(vfe.vfe_fsname, "romfs", 5);
	vfe.vfe_flags =		VFS_TBLTHREADSAFE |
	VFS_TBLNOTYPENUM |	
	VFS_TBLLOCALVOL |
	VFS_TBL64BITREADY |
	VFS_TBLNATIVEXATTR |
	VFS_TBLGENERICMNTARGS|
	VFS_TBLREADDIR_EXTENDED;
	vfe.vfe_reserv[0] = 0;
	vfe.vfe_reserv[1] = 0;
	
	/* Register. */
	error = vfs_fsadd(&vfe, &romfs_vfsconf);
	if(error)
		printf("Error registering ROMFS with VFS.\n");
	else
	    printf("Registered ROMFS with VFS.\n");
	return error ? KERN_FAILURE : KERN_SUCCESS;
}


kern_return_t romfs_stop (kmod_info_t * ki, void * d) {
	errno_t error;
	
	printf("Unloading ROMFS.\n");
	
	/* Try to unregister. */
	error = vfs_fsremove(romfs_vfsconf);
	if(error)
		printf("Error unregistering ROMFS with VFS.\n");
	else
		printf("Unregistered ROMFS with VFS.\n");
	
	return error ? KERN_FAILURE : KERN_SUCCESS;
}
