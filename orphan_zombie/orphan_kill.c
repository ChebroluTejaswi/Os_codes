//killing a orphan process
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//orphan : parent exited child is sleeping
int main()
{
	pid_t p;
	p=fork();
	if(p>0)
	{
		exit(0);//parent is exited here
	}
	if(p==0)
	{
		sleep(50);//child sleeping
	}
	return 0;
}