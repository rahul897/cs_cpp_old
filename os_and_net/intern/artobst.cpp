#include<iostream>
using namespace std;
struct bnode
{int data;
bnode * lchild;
bnode *rchild;
bnode(int t)
{data=t;lchild=NULL;rchild=NULL;}
};
int a[]={1,2,3,4,5,6,7,8,9};
bnode* bulidBst(int left,int right)
{
	bnode* node;
	int mid;
	if(left>right)return NULL;
	if(left==right)node =new bnode(a[left]);
	else
	{
		mid=(left+right)/2;
		node=new bnode(a[mid]);
		node->lchild=bulidBst(left,mid-1);
		node->rchild=bulidBst(mid+1,right);
	}
	return node;
}
void pre(bnode* t)
{
	if(t)
	{
		pre(t->lchild);
		cout<<t->data<<" ";
		pre(t->rchild);
	}
}
int main()
{
	pre(bulidBst(0,8));
	return 0;
}
