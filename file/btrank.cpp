#include<iostream>
#include<fstream>
using namespace std;
struct student{
	int sno;
	int r;
	char n[30];
	float c;
};
istream &operator >> (istream &i,student &s)
{i>>s.sno;
i>>s.r;
i>>s.n;
i>>s.c;
return i;}

void search(int n,ifstream &fin)
{int k=0;char ch;
while(!fin.eof())
{if(n==k&&ch!='\n')
{fin>>ch;cout<<ch;}
else if(ch=='\n')k++;}
}

struct tnode
{float key;
int in;
tnode *lchild;
tnode *rchild;
};
void insert(tnode *&t,int k,float f)
{if(t==NULL)
{t=new tnode;t->key=f;t->in=k;t->lchild=NULL;t->rchild=NULL;}
else if(f<t->key)
insert(t->lchild,k,f);
else if(f>t->key)
insert(t->rchild,k,f);
}

void sprint(tnode *t,ofstream &f)
{if(t!=NULL)
{sprint(t->lchild,f);
int i=t->lchild==NULL?-1:t->lchild->in,j=t->rchild==NULL?-1:t->rchild->in;
f<<i<<"     "<<t->key<<"      "<<t->in<<"      "<<j<<endl;
sprint(t->rchild,f);}
}

int main()
{student s[30],t;
ifstream fin;ofstream fout;
fout.open("data.txt");int l=1,k=0,i,j,n;
while(l)
{s[k].sno=k+1;fout<<s[k].sno<<" ";
cout<<"roll no  :";cin>>s[k].r;fout<<s[k].r<<" ";
cout<<"\n name  :";cin>>s[k].n;fout<<s[k].n<<" ";
cout<<"\ncgpa  :";cin>>s[k].c;fout<<s[k].c<<"\n";k++;
cout<<"to enter again press 1\nelse 0;\n";cin>>l;}
fout.close();
fout.open("index.txt");
fin.open("data.txt");k=0;
while(!fin.eof())
{fin>>s[k];k++;}k--;
tnode *b=NULL;

for(i=0;i<k;i++)
{insert(b,s[i].sno,s[i].c);}
fout<<"left  data  index right\n";
sprint(b,fout);
fout.close();
}
