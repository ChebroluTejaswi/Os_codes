//FCFS 
#include<stdio.h>
int main()
{
	int n;
	printf("Total number of processes- ");
	scanf("%d",&n);
	int p[n],a[n],b[n],w[n],t[n]; 
	// p: process  a:arrival_time  b:brust _time  
	//w:waiting_time  t:turnaround_time
	int i=0;
	float avg_waiting=0,avg_turnaround=0;
	for(i=0;i<n;i++) // to take inputs of arrival time and burst time
	{
		p[i]=i+1;
		printf("Arrival time of process %d: ", i+1);
		scanf("%d",&a[i]);
		printf("Brust time of process %d : ", i+1);
		scanf("%d",&b[i]);
	}
	
	for(i=0;i<n;i++)//arranging all processes based on arrival times in increasing order
	{
		int j;
		for(j=i;j<n;j++)
		{
			if(a[j]<a[i])//process with less arrival time has to be processed first
			{
				int t=0;
				t=a[i];
				a[i]=a[j];  //swaping arrival times
				a[j]=t;
				
				t=b[i];
				b[i]=b[j];	//swaping brust times
				b[j]=t;
				
				t=p[i];
				p[i]=p[j];	//swaping process_numbers
				p[j]=t;
			}
		}
	}
	w[0]=0;
	t[0]=b[0];
	avg_waiting=avg_waiting+w[0];
	avg_turnaround=avg_turnaround+b[0];
	for(i=1;i<n;i++)// calculating average waiting time and average turnaround time
	{
		w[i]=t[i-1]-a[i]; 
		t[i]=w[i]+b[i];
		avg_waiting=avg_waiting+w[i];
		avg_turnaround=avg_turnaround+t[i];
	}
	printf("Processing......\n");
	printf("process\t arrival time\t burst time\t waiting time\t  turn around time\t\n");
	for(i=0;i<n;i++) // for printing output
	printf("%d\t %d\t\t %d\t\t %d\t\t %d\t\n",p[i],a[i],b[i],w[i],t[i]);
	
	avg_waiting=avg_waiting/n;
	avg_turnaround=avg_turnaround/n;
	printf("Average waiting time of %d processes: %f \n",n,avg_waiting);
	printf("Average turnaround time of %d processes %f \n  ",n,avg_turnaround);
	return 0;
}