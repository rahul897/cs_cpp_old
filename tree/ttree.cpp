#include<iostream>
using namespace std;
struct tnode
{int data[2];
tnode* child[3];
tnode(){data[1]=-1;data[0]=-1;for(int i=0;i<3;i++)child[i]=NULL;}
};
void insert(tnode *&t,int x)
{if(t==NULL)
{t=new tnode;t->data[0]=x;}
else if(t->data[0]<x)
insert(t->child[0],x);
else if(t->data[0]>x&&t->data[1]==-1)
{if(t->data[0]<x)t->data[1]=x;
else {t->data[1]=t->data[1];t->data[0]=x;}}
else if(t->data[0]>x&&t->data[1]<x)
insert(t->child[1],x);
else if(t->data[1]<x)
insert(t->child[3],x);


}
void display(tnode *t)
{
	if(t!=NULL)
	{
	display(t->child[0]);
	cout<<t->data[0]<<" ";
	display(t->child[1]);
	if(t->data[1]!=-1)
	cout<<t->data[1]<<" ";
	display(t->child[2]);
    }
}

void serpg(tnode *&t,int k,int i=0)
{if(i<3)
{if(t->data[i]<k)
{i=0;serpg(t->child[i+1],k,i);}
else if(t->data[0]>k)
{i=0;serpg(t->child[0],k,i);}
else if(t->data[0]==k)
cout<<"Jaffa\n";
else serpg(t,k,i++);	
}	
}

int main()
{tnode *t=NULL;int x;
cout<<"enter els\nenter -1 to stop\n";
cin>>x;
while(x!=-1)
{insert(t,x);cin>>x;}
display(t);
cout<<"enter el to search\n";
cin>>x;
serpg(t,x);
}
