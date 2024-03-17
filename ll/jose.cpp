#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
int main()
{
	int n,j,i,k;
	node *l,*t,*s;
	cout<<"\n Enter the no. of nodes";
	cin>>n;
	cout<<"\n Enter skipping no.";
	cin>>k;
	l=new node;
	l->data=1;
	l->next=NULL;
	s=l;
	for(i=1;i<n;i++)
	{t=new node;
	t->data=i+1;
	t->next=NULL;
	l->next=t;
	l=t;}
	l->next=s;
	l=s;
	for(i=0;i<n;i++)
	{
		for(j=1;j<k-1;j++)
		{
			l=l->next;
		}cout<<l->next->data<<" ";
		l->next=l->next->next;
		l=l->next;}
		cout<<"\n last node is"<<l->data;
		return 0;
}
