#include<iostream>
using namespace std;
struct node
{int data;
node * next;
node(int x){data=x;next=NULL;}
};
void ab(node *&t,node *&s,int x)
{if(t==s)
{node *k=new node(x);
k->next=t;s=k;}
else 
{node *l=s;
while(l->next->data!=t->data)
l=l->next;
node *k=new node(x);
k->next=l->next;l->next=k;}
}

void ae(node *&t,node *&s,int x)
{node *l=s;
while(l->data!=t->data)
l=l->next;
node *k=new node(x);
k->next=l->next;
l->next=k;
}

void aa(node *&t,int x)
{if(t==NULL)t=new node(x);
else aa(t->next,x);}

void ins(node *&s,node *&ss,int x)
{if(s==NULL)
{s=new node(x);ss=s;}
else if(s->data>x)
ab(s,ss,x);
else if(s->data<x)
ae(s,ss,x);
}

void ris(node *&t,node *&s,node *&ss)
{if(t!=NULL)
{ins(s,ss,t->data);
ris(t->next,s,ss);
}
}

int main()
{node *l=NULL,*s=NULL,*ss;int x;
cout<<"Enter els\n";
cin>>x;
while(x!=-1)
{aa(l,x);cin>>x;}
ris(l,s,ss);
s=ss;
while(s!=NULL)
{cout<<s->data;s=s->next;}
}
