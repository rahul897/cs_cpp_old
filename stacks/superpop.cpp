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
	if(isfull()) cout<<"stackoverflow\n";
	else e[++top]=x;
}
int stack::pop()
{if(isempty())cout<<"stackunderflow\n";
else return e[top--];}

int main()
{stack s(30);int i,n,k,l=1,set=0;
do{
	cout<<"enter the no.of elements in the set\n";cin>>n;
	for(i=0;i<n;i++)
	{cin>>k;s.push(k);}
	s.push(n);
	cout<<"want enter an other set:press 1 else 0\n";cin>>l;
	set++;
}while(l==1);l=1;
while(!s.isempty()&&l!=0)
{cout<<"press 1 to pop 0 to close\n";cin>>l;if(l==1){n=s.pop();
for(i=0;i<n;i++)
cout<<s.pop();}
}


}

