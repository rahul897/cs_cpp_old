#include<iostream>
#include<fstream>
using namespace std;
struct tnode
{char data;
tnode* r;
tnode* l;
tnode(char a){data=a;r=NULL;l=NULL;}
};


int in(char a[],char k,char k1)
{int l,k2,k3;for(l=0;a[l]!='\0';l++);
for(int i=0;i<l;i++)
{if(a[i]==k)k2=k;
if(a[i]==k1)k3=k1;
return k2<k3;}
}

void insert(tnode* &t,char a[],char d)
{if(t==NULL)
{t=new tnode(d);}
else
{if(in(a,d,t->data))
insert(t->r,a,d);
else 
insert(t->l,a,d);
}}



/*tnode* tree(char c[],char d[],tnode* &t,tnode* &l,stack &s,int n)
{int i=0;t=new tnode(d[i++]);l=t;s.push(t);
while(1&&i<n)
{t=s.pop();tnode *p=t;
if(in(c,t->data,n)>in(c,d[i],n))
{t->l=new tnode(d[i++]);t=t->l;s.push(t);}
if(in(c,t->data,n)<in(c,d[i],n))
{p->r=new tnode(d[i++]);p=p->l;s.push(p);}}
return l;
}*/

void print(tnode *t)
{if(t!=NULL)
{
print(t->l);
print(t->r);
cout<<t->data;
}}


int main()
{char c[30],d[30],ch;int i,j,l,z=0;
tnode *t=NULL;
cout<<"enter inorder \n";
cin>>c;
cout<<"enter preorder \n";
cin>>d;for(l=0;d[l]!='\0';l++);
for(i=0;i<l;i++)
insert(t,c,d[i]);
print(t);
}
