#include<iostream>
using namespace std;
struct tnode
{int data[4];
tnode* child[5];
tnode(){for(int i=0;i<5;i++)child[i]=NULL;}
};

void search(tnode*&t,int k=0)
{if(t==NULL)
{cout<<"jadasd\n";return;}
else
for(int i=0;i<4;i++)
if(t->data[i]==k)
{cout<<"jada\n";return;}

for(int i=0;i<5;i++)
if(i<4)
if(t->data[i]>k)
{search(t->child[i],k);break;}
else
{search(t->child[i],k);break;}
}

void insort(int a[],int k,int l)
{int i=0;
while(1)
{if(a[i]==-1){a[i]=k;break;}
else if(a[i]<k)i++;
else 
{int t;
for(t=l-1;t!=i;t--)
a[t]=a[t-1];
a[t]=k;break;}}
}

int main()
{tnode *t=new tnode;
t->data[0]=2;
t->data[1]=5;
t->data[2]=7;
t->data[3]=9;
t->child[0]=new tnode;
t->child[0]->data[0]=-1;
t->child[0]->data[1]=0;
t->child[0]->data[2]=1;
search(t,-1);


}
