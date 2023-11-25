#include <stdio.h>
#include <stdbool.h>
#define m 10

int main() {
    int n1, n2, p[m], i, j, memory[m], psize[m], wastage[m], totalWastage = 0;
    bool partitionUsed[m] = {false}; 
    printf("Enter number of partitioning memory:");
    scanf("%d", &n1);
    printf("Enter the size of the memory %d partition:",n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &memory[i]);
    }

    printf("Enter number of processes:");
    scanf("%d", &n2);
    printf("Enter the process numbers:");
    for (i = 0; i < n2; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter the process size:");
    for (i = 0; i < n2; i++) {
        scanf("%d", &psize[i]);
    }
    printf("Process  Allocate memory   Wastage  Waiting process\n");
    for (i = 0; i < n2; i++) {
        for (j = 0; j < n1; j++) {
            if (!partitionUsed[j] && memory[j] >= psize[i]) {
                wastage[i] = memory[j] - psize[i];
                totalWastage += wastage[i];
                printf("P%d\t\t%d\t    %d\n", p[i], j,wastage[i]);
                memory[j] -= psize[i];
                partitionUsed[j] = true; 
                break;
            }
        }

        if (j == n1) {
            printf("P%d \t\t..\t    ..\t\tWait\n",p[i]);
        }
    }

    printf("\nTotal Wastage: %d\n", totalWastage);

    return 0;
}
