#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10], at[10], ct[10];
    float avgWT = 0, avgTAT = 0;
    int i, j;

    printf("Enter total number of processes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter Process %d Arrival Time :\n", i+1 );
        scanf("%d", &at[i]);
        printf("Enter Process %d Burst Time   :\n", i+1 );
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    ct[0] = bt[0] + at[0];
    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i];
            wt[i] = 0;
            tat[i] = bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
        }
    }

    printf("\nProcess\tBT\tWT\tTAT");

    for (i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
        printf("\nP[%d]\t%d\t%d\t%d", i + 1, bt[i], wt[i], tat[i]);
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\n\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f", avgTAT);

    return 0;
}

/*
Enter total number of processes : 4

Enter Process 1 Arrival Time : 2
Enter Process 1 Burst Time   : 4
Enter Process 2 Arrival Time : 3
Enter Process 2 Burst Time   : 5
Enter Process 3 Arrival Time : 3
Enter Process 3 Burst Time   : 2
Enter Process 4 Arrival Time : 3
Enter Process 4 Burst Time   : 5
Process BT      WT      TAT
P[1]    4       0       4
P[2]    5       3       8
P[3]    2       8       10
P[4]    5       10      15
Average Waiting Time: 5.25
Average Turnaround Time: 9.25
*/