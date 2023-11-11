#include <stdio.h>
int main()
{
    int i, j, n, p[15], bt[15], at[15], ct[15], tat[15], wt[15], rt[15], pr[15];
    float t_tat = 0, t_wt = 0;
    int priority, time, done = 0;
    // FOR GANNT CHART (LINE -> 8-10)
    int k = 0, m = 0, count = 0, gannt_time = 0, gantt[200], temp[15];

    printf("Enter the number of process---> ");
    scanf("%d", &n);

    printf("Enter process values of all the process---> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter brust time of all the process---> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter arrival time of all the process---> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter priority of all the process---> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }

    int choice;
    printf("ENTER 0 --- IF LOWEST VALUE HAS HIGHER PRIORITY---> ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        pr[14] = 9999;
    }
    else
    {
        pr[14] = -9999;
    }

    printf("\n-------------|---------------|---------------|---------------|---------------|--------------|--------------\n");
    printf("Process\t\tPR\t\tBT\t\tAT\t\tCT\t\tTAT\t\tWT\n");
    for (time = 0; done != n; time++)
    {
        priority = 14;
        for (i = 0; i < n; i++)
        {
            if (choice == 0)
            {
                if (at[i] <= time && pr[i] < pr[priority] && rt[i] != 0)
                {
                    priority = i;
                }
            }

            else
            {
                if (at[i] <= time && pr[i] > pr[priority] && rt[i] != 0)
                {
                    priority = i;
                }
            }
        }

        // FOR GANNT CHART (LINE -> 78)
        gantt[k++] = p[priority];

        rt[priority]--;
        if (rt[priority] == 0)
        {
            done++;
            ct[priority] = time + 1;
            tat[priority] = ct[priority] - at[priority];
            wt[priority] = tat[priority] - bt[priority];
            t_tat = t_tat + tat[priority];
            t_wt = t_wt + wt[priority];
            printf("-------------|---------------|---------------|---------------|---------------|--------------|--------------\n");
            printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[priority], pr[priority], bt[priority], at[priority], ct[priority], tat[priority], wt[priority]);
        }
    }

    printf("-------------|---------------|---------------|---------------|---------------|--------------|--------------\n");
    printf("\n\t\t\t\t\t||----------------------||\n");
    printf("\t\t\t\t\t    AvgTAT : %f    \n", (t_tat / n));
    printf("\t\t\t\t\t||----------------------||\n");
    printf("\t\t\t\t\t    AvgWT  : %f    \n", (t_wt / n));
    printf("\t\t\t\t\t||----------------------||\n");

    printf("\t\t\t\t\t\t\t\n|| GANTT CHART ||\n");
    printf("-----------------\n");

    for (i = 0; i < k; i++)
    {
        if (gantt[i] == gantt[i + 1])
        {
            gannt_time++;
            continue;
        }
        temp[m++] = gannt_time;
        printf("--|p[%d]|", gantt[i]);
        gannt_time++;
    }
    printf("\n");
    for (i = 0; i < m; i++)
    {
        printf("\t%d", temp[i] + 1);
    }
}