#include<iostream>
using namespace std;
struct bnode
{int data;
bnode * lchild;
bnode *rchild;
bnode(){}
bnode(int t)
{data=t;lchild=NULL;rchild=NULL;}
}*root;

void create(bnode *&t,int k)
{
	if(!t)
		t=new bnode(k);
	else if(k>t->data)
		create(t->rchild,k);
	else
		create(t->lchild,k);
}

bnode *conv(bnode *t,bnode **tt)
{
	bnode *left=NULL,*right=NULL,*ltail=NULL,*rtail=NULL;
	if(!t)
	{
		ltail=NULL;
		return NULL;
	}
	left=conv(t->lchild,&ltail);
	right=conv(t->rchild,&rtail);
	if(!right)ltail=t;
	else
	{
		right->lchild=t;
		ltail=rtail;
	}
	if (!left)return t;
	else 
	{
		ltail->rchild=t;
		return left;
	}
}

void pre(bnode* t)
{
	bnode *node=conv(t,NULL);
	while(node->lchild)
		node=node->lchild;
	while(node)
	{
		cout<<node->data<<" ";
		node=node->rchild;
	}
}
int main()
{
	int d;root=NULL;
	cin>>d;
	while(d!=-1)
		{create(root,d);cin>>d;}
	pre(root);
	return 0;
}
