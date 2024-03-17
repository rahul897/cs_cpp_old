#include<iostream>
using namespace std;
int get(char c[6][10],int t)
{int z[6],l,m=0,r[10]={0,0,0,0,0,0,0,0,0,0};;
for(l=0;c[l][t]!='\0';l++);
for (int i=0;i<l;i++)
z[i]=c[i][t]-48;
for (int i=0;i<=9;i++)
for (int j=0;j<l;j++)
if(i==z[j])
r[i]++;
for (int i=0;i<=9;i++)
m=m+i*r[i];
return m;
}
int main()
{int t;char c[6][10];
cin>>t;
for (int i=0;i<t;i++)
cin>>c[6][i];
for (int i=0;i<t;i++)
cout<<get(c[6][10],i);
}
