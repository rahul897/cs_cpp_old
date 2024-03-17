#include<iostream>
#include<queue>
using namespace std;

void indeg(int a[10][10],int v,int l)
{for(int i=0;i<v;i++)
if(a[l][i]==1)return 0;
return 1;}

void tsort(int a[10][10],int v)
{queue<int> qu(30);int c=0,i,t;
for(i=0;i<v;i++)
if(indeg(a,v,i))qu.enqueue(i);

while(!qu.isEmpty())
{t=qu.dequeue();
cout<<t<<" ";
for(i=0;i<v;i++)
if()
qu.enqueue(i);	
}

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
	tsort(a,v);
}
