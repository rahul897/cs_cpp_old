#include<iostream>
using namespace std;

int find(int a[],int k)
{for(int i=0;i<14;i++)
if(a[i]==k)return i;}

int main()
{
	int sol1[]={1,10,8,2,9,14,6,4,11,5,3,12,13,7};
	int sol2[]={1,7,13,5,3,12,6,4,11,2,9,14,8,10},index,i;
	cout<<"enter the starting vertex\n";
	cin>>index;
	cout<<"solution :\n";
	index=find(sol1,index);cout<<sol1[index]<<" ";
	for(i=index+1;i!=index;i=(i+1)%14)
	cout<<sol1[i]<<" ";cout<<sol1[index]<<endl;	
	
	cout<<sol1[index]<<" ";
	for(i=index-1;;i=i-1)
	{if(i==index)break;
	cout<<sol1[i]<<" ";if(i==0)i=14;}
	cout<<sol1[index]<<endl;
	
	index=find(sol2,sol1[index]);cout<<sol2[index]<<" ";
	for(i=index+1;i!=index;i=(i+1)%14)
	cout<<sol2[i]<<" ";cout<<sol2[index]<<endl;	
	
	cout<<sol2[index]<<" ";
	for(i=index-1;;i=i=i-1)
	{if(i==index)break;
	cout<<sol2[i]<<" ";if(i==0)i=14;}
	cout<<sol2[index]<<endl;	
	
}
