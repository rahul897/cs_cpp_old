#include<iostream>
using namespace std;
struct dnode
{
dnode *left;
int data;
dnode *right;
dnode(int x){data=x;left=NULL;right=NULL;}
};


int palin(dnode *d1,dnode *d2)
{if(d1!=NULL&&d2!=NULL)
{if(d1!=d2)
{if(d1->data==d2->data)
return 1&&palin(d1->right,d2->left);}
else return 1;}
}

int main()
{dnode *d1,*d2,*t;int x;
cout<<"Enter elx\n";
cin>>x;
t=new dnode(x);
d2=t;d1=d2;cin>>x;
while(x!=-1)
{t=new dnode(x);
d2->right=t;
d2=t;
cin>>x;}

if(palin(d1,d2)==1)
cout<<"yes palin\n";
else cout<<"no palin";

}
