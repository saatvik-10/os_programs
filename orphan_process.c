/*
NAME - SAATVIK MADAN
ROLL NO - 81
STATEMENT - WAP TO CREATE A CHILD PROCESS AND MAKE IT AN ORPHAN PROCESS
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    pid_t pid = fork();

    if(pid < 0) {
        printf("Error in fork execution\n");
        exit(EXIT_FAILURE);
    } else {
        if(pid == 0) {
            // sleep(5);
            printf("Child process with id %d\n", getpid());
            printf("Child's parent process id is %d\n", getppid());
            sleep(10);
        } else {
            printf("Parent process with id %d\n", getpid());
            printf("Parent is terminating, child %d will become orphan\n", pid);
        }
    }
    exit(0);
}

/*
Parent process with id 39852
Parent is terminating, child 39853 will become orphan
Child process with id 39853
Child's parent process id is 1
*/