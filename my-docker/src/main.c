#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include "commons/commons.h"
#include "directory-space/directory-space.h"
#include "name-space/name-space.h"

#include <sys/stat.h>

#include <dirent.h>

const char rootDirectory[PATH_MAX] = "/src/container-root";

int main(int argc, char **argv) {
    pid_t pid, wpid, unsharedPid, waitUnsharedPid;
    char *argument[argc];
    int status, unsharedStatus;

    int i;
    for(i = 1; i < argc; i++) argument[i - 1] = argv[i];

    if((pid = fork()) == 0){

        separateDirectory(rootDirectory);
        separateNamespace();
        
        if((unsharedPid = fork()) == 0){
            
            if (mount("proc", "/proc", "proc", 0, NULL) == -1) {
                perror("proc");
                exit(1);
            }

            fprintf(stderr, "container starting....\n");

            execvp(argv[1], argument);
            perror("execvp");
        }else{
            do {
                waitUnsharedPid = waitpid(unsharedPid, &unsharedStatus, WUNTRACED);
            } while (!WIFEXITED(unsharedStatus) && !WIFSIGNALED(unsharedStatus));

            umount("/proc");

            fprintf(stderr, "container down.\n");
        }
        

    }else{
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 0;
}