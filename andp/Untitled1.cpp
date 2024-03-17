#include<iostream>
using namespace std;

int mod(int val,int m)
{if(val>=0)return val%m;
return val+m;
}

int main()
{
	int a[9][9],b[9],c[9],d[9];
	int i,j,k,t;
	for(i=0;i<3;i++)
	{for(j=0;j<3;j++)
	{
	for(k=0;k<9;k++)b[k]=0;
	t=i*3+j;
	b[t]=1;
	if(t+1<9&&(t-j)/3==(t+1-mod(j+1,3))/3)b[t+1]=1;
	if(t-1>=0&&(t-j)/3==(t-1-mod(j-1,3))/3)b[t-1]=1;
	if(t+3<9)b[t+3]=1;
	if(t-3>=0)b[t-3]=1;
	for(k=0;k<9;k++)if(i!=-1)a[t][k]=b[k];
	}}
	
	for(i=0;i<9;i++)
	{for(j=0;j<9;j++)
	cout<<a[i][j]<<" ";
	cout<<endl;}
	
	cout<<"enter mat\n";
	for(i=0;i<9;i++)
	{cin>>b[i];
	d[i]=b[i];}
	
	
	for(k=0;k<9;k++)
	{c[k]=0;
	for(j=0;j<9;j++)
	c[k]=c[k]+a[k][j]*d[j];}
	cout<<endl;
	for(k=0;k<9;k++)
	cout<<mod(c[k],2)<<" ";
	cout<<endl;

}
