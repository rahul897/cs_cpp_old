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

int index(bnode *&t,bnode *&k)
{for(int i=0;i<t->c+1;i++)
if(t->child[i]==k)return i;}

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
if(!isleaf(t))t->child[j]=t->child[j+1];}
t->c--;
}

void lr_dis(bnode *&t,int i)
{bnode *p=parent(root,t),*s=p->child[i+1];
for(int j=s->c;j>0;j--)
{s->data[j]=s->data[j-1];
if(!isleaf(s))s->child[j+1]=s->child[j];}
s->data[0]=p->data[i];
s->c++;
s->child[0]=t->child[t->c];
t->c--;p->data[i]=t->data[t->c];	
}

void overflow(bnode *&t)
{if(t->c>2*d)
{bnode *p=parent(root,t);
if(p){
int i=index(p,t);
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

int find(bnode *&t,int k)
{for(int i=0;i<t->c;i++)
if(t->data[i]==k)return i;
return -1;
}

bnode * min(bnode* &t)
{if(t->child[0]!=NULL)
min(t->child[0]);
return t;
}

void merge(bnode *&t,bnode *&p,int k)
{bnode *s=p->child[k];int i,j,a;
t->data[t->c++]=p->data[k-1];
for(i=0;i<=s->c;i++)
{if(i!=s->c){t->data[t->c++]=s->data[i];
t->child[t->c-1]=s->child[i];}
else t->child[t->c]=s->child[i];}
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
}

void underflow(bnode *&t)
{if(t->c<d)
{bnode *p=parent(root,t);
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
merge(t,p,i+1);
else
merge(p->child[i-1],p,i);}
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



int main()
{int x;
cout<<"enter deg\n";
cin>>d;
cin>>x;
while(x!=-1)
{add(root,x);cin>>x;}
cout<<endl;

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
