//zombie process
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//zombie : parent sleeping child is exits
//should type ps-aux in new window

int main()
{
	pid_t p;
	p=fork();// creates new process
	if(p>0)
	{
		printf("%d\n",getpid());//to print PID
		sleep(70);//parent is sleeping for 70 sec
	}
	if(p==0)
	{
		printf("%d\n",getppid());// to print PID of parent
		exit(0);//child exits here
	}
	return 0;
}