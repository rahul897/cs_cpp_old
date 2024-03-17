#include<iostream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
int l;
};
int create(tnode *&t,int k,int &i)
{if(t==NULL)
{t=new tnode;t->data=k;t->l=i;t->lchild=NULL;t->rchild=NULL;}
else if(k<t->data)
{i=i+1;create(t->lchild,k,i);}
else if(k>t->data)
{i++;create(t->rchild,k,i);}
return i;
}

int getar(tnode *&t,int a[],int b[],int &k)
{if(t!=NULL)
{a[k]=t->data;b[k++]=t->l;
getar(t->lchild,a,b,k);
getar(t->rchild,a,b,k);}
return k;
}

int main()
{tnode *t=NULL;int n=0,i,j,x=0,m=0;
cout<<"enter the els\n enter -1 to stop\n";
cin>>n;
while(n!=-1)
{i=0;x=create(t,n,i);if(x>m)m=x;cin>>n;}
cout<<endl;
int *a=new int[30],*b=new int[30],k=0,sp=10;
k=getar(t,a,b,k);
for(i=0;i<m;i++,sp-=i)
{for(int l=0;l<sp;l++)cout<<" ";
for(j=0;j<k;j++)
if(b[j]==i)
cout<<a[j]<<" ";
cout<<endl;
for(int l=0;l<sp-1;l++)cout<<" ";}
}

