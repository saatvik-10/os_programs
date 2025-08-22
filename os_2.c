#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    pid_t pid = fork();
    
    if (pid < 0) {
        printf("Error in fork execution\n");
    } else if (pid == 0) {
        printf("Hello World from child process with id %d\n", getpid());
    } else {
        wait(NULL);
        printf("Hello World from parent process with id %d\n", getpid());
    }
    return 0;
}

/*
Hello World from child process with id 18326
Hello World from parent process with id 18325
*/