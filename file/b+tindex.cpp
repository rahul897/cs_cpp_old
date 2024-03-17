#include<iostream>
#include<fstream>
using namespace std;
int d;
struct bnode
{int *data;
bnode **child;
int *in;
int nno;
int c;
bnode(){data=new int[2*d+1];in=new int[2*d+1];child=new bnode*[2*d+2];c=0;nno=-1;
for(int i=0;i<2*d+1;i++){data[i]=-1;in[i]=-1;child[i]=NULL;}child[2*d+1]=NULL;}
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
{for(int i=0;i<=t->c;i++)
if(t->child[i]->data[0]==k)return i;}

void print(bnode *&t)
{if(t!=NULL)
{for(int i=0;i<t->c;i++)
cout<<t->data[i]<<" ";
cout<<endl;
for(int i=0;i<t->c+1;i++)
{print(t->child[i]);}}}

void sort(bnode *&t)
{int k,l;
for(int i=0;i<t->c;i++)
for(int j=0;j<t->c;j++)
if(t->data[i]<t->data[j])
{k=t->data[j];l=t->in[j];
t->data[j]=t->data[i];t->in[j]=t->in[i];
t->data[i]=k;t->in[i]=l;}}

int isleaf(bnode *&t)
{return t->child[0]==NULL?1:0;}

void split(bnode *&t)
{bnode *p=parent(root,t);int i;
bnode *l=new bnode;
bnode *r=new bnode;
for(i=0;i<=d;i++)
{if(i!=d){l->in[l->c]=t->in[i];
l->data[l->c++]=t->data[i];}
l->child[i]=t->child[i];}
for(i=d+1;i<=2*d+1;i++)
{if(!isleaf(t))
{if(i!=d)
{if(i!=2*d+1){r->in[r->c]=t->in[i];
r->data[r->c++]=t->data[i];}
r->child[i-d-1]=t->child[i];}}
else
{{r->in[r->c]=t->in[i];
r->data[r->c++]=t->data[i];}
if(i!=d){r->child[i-d-1]=t->child[i];}}}
if(!p)
{p=new bnode;
p->in[p->c]=t->in[d];
p->data[p->c++]=t->data[d];
p->child[0]=l;p->child[1]=r;root=p;}
else
{int j=index(p,t->data[0]);
for(i=p->c;i!=j;i--)
{p->data[i]=p->data[i-1];
p->in[i]=p->in[i-1];
p->child[i+1]=p->child[i];}
p->data[i]=t->data[d];
p->in[i]=t->in[d];
p->child[i]=l;p->child[i+1]=r;p->c++;}
}

void overflow(bnode *&t)
{if(t->c>2*d)
{bnode *p=parent(root,t);
split(t);
if(p)overflow(p);}	
}

void ind(bnode *&t,int i,int &k)
{if(t!=NULL)
{if(i==0)
t->nno=k++;
else if(i>0)
{for(int j=0;j<=t->c;j++)
ind(t->child[j],i-1,k);}}
}

void height(bnode *&t,int &i)
{if(t!=NULL)
{i++;height(t->child[0],i);}}

void li(bnode *&t)
{int i,j,n,k=0;height(t,n);
for(i=0;i<n;i++)
ind(t,i,k);}

void add(bnode *&t,int k,int in)
{if(t==NULL)
{t=new bnode;t->in[t->c];t->data[t->c++]=k;}
else if(isleaf(t))
{t->in[t->c];t->data[t->c++]=k;sort(t);
overflow(t);}
else
{int i;
for(i=0;i<t->c;i++)
if(t->data[i]>k)break;
add(t->child[i],k,in);}
}

struct student
{int rno;
char name[10];
float cg;
student(){rno=-1;cg=-1;}
};

void ordr(ofstream &out,bnode *&t,int i)
{if(t!=NULL)
{if(i==0)
{for(int j=0;j<=2*d;j++)
{if(t->child[i]&&j<t->c)out<<t->child[i]->nno<<" ";else -1;
if(i<t->c)out<<t->data[i]<<" "<<t->nno<<" ";}
cout<<endl;}
else if(i>0)
{for(int j=0;j<t->c+1;j++)
{ordr(out,t->child[j],i-1);}}}
}

void lo(ofstream &out,bnode *&t)
{int n;height(t,n);
ordr(out,root,n);
}

int main()
{cout<<"enter deg\n";int d,l=1,i=0;
cin>>d;
student s[30],k;
ofstream fout;
fout.open("data1.txt");

while(l)
{cout<<"enter student roll.no\n";
cin>>s[i].rno;
cout<<"enter studetn name\n";
cin>>s[i].name;
cout<<"enter cgpa\n";
cin>>s[i].cg;
add(root,s[i].rno,i);
cout<<"press 1 to enter again\npress 0 to stop\n";
cin>>l;i++;}

ofstream file;file.open("index.txt");
lo(file,root);

}
