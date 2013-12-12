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

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/vnode.h>

/*
 * Definitions for ROMFS vnode operations
 */

int romfs_vnop_create(struct vnop_create_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_mknod(struct vnop_mknod_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_open(struct vnop_open_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_close(struct vnop_close_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_getattr(struct vnop_getattr_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_setattr(struct vnop_setattr_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_getxattr(struct vnop_getxattr_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_setxattr(struct vnop_setxattr_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_removexattr(struct vnop_removexattr_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_listxattr(struct vnop_listxattr_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_read(struct vnop_read_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_write(struct vnop_write_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}
int romfs_vnop_pagein(struct vnop_pagein_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}
int romfs_vnop_fsync(struct vnop_fsync_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_remove(struct vnop_remove_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_rename(struct vnop_rename_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_mkdir(struct vnop_mkdir_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_rmdir(struct vnop_rmdir_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_readdir(struct vnop_readdir_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_strategy(struct vnop_strategy_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_pathconf(struct vnop_pathconf_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_symlink(struct vnop_symlink_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_readlink(struct vnop_readlink_args *ap) {
#pragma unused (ap)
	return EINVAL;
}

int romfs_vnop_ioctl(struct vnop_ioctl_args *ap) {
#pragma unused (ap)
	return EINVAL;
}

int romfs_vnop_pageout(struct vnop_pageout_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_lookup(struct vnop_lookup_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_inactive(struct vnop_inactive_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_reclaim(struct vnop_reclaim_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_blktooff(struct vnop_blktooff_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_offtoblk(struct vnop_offtoblk_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

int romfs_vnop_blockmap(struct vnop_blockmap_args *ap) {
#pragma unused (ap)
	return (EINVAL);
}

