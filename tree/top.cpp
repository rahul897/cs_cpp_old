#include<iostream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
tnode(){};
tnode(int x,tnode *a,tnode *b){data=x;lchild=a;rchild=b;}
};
struct node
{int in;
int data;
node *next;
node(int d,int i){in=i;data=d;next=NULL;}
};
void create(tnode *&t,int k)
{if(t==NULL)
t=new tnode(k,NULL,NULL);
else if(k<t->data)
create(t->lchild,k);
else if(k>t->data)
create(t->rchild,k);
}
class q
{
	int size;
	tnode* e[50];
	int f;
	int r;
	public:
	q();
	q(int);
	void enq(tnode*);
	tnode* dq();
	int isf();
	int ise();
};
q::q()
{
	size=50;
	f=-1;r=-1;
}
q::q(int s)
{
	size=s;
	f=-1;r=-1;
}
void q::enq(tnode* i)
{
	if(r+1%size==f)
		cout<<"queue is full\n";
	else
	{
		r=r+1%size;
		e[r]=i;
		if(f==-1)
			f++;
	}
}
int q::ise()
{
	return f==-1;
}
tnode* q::dq()
{
	if(f==-1)
		{cout<<"q is empty";
		return 0;}
	else
	{tnode* c=e[f];
		if(f==r)
			{f=-1;r=-1;}
		else 
			f=f+1%size;
		return c;
	}
}

class q1
{
	int size;
	node* e[50];
	int f;
	int r;
	public:
	q1();
	q1(int);
	void enq(node*);
	node* dq();
	int isf();
	int ise();
};
q1::q1()
{
	size=50;
	f=-1;r=-1;
}
q1::q1(int s)
{
	size=s;
	f=-1;r=-1;
}
void q1::enq(node* i)
{
	if(r+1%size==f)
		cout<<"queue is full\n";
	else
	{
		r=r+1%size;
		e[r]=i;
		if(f==-1)
			f++;
	}
}
int q1::ise()
{
	return f==-1;
}
node* q1::dq()
{
	if(f==-1)
		{cout<<"q is empty";
		return 0;}
	else
	{node* c=e[f];
		if(f==r)
			{f=-1;r=-1;}
		else 
			f=f+1%size;
		return c;
	}
}

void adnode(node*&t,node *k)
{if(t==NULL)
t=k;
else adnode(t->next,k);
}

int search(node* &t,int i)
{if(t==NULL)return 0;
else if(t->in==i)return 1;
else search(t->next,i);
}

void printl(node *&t)
{
	while(t!=NULL)
	{cout<<t->data;t=t->next;}
	
}


void print(tnode *&t)
{q a(30);tnode *k=t;
a.enq(k);
node *j=NULL,*s=new node(k->data,0),*f;
q1 a1(30);a1.enq(s);
while(!a.ise())
{k=a.dq();
s=a1.dq();
if(!search(j,s->in))
adnode(j,s);
if(k->lchild)
{a.enq(k->lchild);f=new node(k->lchild->data,s->in-1);a1.enq(f);}
if(k->rchild)
{a.enq(k->rchild);f=new node(k->rchild->data,s->in+1);a1.enq(f);}}

printl(j);

}


int main()
{tnode *t=NULL;int n=0,s=0;
cout<<"enter the els\n enter -1 to stop\n";
cin>>n;
while(n!=-1)
{create(t,n);cin>>n;}
cout<<endl;
print(t);cout<<endl;

}
