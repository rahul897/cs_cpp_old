#include<iostream>
using namespace std;
struct node
{int data;
node *next;
};
class l
{node *ll;
public:
	node *s;
	l(){s=NULL;ll=NULL;	}
	
	
	void input()
	{ll =new node;s=ll;int d;
	cout<<"start entering data\nenter -1 to close\n";
	while(1)
	{cin>>d;
	if(d!=-1)
	{ll->data=d;
	ll->next=new node;
	ll=ll->next;}
	else
	{ll->next=NULL;
	break;
	}}}


	void output()
	{ll=s;
	if(ll==NULL)
	{cout<<"empty list\n";}
	else
	while(ll->next!=NULL)
	{
		cout<<ll->data<<endl;
       ll=ll->next;
	}}
	
	
	void addbegin()
	{ll=s;
	node *t=new node;
	cout<<"enter el\n";
	cin>>t->data;
	if(ll==NULL)
	{ll=t;
	t->next=NULL;
	s=ll;}
	else 
	{s=t;
	t->next=ll;}}
	
	
	void addend()
	{ll=s;
	node *t=new node;
	cout<<"enter el\n";
	cin>>t->data;
	if(ll==NULL)
	{ll=t;
	t->next=NULL;
	s=ll;}
	else 
	{while(ll->next!=NULL)
	{ll=ll->next;}
	ll=t;
	t->next=NULL;}}	
	
	
	void addafter()
	{ll=s;node *t=new node;int d,f=1;
	cout<<"enter no. in node\n";cin>>d;
	cout<<"enter el\n";cin>>t->data;
	while(ll->next!=NULL)
	{if(ll->data==d)
	{t->next=ll->next;
	ll->next=t;
	f=0;break;}
	ll=ll->next;}
	
	if(f)cout<<"key not found\n";
	}	
	
	
	void addbefore()
	{ll=s;node *y,*t=new node;int d,f=1;
	cout<<"enter no. in node\n";cin>>d;
	cout<<"enter el\n";cin>>t->data;
	while(ll->next!=NULL)
	{if(ll->data==d)
	{t->next=y->next;
	y->next=t;f=0;break;}
	y=ll;ll=ll->next;}
	
	if(f)cout<<"key not found\n";
	}
	
	
void sort()
{node *i,*j;int t;
for(i=s;i->next!=NULL;i=i->next)
for(j=s;j->next!=NULL;j=j->next)
if(i->data > j->data)
{t=i->data;
i->data=j->data;
j->data=t;}
}
	
};
int main()
{l l1;int i,l=1;

while(l)
{cout<<"1.input\n2.display\n3.addbegin\n4.addend\n5.addafter\n6.addbefore\n7.sort\n8.exit  :";cin>>i;
switch(i)
{case 1:l1.input();break;
case 2:l1.output();break;
case 3:l1.addbegin();break;
case 4:l1.addend();break;
case 5:l1.addafter();break;
case 6:l1.addbefore();break;
case 7:l1.sort();break;
case 8:l=0;break;}
}
}
