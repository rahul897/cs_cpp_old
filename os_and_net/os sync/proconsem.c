#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define N 10
int sem_init(int val)
{
	int sem_id=semget(IPC_PRIVATE,1,IPC_CREAT|0666);
	semctl(sem_id,0,SETVAL,val);
	return sem_id;
}
void down(int sem_id)
{	
	struct sembuf tmp;
	tmp.sem_num=0;
 	tmp.sem_op=-1;
 	tmp.sem_flg=0;
	semop(sem_id,&tmp,1);
}
void up(int sem_id)
{
	struct sembuf tmp;
	tmp.sem_num=0;
 	tmp.sem_op=1;
 	tmp.sem_flg=0;
	semop(sem_id,&tmp,1);
}
int full,empty,mutex,buffer[N],in=0,out=0;
void *producer()
{
	while(1)
	{
		down(empty);
		down(mutex);
		buffer[in]=in;
		sleep(rand()%2);
		printf("produced %d <----\n",in );
		in=(in+1)%N;
		up(mutex);
		up(full);
	}
}
void *consumer()
{
	while(1)
	{
		down(full);
		down(mutex);
		out=buffer[out];
		sleep(rand()%3);
		printf("-----> consumed %d\n",out );
		out=(out+1)%N;
		up(mutex);
		up(empty);
	}
}
int main()
{
	full=sem_init(0);
	empty=sem_init(N);
	mutex=sem_init(1);
	pthread_t pro,con;
	pthread_create(&pro,NULL,producer,NULL);
	pthread_create(&con,NULL,consumer,NULL);
	pthread_join(pro,NULL);
}