#include<iostream>
using namespace std;
class stack{
	char e[50];
	int top;
	int size;
	public:
	void push(char x);
	int pop();
	int isfull();
	int isempty();
	stack(int s){size=s;top=-1;}
};
int stack::isfull()
{return top==size-1;}
int stack::isempty()
{return top==-1;}
void stack::push(char x){
	if(isfull())cout<<"stackoverflow\n";
	else e[++top]=x;
}
int stack::pop()
{if(isempty())cout<<"stackunderflow\n";
else return e[top--];}


int main()
{stack s(20);char d[20],c[20],e;
int l,k=0,m=0;
cout<<"enter a eqn\n";cin>>c;
for(l=0;c[l]!='\0';l++);
for(int i=0;i<l;i++)
{if((c[i]>47&&c[i]<58)||(c[i]>96&&c[i]<123))
{d[k]=c[i];k++;}
else if(c[i]=='*'||c[i]=='/'||c[i]==40)s.push(c[i]);
else if(c[i]=='+'||c[i]=='-')
{if(!s.isempty())e=s.pop();else e=40;
while(!s.isempty())
{if(e!=40)
d[k++]=e;
else break;
if(!s.isempty())e=s.pop();else break;}
if(e!=40)d[k++]=e;s.push(c[i]);}
else if(c[i]==41)
{if(!s.isempty())e=s.pop();else e=40;
while(e!=40)
{d[k++]=e;
if(!s.isempty())e=s.pop();else break;}}
}
while(!s.isempty()){e=s.pop();d[k++]=e;}
for (int i=0;i<k;i++)
cout<<d[i];
}



