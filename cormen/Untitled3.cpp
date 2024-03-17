#include<iostream>
using namespace std;
int main()
{int *a=new int[8];
for(int i=0;i<8;i++)
cin>>a[i];
int k;
for(int i=0;i<8;i++)
if(a[i]==a[i+1])
{a[i]*=2;a[i+1]=0;}
for(int i=0,k=0;i<8;i++)
if(a[i]!=0)a[k++]=a[i];
cout<<k;
for(k;k<8;k++)
a[k]=0;
for(int i=0;i<8;i++)
cout<<a[i]<<" ";
}
