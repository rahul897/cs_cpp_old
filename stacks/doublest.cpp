#include<iostream>
using namespace std;
class stack{
	int e[50];
	int top1,top2;
	int size;
	public:
	void push1(int x);
	void push2(int x);
	int pop1();
	int pop2();
	void top();
	int isfull();
	int isempty();
	stack(int s){size=s;top1=-1;top2=50;}
};
int stack::pop1()
{if(top1==-1)cout<<"underflow\n";
else return e[top1--];}
int stack::pop2()
{if(top2==50)cout<<"underflow\n";
else return e[top2++];}
void stack::push1(int x)
{if(top1-top2==1||top1-top2==-1)cout<<"overflow\n";
else e[++top1]=x;}
void stack::push2(int x)
{if(top1-top2==1||top1-top2==-1)cout<<"overflow\n";
else e[--top2]=x;}
int stack::isempty()
{return top1==-1&&top2==50;}
int stack::isfull()
{return top1-top2==1||top1-top2==-1;}
int main()
{stack s(30);int i,n,l=1;
do{
	cout<<"press \n0 for pushing from left\n1 for pushing from right\n";cin>>i;
	cout<<"enter element\n";cin>>n;
	if(i==0)s.push1(n);else s.push2(n);
	cout<<"want to enter another element\npress 1\nelse 0\n";cin>>l;
}while(l==1);l=1;
while(!s.isempty()&&l!=0)
{cout<<"press 0 to popleft\n1 to popright\n";cin>>i;
if(i==1)cout<<s.pop1()<<endl;else cout<<s.pop2()<<endl;
cout<<"press 1 to pop again\n0 to close\n";cin>>l;
}
}
