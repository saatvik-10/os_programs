//  WAP TO IMPLEMENT PIPE FOR ONE WAY COMMUNICATION

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 100

int main() {
    int fd[2], n;
    char str[MAX];
    char l[MAX];
    pid_t pid;

    printf("Enter parent string: ");
    fflush(stdin);

    fgets(str, sizeof(str), stdin);

    if((pipe(fd)) < 0) {
        printf("Error in pipe");
        exit(0);
    }

    if((pid = fork()) < 0) {
        printf("Error in fork");
        exit(0);
    }

    if(pid > 0) {
        close(fd[0]);
        write(fd[1], str, strlen(str));
        close(fd[1]); 
        wait(NULL);
    } else {
        close(fd[1]);
        n = read(fd[0], l, MAX-1);
        l[n] = '\0';
        printf("Child received: %s", l);
        close(fd[0]); 
    }
    return 0;
}

// Enter parent string: Saatvik Madan
// Child received: Saatvik Madan