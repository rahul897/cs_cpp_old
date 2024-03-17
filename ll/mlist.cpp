#include<iostream>
using namespace std;
struct mnode
{union md
{int in;
mnode *m;}dm;
int tag;
mnode *next;
};

void display(mnode *s[],int z,int i=0)
{if(i<z)
{cout<<"(";
while(s[i]!=NULL)
{if(s[i]->tag==1)cout<<s[i]->dm.in;
else display(s,z,i+1);
s[i]=s[i]->next;}
cout<<")";
}
}
int main()
{char c[30];int i,l,k=0,z=0;
cin>>c;mnode *p,*s[10],*t[10];
p=new mnode;s[z++]=p;
for(l=0;c[l]!='\0';l++);
for(i=1;i<l-1;i++)
{if(c[i]==40)
{p->tag=2;
p->dm.m=new mnode;s[z++]=p;
p=p->dm.m;
p->next=NULL;k++;}

if(c[i]<'9'&&c[i]>'0')
{p->tag=1;
p->dm.in=c[i]-48;
if(c[i+1]!=41)
{p->next=new mnode;
p=p->next;t[k]=p;p->next=NULL;}}

if(c[i]==41)
{if(k>0)
{p=t[--k];
if(c[i+1]!=41)
{p->next=new mnode;
p=p->next;p->next=NULL;}}}
}
cout<<endl;
for(i=0;i<l;i++)
cout<<c[i];

}
