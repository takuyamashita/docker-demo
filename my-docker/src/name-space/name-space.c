#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "name-space.h"

/*
CLONE_FILES
        Reverse the effect of the clone(2) CLONE_FILES flag.  Unshare the file descriptor table, so that the calling process no longer shares its file descriptors with any
        other process.

CLONE_FS
        Reverse  the  effect  of  the clone(2) CLONE_FS flag.  Unshare file system attributes, so that the calling process no longer shares its root directory (chroot(2)),
        current directory (chdir(2)), or umask (umask(2)) attributes with any other process.

CLONE_NEWIPC (since Linux 2.6.19)
        This flag has the same effect as the clone(2) CLONE_NEWIPC flag.  Unshare the System V IPC namespace, so that the calling process has a private copy of the  System
        V  IPC  namespace  which is not shared with any other process.  Specifying this flag automatically implies CLONE_SYSVSEM as well.  Use of CLONE_NEWIPC requires the
        CAP_SYS_ADMIN capability.

CLONE_NEWNET (since Linux 2.6.24)
        This flag has the same effect as the clone(2) CLONE_NEWNET flag.  Unshare the network namespace, so that the calling process is moved into a new network  namespace
        which is not shared with any previously existing process.  Use of CLONE_NEWNET requires the CAP_SYS_ADMIN capability.

CLONE_NEWNS
        This flag has the same effect as the clone(2) CLONE_NEWNS flag.  Unshare the mount namespace, so that the calling process has a private copy of its namespace which
        is not shared with any other process.  Specifying this flag automatically implies CLONE_FS as well.  Use of CLONE_NEWNS requires the CAP_SYS_ADMIN capability.

CLONE_NEWUTS (since Linux 2.6.19)
        This flag has the same effect as the clone(2) CLONE_NEWUTS flag.  Unshare the UTS IPC namespace, so that the calling process has a private copy of the  UTS  names‐
        pace which is not shared with any other process.  Use of CLONE_NEWUTS requires the CAP_SYS_ADMIN capability.

CLONE_SYSVSEM (since Linux 2.6.26)
        This  flag reverses the effect of the clone(2) CLONE_SYSVSEM flag.  Unshare System V semaphore undo values, so that the calling process has a private copy which is
        not shared with any other process.  Use of CLONE_SYSVSEM requires the CAP_SYS_ADMIN capability.

If flags is specified as zero, then unshare() is a no-op; no changes are made to the calling process's execution context.
*/
void separateNamespace(){
    
    if(unshare(CLONE_NEWPID | CLONE_NEWNS | CLONE_NEWUTS) == -1){

        perror("unshare");
        exit(1);
    }
}