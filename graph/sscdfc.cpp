#include<iostream>
using namespace std;

int zoud(int **a,int v,int s)
{for(int i=0;i<v;i++)
if(a[s][i])return 0;
return 1;}

int zind(int **a,int v,int s)
{for(int i=0;i<v;i++)
if(a[i][s])return 0;
return 1;}

void dfs(int **a,int v,int *tg,int s,int &j)
{tg[s]=1;cout<<s+1<<" ";j++;
for(int i=0;i<v;i++)
if(!tg[i]&&a[s][i]>0)dfs(a,v,tg,i,j);}

void scc(int **a,int v)
{int *tg=new int[v],i,j,k=0,c=0;
for(i=0;i<v;i++)
{tg[i]=0;
if(zind(a,v,i)){cout<<i+1<<endl;for(j=0;j<v;j++)a[i][j]=0;c++;tg[i]=1;}
if(zoud(a,v,i)){cout<<i+1<<endl;for(j=0;j<v;j++)a[j][i]=0;c++;tg[i]=1;}}
for(i=0;i<v;i++)
if(!tg[i])break;cout<<endl;
dfs(a,v,tg,i,k);cout<<endl;
while(k<v-c)
{for(i=0;i<v;i++)
if(!tg[i])break;
dfs(a,v,tg,i,k);cout<<endl;}
}

int main()
{
	int **a,i,j,v,n,w,k;
	cout<<"enter no of vertices\n";cin>>v;
	a=new int*[v];
	for(i=0;i<v;i++)
	a[i]=new int[v];
	for(i=0;i<v;i++)
	for(j=0;j<v;j++)
	a[i][j]=0;
	for(i=0;i<v;i++)
	{for(j=0;j<v;j++)
		{cout<<"enter weight of edge <"<<i+1<<","<<j+1<<"> ";
		cin>>a[i][j];
		}
	}
	/*a[0][2]=1;a[1][0]=1;
	a[2][1]=1;a[2][5]=1;
	a[3][0]=1;a[3][2]=1;
	a[4][2]=1;a[4][3]=1;
	a[5][1]=1;a[5][6]=1;
	a[7][8]=1;a[8][9]=1;a[9][7]=1;*/
	scc(a,v);
}
