#include<iostream>
using namespace std;
union node
{int cf;
int ex;
node *next;
};
class pn
{public:
node *p;
node *s;

pn(){p=NULL;s=p;}

void input()
{cout<<"enter cof and ex\nenter -1 to close\n";
p=new node;s=p;int n;
cin>>n>>p->ex;p->cf=n;p->next=NULL;
while(n!=-1)
{node *t=new node;cout<<"enter cof and ex\nenter -1 to close\n";
cin>>n;t->cf=n;if(t->cf!=-1)break;cin>>t->ex;t->next=NULL;
p->next=t;}}

void insert(int c,int e)
{node *t;int f=1;
for(t=s;t!=NULL;t=t->next)
if(e==t->ex)
{t->cf+=c;f=0;break;}
else
{f=1;break;}
if(f)
{node *t=new node;
t->cf=c;cout<<c;t->ex=e;cout<<e;t->next=NULL;
if(p!=NULL){p->next=t;p=t;}else {p=t;s=p;}}
}


void add(pn &a,pn &b)
{int c,e;a.p=a.s;b.p=b.s;
while(a.p!=NULL&&b.p!=NULL)
{if(a.p->ex==b.p->ex)
{c=a.p->cf+b.p->ex;
e=a.p->ex;
insert(c,e);
a.p=a.p->next;
b.p=b.p->next;}
else if ( a.p->ex> b.p->ex)
{c = a.p->cf;
e = a.p->ex;
insert( c, e );
a.p = a.p->next;}
else
{c = b.p->cf;
e = b.p->ex;
insert( c, e );
b.p = b.p->next;}}}
void sub(pn &a,pn &b)
{int c,e;
while(a.p!=NULL&&b.p!=NULL)
{if(a.p->ex==b.p->ex)
{c=a.p->cf-b.p->ex;
e=a.p->ex;
insert(c,e);
a.p=a.p->next;
b.p=b.p->next;}
else if ( a.p->ex> b.p->ex)
{c = a.p->cf;
e = a.p->ex;
insert( c, e );
a.s = a.s->next;}
else
{c = -b.p->cf;
e = b.p->ex;
insert( c, e );
b.p = b.p->next;}}}
void mult(pn &a,pn &b)
{int c,e;
for(a.p=a.s;a.p!=NULL;a.p=a.p->next)
for(b.p=b.s;b.p!=NULL;b.p=b.p->next)
{c=a.p->cf*b.p->cf;
e=a.p->ex+b.p->ex;
insert(c,e);}}

void display()
{for(p=s;p!=NULL;p=p->next)
cout<<p->cf<<"x"<<p->ex<<" ";
}
};
int main()
{pn a,b,c,d,e;int n,i,cf;
cout<<"no.of terms\n";
cin>>n;
for(i=0;i<n;i++)
{cout<<"\nenter coeff of "<<n-i<<" ";
cin>>cf;a.insert(cf,n-i);}
cout<<"pn is :";
a.display();
cout<<"\nno.of terms\n";cin>>n;
for(i=0;i<n;i++)
{cout<<"\nenter coeff of "<<n-i<<" ";
cin>>cf;b.insert(cf,n-i);}
cout<<"pn is :";
b.display();
cout<<"sum is :\n";
c.add(a,b);
c.display();
cout<<"\ndif is :\n";
d.sub(a,b);
d.display();
cout<<"\nmulti is :\n";
e.mult(a,b);
e.display();

}
