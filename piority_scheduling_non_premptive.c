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
 

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (pri[i] > pri[j]) {
                tmp = pri[i];
                pri[i] = pri[j];
                pri[j] = tmp;

                tmp = at[i];
                at[i] = at[j];
                at[j] = tmp;

                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;

                tmp = bt[i];
                bt[i] = bt[j];
                bt[j] = tmp;
            }
        }
         sum += bt[i];
        ct[i] = sum;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("Process\tPriority\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], at[i], wt[i], tat[i]);
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
