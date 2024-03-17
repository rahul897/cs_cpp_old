#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct tnode;
struct nl
{char *a;
tnode **child;
nl()
{a=new char[26];char c='a';
for(int i=0;i<26;i++,c++)
a[i]=c;
child=new tnode*[27];
for(int i=0;i<27;i++)
child[i]=NULL;}
};
union un
{nl *nol;
int in;};
struct tnode
{int tag;
un node;};

void node(tnode *&k)
{k=new tnode;k->tag=1;k->node.nol=new nl;}

void leaf(tnode *&k,int i)
{k=new tnode;k->tag=0;k->node.in=i;}

void insert(tnode *&t,char c[],int in)
{tnode *k=t,*p;ofstream fout("triedata.txt",ios::app);
if(!k)node(k);
for(int i=0;c[i]!='\0';i++)
{p=k->node.nol->child[c[i]-'a'];
if(!p){node(p);}
k=p;}
if(!k)node(k);p=k->node.nol->child[26];
leaf(p,in);
fout<<in<<" "<<c;
}

int main()
{tnode *t=NULL;
char c[20];int in=0,l;
while(1)
{cout<<"enter string\n";
cin>>c;
insert(t,c,in++);
cout<<"enter 1 to enter again\n";
cin>>l;
if(l!=1)break;}
	
}
