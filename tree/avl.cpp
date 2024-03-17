#include<iostream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
tnode(int x){data=x;lchild=NULL;rchild=NULL;}
};

int height(tnode *t)
{if(t==NULL)return -1;
else
{int a=height(t->lchild);
int b=height(t->rchild);
return a>b?a+1:b+1;}
}

void rol(tnode *&k1)
{tnode *k2=k1->lchild;
k1->lchild=k2->rchild;
k2->rchild=k1;
k1=k2;}

void ror(tnode *&k1)
{tnode *k2=k1->rchild;
k1->rchild=k2->lchild;
k2->lchild=k1;
k1=k2;}

void drol(tnode *&k1)
{ror(k1->rchild);
rol(k1);}

void dror(tnode *&k1)
{rol(k1->rchild);
ror(k1);}

void create(tnode *&t,int k)
{if(t==NULL)
t=new tnode(k);
else if(k<t->data)
{create(t->lchild,k);
if(height(t->lchild)-height(t->rchild)>1)
if(k<t->lchild->data)
rol(t);
else drol(t);}
else if(k>t->data)
{create(t->rchild,k);
if(height(t->rchild)-height(t->lchild)>1)
if(k>t->rchild->data)
ror(t);
else dror(t);}}

void print(tnode *t)
{if(t!=NULL)
{cout<<t->data<<" ";
print(t->lchild);
print(t->rchild);}
}

void bal(tnode *&t)
{if(t!=NULL)
{if(height(t->lchild)+2==height(t->rchild))
{tnode *k1=t->rchild,*k2=k1->rchild;
if(k2&&k1->data<k2->data)
ror(t);
else dror(t);}
else if(height(t->rchild)+2==height(t->lchild))
{tnode *k1=t->lchild,*k2=k1->lchild;
if(k2&&k1->data<k2->data)
rol(t);
else drol(t);}}
}

tnode* maax(tnode *t)
{if(t->rchild==NULL)return t;
return maax(t->rchild);}

void del(tnode *&t,int &k)
{if(t==NULL)return;
else if(t->data>k)del(t->lchild,k);
else if(t->data<k)del(t->rchild,k);
else if(t->lchild!=NULL&&t->rchild!=NULL)
{t->data=maax(t->lchild)->data;

del(t->rchild,t->data);
if(height(t->lchild)-height(t->rchild)>1)
if(k<t->lchild->data)
rol(t);
else drol(t);
else 
if(k>t->rchild->data)
ror(t);
else dror(t);}
else
{tnode *m=t;
if(t->rchild!=NULL)
t=t->rchild;
else t=t->lchild;
delete m;}
bal(t);
}


int main()
{tnode *t=NULL;
int x;
cout<<"Enter els\n";
cin>>x;
while(x!=-1)
{create(t,x);
cin>>x;}

print (t);
cout<<"enter el to delete\n";
cin>>x;
del(t,x);
print (t);
}
