#include<iostream>
using namespace std;
int d=1;
struct bnode
{int data[2];
bnode* child[3];
bnode(){for(int i=0;i<2*d+1;i++)child[i]=NULL;
for(int i=0;i<2*d;i++)data[i]=-1;}

bnode(int a[],int s,int e)
{for(int i=0;i<2*d+1;i++)child[i]=NULL;
for(int i=0;i<2*d;i++)data[i]=-1;
for(int i=s;i<e;i++)data[i-s]=a[i];}

bnode(bnode *t,int s,int e)
{for(int i=0;i<2*d+1;i++)child[i]=NULL;
for(int i=0;i<2*d;i++)data[i]=-1;
for(int i=s;i<e;i++)
{if(i<e-1)
data[i-s]=t->data[i];
child[i-s]=t->child[i];}}
};

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
{for(int i=0;i<2*d+1;i++)
if(t->child[i]->data[0]==k)return i;}

void merge(bnode*&t,int k)
{int i;
for(i=nempty(t->data);i!=index(t,k);i--)
{t->data[i]=t->data[i-1];
t->child[i+1]=t->child[i];}	

t->data[i]=t->child[i]->data[0];
t->child[i+1]=t->child[i]->child[1];
t->child[i]=t->child[i]->child[0];	
}

void print(bnode *&t)
{if(t!=NULL)
{for(int i=0;i<2*d;i++)
cout<<t->data[i]<<" ";
cout<<endl;
for(int i=0;i<2*d+1;i++)
{print(t->child[i]);}}}


void purge(bnode *&t,int k)
{int i=index(t,k);
bnode *z=t;
if(i<d)
{z=new bnode;z->data[0]=t->data[d-1];
bnode *y=new bnode(t,d,2*d+1);
bnode *x=new bnode(t,0,d);
merge(x,k);
z->child[0]=x;
z->child[1]=y;
t=z;}
else if(i>d)
{z=new bnode;z->data[0]=t->data[d];
bnode *y=new bnode(t,d+1,2*d+1);
merge(y,k);
bnode *x=new bnode(t,0,d+1);
z->child[0]=x;
z->child[1]=y;
t=z;}
else if(i==d)
{z=new bnode;z->data[0]=k;
bnode *y=new bnode(t,d,2*d+1);
bnode *x=new bnode(t,0,d+1);
y->child[i]=t->child[i]->child[0];
x->child[0]=t->child[i]->child[1];
z->child[0]=x;
z->child[1]=y;
t=z;}	
}


int add(bnode *&t,int a[],int k)
{if(t==NULL)
{t=new bnode;
insort(t->data,k,2*d);return -1;}
else if(isleaf(t))
{if(nempty(t->data)!=0)
{insort(t->data,k,2*d);return -1;}
else
{ar(t->data,a,k);
mempty(t->data,2*d);
t->data[0]=a[d];	
t->child[0]=new bnode(a,0,d);
t->child[1]=new bnode(a,d+1,2*d+1);return a[d];}}
for(int i=0;i<2*d+1;i++)
if(i==0){if(t->data[0]>k){add(t->child[0],a,k);break;}}
else if(t->data[i-1]<k&&t->data[i]==-1){add(t->child[i],a,k);break;}
else if(i==2*d){if(t->data[i-1]<k){add(t->child[i],a,k);break;}}
else if(t->data[i-1]<k&&t->data[i]>k){add(t->child[i],a,k);break;}
}

void sermg(bnode *&t,bnode *&p,int k,int g)
{if(t==p)
g==1?merge(p,k):purge(p,k);
for(int i=0;i<2*d+1;i++)
if(i==0){if(t->data[0]>p->data[0]){sermg(t->child[0],p,k,i);break;}}
else if(t->data[i-1]<p->data[0]&&t->data[i]==-1){sermg(t->child[i],p,k,i);break;}
else if(i==2*d){if(t->data[i-1]<p->data[0]){sermg(t->child[i],p,k,i);break;}}
else if(t->data[i-1]<p->data[0]&&t->data[i]>p->data[0]){sermg(t->child[i],p,k,i);break;}}


void set(bnode *&t,int k)
{if(k!=-1)
{stack s(30);bnode *f=t;int i;
while(1)
{if(f->data[0]==k)break;
s.push(f);	
for(int i=0;i<2*d+1;i++)
if(i==0){if(f->data[0]>k){f=f->child[0];break;}}
else if(f->data[i-1]<k&&f->data[i]==-1){f=f->child[i];break;}
else if(i==2*d){if(f->data[i-1]<k){f=f->child[i];break;}}
else if(f->data[i-1]<k&&f->data[i]>k){f=f->child[i];break;}}	

while(!s.isempty())
{f=s.pop();
i=nempty(f->data)!=0;
sermg(t,f,k,i);
if(i)break;
}}}
static bnode *root;

int main()
{int x,a[10];
cin>>x;
while(x!=-1)
{mempty(a,10);
set(root,add(root,a,x));cin>>x;}

print(root);

}
