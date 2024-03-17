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

int index(bnode *&t,bnode *&k)
{for(int i=0;i<=t->c;i++)
if(t->child[i]==k)return i;}

void height(bnode *&t,int &i)
{if(t!=NULL)
{i++;height(t->child[0],i);}}

void print(bnode *&t)
{if(t!=NULL)
{for(int i=0;i<t->c;i++)
cout<<t->data[i]<<" ";
cout<<endl;
for(int i=0;i<t->c+1;i++)
{print(t->child[i]);}}}

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

void ordr(bnode *&t,int i)
{if(t!=NULL)
{if(i==0)
{cout<<"[ ";
for(int j=0;j<2*d;j++)
if(j<t->c)cout<<t->data[j]<<" ";
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

void split(bnode *&t)
{bnode *p=t->pt;int i;
bnode *l=new bnode;
bnode *r=new bnode;
for(i=0;i<=d;i++)
{if(i!=d)l->data[l->c++]=t->data[i];
l->child[i]=t->child[i];}
for(i=d+1;i<=2*d+1;i++)
{if(i!=2*d+1)r->data[r->c++]=t->data[i];
r->child[i-d-1]=t->child[i];}
for(i=0;i<=d;i++)
{if(l->child[i])l->child[i]->pt=l;
if(r->child[i])r->child[i]->pt=r;}
if(!p)
{p=new bnode;
p->data[p->c++]=t->data[d];
p->child[0]=l;p->child[1]=r;
p->child[0]->pt=p;p->child[1]->pt=p;root=p;}
else
{int j=index(p,t);
for(i=p->c;i!=j;i--)
{p->data[i]=p->data[i-1];
p->child[i+1]=p->child[i];}
p->data[i]=t->data[d];
p->child[i]=l;p->child[i+1]=r;
p->c++;
for(i=0;i<=p->c;i++)
p->child[i]->pt=p;}
}

void overflow(bnode *&t)
{if(t->c>2*d)
{bnode *p=t->pt;
split(t);
if(p)overflow(p);}	
}

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
for(int j=0;j<=t->c;i++)
if(t->child[j])t->child[j]->pt=t;
}

void lr_dis(bnode *&t,int i)
{bnode *p=t->pt,*s=p->child[i+1];
for(int j=s->c;j>0;j--)
{s->data[j]=s->data[j-1];
s->child[j+1]=s->child[j];}
s->data[0]=p->data[i];
s->c++;
s->child[0]=t->child[t->c];
for(int j=0;j=s->c;j++)
if(s->child[j])s->child[j]->pt=s;
t->c--;p->data[i]=t->data[t->c];	
}

int find(bnode *&t,int k)
{for(int i=0;i<t->c;i++)
if(t->data[i]==k)return i;
return -1;
}

bnode * min(bnode* &t)
{if(t->child[0]==NULL)return t;
return min(t->child[0]);}

void merge(bnode *&t,int k)
{bnode *p=t->pt,*s=p->child[k];int i,j,a;
t->data[t->c++]=p->data[k-1];
for(i=0;i<=s->c;i++)
{if(i!=s->c){t->data[t->c++]=s->data[i];
t->child[t->c-1]=s->child[i];}
else t->child[t->c]=s->child[i];}
for(i=0;i<=t->c;i++)
if(t->child[i])t->child[i]->pt=t;
j=index(p,t);
if(j>k)
for(i=k;i<p->c;i++)
{if(i!=p->c)p->data[i]=p->data[i+1];
p->child[i]=p->child[i+1];}
else
for(i=j;i<=p->c;i++)
{if(i!=p->c)p->data[i]=p->data[i+1];
p->child[i+1]=p->child[i+2];}
p->c--;
for(i=0;i<=p->c;i++)
p->child[i]->pt=p;
}

void underflow(bnode *&t)
{if(t->c<d)
{bnode *p=t->pt;
if(t->c==0&&t==root)
{root=t->child[0];p=NULL;}
if(p){
int i=index(p,t);
if(i!=2*d+1&&p->child[i+1]&&p->child[i+1]->c>d)
rl_dis(p->child[i+1],i+1);
else if(i!=0&&p->child[i-1]&&p->child[i-1]->c>d)
lr_dis(p->child[i-1],i-1);
else 
{if(p->child[i+1])
merge(t,i+1);
else
merge(p->child[i-1],i);}
underflow(p);}
}	
}
	

void del(bnode *&t,int k)
{if(find(t,k)!=-1)
{int i=find(t,k);
if(isleaf(t))
{t->data[i]=1000;sort(t);t->c--;
t->data[t->c]=-1;
underflow(t);}
else
{bnode *n=min(t->child[i+1]);
t->data[i]=n->data[0];
n->data[0]=1000;sort(n);n->c--;
underflow(n);
}}
else
{int i;
for(i=0;i<t->c;i++)
if(t->data[i]>k)break;
del(t->child[i],k);}
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

lo(root);

cout<<"enter el to del\n";
cin>>x;
while(x!=-1)
{del(root,x);
lo(root);
cout<<"enter el to del\n";
cin>>x;
}


	
	
}
