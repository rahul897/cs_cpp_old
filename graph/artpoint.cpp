#include<iostream>
using namespace std;
int c=0,a[10][10],n[10],p[10],l[10],vis[10],ver,k;

void dfs(int i)
{l[i]=n[i]=c++;vis[i]=1;k=0;
for(int j=0;j<ver;j++)
{if(!vis[j]&&a[i][j])
{p[j]=i;
dfs(j);
if(l[j]>=n[i])
{if(i)cout<<i+1<<" is art point\n";
else{for(int b=0;b<ver;b++)if(p[b]==0)k++;if(k>=2)cout<<i+1<<" is art point\n";}}
l[i]=l[i]<l[j]?l[i]:l[j];}
else if(p[i]!=j&&a[i][j])l[i]=l[i]<n[j]?l[i]:n[j];}
}

int main()
{
	int i,j,v,w,k;
	cout<<"enter no of vertices\n";cin>>v;ver=v;
	for(i=0;i<v;i++)
	for(j=0;j<v;j++)
	a[i][j]=0;
	for(i=0;i<v;i++)
	{for(j=0;j<v;j++)
		{ cout<<"enter weight of edge <"<<i+1<<","<<j+1<<"> ";
		cin>>a[i][j];
		}
	}
	cout<<"enter starting point\n";cin>>w;
	for(i=0;i<v;i++){vis[i]=0;l[i]=-1;p[i]=-1;}
	dfs(w-1);
}
