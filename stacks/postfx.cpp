#include<iostream>
using namespace std;
class stack{
	char e[50];
	int tp;
	int size;
	public:
	void push(char x);
	void pop();
	int isfull();
	int isempty();
	int top();
	stack(int s){size=s;tp=-1;}
};
int stack::isfull()
{return tp==size-1;}
int stack::isempty()
{return tp==-1;}
void stack::push(char x){
	if(isfull())cout<<"stackoverflow\n";
	else e[++tp]=x;}
void stack::pop()
{if(isempty())cout<<"stackunderflow\n";
else tp--;}
int stack::top()
{if(isempty())cout<<"stackunderflow\n";
else return e[tp];}

int main()
{stack s(20);char d[20],c[20],e;
int l,k=0;
cout<<"enter a eqn\n";cin>>c;
for(l=0;c[l]!='\0';l++);
for(int i=0;i<l;i++)
{if((c[i]>47&&c[i]<58)||(c[i]>96&&c[i]<123))
d[k++]=c[i];
else s.push(c[i]);
e=s.top();
if(e=='+')
{s.pop();while(!s.isempty()){d[k++]=e;e=s.top();s.pop();}s.push('+');}
else if(e=='-')
{s.pop();while(!s.isempty()){d[k++]=e;e=s.top();s.pop();}s.push('-');}
else if(e==41)
{s.pop();while(!s.isempty()){d[k++]=e;e=s.top();s.pop();}s.pop();}}
while(!s.isempty()){e=s.top();d[k++]=e;s.pop();}
for (int i=0;i<k;i++)
cout<<d[i];
}

