#include<iostream>
using namespace std;
int min(int dv[],int vis[],int v)
{int min=1000,i,mp;
    for(i=0;i<v;i++)
	{if(vis[i]==0 && dv[i]<min)
	   {min=dv[i];mp=i;}
	}
	return mp;
}
void print_path(int pv[],int d,int s)
{
    if(d!=s)
	{print_path(pv,pv[d],s);
	cout<<"->";}
	cout<<d+1;
}
void cal(int a[10][10],int v)
{
	int i,s,d,cur;
	int vis[v];
	for(i=0;i<v;i++) vis[i]=0;
	int dv[v];
	for(i=0;i<v;i++) dv[i]=1000;
	int pv[v];
	cout<<"enter source and destination vertex\n";
	cin>>s>>d;
	cur=s-1;dv[cur]=0;pv[cur]=cur;
	while(cur!=d-1)
	{for(i=0;i<v;i++)
	{if(a[cur][i]>0 && vis[i]!=1)
	if(dv[cur]+a[cur][i]<dv[i])
	{dv[i]=dv[cur]+a[cur][i];pv[i]=cur;}}
	vis[cur]=1;cur=min(dv,vis,v);}
	cout<<"min distance: "<<dv[d-1];
	cout<<"\npath: ";
	print_path(pv,d-1,s-1);
}
int main()
{
	int a[10][10],i,j,v,n,w,k;
	cout<<"enter no of vertices\n";cin>>v;
	for(i=0;i<v;i++)
	for(j=0;j<v;j++)
	a[i][j]=0;
	for(i=0;i<v;i++)
	{for(j=0;j<v;j++)
		{cout<<"enter weight of edge <"<<i+1<<","<<j+1<<"> ";
		cin>>a[i][j];
		}
	}
	cal(a,v);
}
