#include <stdio.h>

int main() {
    int i, j, n, p[20], bt[20], at[20], wt[20] = {0}, tat[20] = {0}, ct[20] = {0}, remaining[20] = {0}, time = 0, completed = 0;

    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Processes:");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the burst time:");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];
    }

    printf("Enter the arrival time:");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    while (completed < n) {
        int smallest = -1;
        int minRemainingTime = 9999; // A high initial value.

        for (i = 0; i < n; i++) {
            if (at[i] <= time && remaining[i] < minRemainingTime && remaining[i] > 0) {
                smallest = i;
                minRemainingTime = remaining[i];
            }
        }

        if (smallest == -1) {
            time++;
        } else {
            remaining[smallest]--;
            if (remaining[smallest] == 0) {
                completed++;
                ct[smallest] = time + 1;
                tat[smallest] = ct[smallest] - at[smallest];
                wt[smallest] = tat[smallest] -  bt[smallest];
                
                awt += wt[smallest];
                atat += tat[smallest];
            }
            time++;
        }
    }

    awt = awt / n;
    atat = atat / n;

    printf("Process\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], wt[i], tat[i]);
    }
    printf("Average waiting time : %.2f\n", awt);
    printf("Average turnaround time : %.2f", atat);
    return 0;
}
