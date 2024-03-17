#include<iostream>
using namespace std;

class q
{
	int size;
	int e[50];
	int f;
	int r;
	public:
	q();
	q(int);
	void enq(int);
	int dq();
	int isf();
	int ise();
};
q::q()
{
	size=50;
	f=-1;r=-1;
}
q::q(int s)
{
	size=s;
	f=-1;r=-1;
}
void q::enq(int i)
{
	if(r+1%size==f)
		cout<<"queue is full\n";
	else
	{
		r=r+1%size;
		e[r]=i;
		if(f==-1)
			f++;
	}
}
int q::ise()
{
	return f==-1;
}
int q::dq()
{
	if(f==-1)
		{cout<<"q is empty";
		return 0;}
	else
	{char c=e[f];
		if(f==r)
			{f=-1;r=-1;}
		else 
			f=f+1%size;
		return c;
	}
}

int indeg(int a[10][10],int v,int l)
{for(int i=0;i<v;i++)
if(a[l][i]==1)return 0;
return 1;}

void tsort(int a[10][10],int v)
{q qu(30);int c=0,i,t;
for(i=0;i<v;i++)
if(indeg(a,v,i))qu.enq(i);

while(!qu.ise())
{t=qu.dq();
cout<<t<<" ";
for(i=0;i<v;i++)
if()
qu.enq(i);	
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
