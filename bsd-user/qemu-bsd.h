/*
 *  BSD conversion extern declarations
 *
 *  Copyright (c) 2013 Stacey D. Son
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _QEMU_BSD_H_
#define _QEMU_BSD_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/resource.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/uuid.h>
#include <sys/wait.h>
#include <netinet/in.h>

/* bsd-proc.c */
int target_to_host_resource(int code);
rlim_t target_to_host_rlim(abi_ulong target_rlim);
abi_ulong host_to_target_rlim(rlim_t rlim);
abi_long host_to_target_rusage(abi_ulong target_addr,
        const struct rusage *rusage);
#if defined(__FreeBSD_version) && __FreeBSD_version >= 1000000
abi_long host_to_target_wrusage(abi_ulong target_addr,
        const struct __wrusage *wrusage);
#endif /*  __FreeBSD_version >= 1000000 */
int host_to_target_waitstatus(int status);
void h2t_rusage(const struct rusage *rusage,
        struct target_freebsd_rusage *target_rusage);

#endif /* !_QEMU_BSD_H_ */
