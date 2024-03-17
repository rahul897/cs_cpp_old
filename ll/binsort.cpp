#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

struct onode
{
	char c;
	node *in;
	onode *on;
};

void sort(node *s)
{node *i,*j;int k;
for(i=s;i!=NULL;i=i->next)
for(j=s;j!=NULL;j=j->next)
if(i->data < j->data)
{k=i->data;
i->data=j->data;
j->data=k;}}

int main()
{
	onode *o=new onode,*so;so=o;int d,i,j;char e[30],ch;
	cout<<"enter char and int\nenter $ to close\n";
	cin>>ch>>d;
	o->c=ch;o->in=new node;o->in->data=d;
	o->on=NULL;
	while(ch!='$')
	{cout<<"enter char and int\nenter $ to close\n";
	cin>>ch;if(ch=='$')break;cin>>d;
	onode *to=new onode;
	to->c=ch;
	to->in=new node;to->in->data=d;to->on=NULL;
	o->on=to;o=to;}
	
	onode *q,*w;d=0;
	for(q=so;q!=NULL;q=q->on)
	for(w=so;w!=NULL;w=w->on)
	if(q->c == w->c)
	{e[d++]=q->c;
	for(i=0;i<d;i++)
	{for(j=0;j<d;j++)
	if(i!=j&&e[i]==e[j])d--;}}	
	
	node *t[10],*s[10];
	for(i=0;i<d;i++)
	{t[i]=new node;s[i]=t[i];}
	
	for(i=0;i<d;i++)
	{for(q=so;q!=NULL;q=q->on)
	if(e[i] == q->c)
	{t[i]->data=q->in->data;
	if(q->on!=NULL)
	{t[i]->next=new node;
	t[i]=t[i]->next;}
	else t[i]->next=NULL;}
	t[i]->next=NULL;}

	onode *m=new onode;so=m;
	for(i=0;i<d;i++)
	{m->c=e[i];sort(s[i]);m->in=s[i];if(i!=d-1){m->on=new onode;m=m->on;}
	else m->on=NULL;}
	
	m=so;i=0;
	while(m!=NULL)
	{cout<<m->c<<" ";
	m->in=s[i++];
	while(m->in!=NULL)
	{cout<<m->in->data<<" ";
	m->in=m->in->next;}
	cout<<endl;
	m=m->on;}
}
