#include<iostream>
#include<vector>
using namespace std;
vector< vector <int> > v;
vector<int> vis;
int n,m,x,y,mi,k,co=0,flag=0,*path;
void dfs(int i,int k)
{vis[i]=1;
if(mi==0)return;
if(i==n-1)
{co=0;flag=1;
for(int q=0;q<k-1;q++)
{x=path[q];y=path[q+1];
for(int p=1;p<v[x].size();p++)
if(v[x][p]%n==y&&v[x][p]>n){co++;break;}}
if(mi>co)mi=co;return;
}
for(int j=1;j<v[i].size();j++)
if(!vis[v[i][j]%n])
{path[k]=v[i][j]%n;
dfs(v[i][j]%n,k+1);
vis[v[i][j]%n]=0;}
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
path[k++]=0;
dfs(0,k);
if(flag)cout<<mi<<endl;
else cout<<-1<<endl;
}
