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
		return 0;
	else
	{char c=e[f];
		if(f==r)
			{f=-1;r=-1;}
		else 
			f=f+1%size;
		return c;
	}
}

void cal(char a,char b,char c,q &k)
{switch(c)
	{
		case '*':c=(a-48)*(b-48);k.enq(c+48);break;
		case '+':c=(a-48)+(b-48);k.enq(c+48);break;
		case '-':c=(a-48)-(b-48);k.enq(c+48);break;
		case '/':c=(a-48)/(b-48);k.enq(c+48);break;
	}
}

int main()
{
	q a(30);int i,l;char c[30],x,y,z;
	cout<<"enter pf exp:\n";
	cin>>c;
	for(l=0;c[l]!='\0';l++);

for(i=0;i<l;i++)
{if(c[i]>47&&c[i]<58)
{a.enq(c[i]);}
else
{x=a.dq();y=a.dq();
if(!a.ise())
{a.enq(x);x=y;y=a.dq();}
cal(x,y,c[i],a);
}}


cout<<a.dq()-48;

}
