#include<iostream>
using namespace std;
struct node
{int v;
int w;
node *next;
node(int x,int y){v=x;w=y;next=NULL;}};

struct ver
{int x;
node *al;
ver(){x=-1;al=NULL;}
};

void ab(node *&t,node *&s,int x,int w)
{if(t==s)
{node *k=new node(x,w);
k->next=t;
s=k;}
else 
{node *l=s;
while(l->next->v!=t->v)
l=l->next;
node *k=new node(x,w);
k->next=l->next;
l->next=k;}
}

void ris(node *&t,node *&s,int x,int w)
{if(t==NULL)
{node *k=new node(x,w);t=k;if(s==NULL)s=t;}
else if(t->v<x)
ris(t->next,s,x,w);
else
{ab(t,s,x,w);t=s;}}



int main()
{ver *v;node *t;
int n,i=0,k,w,x=0;
cout<<"enter no.of vertices\n";
cin>>n;
v=new ver[n];
while(i<n)
{cout<<"enter vertex \n";cin>>v[i].x;t=NULL;x=0;
while(x!=-1)
{cout<<"enter adjacent to "<<v[i].x<<"\n";cin>>x;if(x==-1)break;
cout<<"enter weight of "<<x<<" & "<<v[i].x<<"\n";cin>>w;
ris(v[i].al,t,x,w);}i++;}

for(i=0;i<n;i++)
{cout<<v[i].x<<"\n";t=v[i].al;
while(t!=NULL)
{cout<<t->v<<"$"<<t->w<<" ";
t=t->next;}cout<<endl;}	
}
