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

int main()
{q a(50);int x,y,n,i,j;
cout<<"enter no.of elements\n";cin>>n;
cout<<"enter nmbers\n";
for(i=0;i<n;i++)
{cin>>x;a.enq(x);}
for(j=0;j<n;j++)
{x=a.dq();y=a.dq();
for(i=0;i<n;i++)
{if(i==n-1)if(x>y)a.enq(x);else a.enq(y);
else if(x>y)
{a.enq(y);if(i!=n-2)y=a.dq();}
else {a.enq(x);if(i!=n-2)x=a.dq();}
}

}
for(i=0;i<n;i++)
cout<<a.dq()<<endl;

}
