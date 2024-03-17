#include<iostream>
using namespace std;
struct node
{int data;
node *next;};

class stack
{node *top;
public:
	node *s;
	stack()
	{top=NULL;s=NULL;}
void push(int x)
{if(top==NULL)
{top =new node;s=top;
top->data=x;top->next=NULL;}
else
{node *t=new node;
t->data=x;
t->next=NULL;
top->next=t;
top=t;}
}

int pop()
{if(s==NULL){cout<<"stack is enpty";return 0;}
else 
{node *t,*u;t=s;int x;
if(t->next==NULL)
{x=t->data;s=NULL;}
else
{while(t->next!=NULL)
{u=t;t=t->next;}
x=top->data;
top=u;
u->next=NULL;}
return x;}}

void display()
{node *t;t=s;
if(t->next==NULL&&s!=NULL)
cout<<t->data<<" ";
else
while(t->next!=NULL)
{cout<<t->data<<" ";
t=t->next;}
}

};

int main()
{stack s;int l=1,t,g;
while(l)
{cout<<"1.push\n2.pop\n3.display\n4.exit  :";cin>>t;
switch(t)
{case 1:cout<<"enter el to push\n";cin>>g;s.push(g);break;
case 2:cout<<"poped el is  :"<<s.pop()<<endl;break;
case 3:s.display();
case 4:l=0;break;
}
}
}
