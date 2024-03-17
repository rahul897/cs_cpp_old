#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node(int k)
	{data=k;next=NULL;}
};

void add(node* &l,int d)
{if(l==NULL)
l=new node(d);
else add(l->next,d);}

int main()
{
	int n,j,i,k;
	node *l=NULL,*s,*t;
	cout<<"\n Enter the no. of nodes";
	cin>>n;
	cout<<"\n Enter skipping no.";
	cin>>k;
	for(i=1;i<n;i++)
	add(l,i);
	t=l;
	while(t!=NULL)
	{t=t->next;
	if(t==NULL)t=l;}
	t=l;
	while(t->next!=l)
	{cout<<t->data;
	t=t->next;
	}
	
}
