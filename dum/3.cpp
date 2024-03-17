#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream fin;
char c[100],d[10][10],e[100];int l=0,i,j,k=0,x=0,y,t=0,a[10];
fin.open("c.txt");
for(i=0;i<10;i++)
{a[i]=0;
for(j=0;j<10;j++)
d[i][j]=' ';}
while(!fin.eof())
{fin>>c[l];l++;}


for(i=0;i<l;i++)
{for(j=0;j<l;j++)
if(c[i]==c[j])
{e[x]=c[j];
x++;
for(int k=0;k<x;k++)
{for(int y=0;y<x;y++)
if(k!=y&&e[k]==e[y])x--;}
}}

k=0;
for(i=0;i<x;i++)
{for(j=0;j<l;j++)
if(c[j]==e[i])
{a[k]++;if(t<a[k])t=a[k];}k++;}
while(t)
{for(i=0;i<x-1;i++)
if(a[i]>=t)cout<<"*";
else cout<<" ";t--;cout<<endl;
}
for(i=0;i<x-1;i++)
cout<<e[i];
}

