#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, time = 0, completed = 0;
  
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int process[n];
    int arrival_time[n];
    int burst_time[n];
    int remaining_time[n];
    int completion_time[n];
    int waiting_time[n];
    int turnaround_time[n];
    int is_completed[n];
    
    for(i = 0; i < n; i++) {
        process[i] = i + 1;
        is_completed[i] = 0;
    }
    
    // Input process details
    printf("\nEnter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }
    
    printf("\n--- Preemptive SJF (SRTF) Execution ---\n");
    printf("Time\tProcess\tRemaining Time\n");
    printf("----\t-------\t--------------\n");
    
    while(completed < n) {
        int shortest_job = -1;
        int min_remaining = 999999;
        
        for(i = 0; i < n; i++) {
            if(arrival_time[i] <= time && is_completed[i] == 0) {
                if(remaining_time[i] < min_remaining) {
                    min_remaining = remaining_time[i];
                    shortest_job = i;
                }
            }
        }
        
        if(shortest_job == -1) {
            time++;
        } else {
            printf("%d\tP%d\t%d\n", time, process[shortest_job], remaining_time[shortest_job]);
            remaining_time[shortest_job]--;
            time++;
            
            if(remaining_time[shortest_job] == 0) {
                completion_time[shortest_job] = time;
                is_completed[shortest_job] = 1;
                completed++;
            }
        }
    }
    
    for(i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }
    
    printf("\n--- Final Results ---\n");
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    printf("-------\t-------\t-----\t----------\t----------\t-------\n");
    
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", 
               process[i], arrival_time[i], burst_time[i], 
               completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    
    float total_waiting = 0, total_turnaround = 0;
    for(i = 0; i < n; i++) {
        total_waiting = total_waiting + waiting_time[i];
        total_turnaround = total_turnaround + turnaround_time[i];
    }
    
    float avg_waiting = total_waiting / n;
    float avg_turnaround = total_turnaround / n;
    
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
    
    return 0;
}