#include<iostream>
using namespace std;
int d=1;
struct bnode
{int data[2];
bnode* child[3];
bnode(){for(int i=0;i<2*d+1;i++)child[i]=NULL;
for(int i=0;i<2*d;i++)data[i]=-1;}

bnode(int k){data[0]=k;for(int i=1;i<2*d;i++)data[i]=-1;
for(int i=0;i<2*d+1;i++)child[i]=NULL;}

bnode(int a[],int s,int e)
{for(int i=s;i<e;i++)data[i-s]=a[i];
for(int i=e;i<2*d;i++)data[i]=-1;for(int i=0;i<2*d+1;i++)child[i]=NULL;}

bnode(bnode *t,int s,int e)
{for(int i=s;i<e;i++)
{if(i!=e-1)
data[i]=t->data[i];
child[i]=t->child[i];}}
};

class stack{
	bnode* e[50];
	int top;
	int size;
	public:
	void push(bnode* x);
	bnode* pop();
	int isfull();
	int isempty();
	stack(int s){size=s;top=-1;}
};
int stack::isfull()
{return top==size-1;}
int stack::isempty()
{return top==-1;}
void stack::push(bnode* x){
	if(isfull())cout<<"stackoverflow\n";
	else e[++top]=x;
}

bnode* stack::pop()
{if(isempty())return 0;
else return e[top--];}


void insort(int a[],int k,int l)
{int i=0;
while(1)
{if(a[i]==-1){a[i]=k;break;}
else if(a[i]<k)i++;
else 
{int t;
for(t=l-1;t!=i;t--)
a[t]=a[t-1];
a[t]=k;break;}}
}

int isleaf(bnode*& t)
{for(int i=0;i<2*d+1;i++)
if(t->child[i]!=NULL)return 0;
return 1;
}

int nempty(int a[])
{for(int i=0;i<2*d;i++)
if(a[i]==-1)
return 1;
return 0;
}

void ar(int a[],int b[],int k)
{for(int i=0;i<2*d+1;i++)
insort(b,a[i],2*d);
insort(b,k,2*d+1);
}

int index(bnode *&t,int k)
{int i;
for(i=0;i<2*d;i++)
if(t->data[i]<k)return i;
return i;
}

void mempty(bnode *&t,int s,int e)
{int i;
for(i=s;i<e;i++)
{if(i!=e-1)t->data[i]=-1;
t->child[i]=NULL;}
}


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
if(i<d+1)
{bnode *z=new bnode(t->data[d]);
bnode *y=new bnode(t,d+1,2*d+1);
bnode *x=new bnode(t,0,d);
merge(x,k);
z->child[0]=x;
z->child[1]=y;
t=z;}
else if(i>d+1)
{bnode *z=new bnode(t->data[d+1]);
bnode *y=new bnode(t,d+2,2*d+1);
bnode *x=new bnode(t,0,d+1);
merge(y,k);
z->child[0]=x;
z->child[1]=y;
t=z;}
else if(i==d+1)
{bnode *z=new bnode(k);
bnode *y=new bnode(t,0,d+1);
bnode *x=new bnode(t,d+1,2*d+1);
y->child[d+1]=t->child[d+1]->child[0];
x->child[0]=t->child[0]->child[1];
z->child[0]=x;
z->child[1]=y;
t=z;}	
}


int add(bnode* &t,int a[],int k)
{if(isleaf(t))
{if(nempty(t->data))
{insort(t->data,k,2*d);return -1;}
else
{ar(t->data,a,k);
insort(t->data,a[d+1],2*d);
bnode* z=new bnode(a,d+2,2*d);
bnode* y=new bnode(a,0,d+1);
t->child[0]=y;t->child[1]=z;
return a[d+1];}		
}
for(int i=0;i<2*d;i++)
if(t->data[i]>k)
add(t->child[i],a,k);
else if(i==2*d-1)
add(t->child[i],a,k);
}

void sermg(bnode *&t,bnode *&p,int k)
{if(t==p)
merge(p,k);
for(int i=0;i<2*d;i++)
if(t->data[i]>k)
sermg(t->child[i],p,k);
else if(i==2*d-1)
sermg(t->child[i],p,k);
}
void serpg(bnode *&t,bnode *&p,int k)
{if(t==p)
purge(p,k);
for(int i=0;i<2*d;i++)
if(t->data[i]>k)
serpg(t->child[i],p,k);
else if(i==2*d-1)
serpg(t->child[i],p,k);
}


void set(bnode*&t,int k)
{stack s(30);bnode *p=t;int i,f=1;
if(k!=-1)
{
while(1)
{if(p->data[0]==k)break;
s.push(p);
else for(i=0;i<2*d-1;i++)
if(p->data[i]<k){p=p->child[i];f=0;break;}
if(f)p=p->child[2*d];}

while(!s.isempty())
{p=s.pop();
if(nempty(p->data))
{sermg(t,p,k);break;}
else
serpg(t,p,k);}

}
}

int main()
{bnode *t=NULL;
int x,a[10];
cout<<"enter els\n";
cin>>x;
t=new bnode;
for(int i=0;i<2;i++)
cout<<t->data[i];
while(x!=-1)
{set(t,add(t,a,x));
cin>>x;
}
for(int i=0;i<2;i++)
cout<<t->data[i];
	
	
	
}
