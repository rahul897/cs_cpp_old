#include<iostream>
using namespace std;
void rev(int **a,int v)
{int** b=new int*[v];
for(int i=0;i<v;i++)
b[i]=new int[v];
for(int i=0;i<v;i++)
for(int j=0;j<v;j++)
b[i][j]=a[j][i];
for(int i=0;i<v;i++)
for(int j=0;j<v;j++)
a[i][j]=b[i][j];
}

void post(int **a,int v,int *tg,int s,int **m,int &k,int &j)
{tg[s]=1;
for(int i=0;i<v;i++)
if(!tg[i]&&a[s][i]>0)post(a,v,tg,i,m,k,j);
m[0][k]=s;
m[1][k++]=j++;}

void dfs(int **a,int v,int *tg,int s,int &j)
{tg[s]=1;cout<<s+1<<" ";j++;
for(int i=0;i<v;i++)
if(!tg[i]&&a[s][i]>0)dfs(a,v,tg,i,j);}

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
	int **m,*tg;k=0,j=0,w=0;
	m=new int*[2];tg=new int[v];for(i=0;i<v;i++)tg[i]=0;
	for(i=0;i<2;i++)
	m[i]=new int[v];
	post(a,v,tg,w,m,k,j);
	while(j!=v)
	{for(i=0;i<v;i++)
	if(!tg[i])w=i;
	post(a,v,tg,w,m,k,j);}

	for(i=0;i<2;i++)
	{for(w=0;w<v;w++)
	cout<<m[i][w]<<" ";
	cout<<endl;
	}
	cout<<endl;
	for(i=0;i<v;i++)tg[i]=0;w=0;j=0;
	rev(a,v);
	dfs(a,v,tg,0,j);cout<<endl;
	while(j!=v)
	{for(i=0;i<v;i++)
	if(!tg[i])w=i;
	dfs(a,v,tg,w,j);cout<<endl;}
}
