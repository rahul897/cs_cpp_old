#include<iostream>
using namespace std;
int d;
struct bnode
{int *data;
bnode **child;
bnode *pt;
int c;
bnode(){data=new int[2*d+1],child=new bnode*[2*d+2];c=0;pt=NULL;
for(int i=0;i<2*d+1;i++){data[i]=-1;child[i]=NULL;}child[2*d+1]=NULL;}
};
bnode *root; 

int index(bnode *&t,int k)
{for(int i=0;i<t->c+1;i++)
if(t->child[i]->data[0]==k)return i;}

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
{bnode *p=t->pt;int i;
bnode *l=new bnode;
bnode *r=new bnode;
for(i=0;i<=d;i++)
{if(i!=d)l->data[l->c++]=t->data[i];
l->child[i]=t->child[i];}
for(i=d+1;i<=2*d+1;i++)
{if(i!=2*d+1){r->data[r->c++]=t->data[i];
r->child[r->c-1]=t->child[i];}
else r->child[r->c]=t->child[i];}
for(i=0;i<=r->c;i++)
{if(l->child[i])l->child[i]->pt=l;
if(r->child[i])r->child[i]->pt=r;}
if(!p)
{p=new bnode;
p->data[p->c++]=t->data[d];
p->child[0]=l;p->child[1]=r;
p->child[0]->pt=p;p->child[1]->pt=p;root=p;}
else
{int j=index(p,t->data[0]);
for(i=p->c;i!=j;i--)
{p->data[i]=p->data[i-1];
p->child[i+1]=p->child[i];
if(p->child[i+1])p->child[i+1]->pt=p;}
p->data[i]=t->data[d];
p->child[i]=l;p->child[i+1]=r;
p->child[i+1]->pt=p;p->child[i]->pt=p;p->c++;
for(i=0;i<=p->c;i++)
p->child[i]->pt=p;}}}


void rl_dis(bnode *&t,int i)
{bnode *p=t->pt,*s=p->child[i-1];
s->data[s->c]=p->data[i-1];s->c++;
p->data[i-1]=t->data[0];
s->child[s->c+1]=t->child[0];
if(s->child[s->c+1])s->child[s->c+1]->pt=s;
for(int j=0;j<=t->c;j++)
{if(j!=t->c)t->data[j]=t->data[j+1];
t->child[j]=t->child[j+1];}
t->c--;
for(int j=0;j<=t->c;j++)
if(t->child[j])t->child[j]->pt=t;
}

void lr_dis(bnode *&t,int i)
{bnode *p=t->pt,*s=p->child[i+1];
for(int j=s->c;j>0;j--)
{s->data[j]=s->data[j-1];
s->child[j+1]=s->child[j];
if(!isleaf(s))s->child[j+1]->pt=s;}
s->data[0]=p->data[i];
s->c++;
s->child[0]=t->child[t->c];
for(int j=0;j<=s->c;j++)
if(s->child[j])s->child[j]->pt=s;
t->c--;p->data[i]=t->data[t->c];	
}

void overflow(bnode *&t)
{if(t->c>2*d)
{bnode *p=t->pt;
if(p){
int i=index(p,t->data[0]);
if(i!=2*d+1&&p->child[i+1]&&p->child[i+1]->c<2*d)
lr_dis(t,i);
else if(i!=0&&p->child[i-1]&&p->child[i-1]->c<2*d)
rl_dis(t,i);}
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
