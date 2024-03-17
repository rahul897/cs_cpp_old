#include<iostream>
using namespace std;
struct node
{int in;
node *next;
};
void create(node *d,node *s,int n)
{if(d==NULL)
{node *t=new node;
t->in=n;t->next=NULL;d=t;d=s;}
else
{node *t=new node;
t->in=n;t->next=NULL;d->next=t;}
}
void display(node *s)
{node *t=s;
while(t!=NULL)
{cout<<t->in;
t=t->next;}}
int main()
{node *d,*s,*d1,*s1;int n=0;
cout<<"first num \nenter -1 t0 end num";
while(n!=-1)
{cin>>n;
if(n==-1)break;
create(d,s,n);}
display(s);
cout<<endl;
cout<<"sec num \nenter -1 t0 end num";
while(n!=-1)
{cin>>n;
if(n==-1)break;
create(d1,s1,n);}
display(s1);
cout<<endl;
}
