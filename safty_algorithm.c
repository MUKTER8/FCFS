#include <stdio.h>
#define m 10

int main() {
    int p[m], maxneed[m][m], need[m][m], alloc[m][m], avil[m], i, j, n;
    int r, work[m], Finish[m], complete = 0, found, d[m];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("Enter the processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the allocation: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Max Need: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &maxneed[i][j]);
        }
    }

    printf("Enter the available: ");
    for (i = 0; i < r; i++) {
        scanf("%d", &avil[i]);
        work[i] = avil[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = maxneed[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        Finish[i] = 0;
    }

    while (complete < n) {
        found = 0;
        for (i = 0; i < n; i++) {
            if (!Finish[i]) {
                int canalloc = 1;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        canalloc = 0;
                        break;
                    }
                }
                if (canalloc) {
                    for (j = 0; j < r; j++) {
                        work[j] = work[j] + alloc[i][j];
                    }
                    d[complete] = p[i];
                    Finish[i] = 1;
                    found = 1;
                    complete++;
                }
            }
        }
        if (!found) {
            printf("The system is not in a safe state.\n");
            break;
        }
    }

    if (found) {
        printf("The system is in a safe state.\n");
        for (i = 0; i < n; i++) {
            printf("P%d ", d[i]);
        }
        printf("\n");
    }

    return 0;
}
