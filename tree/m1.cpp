#include<iostream>
using namespace std;
struct tnode
{char data[2];
tnode* child[3];
tnode(char x,char y){data[0]=x;data[1]=y;for(int i=0;i<3;i++)child[i]=NULL;}
};

void insert(tnode *&t,tnode *&k,int &i,int &j)
{if(t==NULL)
t=k;
else if(t->child[0]==NULL)
insert(t->child[0],k,i,j);
else if(t->child[1]==NULL)
insert(t->child[1],k,i,j);
else if(t->child[2]==NULL)
insert(t->child[2],k,i,j);
else 
{if(j==3){i++;j=0;}else j++;
insert(t->child[i],k,i,j);}
}

void display(tnode *t)
{
	if(t!=NULL)
	{
	display(t->child[0]);
	cout<<t->data[0];
	display(t->child[1]);
	cout<<t->data[1];
	display(t->child[2]);
    }
}

int main()
{tnode *t=NULL;
char k1,k2;int i=0,j=0;
cout<<"enter els\n";
cin>>k1>>k2;

while(k1!='$')
{tnode *k=new tnode(k1,k2);if(i==3)i=0;
insert(t,k,i,j);
cin>>k1;if(k1=='$')break;cin>>k2;}

display(t);
}
