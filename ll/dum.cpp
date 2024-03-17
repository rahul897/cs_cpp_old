#include<iostream>
using namespace std;
struct node
{int data;
node *next;
node(int k){data=k;next=NULL;}
};

void add(node *&l,int d)
{if(l==NULL)
l=new node(d);
else add(l->next,d);
}

int main()
{node *l=NULL;int d;
cout<<"enter el\n";
cin>>d;
while(d!=-1)
{add(l,d);
cin>>d;}
while(l!=NULL)
{cout<<l->data<<" ";
l=l->next;}
}
