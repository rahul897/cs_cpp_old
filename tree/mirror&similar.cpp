#include<iostream>
#include<fstream>
using namespace std;
struct tnode
{char data;
tnode* r;
tnode* l;};
void insert(tnode* &t,char d)
{if(t==NULL)
{t=new tnode;t->data=d;t->l=NULL;t->r=NULL;}
else
{char c;
cout<<"to right of "<<t->data<<" enter r\n";
cout<<"to left of "<<t->data<<" enter l\n";
cin>>c;
if(c=='r')insert(t->r,d);
else if(c=='l')insert(t->l,d);
else return;}
}
void print(tnode *t)
{if(t!=NULL)
{print(t->l);
cout<<t->data;
print(t->r);}}

int mirror(tnode*&t,tnode*&y)
{if(t->data==y->data)return 1;
return mirror(t->lchild,y->rchild)&&mirror(t->rchild,t->lchild);
}

int similar(tnode *&t,tnode *&y)
{if(t->data==y->data)return 1;
return similar(t->lchild,y->lchild)&&similar(t->rchild,y->rchild);
}

int main()
{tnode *t=NULL;char c;
cout<<"enter chars \n enter $ to close\n";
cin>>c;
while(c!='*')
{insert(t,c);cin>>c;}
print(t);
}
