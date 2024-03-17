#include<iostream>
#include<cmath>
using namespace std;

char a[]={'1','2','3','4','5','6','7'};//,'8','9'};

void swap(int a,int b)
{int t=a;
a=b;
b=t;}

void sw(int i,int j)
{for(int q=i;q<j;q++)
swap(a[q],a[j]);
}

void ws(int i,int j)
{for(int q=i;q>j;q--)
swap(a[q],a[j]);
}

void prime()
{
	long long t=0ll,x,y;
	for(int d=0;d<7;d++)
	t=t*10+a[d]-'0';
	y=sqrt(t);
	for(x=3;x<y;x+=2)
	if(t%x==0)return;
	cout<<t<<endl;
}

void per(int i,int &k)
{if(i<7){int j;
if(i==6)
prime();
for(j=i;j<7;j++)
{sw(i,j);
per(i+1,k);
ws(j,i);
}
}}

int main()
{int k=0;
per(0,k);
}
