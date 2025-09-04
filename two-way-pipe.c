//  WAP TO IMPLEMENT PIPE FOR TWO WAY COMMUNICATION

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 100

int main() {
    int fd1[2], fd2[2], n;
    char parent_msg[MAX];
    char child_msg[MAX];
    char received_msg[MAX];
    pid_t pid;

    // Create two pipes
    if(pipe(fd1) < 0) {
        printf("Error in pipe1");
        exit(0);
    }
    
    if(pipe(fd2) < 0) {
        printf("Error in pipe2");
        exit(0);
    }

    printf("Enter parent message: ");
    fgets(parent_msg, sizeof(parent_msg), stdin);

    if((pid = fork()) < 0) {
        printf("Error in fork");
        exit(0);
    }

    if(pid > 0) {
        close(fd1[0]);
        close(fd2[1]);
        
        write(fd1[1], parent_msg, strlen(parent_msg));
        close(fd1[1]);
        
        n = read(fd2[0], received_msg, MAX-1);
        received_msg[n] = '\0';
        printf("Parent received from child: %s", received_msg);
        close(fd2[0]);
        
        wait(NULL);
    } else {
        close(fd1[1]);
        close(fd2[0]);
        
        n = read(fd1[0], received_msg, MAX-1);
        received_msg[n] = '\0';
        printf("Child received from parent: %s", received_msg);
        close(fd1[0]);
        
        printf("Child, enter response: ");
        fgets(child_msg, sizeof(child_msg), stdin);
        write(fd2[1], child_msg, strlen(child_msg));
        close(fd2[1]);
    }
    return 0;
}

/*
Enter parent message: saatvik madan
Child received from parent: saatvik madan
Child, enter response: syed farjad
Parent received from child: syed farjad
*/