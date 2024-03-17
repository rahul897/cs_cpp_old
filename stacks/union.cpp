#include<iostream>
using namespace std;
union u
{int i;
float f;
char c[20];
double d;}u1;
class stack{
	u e[50];
	int top;
	int size;
	public:
	int tag[50];
	void push(u x,int y);
	u pop();
	int tagpop();
	int isempty();
	stack(int s){size=s;top=-1;}
};
void stack::push(u x,int y)
{if(top==size-1)cout<<"overflow\n";
else {tag[top]=y;e[++top]=x;}}
u stack::pop()
{if(top==-1)cout<<"underflow\n";
else return e[top--];}
int stack::isempty()
{return top==-1;}
int stack::tagpop()
{return tag[top];}

int main()
{stack s(30);u u1;int i,n,k,t,l=1;float f;double d;char c[20];
do{
	cout<<"enter \n0 for int\n1 for float\n2 for string\n3 for double\n";cin>>t;
	cout<<"enter the element\n";switch(t){
		case 0:cin>>u1.i;break;
		case 1:cin>>u1.f;break;
		case 2:cin>>u1.c;break;
		case 3:cin>>u1.d;break;	}
	s.push(u1,t);
	cout<<"want to enter another element press 1 else 0\n";cin>>l;
}while(l==1);l=1;
while(!s.isempty()&&l!=0)
{cout<<"press 1 to pop 0 to close\n";cin>>l;if(l==1)
{u1=s.pop();
switch(s.tagpop())
{case 0:i=u1.i;cout<<i<<endl;break;
case 1:f=u1.f;cout<<f<<endl;break;
case 2:for(i=0;u1.c[i]!='\0';i++)c[i]=u1.c[i];cout<<c;break;
case 3:d=u1.d;cout<<d<<endl;break;
}
}}

}


