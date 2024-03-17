#include<iostream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
tnode(int x){data=x;lchild=NULL;rchild=NULL;}
};

void insert(tnode *&t,tnode *&k)
{tnode *y=NULL,*x;char ch;
if(t!=NULL)
{x=t;
while(x!=NULL)
{y=x;cout<<"enter l to insert at "<<x->data<<" left\nenter r to insert at right\n";
cin>>ch;
if(ch=='l')
x=x->lchild;
else if(ch=='r')
x=x->rchild;}
if(ch=='l')y->lchild=k;
else y->rchild=k;}
else t=k;
}

void display(tnode *&t)
{if(t!=NULL)
{cout<<t->data<<" ";
display(t->lchild);
display(t->rchild);
}
}


int main()
{tnode *t=NULL;int x;
cout<<"enter els\n";
cin>>x;
while(x!=-1)
{tnode *k=new tnode(x);
insert(t,k);
cout<<"enter another number\n";
cin>>x;}

display(t);
}
