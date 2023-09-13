#include<stdio.h>
#include<conio.h>


int main()
{   
    int i,j,n,p[20]={0},bt[20]={0},at[20]={0},wt[20]={0},tat[20]={0},ct[20]={0},tmp;
    float awt=0,atat=0;
    printf("Enter the number of process :");
    scanf("%d",&n);
    printf("Process:");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the burst time :");
    for(i=0;i<n;i++){
      scanf("%d",&bt[i]);  
    }
    printf("Enter the arrival time :");
    for(i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    //sorting
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                tmp=at[i];
                at[i]=at[j];
                at[j]=tmp;

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
    printf("Process\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for(i=0;i<n;i++){
     
       printf("P%d\t %d \t\t%d\t\t%d\t\t%d\n",p[i],bt[i],at[i],wt[i],tat[i]);
    }
    awt=awt/(float)n;
    atat=atat/(float)n;
    printf("Average waiting time : %.2f\n",awt);
    printf("Average turnaround time : %.2f",atat);
    return 0;
}