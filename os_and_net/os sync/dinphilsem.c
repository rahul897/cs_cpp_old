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
int spoon[N],room;
void *phil(void *arg)
{
	int i=*(int*)arg;
	while(1)
	{
		printf("philosopher %d is thinking\n",i+1 );
		sleep(rand()%2);
		down(room);
		down(spoon[i]);
		down(spoon[(i+1)%N]);
		printf("%d is eating\n",i+1 );
		sleep(rand()%3);
		up(spoon[i]);
		up(spoon[(i+1)%N]);
		up(room);
	}
}
int main()
{
	int i;
	for(i=0;i<N;i++)
		spoon[i]=sem_init(1);
	room=sem_init(N-1);
	int* g=(int*)malloc(N*sizeof(int));
	pthread_t phi[N];
	for(i=0;i<N;i++)
	{g[i]=i;pthread_create(&phi[i],NULL,phil,(void*)&g[i]);}
	pthread_join(phi[0],NULL);
	return 0;
}