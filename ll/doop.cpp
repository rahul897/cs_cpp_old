#include<iostream>
using namespace std;
struct dnode
{
dnode *left;
int data;
dnode *right;
};
void addbegin(dnode* &d, int x)
{
d->left=new(dnode);
d->left->right=d;
d=d->left;
d->data=x;
d->left=NULL;
}
void addend(dnode *d, int x)
{
while(d->right!=NULL)
d=d->right;
d->right=new(dnode);
d->right->left=d;
d=d->right;
d->data=x;
d->right=NULL;
}
void addbefore(dnode *d,int x,int y)
{
while(d->data!=y)
d=d->right;
dnode *t=new(dnode);
t->data=x;
t->right=d;
t->left=t->right->left;
if(t->left!=NULL)
t->left->right=t;
t->right->left=t;
}
void addafter(dnode *d,int y,int x)
{
while(d->data!=y)
d=d->right;
dnode *t=new(dnode);
t->data=x;
t->left=d;
t->right=t->left->right;
t->left->right=t;
if(t->right!=NULL)
t->right->left=t;
}
void del(dnode *d,int x)
{
while(d->data!=x)
d=d->right;
dnode *t=d;
t->left->right=t->right;
if(t->right!=NULL)
t->right->left=t->left;
t->right=NULL;
t->left=NULL;
}
void display(dnode *d)
{
if(d!=NULL)
    {
    cout<<d->data<<" ";
    display(d->right);
    }
}
int main()
{
dnode *d;
int x,ch;
cout<<"Enter first elt: ";
d=new(dnode);
cin>>x;
d->data=x;
d->right=NULL;
d->left=NULL;
cout<<"1.addend\n2.addbegin\n3.addbefore\n4.addafter\n5.delete\n6.display\n7.exit";
cout<<"\nEnter choice: ";
cin>>ch;
while(ch!=7)
{switch(ch){
case 1:cout<<"Enter no: ";
cin>>x;
addend(d,x);
case 2:
cout<<"Enter no: ";
cin>>x;
addbegin(d,x);
case 3:
cout<<"Enter no to add: ";
cin>>x;
cout<<"Before elt: ";
int y;
cin>>y;
addbefore(d,x,y);
case 4:
cout<<"Enter no to add: ";
cin>>x;
cout<<"dfter elt: ";
cin>>y;
addafter(d,y,x);
case 5:
cout<<"Enter elt: ";
cin>>x;
del(d,x);
case 6:
display(d);
cout<<endl;
default :
cout<<"Wrong choice!\n";
cout<<"enter choice: ";
cin>>ch;
}}
return 0;
}
