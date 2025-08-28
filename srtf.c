#include <stdio.h>
#define MAX_PROCESSES 10

int main() {
    int n, time = 0, completed = 0, min_rem, shortest, finish_time;
    float total_wait = 0, total_turnaround = 0;
    int pid[MAX_PROCESSES];
    int burst[MAX_PROCESSES];
    int arrival[MAX_PROCESSES];
    int remaining[MAX_PROCESSES];
    int is_completed[MAX_PROCESSES];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &arrival[i], &burst[i]);
        pid[i] = i + 1;
        remaining[i] = burst[i];
        is_completed[i] = 0;
    }

    while (completed != n) {
        min_rem = 100000;
        shortest = -1;

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && is_completed[i] == 0 && remaining[i] < min_rem && remaining[i] > 0) {
                min_rem = remaining[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        remaining[shortest]--;
        time++;

        if (remaining[shortest] == 0) {
            is_completed[shortest] = 1;
            completed++;
            finish_time = time;
            int wait = finish_time - arrival[shortest] - burst[shortest];
            int turnaround = finish_time - arrival[shortest];
            total_wait += wait;
            total_turnaround += turnaround;
            printf("Process %d finished at time %d, Waiting time: %d, Turnaround time: %d\n",
                   pid[shortest], finish_time, wait, turnaround);
        }
    }

    printf("Average waiting time: %.2f\n", total_wait / n);
    printf("Average turnaround time: %.2f\n", total_turnaround / n);

    return 0;
}

/*
Enter number of processes: 4
Enter arrival time and burst time for process 1: 3
5
Enter arrival time and burst time for process 2: 3
7
Enter arrival time and burst time for process 3: 5
7
Enter arrival time and burst time for process 4: 2
3
Process 4 finished at time 5, Waiting time: 0, Turnaround time: 3
Process 1 finished at time 10, Waiting time: 2, Turnaround time: 7
Process 2 finished at time 17, Waiting time: 7, Turnaround time: 14
Process 3 finished at time 24, Waiting time: 12, Turnaround time: 19
Average waiting time: 5.25
Average turnaround time: 10.75
*/