#include <stdio.h>
//initialization varriable
    int i, j, k = 1, n, tmp, p[15], bt[15], at[15], ct[15], tat[15], wt[15];
    float atat = 0, awt = 0;
    int min, bt_max = 0;

void getinput(){
    
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter process : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter brust time : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter arrival time : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

}

void Different_Arrival_time(){

      for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                tmp = at[i];
                at[i] = at[j];
                at[j] = tmp;

                tmp = bt[i];
                bt[i] = bt[j];
                bt[j] = tmp;

                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
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
                tmp = p[i + 1];
                p[i + 1] = p[j];
                p[j] = tmp;

                tmp = at[i + 1];
                at[i + 1] = at[j];
                at[j] = tmp;

                tmp = bt[i + 1];
                bt[i + 1] = bt[j];
                bt[j] = tmp;
            }
        }
        k++;
    }


    ct[-1] = 0;
    for (i = 0; i < n; i++)
    {
        ct[i] = bt[i] + ct[i - 1];
        tat[i] = ct[i] - at[i];
        atat = atat + tat[i];
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
    }

}

void Same_arrival_time(){
     
     for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                
                tmp=bt[i];
                bt[i]=bt[j];
                bt[j]=tmp;

                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;

            }
        }
    }
    int sum=0;
    for(i=0;i<n;i++){
        sum+=bt[i];
        ct[i]+=sum;
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        atat=atat+tat[i];
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
    }
}
void printfunction(){
     printf("Process\t\tBT\t\tAT\t\tTAT\t\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], tat[i], wt[i]);
    }


    printf("Average turnaround time : %.2f \n", (atat / n));
    printf("Average waiting time    : %.2f \n", (awt / n));
}

int main()
{
int ch;
    printf("Press 1:SAME ARRIVAL TIME\n");
    printf("Press 2 :Different Arrival time\n");
    printf("Press any key :Exit the program\n");
do{
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
    getinput();
    Same_arrival_time();
    printfunction();
        break;
    case 2:
    getinput();
    Different_Arrival_time();
    printfunction();
    
    default:
    printf("\nExit the program.");
        break;
    }
}while (ch==1);

return 0;
}