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
	void senq()
	{int x;
	cout<<"enter a set and -1 to stop entering\n";
	cin>>x;
	while(x!=-1)
	{enq(x);
	cin>>x;}
	enq(-1);}
	
	void sdq()
	{int t=dq();
	while(t!=-1)
	{cout<<t;t=dq();}}
	
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

