#include<iostream>
using namespace std;

struct tnode
{int data;
tnode* l;
tnode* r;
};

class stack{
	tnode* e[50];
	int top;
	int size;
	public:
	void push(tnode* x);
	tnode* pop();
	int isfull();
	int isempty();
	stack(int s){size=s;top=-1;}
};
int stack::isfull()
{return top==size-1;}

int stack::isempty()
{return top==-1;}
void stack::push(tnode *x){
	if(isfull())cout<<"stackoverflow\n";
	else e[++top]=x;
}

tnode* stack::pop()
{if(isempty())return NULL;
else return e[top--];}


void insert(tnode *&t,int k)
{if(t==NULL)
{t=new tnode;t->data=k;t->l=NULL;t->r=NULL;}
else if(t->data>k)
insert(t->l,k);
else if(t->data<k)
insert(t->r,k);}

void print(tnode *t)
{if(t!=NULL)
{print(t->l);
cout<<t->data;
print(t->r);
}
}

void ino(tnode *t,stack &s)
{while(1)
{if(t!=NULL)
{s.push(t);t=t->l;}
else
{if(!s.isempty())
{t=s.pop();
cout<<t->data<<" ";
t=t->r;}
else break;}}}

void preo(tnode *t,stack &s)
{s.push(t);
while(!s.isempty())
{t=s.pop();
cout<<t->data<<" ";
if(t->r!=NULL)s.push(t->r);
if(t->l!=NULL)s.push(t->l);}
}

void poso(tnode *t)
{if(t==NULL)return;
stack s1(30),s(30);
s.push(t);
l1:
{t=s.pop();
s1.push(t);
if(t->l!=NULL)s.push(t->l);
if(t->r!=NULL)s.push(t->r);}if(!s.isempty())goto l1;
l:
{cout<<s1.pop()->data<<" ";}if(!s1.isempty())goto l;
}

int main()
{tnode *t=NULL;int x;stack s(30);
cout<<"enter els\n enter -1 to stop\n";
cin>>x;
while(x!=-1)
{insert(t,x);cin>>x;}
cout<<endl;
ino(t,s);
cout<<endl;
preo(t,s);
cout<<endl;
poso(t);
}

