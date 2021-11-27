#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "commons/commons.h"
#include "directory-space/directory-space.h"

#include <dirent.h>

const char rootDirectory[PATH_MAX] = "/src/base-image";

int main(int argc, char **argv) {
    pid_t pid, wpid;
    char *argument[argc];
    int status;

    int i;
    for(i = 1; i < argc; i++) argument[i - 1] = argv[i];

    if((pid = fork()) == 0){

        separateDirectory(rootDirectory);

        execvp(argv[1], argument);
        perror("execvp");

    }else{
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 0;
}