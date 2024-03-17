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
k->next=t;
s=k;}
else 
{node *l=s;
while(l->next->data!=t->data)
l=l->next;
node *k=new node(x);
k->next=l->next;
l->next=k;}
}

void aa(node *&t,int x)
{if(t==NULL)t=new node(x);
else aa(t->next,x);}


void ris(node *&t,node *&s,int x)
{if(t==NULL)
{node *k=new node(x);t=k;}
else if(t->data<x)
ris(t->next,s,x);
else
ab(t,s,x);
}


int main()
{node *l=NULL,*s=NULL,*ss;int x;
cout<<"Enter els\n";
cin>>x;l=new node(x);s=l;cin>>x;
while(x!=-1)
{l=s;ris(l,s,x);cin>>x;}

while(s!=NULL)
{cout<<s->data;
s=s->next;
}

}
