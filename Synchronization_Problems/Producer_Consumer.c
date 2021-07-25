#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>
sem_t mutex;
sem_t full;
sem_t empty;
int ind=0;
int index1=0;
char buffer[10];
void *producer(void *arg)
{
int i;
for(i=0;i<10;i++)
{
sem_wait(&empty);
sem_wait(&mutex);
buffer[ind]=i+65;
printf("producer added %c to index %d\t thread id is %ld\n",
buffer[ind],ind,pthread_self());
CHEBROLU TEJASWI
19MID0116
sem_post(&full);
sem_post(&mutex);
ind++;
if(ind==10)
ind=0;
//if(rand()%3==0)
//sleep(3);
}
}
void *consumer()
{
int i;
for(i=0;i<10;i++)
{
sem_wait(&full);
sem_wait(&mutex);
printf("consumer consumed %c from index %d\t thread id is %ld\n" ,
buffer[index1],index1,pthread_self());
sem_post(&empty);
sem_post(&mutex);
index1++;
if(index1==10)
index1=0;
//if(rand()%5==0)
//sleep(3);
}
}
int main()
{
pthread_t tid1[5],tid2[5];
sem_init(&mutex,0,1);
sem_init(&full,0,0);
sem_init(&empty,0,10);
int i;
for(i=0;i<5;i++)
{
pthread_create(&tid1[i],NULL,producer,NULL); //producer()
pthread_create(&tid2[i],NULL,consumer,NULL); //consumer()
}
for(i=0;i<5;i++)
{
pthread_join(tid1[i],NULL);
pthread_join(tid2[i],NULL);
}
sem_destroy(&mutex);
sem_destroy(&full);
sem_destroy(&empty);
return 0;}