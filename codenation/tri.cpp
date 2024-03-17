#include<iostream>
#include<vector>
using namespace std;
vector<char> v;
struct node
{int c;
char d;
node **child;
node(char n,int x)
{c=0;d=n;child=new node*[x];
for(int i=0;i<x;i++)child[i]=NULL;}
}*root;
int fin(node *p,node *t)
{for(int i=0;i<p->c;i++)
if(p->child[i]==t)return i;
}
int nul(node *t)
{for(int i=0;i<t->c;i++)
if(t->child[i]!=NULL)return 0;
return 1;
}
void split(node *p,node *t,int k)
{if(t==NULL){return;}
v.push_back(t->d);int c=0;
for(int i=0;i<k;i++)
{if(c==2)break;
if(t->child[i]){c++;split(t,t->child[i],t->child[i]->c?t->child[i]->c:0);}
}
if(nul(t)){if(t!=root){p->child[fin(p,t)]=NULL;v.push_back('@');}else root=NULL;
}
}
int main()
{node *t=new node('a',3),*p=NULL;root=t;
t->child[0]=new node('b',3);t->c=3;t->child[0]->c=1;
t->child[0]->child[0]=new node('e',3);
t->child[1]=new node('c',2);t->child[1]->c=2;
t->child[1]->child[0]=new node('f',3);
t->child[1]->child[1]=new node('g',3);
t->child[2]=new node('d',1);t->child[2]->c=3;
t->child[2]->child[0]=new node('h',3);
t->child[2]->child[1]=new node('i',3);
t->child[2]->child[2]=new node('j',3);
while(root!=NULL)
{split(p,t,t->c);
for(int i=0;i<v.size();i++)
cout<<v[i]<<" ";cout<<endl;
v.clear();}
}
