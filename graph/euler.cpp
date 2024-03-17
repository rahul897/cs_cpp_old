#include<iostream>
using namespace std;
struct node
{int data;
node *next;
node(int k){data=k;next=NULL;}
};
void aa(node *&l,node *&s,int x)
{if(s==NULL)
{node *k=new node(x);
l=k;s=l;}
else
{node *k=new node(x);
k->next=l->next;
l->next=k;
l=k;}}

int edge(int **a,int v)
{int c=0;
for(int i=0;i<v;i++)
for(int j=0;j<v;j++)
if(a[i][j]==0)c++;
return c;}

int deg(int **a,int v,int d)
{int c;
for(int i=0;i<v;i++)
if(a[d][i]>0)c++;
return c;
}

void cal(int **a,int v,node *&l,node *&s,int so)
{if(edge(a,v))
{int so1=so;
for(int i=0;i<v;i++)
if(a[so][i]>0){a[so][i]=0;a[i][so]=0;aa(l,s,so);so=i;break;}
while(so!=so1)
{for(int i=0;i<v;i++)
if(a[so][i]>0){a[so][i]=0;a[i][so]=0;aa(l,s,so);so=i;break;}}
if(so==so1)
{aa(l,s,so);node *t,*k=NULL;int ki=-1,ti;
for(t=s;t!=NULL;t=t->next)
{ti=deg(a,v,t->data);
if(ti>0&&ti>ki){ki=ti;k=t;}}
if(k)cal(a,v,k,s,k->data);}
}}

int main()
{
	int **a,i,j,v,n,w=1,k;node *l=NULL,*s=NULL;
	cout<<"enter no of vertices\n";cin>>v;
	a=new int*[v];
	for(i=0;i<v;i++)
	a[i]=new int[v];
	for(i=0;i<v;i++)
	for(j=0;j<v;j++)
	a[i][j]=0;
	for(i=0;i<v;i++)
	{for(j=0;j<v;j++)
		{cout<<"enter weight of edge <"<<i+1<<","<<j+1<<"> ";
		cin>>a[i][j];
		}
	}
	for(i=0;i<v;i++)
	{for(j=0;j<v;j++)
	cout<<a[i][j]<<" ";
	cout<<endl;}
	cout<<"enter starting point\n";cin>>w;
	cal(a,v,l,s,w-1);
	l=s;
	while(l)
	{cout<<l->data+1<<" ";
	l=l->next;
	}	
}
