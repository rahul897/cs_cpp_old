#include<iostream>
using namespace std;
int **a,*tg,*p,v,i,j,n=0;

int dfs(int s,int e)
{if(n==14&&a[s][e])
return 1;
for(i=1;i<=v;i++)
if(!tg[i]&&a[s][i])
{p[s]=n++;
if(dfs(i,e))return 1;
else tg[i]=0;}
return 0;}

int main()
{
	v=14;
	a=new int*[15];tg=new int[15];p=new int[15];
	for(i=0;i<=v;i++)
	{a[i]=new int[15];tg[i]=0;p[i]=-1;
	for(j=0;j<=15;j++)
	a[i][j]=0;}
	a[1][7]=1;a[1][10]=1;
	a[2][9]=1;a[2][11]=1;a[2][8]=1;
	a[3][10]=1;a[3][12]=1;a[3][5]=1;
	a[4][6]=1;a[4][11]=1;
	a[5][3]=1;a[5][11]=1;a[5][13]=1;
	a[6][14]=1;a[6][4]=1;a[6][12]=1;
	a[7][1]=1;a[7][9]=1;a[7][13]=1;
	a[8][14]=1;a[8][10]=1;a[8][2]=1;
	a[9][2]=1;a[9][7]=1;a[9][14]=1;
	a[10][1]=1;a[10][3]=1;a[10][8]=1;
	a[11][2]=1;a[11][4]=1;a[11][5]=1;
	a[12][13]=1;a[12][6]=1;a[12][3]=1;
	a[13][5]=1;a[13][7]=1;a[13][12]=1;
	a[14][9]=1;a[14][9]=1;a[14][8]=1;	
	
	cout<<"enter start\n";
	cin>>i;
	dfs(i,i);
	for(i=0;i<14;i++)
	cout<<i<<" ";cout<<endl;
	for(i=0;i<15;i++)
	if(p[i]!=-1)cout<<p[i]<<" ";cout<<endl;
	
}
