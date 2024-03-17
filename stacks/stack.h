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
