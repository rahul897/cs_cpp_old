#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define N 5
int sem_init(int val)
{
	int sem_id=semget(IPC_PRIVATE,1,IPC_CREAT|0666);
	semctl(sem_id,0,SETVAL,val);
	return sem_id;
}
void wait(int sem_id)
{	
	struct sembuf tmp;
	tmp.sem_num=0;
 	tmp.sem_op=-1;
 	tmp.sem_flg=0;
	semop(sem_id,&tmp,1);
}
void signal(int sem_id)
{
	struct sembuf tmp;
	tmp.sem_num=0;
 	tmp.sem_op=1;
 	tmp.sem_flg=0;
	semop(sem_id,&tmp,1);
}
int wcmutex,rcmutex,rre,wr,re,now=0,nor=0;

void *writer(void* i)
{
	int id=*(int*)i;
	while(1)
	{
		wait(wcmutex);
		now++;
		if(now==1)
			wait(re);
		signal(wcmutex);
		wait(wr);
		sleep(rand()%3);
		printf("____->writer %d finished writing %d %d\n",id,now-1,nor );
		signal(wr);
		wait(wcmutex);
		now--;
		if(now==0)
			signal(re);
		signal(wcmutex);
	}

}

void *reader(void* i)
{
	int id=*(int*)i;
	while(1)
	{
		wait(rre);
		wait(re);
		wait(rcmutex);
		nor++;
		if(nor==1)
			wait(wr);
		signal(rcmutex);
		signal(re);
		wait(rre);
		sleep(rand()%2);
		printf("reader %d finished reading %d %d\n",id,now,nor-1 );

		wait(rcmutex);
		nor--;
		if(nor==0)
			signal(wr);
		signal(rcmutex);
	}
}

int main()
{
	wcmutex=sem_init(1);
	rcmutex=sem_init(1);
	rre=sem_init(1);
	re=sem_init(1);
	wr=sem_init(1);
	int i,w[N],r[N];
	pthread_t readr[N],writr[N];
	for(i=0;i<N;i++)
	{
		r[i]=i+1;w[i]=i+1;
	}
	for(i=0;i<N;i++)	
		{
			pthread_create(&writr[i],NULL,writer,&w[i]);
			pthread_create(&readr[i],NULL,reader,&r[i]);
		}
	pthread_join(writr[0],NULL);
	pthread_join(readr[0],NULL);
	return 0;
}
