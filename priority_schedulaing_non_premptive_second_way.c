#include <stdio.h>

int main() {
    int i, j, n, tmp, p[20], pri[20], bt[20], at[20], wt[20] = {0}, tat[20] = {0}, ct[20] = {0};
    float atat = 0, awt = 0, sum = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("Priority: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pri[i]);
    }

    printf("Enter the burst time: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter the arrival time: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
 
    // Sort the processes based on arrival time in ascending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap the processes
                tmp = at[i];
                at[i] = at[j];
                at[j] = tmp;

                tmp = pri[i];
                pri[i] = pri[j];
                pri[j] = tmp;

                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;

                tmp = bt[i];
                bt[i] = bt[j];
                bt[j] = tmp;
            }
        }
    }

    // Execute processes based on arrival time and priority
    for (i = 0; i < n; i++) {
        int min_priority = 9999;  // Initialize with a large value
        int min_priority_idx = -1;

        for (j = i; j < n; j++) {
            if (at[j] <= sum) {
                if (pri[j] < min_priority) {
                    min_priority = pri[j];
                    min_priority_idx = j;
                }
            }
        }

        if (min_priority_idx != -1) {
            // Execute the process with the highest priority
            tmp = at[i];
            at[i] = at[min_priority_idx];
            at[min_priority_idx] = tmp;

            tmp = pri[i];
            pri[i] = pri[min_priority_idx];
            pri[min_priority_idx] = tmp;

            tmp = p[i];
            p[i] = p[min_priority_idx];
            p[min_priority_idx] = tmp;

            tmp = bt[i];
            bt[i] = bt[min_priority_idx];
            bt[min_priority_idx] = tmp;
        }

        sum += bt[i];
    }

    // Calculate completion time, turnaround time, and waiting time
    for (i = 0; i < n; i++) {
        if (i == 0 || at[i] > ct[i - 1]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("Process\tPriority\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], at[i], wt[i], tat[i]);
    }

    for (i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;
    printf("Average waiting time: %.2f\n", awt);
    printf("Average turnaround time: %.2f", atat);

    return 0;
}
