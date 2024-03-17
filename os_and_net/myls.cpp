#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char **argv)
{
	int f,n;char c;
	f=open(argv[1],O_RDONLY);
	if(f!=0)
	while((n=read(f,&c,1))>0)
		printf("%c",c);
}
