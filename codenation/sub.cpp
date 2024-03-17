#include<iostream>
using namespace std;
int n,*a;
int fun()
{int s=0;for(int i=0;i<n;i++)
s=s+a[i];return s==n?1:0;}

void pri(int r,int k)
{if(fun())
{for(int i=0;i<n;i++)
if(a[i]>0)cout<<a[i]<<" ";cout<<endl;}
else
for(int i=r;i>0;i--)
{if(a[k-1]>=i){a[k]=i;pri(r-1,k+1);a[k]=0;}
}
}


int main()
{cin>>n;
a=new int[n];
for(int i=0;i<n;i++)
a[i]=0;
pri(n,0);
}
