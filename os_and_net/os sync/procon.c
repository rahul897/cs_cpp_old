#include<stdio.h>
#include<pthread.h>
#define MAX 10
int in=0,count=0,out=0;
int buffer[MAX];
void* producer()
{
	
	while(1)
	{
		//printf("haip\n");
		while(count==MAX);
		buffer[in]=in;
		printf("produced %d\n",in);
		sleep(1);
		in=(in+1)%MAX;
		count++;
	}
}
void* consumer()
{
	while(1)
	{
			//printf("haic\n");
		while(count==0);
		out=buffer[out];
		printf("consumed %d\n",out);
		sleep(1);
		out=(out+1)%MAX;
		count--;
	}
}
int main()
{ 
	pthread_t pro,con;
	printf("hai\n");
	pthread_create(&pro,NULL,producer,NULL);
	pthread_create(&con,NULL,consumer,NULL);
	pthread_join(pro,NULL);
return 0;}