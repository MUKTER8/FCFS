#include <stdio.h>
int main()
{
//initialization
    int i, j, k = 1, n, temp, p[15], bt[15], at[15], ct[15], tat[15], wt[15];
    float t_tat = 0, t_wt = 0;
    int min, bt_max = 0;

//getting the process number
    printf("Enter the number of process---> ");
    scanf("%d", &n);
    printf("Enter process values of all the process---> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
//getting brust time and arrival time
    printf("Enter brust time of all the process---> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter arrival time of all the process---> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }



//positioning
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

    for (i = 0; i < n; i++)
    {
        bt_max = bt_max + bt[i];
        min = bt[i + 1];
        for (j = i + 1; j < n; j++)
        {
            if (bt_max >= at[j] && bt[j] < min)
            {
                temp = p[i + 1];
                p[i + 1] = p[j];
                p[j] = temp;

                temp = at[i + 1];
                at[i + 1] = at[j];
                at[j] = temp;

                temp = bt[i + 1];
                bt[i + 1] = bt[j];
                bt[j] = temp;
            }
        }
        k++;
    }


//determination of  ct,tat,wt,total_tat,total_wt
    ct[-1] = 0;
    for (i = 0; i < n; i++)
    {
        ct[i] = bt[i] + ct[i - 1];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        t_tat = t_tat + tat[i];
        t_wt = t_wt + wt[i];
    }

    printf("\n-------------|---------------|---------------|---------------|---------------|--------------\n");

    printf("Process\t\tBT\t\tAT\t\tCT\t\tTAT\t\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], ct[i], tat[i], wt[i]);
    }
            printf("-------------|---------------|---------------|---------------|---------------|--------------\n");


    printf("\t\t\t\t    AvgTAT : %f    \n", (t_tat / n));
    printf("\t\t\t\t    AvgWT  : %f    \n", (t_wt / n));
}
