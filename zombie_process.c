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
            printf("Hello World from child process with id %d\n", getpid());
        } else {
            sleep(10);
            printf("Hello World from parent process with id %d\n", getpid());
            system("ps -axj | tail");
        }
    }
    exit(0);
}