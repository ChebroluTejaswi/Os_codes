//orphan process
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//type ps -aux in new window to observe the status of process
//orphan : parent exits while child is sleeping
int main()
{
	pid_t p;
	p=fork();//p is zero for child
	if(p>0)
	{
		printf("%d\n",getpid());
		exit(0);//parent exits here
	}
	if(p==0)
	{
		printf("%d\n",getppid());
		sleep(80);//child sleeping
	}
	return 0;
}