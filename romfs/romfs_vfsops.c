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

/*
 * Definitions for ROMFS VFS operations
 */

int romfs_vfs_mount(struct mount *mp, vnode_t devvp, user_addr_t data, vfs_context_t context) {
	printf("VFS_MOUNT called.\n");
	return (ENOTSUP);
}

int romfs_vfs_start(struct mount *mp, int flags, vfs_context_t context) {
	printf("VFS_START called.\n");
	return (ENOTSUP);
}

int romfs_vfs_unmount(struct mount *mp, int mntflags, vfs_context_t context) {
	printf("VFS_UMOUNT called.\n");
	return (ENOTSUP);
}

int romfs_vfs_root(struct mount *mp, struct vnode **vpp, vfs_context_t context) {
	printf("VFS_ROOT called.\n");
	return (ENOTSUP);
}

int romfs_vfs_getattr(struct mount *mp, struct vfs_attr *attr, vfs_context_t context) {
	printf("VFS_GETATTR called.\n");
	return (ENOTSUP);
}

int romfs_vfs_sync(struct mount *mp, int waitfor, vfs_context_t context) {
	printf("VFS_SYNC called.\n");
	return (ENOTSUP);
}

int romfs_vfs_init(struct vfsconf *vc) {
	printf("VFS_INIT called.\n");	
	return (ENOTSUP);
}

int romfs_vfs_setattr(struct mount *mp, struct vfs_attr *attr, vfs_context_t context) {
	printf("VFS_SETATTR called.\n");
	return (ENOTSUP);
}

