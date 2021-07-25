#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>
sem_t wrt;
pthread_mutex_t mutex;
int cnt=1;
int num_reader=0;
void *writer(void *wno)//wno refers to write number
{
sem_wait(&wrt);
cnt=cnt*2;
printf("Writer %d modified cnt to %d\t thread id is %ld\n", (*((int
*)wno)),cnt,pthread_self());
sem_post(&wrt);
}
void *reader(void *rno)//rno refers to reader number
{
pthread_mutex_lock(&mutex);
num_reader++;
if(num_reader ==1){
sem_wait(&wrt);
}
pthread_mutex_unlock(&mutex);
printf("Reader %d read cnt as %d\t\t thread id is %ld\n", (*((int
*)rno)),cnt,pthread_self());
pthread_mutex_lock(&mutex);
num_reader--;
if(num_reader ==0){
sem_post(&wrt);
}
pthread_mutex_unlock(&mutex);
}
int main()
{
pthread_t read[5],write[5];
pthread_mutex_init(&mutex,NULL);
sem_init(&wrt,0,1);
int a[10]={1,2,3,4,5,6,7,8,9,10};
for(int i=0;i<5;i++)
{
pthread_create(&read[i],NULL,(void*)reader,(void*)&a[i]);
//producer()
pthread_create(&write[i],NULL,(void*)writer,(void*)&a[i]);
//consumer()
}
for(int i=0;i<5;i++)
{
pthread_join(read[i],NULL);
pthread_join(write[i],NULL);
}
pthread_mutex_destroy(&mutex);
sem_destroy(&wrt);
return 0;
}