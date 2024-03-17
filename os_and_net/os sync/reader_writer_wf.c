#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <pthread.h>

int sem_init(int value)
{
	int sem_id=semget(IPC_PRIVATE,1,IPC_CREAT|0666);
	semctl(sem_id,0,SETVAL,value);
	return sem_id;
}

int wait(int sem_id)  //down
{
	struct sembuf temp;
	temp.sem_num=0;
	temp.sem_op=-1;
	temp.sem_flg=0;
	semop(sem_id,&temp,1);
}

int signal(int sem_id) //up
{
	struct sembuf temp;
	temp.sem_num=0;
	temp.sem_op=1;
	temp.sem_flg=0;
	semop(sem_id,&temp,1);
}

int mutex,mutex2,writer,reader;
int no_of_writers=0,no_of_readers=0;

void *fwriter(void *arg)
{
	int id=*((int *)arg);
	printf("Writer %d started\n",id);
	while(1)
	{
		wait(mutex);
			no_of_writers++;
			if(no_of_writers==1)
				wait(reader);
		signal(mutex);
		wait(writer);
			printf("Writer %d is writing\n",id);
			sleep(rand()%3);
			printf("Writer %d finished writing with %d writers remaining\n",id,no_of_writers--);
		signal(writer);
		wait(mutex);
			no_of_writers--;
			if(no_of_writers==0)
				signal(reader);
		signal(mutex);
	}
}

void *freader(void *arg)
{
	int id=*((int *)arg);
	printf("Reader %d started\n",id);
	while(1)
	{
		wait(reader);
			wait(mutex2);
				no_of_readers++;
				if(no_of_readers==1)
					wait(writer);
			signal(mutex2);
		signal(reader);

		printf("Reader %d is reading\n",id);
		sleep(rand()%2);
		printf("Reader %d finished reading with %d readers remaining\n",id,no_of_readers--);

		//wait(reader);
			wait(mutex2);
				no_of_readers--;
				if(no_of_writers>0 || no_of_readers==0)
					signal(writer);
			signal(mutex2);
		//signal(reader);	

	}
}

int main()

{
	int n=3;
	int wri[n],rea[n],i;

	writer=sem_init(1);
	reader=sem_init(1);
	mutex=sem_init(1);
	mutex2=sem_init(1);

	for(i=0;i<n;i++)
	{
		wri[i]=i+1;
		rea[i]=i+1;
	}
	pthread_t w[n],r[n];

	for(i=0;i<n;i++)
	{
		pthread_create(&w[i],NULL,fwriter,(void *)&wri[i]);
		pthread_create(&r[i],NULL,freader,(void *)&rea[i]);
	}

	pthread_join(w[0],NULL);
	pthread_join(r[0],NULL);

	return 0;
}