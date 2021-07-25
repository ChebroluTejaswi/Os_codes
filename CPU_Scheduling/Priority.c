#include<stdio.h>
#include<stdlib.h>
struct Process{
	int pid,at,bt,ct,wt,tat,priority;
};
struct Process pr[20];
int compare(const void *a, const void *b);
void comparePr(struct Process pr[], int start, int end);
void completionTime(struct Process pr[], int n);
int main()
{
#include<stdio.h>
#include<stdlib.h>
struct Process{
    int pid,at,bt,ct,wt,tat,priority;
};
struct Process pr[20];
int compare(const void *a, const void *b);
void comparePr(struct Process pr[], int start, int end);
void completionTime(struct Process pr[], int n);
int main()
{
    int n;
    printf("Total number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        printf("\nPID: ");
        scanf("%d", &pr[i].pid);
        printf("\nArrival time: ");
        scanf("%d", &pr[i].at);
        printf("\nBurst time: ");
        scanf("%d", &pr[i].bt);
        printf("\nPriority: ");scanf("%d", &pr[i].priority);
    }
    printf("\nbefore sort\n ");
    printf("\nPID\tAT\tBT\tPriority\n");
    for(int i = 0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", pr[i].pid, pr[i].at, pr[i].bt, pr[i].priority);
    }
    qsort(pr, n, sizeof(pr[0]), compare);
    completionTime(pr,n);
    return 0;
}
    //compare
int compare(const void *a, const void *b){
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    if(p1->at == p2->at)
        return p1->priority -p2->priority;
    else
        return p1->at -p2->at;
}
    //compare priority
void comparePr(struct Process pr[], int start, int end)
{
    struct Process temp;for(int i = start; i<end; i++)
    {
        for(int j = start; j<end-1; j++)
        {
            if(pr[j].priority > pr[j+1].priority)
            temp = pr[j];pr[j] = pr[j+1];pr[j+1]= temp;
        }
    }
}
    //completion time
void completionTime(struct Process pr[], int n){
    int count = 0,i = 0;
    int last_ct = pr[0].at;
    int f=0;
    while(count!=n){
        pr[i].ct = pr[i].bt + last_ct;
        pr[i].tat =pr[i].ct -pr[i].at;
        pr[i].wt = pr[i].tat -pr[i].bt;
        last_ct = pr[i].ct;
        int end;
        int start = i+1;
        if(pr[n-1].at > last_ct){
            for(int j = i+1; j<n; j++)
            {
                if(pr[j].at>last_ct)
                    end = j;break;
            }
            comparePr(pr, start, end);
        }
        else
        {
            if(f!=1)
            {
                comparePr(pr, start, n);f=1;
            }
        }
        i++;
        count++;
    }
    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    float tat_avg=0;
    float wt_avg=0;
    for(int i = 0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", pr[i].pid, pr[i].at, pr[i].bt,pr[i].priority, pr[i].ct,pr[i].tat, pr[i].wt);
        tat_avg += pr[i].tat;
        wt_avg += pr[i].wt;
    }
    printf("Average waiting time of %d processes: %.2f\n",n, wt_avg/(float)n);
    printf("Average turnaround time of %d processes: %.2f\n",n,
    tat_avg/(float)n);
}
}