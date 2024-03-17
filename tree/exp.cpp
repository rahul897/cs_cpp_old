#include<iostream>
using namespace std;
struct tnode
{tnode *lc;
union orod
{int od;
char ot;
}data;
int tag;
tnode *rc;
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
void stack::push(tnode* x){
	if(isfull())cout<<"stackoverflow\n";
	else e[++top]=x;
}
tnode* stack::pop()
{if(isempty())return 0;
else return e[top--];}

int cal(char op,int a,int b)
{
	if(op=='*')
	return a*b;
	else if(op=='/')
	return a/b;
	else if(op=='-')
	return a-b;
	else
	return a+b;
}

void print(tnode *t)
{if(t!=NULL)
{print (t->lc);
if(t->tag)cout<<t->data.od;
else cout<<t->data.ot;
print(t->rc);}}

int eva(tnode *t)
{if(!t->tag)
return cal(t->data.ot,eva(t->lc),eva(t->rc));
else return t->data.od;}

int main()
{stack s(30);char c[30];int i=0,l;tnode *t;
cout<<"enter postfix exp\n";
cin>>c;
while(c[i]!='\0')
{t=new tnode;
t->lc=NULL;
t->rc=NULL;
if(c[i]!='+'&&c[i]!='/'&&c[i]!='*'&&c[i]!='-')
{
	t->data.od=c[i]-48;t->tag=1;
	s.push(t);
}
else
{
	t->rc=s.pop();
	t->lc=s.pop();
	t->data.ot=c[i];t->tag=0;
	s.push(t);
}
i++;
}
cout<<endl;
print(t);
cout<<"\nresult "<<eva(t);

}
