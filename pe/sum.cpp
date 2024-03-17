#include<iostream>
using namespace std;

int *p,x;

void em()
{for(int i=0;i<x;i++)
	p[i]=0;
}

int check()
{int s=0;
for(int i=0;i<x;i++)
s=s+p[i];
return s==x;
}

void print()
{for(int i=0;i<x;i++)
if(p[i]!=0)cout<<p[i]<<" ";
cout<<endl;
}

void show(int i,int k)
{if(i>=1)
{int j;
if(check())
print();
else
for(j=i-1;j>0;j--)
{p[k]=j;
show(i-1,k+1);
}}
}



int main()
{
	cout<<"enter no.\n";
	cin>>x;
	p=new int[x];
	em();
	show(x,0);
}
