#include<iostream>
#include<cmath>
using namespace std;

char a[]={'1','2','3','4','5','6','7','8','9'};
char s[]="    ";

void check(int t)
{
	int c=0;
	for(int i=2;i<t;i++)
	if(t%i==0)c++;
	if(c==0)cout<<t<<endl;
}

void prime()
{
	int t=0;
	for(int d=0;d<4;d++)
	t=t*10+s[d]-'0';
	check(t);
}

void swap(int a,int b)
{int t=a;
a=b;
b=t;}

void sw(int i,int j)
{for(int q=i;q<j;q++)
swap(s[q],s[j]);
}

void ws(int i,int j)
{for(int q=i;q>j;q--)
swap(s[q],s[j]);
}


void per(int i)
{if(i<4){int j;
if(i==3)
prime();
for(j=i;j<4;j++)
{sw(i,j);
per(i+1);
ws(j,i);}
}}



void com(int j,int k)
{
	if(j==4)
	per(0);
	else
		for(;k<9;k++)
		{s[j]=a[k];
		com(j+1,k+1);}
}


int main()
{
com(0,0);
}
