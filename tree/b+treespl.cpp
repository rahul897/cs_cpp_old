#include<iostream>
using namespace std;
int d=1;
struct bnode
{int *data;
bnode **child;
bnode *sib;
int c;
bnode(){data=new int[2*d+1],child=new bnode*[2*d+2];c=0;
for(int i=0;i<2*d+1;i++){data[i]=-1;child[i]=NULL;}child[2*d+1]=NULL;
sib=NULL;}
};
bnode *root; 

bnode* parent(bnode *&p,bnode *&t,int i=0)
{if(t==root)return NULL;
for(i=0;i<=p->c;i++)	
if(p->child[i]==t)return p;
for(i=0;i<p->c;i++)
if(p->data[i]>t->data[0])break;
return parent(p->child[i],t);}


int index(bnode *&t,int k)
{for(int i=0;i<t->c+1;i++)
if(t->child[i]->data[0]==k)return i;}

void height(bnode *&t,int &i)
{if(t!=NULL)
{i++;height(t->child[0],i);}
}
bnode * getlast(bnode *&t)
{if(t->child[0]==NULL)
return t;
return getlast(t->child[0]);
}

void sort(bnode *&t)
{int k;
for(int i=0;i<t->c;i++)
for(int j=0;j<t->c;j++)
if(t->data[i]<t->data[j])
{k=t->data[j];
t->data[j]=t->data[i];
t->data[i]=k;}}

int isleaf(bnode *&t)
{return t->child[0]==NULL?1:0;}

void print(bnode *&t)
{if(t!=NULL)
{for(int i=0;i<t->c;i++)
cout<<t->data[i]<<" ";
cout<<endl;
for(int i=0;i<t->c+1;i++)
{print(t->child[i]);}}}

void ordr(bnode *&t,int i)
{if(t!=NULL)
{if(i==0)
{cout<<"[";
for(int j=0;j<t->c;j++)
cout<<t->data[j]<<" ";
cout<<"]";}
else if(i>0)
{for(int j=0;j<t->c+1;j++)
{ordr(t->child[j],i-1);cout<<" ";}}}
}

void lo(bnode *&t)
{int i,j,n=0;height(t,n);
for(i=0;i<n;i++)
{for(j=0;j<(n-i)*4;j++)
cout<<" ";
ordr(t,i);
cout<<endl;}}

void printino(bnode *&t)
{bnode *l=getlast(t);
int i;
while(l)
{for(i=0;i<t->c;i++)
cout<<t->data[i]<<" ";
l=l->sib;}
}

void split(bnode *&t)
{if(t->c>2*d)
{bnode *p=parent(root,t);int i;
bnode *l=new bnode;
bnode *r=new bnode;
for(i=0;i<=d;i++)
{if(i!=d)l->data[l->c++]=t->data[i];
l->child[i]=t->child[i];}
for(i=d;i<=2*d+1;i++)
{if(!isleaf(t))
{if(i!=d)
{if(i!=2*d+1)r->data[r->c++]=t->data[i];
r->child[i-d-1]=t->child[i];}}
else
{if(i!=2*d+1)r->data[r->c++]=t->data[i];
if(i!=d){r->child[i-d-1]=t->child[i];}}}
if(!p)
{p=new bnode;
p->data[p->c++]=t->data[d];
p->child[0]=l;p->child[1]=r;
root=p;}
else
{int j=index(p,t->data[0]);
for(i=p->c;i!=j;i--)
{p->data[i]=p->data[i-1];
p->child[i+1]=p->child[i];}
p->data[i]=t->data[d];
p->child[i]=l;p->child[i+1]=r;p->c++;}}
}

void overflow(bnode *&t)
{if(t->c>2*d)
{bnode *p=parent(root,t);
split(t);
if(p)overflow(p);}	
}


void add(bnode *&t,int k)
{if(t==NULL)
{t=new bnode;t->data[t->c++]=k;}
else if(isleaf(t))
{t->data[t->c++]=k;sort(t);
overflow(t);}
else
{int i;
for(i=0;i<t->c;i++)
if(t->data[i]>k)break;
add(t->child[i],k);}
}

int main()
{int x;
cin>>x;
while(x!=-1)
{add(root,x);cin>>x;}


lo(root);

cout<<endl<<"inoder\n";

printino(root);
	
}
