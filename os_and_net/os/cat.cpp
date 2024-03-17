#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc,char **argv)
{char *cd;
cd=getenv("PWD");
DIR *d;struct dirent *sd;
d=opendir(cd);
while((sd=readdir(d))!=NULL)
printf("%s \n",sd->d_name);
closedir(d);
}
