#include<iostream>
#include<fstream>
using namespace std;
struct tnode
{int fr;
char ch;
tnode *lchild;
tnode *rchild;
tnode(char d,int x){fr=x;ch=d;lchild=NULL;rchild=NULL;}
};

void print(tnode *t,ofstream &f)
{if(t!=NULL)
if(t->rchil!=NULL&&t->lchild!=NULL)
{fout<<0;print(t->lchild,f);
fout<<1;print(t->rchild,f);}
}

int height(tnode *t)
{if(t==NULL)return -1;
else
{int a=height(t->lchild);
int b=height(t->rchild);
return a>b?a+1:b+1;}
}

void sort(tnode *t[],int s,int e)
{char c1;int d1;
for(int i=s;i<e;i++)
for(int j=s;j<e;j++)
if(t[i]->fr<t[j]->fr)
{c1=t[i]->ch;t[i]->ch=t[j]->ch;t[j]->ch=c1;
d1=t[i]->fr;t[i]->fr=t[j]->fr;t[j]->fr=d1;}
}

char o='A';
tnode* branch(tnode *&x,tnode *&y)
{tnode *k=new tnode(o++,x->fr+y->fr);
if(x->fr<y->fr){k->lchild=x;k->rchild=y;}
else {k->rchild=x;k->lchild=y;}
return k;
}

void leaf(tnode *t,char csa[],int i)
{if(t)
{if(t->lchild==NULL&&t->rchild==NULL)
csa[i++]=t->ch;
leaf(t->lchild,csa,i++);
leaf(t->rchild,csa,i++);}
}

void maketree(tnode *t[],int &l)
{int i=1;
while(i<l)
{t[i++]=branch(t[i-1],t[i]);
sort(t,i,l);
}}

int main()
{tnode *t[20];
char c,c1,ca[20],csa[20];int d,d1,l=0,i;
while(1)
{cout<<"enter char\n";cin>>c;
cout<<"enter fre\n";cin>>d;
ca[l]=c;
t[l++]=new tnode(c,d);
cout<<"enter 1 to enter again\n0 to stop\n";cin>>d;
if(!d)break;}
i=l;
sort(t,0,l);
maketree(t,l);
leaf(t[l-1],csa,0);
l=i;
ofstream fout("code.txt");
print(t[l-1],fout);

}
