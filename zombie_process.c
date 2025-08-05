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

/*
Hello World from child process with id 40377
Hello World from parent process with id 40376
sdc-user          2000  1894  2000      0    0 Ss+  s003    0:00.14 /bin/zsh -il
root             32304 32303 32304      0    0 Ss   s005    0:00.01 login -pf sdc-user
sdc-user         32305 32304 32305      0    1 S+   s005    0:00.07 -zsh
sdc-user         32739  1894 32739      0    0 Ss+  s007    0:00.10 /bin/zsh -il
sdc-user         35655  1894 35655      0    0 Ss   s009    0:00.22 /bin/zsh -il
sdc-user         40376 35655 40376      0    1 S+   s009    0:00.01 ./a.out
sdc-user         40377 40376 40376      0    1 Z+   s009    0:00.00 <defunct>
sdc-user         40392 40376 40376      0    1 S+   s009    0:00.01 sh -c ps -axj | tail
root             40393 40392 40376      0    1 R+   s009    0:00.00 ps -axj
sdc-user         40394 40392 40376      0    1 R+   s009    0:00.00 tail
*/