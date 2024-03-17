#include<iostream>
using namespace std;

struct rnode;
struct studnt
{int rno;
char name[20];
float cg;
studnt * right;
rnode *down;
};
struct coure
{int no;
char name[8];
int cr;
coure *down;
rnode *right;
};
union r
{studnt *nex;
rnode *next;
};
union d 
{coure *nex;
rnode *next;
};
struct rnode
{r right;
d down;
};
struct student
{int rno;
char name[20];
float cg;
};
struct course
{int no;
char name[8];
int cr;
};

struct node
{int cdata;
int sdata;
node* right;
node *down;
node()
{cdata=-1;sdata=-1;right=NULL;down=NULL;}
};

void insert(node *&t)
{if(t==NULL)
t=new node;
else insert(t->right);
}
int main()
{node *s[10],*c[10],*t=NULL,*y=NULL;int n,m,i,j,k,x;
student st[10];course co[10];
cout<<"enter no.of students\n";cin>>n;
cout<<"enter no.of courses\n";cin>>m;
for(i=0;i<m;i++)
{for(j=0;j<n;j++)
insert(t);
c[i]=t;t=NULL;}
for(i=0;i<m;i++)
{cout<<"course details\ncno\ncname\ncredits\n";
cin>>co[i].no>>co[i].name>>co[i].cr;}

t=c[0];
for(i=0;i<n;i++)
{s[i]=t;
cout<<"student "<<i<<" details\nrno\nname\ncg\n";
cin>>st[i].rno>>st[i].name>>st[i].cg;t=t->right;}

for(i=0;i<n;i++)
{y=s[i];
for(j=0;j<m;j++)
{t=c[j];k=i;
while(k){t=t->right;k--;}
y->down=t;y=y->down;}
}

for (i=0;i<n;i++)
{cout<<"courses opted by student "<<st[i].rno<<endl;t=s[i];
for(j=0;j<m;j++)
{cout<<"course "<<co[j].no<<"\npress 1 if opted else 0\n";
cin>>x;
if(x){t->cdata=i+1;t->sdata=j+1;}
t=t->down;}
}


for(i=0;i<m;i++)
{cout<<"course "<<co[i].no<<endl<<co[i].name<<endl<<"credits "<<co[i].cr<<"\nis opted by \n";t=c[i];
while(t!=NULL)
{if(t->sdata!=-1)
cout<<st[t->sdata].rno<<" "<<st[t->sdata].name<<" "<<st[t->sdata].cg<<"\n";
t=t->right;
}
cout<<endl;
}



}
