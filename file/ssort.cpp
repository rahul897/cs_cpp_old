#include<iostream>
#include<fstream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
tnode(int x){data=x;lchild=NULL;rchild=NULL;}
};

void create(tnode *&t,int a[],int &i,int &l,int h,int k)
{if(k<=h)
{if(t==NULL&&k==h&&i<l)
{t=new tnode(a[i++]);}
else
{if(t==NULL)t=new tnode(-1);
create(t->lchild,a,i,l,h,k+1);
create(t->rchild,a,i,l,h,k+1);}
}}

int winner(tnode *&t)
{if(t->lchild==NULL&&t->rchild==NULL)
return t->data;
int a=winner(t->lchild),b=winner(t->rchild);
return a<b?a:b;}

void rep(tnode *&t,int r,int h,int k,int j)
{if(k<=h)
{if(k==h&&t->data==r)
{t->data=j;return;}
else
{rep(t->lchild,r,h,k+1,j);
rep(t->rchild,r,h,k+1,j);}}}

void frep(tnode *&t,int r,int h,int k)
{if(k<=h)
{if(k==h&&t->data==r)
{t->data+=1000;return;}
else
{frep(t->lchild,r,h,k+1);
frep(t->rchild,r,h,k+1);}}}

void remf(tnode *&t,int h,int k)
{if(k<=h)
{if(k==h){t->data-=1000;}
else
{remf(t->lchild,h,k+1);
remf(t->rchild,h,k+1);}
}}


int main()
{tnode *t=NULL;int a[4],i,z=-1,x,y,l=4,h=2;
ifstream fin;fin.open("data.txt");
ofstream a1,a2;a1.open("A1.txt");a2.open("A2.txt");
x=fin.tellg();
fin.seekg(0,ios::end);
y=fin.tellg();
l=y-x;cout<<l;
fin.seekg(0,ios::beg);
for(i=0;i<4;i++)fin>>a[i];i=0;
create(t,a,i,l,h,0);
while(!fin.eof())
{A1:
	while(1)
	{x=winner(t);
	if(z<x&&x<1000){a1<<x<<" ";fin>>y;z=x;rep(t,x,2,0,y);}
	else if(x>=1000){remf(t,2,0);a1<<-1<<" ";z=-1;break;}
	else frep(t,x,2,0);
	}
A2:
	while(1)
	{x=winner(t);
	if(z<x&&x<1000){a2<<x<<" ";fin>>y;z=x;rep(t,x,2,0,y);}
	else if(x>=1000){remf(t,2,0);a2<<-1<<" ";z=-1;break;}
	else frep(t,x,2,0);
	}
}

fin.close();a1.close();a2.close();

while(1)
{{ifstream a1;a1.open("A1.txt");
x=a1.tellg();a1.seekg(0,ios::end);y=a1.tellg();
if(y-x>l+1){cout<<"a1";a1.close();break;}
a1.close();
ifstream a2;a2.open("A2.txt");
x=a2.tellg();a2.seekg(0,ios::end);y=a2.tellg();
if(y-x>l+1){cout<<"a2";a2.close();break;}
a2.close();
ifstream b1;b1.open("B1.txt");
x=b1.tellg();b1.seekg(0,ios::end);y=b1.tellg();
if(y-x>l+1){cout<<"b1";b1.close();break;}
b1.close();
ifstream b2;b2.open("B2.txt");
x=b2.tellg();b2.seekg(0,ios::end);y=b2.tellg();
if(y-x>l+1){cout<<"b2";b2.close();break;}
b2.close();}

AB:
	{ifstream a1,a2;a1.open("A1.txt");a2.open("A2.txt");
	ofstream b1,b2;b1.open("B1.txt");b2.open("B2.txt");
	a1>>x;a2>>y;
	while(!a1.eof()||!a2.eof())
	{B1:
		while(1)
		{if(x==-1&&y==-1){b1<<-1<<" ";a1>>x;a2>>y;break;}
		if(x==-1){b1<<y<<" ";a2>>y;}
		else if(y==-1){b1<<x<<" ";a1>>x;}
		else if(x<y){b1<<x<<" ";a1>>x;}
		else {b1<<y<<" ";a2>>y;}}
	B2:
		while(1)
		{if(x==-1&&y==-1){b2<<-1<<" ";a1>>x;a2>>y;break;}
		if(x==-1){b2<<y<<" ";a2>>y;}
		else if(y==-1){b2<<x<<" ";a1>>x;}
		else if(x<y){b2<<x<<" ";a1>>x;}
		else {b2<<y<<" ";a2>>y;}}	
	}a1.close();a2.close();b1.close();b2.close();}
BA:
	{ifstream b1,b2;b1.open("B1.txt");b2.open("B2.txt");
	ofstream a1,a2;a1.open("A1.txt");a2.open("A2.txt");
	b1>>x;b2>>y;
	while(!b1.eof()||!b2.eof())
	{A21:
		while(1)
		{if(x==-1&&y==-1){a1<<-1<<" ";b1>>x;b2>>y;break;}
		if(x==-1){a1<<y<<" ";b2>>y;}
		else if(y==-1){a1<<x<<" ";b1>>x;}
		else if(x<y){a1<<x<<" ";b1>>x;}
		else {a1<<y<<" ";b2>>y;}}
	A22:
		while(1)
		{if(x==-1&&y==-1){a2<<-1<<" ";b1>>x;b2>>y;break;}
		if(x==-1){a2<<y<<" ";b2>>y;}
		else if(y==-1){a2<<x<<" ";b1>>x;}
		else if(x<y){a2<<x<<" ";b1>>x;}
		else {a2<<y<<" ";b2>>y;}}	
	}a1.close();a2.close();b1.close();b2.close();}
}

}
