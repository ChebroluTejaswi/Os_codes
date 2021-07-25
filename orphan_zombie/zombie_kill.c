//killing zombie process
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//zombie : parent sleeping child is exited
//need to type kill (..) process ID of corresponding ./a.out command
int main()
{
	pid_t p;
	p=fork();
	if(p>0)
	{
		sleep(50);//parent is sleeping
	}
	if(p==0)
	{
		exit(0);//child is exited here
	}
	return 0;
}