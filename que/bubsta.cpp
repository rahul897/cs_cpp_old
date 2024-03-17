#include<iostream>
using namespace std;
class stack{
	int e[50];
	int top;
	int size;
	public:
	void push(int x);
	int pop();
	int isfull();
	int isempty();
	stack(int s){size=s;top=-1;}
};
int stack::isfull()
{return top==size-1;}
int stack::isempty()
{return top==-1;}
void stack::push(int x){
	if(isfull())cout<<"stackoverflow\n";
	else e[++top]=x;
}
int stack::pop()
{if(isempty())cout<<"stackunderflow\n";
else return e[top--];}

int main()
{
	stack s1(30),s2(30);int x,y,i,n,j;
	cout<<"enter no.of elements\n";cin>>n;
cout<<"enter nmbers\n";
for(i=0;i<n;i++)
{cin>>x;s1.push(x);}

for(j=0;j<n;j++)
{for(i=0;i<n;i++)
{x=s1.pop();s2.push(x);}
x=s2.pop();y=s2.pop();
for(i=0;i<n;i++)
{if(i==n-1)if(x>y)s1.push(x);else s1.push(y);
else if(x>y)
{s1.push(y);if(i!=n-2)y=s2.pop();}
else {s1.push(x);if(i!=n-2)x=s2.pop();}
}
}
for(i=0;i<n;i++)
{x=s1.pop();s2.push(x);}
for(i=0;i<n;i++)
cout<<s2.pop()<<endl;
}
