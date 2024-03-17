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
return k2>k3;}
}

void insert(tnode* &t,char a[],char d)
{if(t==NULL)
{t=new tnode(d);}
else
{if(in(a,d,t->data))
insert(t->l,a,d);
else 
insert(t->r,a,d);
}}


void print(tnode *t)
{if(t!=NULL)
{
print(t->l);
print(t->r);
cout<<t->data;}}


int main()
{char c[30],d[30],ch;int i,j,l,z=0;
tnode *t=NULL;
cout<<"enter inorder \n";
cin>>c;
cout<<"enter postorder \n";
cin>>d;for(l=0;d[l]!='\0';l++);
for(i=l-1;i>=0;i--)
insert(t,c,d[i]);
print(t);
}
