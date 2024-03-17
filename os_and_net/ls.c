#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
int main()
{DIR *d;char cd[1024];
struct dirent *sd;getcwd(cd,sizeof(cd));
d=opendir(cd);
while((sd=readdir(d))!=NULL)
printf("%s \n",sd->d_name);
closedir(d);
}

