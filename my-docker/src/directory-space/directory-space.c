#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "../commons/commons.h"
#include "directory-space.h"

bool_t isDirectoryExists(const char *directory){
    /* opendir(3)
    EBADF  fd is not a valid file descriptor opened for reading.

    EMFILE Too many file descriptors in use by process.

    ENFILE Too many files are currently open in the system.

    ENOENT Directory does not exist, or name is an empty string.

    ENOMEM Insufficient memory to complete the operation.

    ENOTDIR name is not a directory.
    */
    DIR *directoryStream = opendir(directory);

    if(directoryStream){

        closedir(directoryStream);
        
        return TRUE;

    }else if(ENOENT == errno){
        
        return FALSE;
    }

    perror("opendir");
    exit(1);
}

void separateDirectory(const char *rootDirectory){

    if(isDirectoryExists(rootDirectory) == FALSE){
        
        fprintf(stderr, "make directory %s .\n", rootDirectory);

        if(mkdir(rootDirectory, 0777) != 0){

            perror("mkdir");
            exit(1);
        }
    }

    chdir(rootDirectory);

    if (chroot(rootDirectory) != 0) {
        
        perror("chroot");
        exit(1);
    }
}
