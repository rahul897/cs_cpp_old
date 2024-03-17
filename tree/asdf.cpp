#include<iostream>
using namespace std;
int d=1;
struct bnode
{int data[2];
bnode* child[3];
bnode(){for(int i=0;i<2*d+1;i++)child[i]=NULL;
for(int i=0;i<2*d;i++)data[i]=-1;}
bnode(int d)
{for(int i=0;i<2*d+1;i++)child[i]=NULL;
for(int i=0;i<2*d;i++)data[i]=-1;
data[0]=d;}
bnode(int a[],int s,int e)
{for(int i=0;i<2*d+1;i++)child[i]=NULL;
for(int i=0;i<2*d;i++)data[i]=-1;
for(int i=s;i<e;i++)data[i-s]=a[i];}

bnode(bnode *t,int s,int e)
{for(int i=0;i<2*d+1;i++)child[i]=NULL;
for(int i=0;i<2*d;i++)data[i]=-1;
for(int i=s;i<e;i++)
{if(i!=e-1)
data[i]=t->data[i];
child[i]=t->child[i];
}}
};

class q
{
	int size;
	bnode* e[50];
	int f;
	int r;
	public:
	q();
	q(int);
	void enq(bnode*);
	bnode* dq();
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
void q::enq(bnode* i)
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
bnode* q::dq()
{
	if(f==-1)
		{cout<<"q is empty";
		return 0;}
	else
	{bnode* c=e[f];
		if(f==r)
			{f=-1;r=-1;}
		else 
			f=f+1%size;
		return c;
	}
}

class stack{
	bnode* e[50];int top;int size;
	public:
	void push(bnode* x);bnode* pop();int isempty();stack(int s){size=s;top=-1;}};
int stack::isempty()
{return top==-1;}

void stack::push(bnode* x){
	if(top==size)cout<<"stackoverflow\n";
	else e[++top]=x;}
bnode* stack::pop()
{if(isempty())return 0;
else return e[top--];}

void insort(int a[],int k,int l)
{int i=0;while(1)
{if(a[i]==-1){a[i]=k;break;}
else if(a[i]<k)i++;
else {int t;
for(t=l-1;t!=i;t--)
a[t]=a[t-1];
a[t]=k;break;}}}

int isleaf(bnode *&t)
{return t->child[0]==NULL?1:0;}

int nempty(int a[])
{for(int i=0;i<2*d;i++)if(a[i]==-1)return i;
return 0;}

void mempty(int a[],int l)
{for(int i=0;i<l;i++)a[i]=-1;}

void ar(int a[],int b[],int k)
{for(int i=0;i<2*d;i++)
insort(b,a[i],2*d);
insort(b,k,2*d+1);}

int index(bnode *&t,int k)
{int i;for(i=0;i<2*d;i++)
if(t->data[i]<k)return i;
return i;}

void merge(bnode*&t,int k)
{int i;
for(i=nempty(t->data);i!=index(t,k);i--)
{t->data[i]=t->data[i-1];
t->child[i+1]=t->child[i];}	

t->data[i]=t->child[i]->data[0];
t->child[i+1]=t->child[i]->child[1];
t->child[i]=t->child[i]->child[0];	
}

void purge(bnode *&t,int k)
{int i=index(t,k);
if(i<d)
{bnode *z=new bnode(t->data[d-1]);
bnode *y=new bnode(t,d,2*d+1);
bnode *x=new bnode(t,0,d-1);
merge(x,k);
z->child[0]=x;
z->child[1]=y;
t=z;}
else if(i>d)
{bnode *z=new bnode(t->data[d]);
bnode *y=new bnode(t,d+1,2*d+1);
bnode *x=new bnode(t,0,d);
merge(y,k);
z->child[0]=x;
z->child[1]=y;
t=z;}
else if(i==d)
{bnode *z=new bnode(k);
bnode *y=new bnode(t,0,d);
bnode *x=new bnode(t,d,2*d+1);
y->child[d+1]=t->child[d+1]->child[0];
x->child[0]=t->child[0]->child[1];
z->child[0]=x;
z->child[1]=y;
t=z;}	
}


int add(bnode *&t,int a[],int k)
{if(t==NULL)
{t=new bnode;
insort(t->data,k,2*d);return -1;}
if(isleaf(t))
{if(nempty(t->data)!=0)
{insort(t->data,k,2*d);return -1;}
else
{ar(t->data,a,k);
mempty(t->data,2*d);
t->data[0]=a[d];	
t->child[0]=new bnode(a,0,d);
t->child[1]=new bnode(a,d+1,2*d+1);return a[d];}}
for(int i=0;i<2*d+1;i++)
if(i<2*d)
{if(t->data[i]<k)
{add(t->child[i],a,k);break;}}
else {add(t->child[i],a,k);break;}
}

void sermg(bnode *&t,bnode *&p,int k)
{if(t==p)
merge(p,k);
for(int i=0;i<2*d+1;i++)
if(i<2*d)
{if(t->data[i]<k)
{sermg(t->child[i],p,k);break;}}
else {sermg(t->child[i],p,k);break;}}

void serpg(bnode *&t,bnode *&p,int k)
{if(t==p)
purge(p,k);
for(int i=0;i<2*d+1;i++)
if(i<2*d)
{if(t->data[i]<k)
{serpg(t->child[i],p,k);break;}}
else {serpg(t->child[i],p,k);break;}}

void set(bnode *&t,int k)
{if(k!=-1)
{stack s(30);bnode *f=t;
while(1)
{if(f->data[0]==k)break;
s.push(f);	
for(int i=0;i<2*d+1;i++)
if(i<2*d)
if(t->data[i]<k)
{t=t->child[i];break;}
else {t=t->child[i];break;}}	

while(!s.isempty())
{f=s.pop();
if(nempty(f->data)!=0)
{sermg(t,f,k);break;}
else
serpg(t,f,k);
}}}

void print(bnode *&t)
{if(t!=NULL)
{for(int i=0;i<2*d;i++)
cout<<t->data[i]<<" ";
for(int i=0;i<2*d+1;i++)
print(t->child[i]);	
}	
}

int main()
{bnode *t=NULL;
int x,a[10];
cin>>x;
while(x!=-1)
{mempty(a,10);
set(t,add(t,a,x));cin>>x;}

print (t);

}
