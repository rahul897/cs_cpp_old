#include<iostream>
using namespace std;
int *b,*c,n,m,x,y,k=0,co=0,sto=0,flag=0;
int **a;

void dfs(int j)
{b[j]=1;if(j==n-1)flag=1;
for(int i=0;i<n;i++)
if(a[j][i]!=0&&!b[i])dfs(i);
}

int min(int dv[],int vis[],int v)
{int i,mp;int mi=1000;
    for(i=0;i<v;i++)
	{if(vis[i]==0 && dv[i]<mi)
	   {mi=dv[i];mp=i;}
	}
	return mp;
}
void print_path(int pv[],int d,int s)
{
    if(d!=s)
	{print_path(pv,pv[d],s);}
	c[sto++]=d;
}
void cal()
{
	int i,s,d,cur;
	int vis[n];
	for(i=0;i<n;i++) vis[i]=0;
	int dv[n];
	for(i=0;i<n;i++) dv[i]=1000;
	int pv[n];
	cur=0;dv[cur]=0;pv[cur]=cur;
	while(cur!=n-1)
	{for(i=0;i<n;i++)
	{if(a[cur][i]!=0 && vis[i]!=1)
	if(dv[cur]+a[cur][i]>dv[i])
	{dv[i]=dv[cur]+a[cur][i];pv[i]=cur;}}
	vis[cur]=1;cur=min(dv,vis,n);}
	print_path(pv,n-1,0);
}
int main()
{cin>>n>>m;int t1,t2;
a=new int*[n];
c=new int[n];
b=new int[n];
for(int i=0;i<n;i++)
{a[i]=new int[n];b[i]=0;
for(int j=0;j<n;j++)
a[i][j]=0;}
while(m--)
{cin>>x>>y;if(x!=y){a[y-1][x-1]=-1;
a[x-1][y-1]=1;}}
dfs(0);
if(flag)
{cal();
for(int i=0;i<sto-1;i++)
{x=c[i];y=c[i+1];
if(a[x][y]<0)co++;
}
cout<<co<<"\n";}
else cout<<"-1\n";
}
