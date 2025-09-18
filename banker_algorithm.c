#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m];
    int max[n][m];
    int need[n][m];
    int avail[m];
    int finished[n];
    int safeSeq[n]; 

    printf("\nEnter Allocation matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Max matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available resources (%d values):\n", m);
    for (j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        finished[i] = 0;
    }

    int count = 0;
    int madeProgress;
    while (madeProgress == 1 && count < n) {
        madeProgress = 0;
        for (i = 0; i < n; i++) {
            if (finished[i] == 0) {
                int canRun = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }
                if (canRun == 1) {
                    for (j = 0; j < m; j++) {
                        avail[j] = avail[j] + alloc[i][j];
                    }
                    finished[i] = 1;
                    safeSeq[count] = i;
                    count = count + 1;
                    madeProgress = 1;
                }
            }
        }
    } 

    if (count == n) {
        int k;
        printf("\nSystem is in a SAFE state.\nSafe sequence: ");
        for (k = 0; k < n; k++) {
            printf("P%d", safeSeq[k]);
            if (k != n - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nSystem is in an UNSAFE state (no safe sequence).\n");
    }

    return 0;
}

/*
Enter number of processes: 5
Enter number of resource types: 3 

Enter Allocation matrix (5 x 3):
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Enter Max matrix (5 x 3):
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Enter Available resources (3 values):
3 3 2

System is in a SAFE state.
Safe sequence: P1 -> P3 -> P4 -> P0 -> P2
*/