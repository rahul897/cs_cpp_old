#include<iostream>
using namespace std;
int d=1;
struct bnode
{int *data;
bnode **child;
bnode *pt;
int c;
bnode(){data=new int[2*d+1],child=new bnode*[2*d+2];c=0;pt=NULL;
for(int i=0;i<2*d+1;i++){data[i]=-1;child[i]=NULL;}child[2*d+1]=NULL;}
};
static bnode *root=NULL;

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

int index(bnode *&t,int k)
{for(int i=0;i<;i++)
if(t->child[i]->data[0]==k)return i;}

void merge(bnode*&t,int k)
{int i;
for(i=t->c;i!=index(t,k);i--)
{t->data[i]=t->data[i-1];
t->child[i+1]=t->child[i];}	

t->data[i]=t->child[i]->data[0];
t->child[i+1]=t->child[i]->child[1];
t->child[i]=t->child[i]->child[0];	
}
void overflow(bnode*&);

int keydist(bnode *&t)
{if(isleaf(t))
{bnode *p=t->pt;int in,i=0;
for(in=0;in<p->c+1;in++)
if(p->child[in]==t)break;
for(i=i%p->c;i!=in;i++)
if(p->child[i]->c<2*d&&p->child[i]->c>d)break;
if(i<in)
{p->child[in-1]->data[p->child[in-1]->c]=p->data[in-1];
p->data[in-1]=t->data[0];
p->child[in-1]->c++;
for(int j=0;j<t->c;j++)
t->data[i]=t->data[i+1];
t->c--;overflow(p->child[in-1]);return 1;}
if(i>in)
{p->child[in+1]->data[p->child[in+1]->c]=p->data[in];
insort(p->child[in+1]->data,p->data[in],p->child[in+1]->c++);
p->data[in]=t->data[t->c];
p->child[in+1]->c++;
t->c--;overflow(p->child[in+1]);return 1;}
if(i==in)return 0;}
}

void overflow(bnode *&t)
{bnode *p=t->pt;int i;
if(t->c>2*d)
{if(p==NULL)
{bnode *r=new bnode;
for(i=d+1;i<2*d+2;i++)
{if(i<2*d+1)r->data[i-d-1]=t->data[i];
r->child[i-d-1]=t->child[i];}r->c=d;
for(i=0;i<r->c;i++)
if(r->child[i])r->child[i]->pt=r;
p=new bnode;p->data[0]=t->data[d];
t->c=d;
r->pt=p;t->pt=p;
p->child[0]=t;p->child[1]=r;p->c++;	
root=p;}
else
{if(!keydist(t))
{int m=t->data[d];
bnode *l=new bnode,*r=new bnode;
for(i=0;i<d+1;i++)
{if(i<d)l->data[i]=t->data[i];
l->child[i]=t->child[i];}
for(i=d+1;i<2*d+1;i++)
{if(i<2*d+1)r->data[i-d-1]=t->data[i];
r->child[i-d-1]=t->child[i];
if(r->child[i-d-1])r->child[i-d-1]->pt=r;}
t=new bnode;t->data[0]=m;
t->child[0]=l;t->child[1]=r;	
merge(p,m);
overflow(p);}}}
}

void add(bnode *&t,int k)
{if(t==NULL)
{t=new bnode;insort(t->data,k,t->c++);}
else if(isleaf(t))
{insort(t->data,k,t->c++);
overflow(t);}
else
{int i;
for(i=0;i<t->c;i++)
if(t->data[i]>k)break;
add(t->child[i],k);}
}


void print(bnode *&t)
{if(t!=NULL)
{for(int i=0;i<t->c;i++)
cout<<t->data[i]<<" ";
cout<<endl;
for(int i=0;i<t->c+1;i++)
{print(t->child[i]);}}}

int main()
{int x;
cin>>x;
while(x!=-1)
{add(root,x);
cin>>x;}

print(root);
	
	
}
