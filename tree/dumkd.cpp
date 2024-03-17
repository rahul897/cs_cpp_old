#include<iostream>
using namespace std;
int d;
struct bnode
{int *data;
bnode **child;
int c;
bnode(){data=new int[2*d+1],child=new bnode*[2*d+2];c=0;
for(int i=0;i<2*d+1;i++){data[i]=-1;child[i]=NULL;}child[2*d+1]=NULL;}
};
bnode *root; 

bnode* parent(bnode *&p,bnode *&t,int i=0)
{if(t==root)return NULL;
for(i=0;i<=p->c;i++)	
if(p->child[i]==t)return p;
for(i=0;i<p->c;i++)
if(p->data[i]>t->data[0])break;
return parent(p->child[i],t);	
}

int index(bnode *&p,bnode *&t)
{for(int i=0;i<=p->c;i++)
if(p->child[i]==t)return i;}

void height(bnode *&t,int &i)
{if(t!=NULL)
{i++;height(t->child[0],i);}
}

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
{int i,j,n;height(t,n);
for(i=0;i<n;i++)
{for(j=0;j<(n-i)*4;j++)
cout<<" ";
ordr(t,i);
cout<<endl;}}

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
print(t->child[i]);}}

void split(bnode *&t)
{if(t->c>2*d)
{bnode *p=parent(root,t);int i;
bnode *l=new bnode;
bnode *r=new bnode;
for(i=0;i<=d;i++)
{if(i!=d)l->data[l->c++]=t->data[i];
l->child[i]=t->child[i];}
for(i=d+1;i<=2*d+1;i++)
{if(i!=2*d+1)r->data[r->c++]=t->data[i];
r->child[i-d-1]=t->child[i];}
if(!p)
{p=new bnode;
p->data[p->c++]=t->data[d];
p->child[0]=l;p->child[1]=r;
root=p;}
else
{int j=index(p,t);
for(i=p->c;i!=j;i--)
{p->data[i]=p->data[i-1];
p->child[i+1]=p->child[i];}
p->data[i]=t->data[d];
p->child[i]=l;p->child[i+1]=r;
p->c++;}}
}

void rl_dis(bnode *&t,int i)
{bnode *p=parent(root,t),*s=p->child[i-1];
s->data[s->c]=p->data[i-1];s->c++;
p->data[i-1]=t->data[0];
s->child[s->c+1]=t->child[0];
for(int j=0;j<=t->c;j++)
{if(j!=t->c)t->data[j]=t->data[j+1];
t->child[j]=t->child[j+1];}
t->c--;
}

void lr_dis(bnode *&t,int i)
{bnode *p=parent(root,t),*s=p->child[i+1];
for(int j=s->c;j>0;j--)
{s->data[j]=s->data[j-1];
s->child[j+1]=s->child[j];}
s->data[0]=p->data[i];
s->c++;
s->child[0]=t->child[t->c];
t->c--;p->data[i]=t->data[t->c];	
}

void overflow(bnode *&t)
{if(t->c>2*d)
{bnode *p=parent(root,t);
if(p){
int i;
for(i=0;i<=p->c;i++)
if(p->child[i]==t)break;
if(i&&p->child[i-1])
{bnode *s=p->child[i-1];
s->data[s->c]=p->data[i-1];s->c++;
p->data[i-1]=t->data[0];
s->child[s->c+1]=t->child[0];
for(int j=0;j<=t->c;j++)
{if(j!=t->c)t->data[j]=t->data[j+1];
t->child[j]=t->child[j+1];}
t->c--;}
else if(i!=2*d+1&&p->child[i+1])
{bnode *s=p->child[i+1];
for(int j=s->c;j>0;j--)
{s->data[j]=s->data[j-1];
s->child[j+1]=s->child[j];}
s->data[0]=p->data[i];
s->c++;
s->child[0]=t->child[t->c];
t->c--;p->data[i]=t->data[t->c];}
}
split(t);
if(p)overflow(p);
}	
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
cout<<"enter deg\n";
cin>>d;
cin>>x;
while(x!=-1)
{add(root,x);cin>>x;}


cout<<endl;

lo(root);
	
	
}
