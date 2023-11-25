#include<stdio.h>
#include<string.h>
struct process
{
    char name[20];
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};
int main()
{
    int n;
    int j,i;
    float wtavg,tatavg;
    struct process temp;
    printf("enter the no. of process you want to execute\n");
    scanf("%d",&n);
    struct process p[n];
    printf("enter the details of process\n");
    for(i=0;i<n;i++)
    {
        printf(" name p[%d]:",i);
        scanf("%s",p[i].name);
        printf("\nbursttime:");
        scanf("%d",&p[i].burst_time);
        printf("\narrivaltime:");
        scanf("%d",&p[i].arrival_time);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].arrival_time>p[j+1].arrival_time)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        int wt;
        int tb;
        if(p[i].arrival_time==0)
        {
        p[i].waiting_time=0;
        tb=p[i].burst_time;
        }
        else
        {
        p[i].waiting_time=tb-p[i].arrival_time;
        tb+=p[i].burst_time;
        }
        p[i].turnaround_time=p[i].burst_time+p[i].waiting_time;
    }
    for(i=0;i<n;i++)
    {
        wtavg;
        wtavg+=p[i].waiting_time;
        tatavg;
        tatavg+=p[i].turnaround_time;
    }
    printf("name\tarrival time\tburst time\twaiting time\tturnaround time\n");
    for(i=0;i<n;i++)
    {
        printf("\t%s\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i].name,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    }
    printf("the average waiting time of the process is %f\n",wtavg/n);
    printf("the average turnaround time of the process is %f",tatavg/n);
    return 0;
}
