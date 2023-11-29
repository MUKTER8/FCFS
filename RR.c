#include <stdio.h>
int main()
{
    int i, j, n, temp, tq, p[15], bt[15], at[15], ct[15], tat[15], wt[15], rt[15], ready_q[50];
    int time = 0, done = 0;
    float t_tat = 0, t_wt = 0;

    printf("Enter the number of process:");
    scanf("%d", &n);

    printf("Enter process values:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter brust time:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter arrival time: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter time quantam : ");
    {
        scanf("%d", &tq);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    while (1)
    {
        if (n == done)
        {
            break;
        }

        for (i = 0; i < n; i++)
        {
            if (n == done)
            {
                break;
            }

            if (rt[i] == 0)
            {
                continue;
            }
            
            temp = tq;
            if (rt[i] >= tq)
            {
                rt[i] = rt[i] - tq;
                time += tq;
            }

            else
            {
                temp = rt[i];
                time += temp;
                rt[i] = 0;
            }

            if (rt[i] == 0)
            {
                done++;
                ct[i] = time;
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];
                t_tat = t_tat + tat[i];
                t_wt = t_wt + wt[i];
            }
        }
    }

    printf("Process\t\tBT\t\tAT\t\tCT\t\tTAT\t\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], ct[i], tat[i], wt[i]);
    }

    printf("Average TAT : %.2f \n", (t_tat / n));
    printf("Average WT  : %.2f \n", (t_wt / n));
}
