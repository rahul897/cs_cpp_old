#include<iostream>
using namespace std;

int mul(int a[])
{
	for(int i=16;i>=0;i--)
	{a[i]=a[i]*2;
	if(a[i]>9)
	{if(i)a[i-1]=a[i]/10;a[i]=a[i]%10;}
	}
}

int main()
{
	int a[]={1,1,2,5,8,9,9,9,0,6,8,4,2,6,2,4},t,i;
	for(i=51;i<=1001;i++)
	{mul(a);}
	
	for(i=0;i<16;i++)
	cout<<a[i];
	
}
