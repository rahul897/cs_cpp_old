#include<iostream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
tnode(int x){data=x;lchild=NULL;rchild=NULL;}
};

void create(tnode *&t,int a[],int &i,int &l,int h,int k)
{if(k<=h)
{if(t==NULL&&k==h&&i<l)
{t=new tnode(a[i++]);}
else
{if(t==NULL)t=new tnode(-1);
create(t->lchild,a,i,l,h,k+1);
create(t->rchild,a,i,l,h,k+1);}
}}

int winner(tnode *&t)
{if(t->lchild==NULL&&t->rchild==NULL)
return t->data;
int a=winner(t->lchild),b=winner(t->rchild);
return a>b?a:b;}

void rep(tnode *&t,int r,int h,int k)
{if(k<=h)
{if(k==h&&t->data==r)
{t->data=-1;return;}
else
{rep(t->lchild,r,h,k+1);
rep(t->rchild,r,h,k+1);}}}

void sort(tnode *&t,int a[],int h)
{int i=0;
while(winner(t)!=-1)
{a[i++]=winner(t);
rep(t,winner(t),h,0);}}

int main()
{tnode *t=NULL;
int a[10],i,n,k,h;
cout<<"enter no.of els\n";
cin>>n;k=n;
for(h=0;n!=0;h++)n=n/2;
cout<<"\nenter els\n";
for(i=0;i<k;i++)cin>>a[i];
i=0;
create(t,a,i,k,h,0);
sort(t,a,h);
for(i=0;i<k;i++)
cout<<a[i];
}
