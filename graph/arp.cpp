#include<iostream>
using namespace std;
int c=0;
void dfs(int a[10][10],int b[10][10],int v,int i,int p[],int vis[])
{vis[i]=1;
for(int j=0;j<v;j++)
if(!vis[j]&&a[i][j])
{p[j]=i;b[i][j]=1;
dfs(a,b,v,j,p,vis);}
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
	for(i=0;i<v;i++)
	{for(j=0;j<v;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	int n[v],vis[v],via[v],low[v];
	cout<<"enter starting point\n";cin>>w;
	for(i=0;i<v;i++){via[i]=-1;vis[i]=0;low[i]=-1;}
	dfs(a,b,v,w-1,via,vis);
	for(i=0;i<v;i++)
	{for(j=0;j<v;j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}cout<<endl;
	for(i=0;i<v;i++)
	cout<<i<<" "<<via[i];
}
