#include<iostream>
using namespace std;
struct node
{int data;
node *next;}*s1,*s2,*m1;

node* input(node *l)
{node *s;l=new node;s=l;int d;
cout<<"start entering data\nenter -1 to close\n";
	while(1)
	{cin>>d;
	if(d!=-1)
	{l->data=d;
	l->next=new node;
	l=l->next;}
	else
	{l->next=NULL;
	break;
	}}
return s;}

void display(node *l,node *s)
{l=s;
if(l==NULL)
	{cout<<"empty list\n";}
	else
	while(l->next!=NULL)
	{
	cout<<l->data<<" ";
    l=l->next;
	}
	cout<<endl;
}


void inter(node *l1,node *l2)
{node *i,*j;
for(i=l1;i->next!=NULL;i=i->next)
for(j=l2;j->next!=NULL;j=j->next)
if(i->data == j->data)
cout<<i->data<<" ";
	
}

node* merge(node *l1,node *l2,node *t)
{node *i;t=new node;t=m1;
for(i=l1;i!=NULL;i=i->next)
{t->data=i->data;cout<<i->data;t->next=new node;t=t->next;}
for(i=l2;i!=NULL;i=i->next)
{t->data=i->data;t->next=new node;t=t->next;}t=NULL;
return t;

}

void uni(node *l1,node *l2)
{
  cout<<endl;
  node *h;
  h=l1;

  while(l1->next!=NULL)
  {
    cout<<l1->data<<" ";
    l1=l1->next;
  }
 int f=1;
  while(l2->next!=NULL)
  {
     l1=h;
     f=1;
     while(l1->next!=NULL)
     {
      if(l1->data==l2->data)
      {
       f=0;
       break;
      }
      l1=l1->next;
     }
     if(f)
     {
       cout<<l2->data<<" ";
     }
     l2=l2->next;
  }
}



int main()
{node *l1,*l2,*m;
s1=input(l1);
s2=input(l2);
l1=s1;l2=s2;

uni(l1,l2);
l1=s1;l2=s2;cout<<endl<<endl;
inter(l1,l2);
l1=s1;l2=s2;cout<<endl<<endl;
m1=merge(l1,l2,m);
display(m,m1);
	
}
