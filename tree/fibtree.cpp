#include<iostream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
tnode(int x){data=x;lchild=NULL;rchild=NULL;}
};

int f(int n)
{if(n==1||n==0)return 1;
return f(n-1)+f(n-2);
}

tnode* fibtr(tnode *&t,int n,int i,int j)
{if(n==1||n==0)
{t=new tnode(1);return t;}
t=new tnode(n);
t->lchild=fibtr(t->lchild,i,j,i-j);
t->rchild=fibtr(t->rchild,j,j-i,2*j-i);
	
}

void printri(tnode *t)
{if(t!=NULL)
{cout<<t->data;
printri(t->lchild);
printri(t->rchild);}
}
int main()
{tnode *t=NULL;int n;
cout<<"enter ind of fibtree\n";
cin>>n;
fibtr(t,n,5,3);
printri(t);
}
