#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define n 5
#define thinking 0
#define hungry 1
#define eating 2
#define left (pno+4)%n
#define right (pno+1)%n
sem_t mutex;
sem_t s[n];
int * philosopher(void *num);
int take_fork(int);
int put_fork(int);
int test(int);
int state[n];
int phil_num[n]={0,1,2,3,4};
int main()
{
 int i;
 pthread_t thread_id[n];
 sem_init(&mutex,0,1);
 for(i=0;i<n;i++)
 sem_init(&s[i],0,0);
 for(i=0;i<n;i++)
 {
 pthread_create(&thread_id[i],NULL,philosopher,&phil_num[i]);
 printf(" Philospher%d:thinking\n",i+1);
 }
 for(i=0;i<n;i++)
 pthread_join(thread_id[i],NULL);
}
int *philosopher(void *num)
{
int j;
 for(j=0;j<2;j++)
 {
 int *i = num;
 sleep(1);
 take_fork(*i);
 sleep(0);
 put_fork(*i);
 }
}
int take_fork(int pno)
{
 sem_wait(&mutex);
 state[pno] = hungry;
 printf(" Philospher%d: Hungry\n",pno+1);
 test(pno);
 sem_post(&mutex);
 sem_wait(&s[pno]);
 sleep(1);
}
int test(int pno)
{
 if (state[pno] == hungry && state[left] != eating && state[right] != eating)
 {
 state[pno] = eating;
 sleep(2);
 printf(" P%d takes fork %d and %d\n",pno+1,left+1,pno+1);
 printf(" P%d:Eating\n",pno+1);
 sem_post(&s[pno]);
 }
}
int put_fork(int pno)
{
 sem_wait(&mutex);
 state[pno] = thinking;
 printf(" Philospher%d puts fork %d and %d down\n",pno+1,left+1,pno+1);
 printf(" Philospher%d:thinking\n",pno+1);
 test(left);
 test(right
 );
 sem_post(&mutex);
}