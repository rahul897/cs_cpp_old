#include<iostream>
using namespace std;
int c=0;

void dfs(int a[10][10],int v,int i,int vis[])
{vis[i]=1;
for(int j=0;j<v;j++)
if(!vis[j]&&a[i][j])
dfs(a,v,j,vis);}

void re(int vis[],int v)
{for(int i=0;i<v;i++)vis[i]=0;}

int emp(int vis[],int v,int k)
{for(int i=0;i<v;i++)if(!vis[i]&&i!=k)return 0;return 1;}

void artpoint(int a[10][10],int v,int vis[])
{int i,j,row[v];
for(i=0;i<v;i++)
{re(vis,v); 
for(j=0;j<v;j++)
{row[j]=a[i][j];a[i][j]=0;}
dfs(a,v,i+1,vis);
if(!emp(vis,v,i+1))cout<<i+1<<" "<<"is artpoint\n";
for(j=0;j<v;j++)
a[i][j]=row[j];}
}

int main()
{
	int a[10][10],b[10][10],i,j,v,w,k;
	cout<<"enter no of vertices\n";cin>>v;
	for(i=0;i<v;i++)
	for(j=0;j<v;j++)
	{a[i][j]=0;b[i][j]=0;}
	for(i=0;i<v;i++)
	{for(j=0;j<v;j++)
		{cout<<"enter weight of edge <"<<i+1<<","<<j+1<<"> ";
		cin>>a[i][j];
		}
	}
	int vis[v];
	artpoint(a,v,vis);	
}
