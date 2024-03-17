#include<iostream>
using namespace std;
int min(int dv[],int vis[],int v)
{int min=1000,i,min_pos;
    for(i=0;i<v;i++)
	{if(vis[i]==0 && dv[i]<min)
	   {min=dv[i];min_pos=i;}
	}
	return min_pos;
}
void print_path(int pv[],int dv[],int s,int v)
{
	for(int i=0;i<v;i++)
	for(int j=0;j<v;j++)
	{if(dv[i]<dv[j])
	{int d=dv[i];dv[i]=dv[j];dv[j]=d;
	int k=pv[i];pv[i]=pv[j];pv[j]=k;}}
	cout<<endl;
	for(int i=0;i<v;i++)
	if(dv[i]>0)
	{cout<<i+1<<"->"<<pv[i]+1<<" "<<dv[i]<<"\n";}
}
int fullv(int a[],int v)
{	
	for(int i=0;i<v;i++)
	if(a[i]==0)return 0;
	return 1;
}
void cal(int a[10][10],int v)
{
	int i,s,d,cur;
	int vis[v];
	for(i=0;i<v;i++) vis[i]=0;
	int dv[v];
	for(i=0;i<v;i++) dv[i]=1000;
	int pv[v];
	cout<<"enter source vertex\n";
	cin>>s;
	cur=s-1;dv[cur]=0;pv[cur]=cur;
	while(!fullv(vis,v))
	{for(i=0;i<v;i++)
	{if(a[cur][i]>0 && vis[i]!=1)
	if(a[cur][i]<dv[i])
	{dv[i]=a[cur][i];pv[i]=cur;}}
	vis[cur]=1;cur=min(dv,vis,v);}
	
	cout<<"\npath: ";
	print_path(pv,dv,s-1,v);
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
