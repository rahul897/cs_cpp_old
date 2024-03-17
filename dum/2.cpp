#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream fin,fn;
ofstream fout;
int a[100],b[100],c[100],i=0,j=0,k=0;
fin.open("a.txt");fn.open("b.txt");fout.open("c.txt");
while(!fin.eof()||!fn.eof())
{if(!fin.eof()){fin>>a[i];i++;}
if(!fn.eof()){fn>>b[j];j++;}}
for(int x=0;x<i;x++)
for(int y=0;y<j;y++)
if(a[x]==b[y])
{fout<<a[x];}
return 0;}

