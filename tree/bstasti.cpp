#include<iostream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
tnode(){};
tnode(int x){data=x;lchild=NULL;rchild=NULL;}
};

void create(tnode *&t,int k)
{if(t==NULL)
t=new tnode(k);
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

void print(tnode *&t,int count)
{q a(30);tnode *k=t;int l=0,i,b[30],j=count,h=1;
a.enq(k);tnode *f=new tnode(-1);tnode *e=new tnode(-2);
a.enq(f);
while(j)
{k=a.dq();
b[l++]=k->data;
if(b[l-1]!=-1&&b[l-1]!=-2)
{if(k->lchild)
a.enq(k->lchild);else a.enq(e);
if(k->rchild)
a.enq(k->rchild);else a.enq(e);j--;}
else if(b[l-1]==-1)a.enq(f);
else if(b[l-1]==-2)a.enq(e);}
cout<<endl;
for(j=0;j<20-h/2;j++)cout<<" ";
for(i=0;i<l;i++)
{if(b[i]==-1){cout<<endl;h*=2;for(j=0;j<20-h/2;j++)cout<<" ";}
else
{if(b[i]==-2)cout<<"  ";
else cout<<b[i]<<" ";}}
}


int main()
{tnode *t=NULL;int n=0,s=0,count=0;
cout<<"enter the els\n enter -1 to stop\n";
cin>>n;
while(n!=-1)
{create(t,n);cin>>n;count++;}
cout<<endl;
print(t,count);cout<<endl;

}
