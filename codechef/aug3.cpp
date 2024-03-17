#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector< vector <int> > v;
vector<int> vis;
int n,m,x,y,mi,k,co=0,flag=0,*path;
void dfs(int i,int k)
{vis[i]=1;
if(i==n-1)
{flag=1;return;}
for(int j=1;j<v[i].size();j++)
if(!vis[v[i][j]%n])
dfs(v[i][j]%n,k+1);
}
int min(int dv[],int vis[])
{int mi=1000,i,min_pos;
    for(i=0;i<n;i++)
	{if(vis[i]==0 && dv[i]<mi)
	   {mi=dv[i];min_pos=i;}
	}
	return min_pos;
}
int fullv(int a[])
{	
	for(int i=0;i<n;i++)
	if(a[i]==0)return 0;
	return 1;
}
void print_path(int pv[],int dv[])
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{if(dv[i]<dv[j])
	{int d=dv[i];dv[i]=dv[j];dv[j]=d;
	int k=pv[i];pv[i]=pv[j];pv[j]=k;}}
	cout<<endl;
	for(int i=0;i<n;i++)
	if(dv[i]>0)
	{cout<<i+1<<"->"<<pv[i]+1<<" "<<dv[i]<<"\n";}
}
void cal()
{
	int i,s,d,cur;
	int vis[n];
	for(i=0;i<n;i++) vis[i]=0;
	int dv[n];
	for(i=0;i<n;i++) dv[i]=10000000;
	int pv[n];
	cur=0;dv[cur]=0;pv[cur]=cur;
	while(!fullv(vis))
	{for(i=1;i<v[cur].size();i++)
	{if(vis[i]!=1)
	if(v[cur][i]%n<dv[i])
	{dv[i]=v[cur][i]%n;pv[i]=cur;if(v[cur][i]>n)co++;}}
	vis[cur]=1;cur=min(dv,vis);}
	print_path(pv,dv);
}
int main()
{cin>>n>>m;
vector<int> vi;mi=n;
path=new int[n];
for(int i=0;i<n;i++)
{vi.push_back(i);v.push_back(vi);vis.push_back(0);vi.clear();}
while(m--)
{cin>>x>>y;
v[x-1].push_back(y-1);
v[y-1].push_back(x-1+n);}
dfs(0,k);for(int i=0;i<n;i++)vis[i]=0;
if(flag){cal();
cout<<co<<"\n";}
else cout<<"-1\n";
}
