#include<iostream>
using namespace std;

void rer(int n)
{
	int k=0;int a[8]={2,2,3,0,4,5,5,8};
			for(int i=0;i<8;i++)
	cout<<a[i]<<" ";cout<<endl;
	for(int i=0;i<n;i++)
	if(a[i]==a[i+1])
	{a[i]*=2;a[i+1]=0;}
	for(int i=0,k=0;i<n;i++)
	if(a[i]!=0)a[k++]=a[i];
	for(;k<n;k++)
	a[k]=0;
		for(int i=0;i<8;i++)
	cout<<a[i]<<" ";cout<<endl;
}
int main()
{
	//int a[]={2,2,3,0,4,5,5,8};
	/*a=new int[8];
	//{2,2,3,0,4,5,5,8};
	for(int i=0;i<8;i++)
	cin>>a[i];*/
	rer(8);
}
