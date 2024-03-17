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

bnode *root;

int isleaf(bnode *&t)
{return t->child[0]==NULL?1:0;}

int index(bnode *&t,int k)
{for(int i=0;i<2*d+2;i++)
if(t->child[i]->data[0]==k)return i;}

void insort(int a[],int k,int l)
{int i=0;while(1)
{if(a[i]==-1){a[i]=k;break;}
else if(a[i]<k)i++;
else {int t;
for(t=l-1;t!=i;t--)
a[t]=a[t-1];
a[t]=k;break;}}}

void print(bnode *&t)
{if(t!=NULL)
{for(int i=0;i<t->c;i++)
cout<<t->data[i]<<" ";
cout<<endl;
for(int i=0;i<t->c+1;i++)
{print(t->child[i]);}}}


void overflow(bnode *&t)
{if(t->c>2*d)
{bnode* p=t->pt;int i;
bnode *l=new bnode,*r=new bnode;
for(i=0;i<t->c/2;i++)
{l->data[i]=t->data[i];
l->child[i]=t->child[i];
if(l->child[i])l->child[i]->pt=l;}
l->c=d;
for(;i<t->c;i++)
{r->data[i-d-1]=t->data[i];
r->child[i-d-1]=t->child[i];
if(r->child[i])r->child[i]->pt=r;}
r->c=d;
if(p==NULL)
{p=new bnode;
p->data[0]=t->data[t->c/2];
l->pt=p;r->pt=p;
p->child[0]=l;p->child[1]=r;p->c++;
root=p;}
else
{int j=index(p,t->data[0]);
for(i=p->c;i!=j;i--)
{p->data[i]=p->data[i-1];
p->child[i+1]=p->child[i];
if(p->child[i])p->child[i]->pt=p->child[i+1];}
p->c++;
p->data[i]=t->data[t->c/2];
p->child[i]=l;
p->child[i+1]=r;
print(p);
overflow(p);}}
}

void add(bnode *&t,int k)
{if(t==NULL)
{t=new bnode;insort(t->data,k,t->c++);}
else if(isleaf(t))
{insort(t->data,k,t->c++);
overflow(t);}
else
{int i;for(i=0;i<t->c;i++)
if(t->data[i]>k)break;
add(t->child[i],k);}	
}

int main()
{int x;
cin>>x;
while(x!=-1)
{add(root,x);
cin>>x;}
print(root);

}

