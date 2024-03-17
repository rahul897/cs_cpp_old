#include<iostream>
using namespace std;
struct dheap
{int data;
dheap **child;
dheap *pptr;
dheap(int x,int y)
{data=x;
pptr=NULL;child=new dheap*[y];
for(int i=0;i<y;i++)
child[i]=NULL;}
};
class q
{
	int size;
	dheap* e[50];
	int f;
	int r;
	public:
	q();
	q(int);
	void enq(dheap*);
	dheap* dq();
	int isf();
	int ise();
};
q::q()
{
	size=50;
	f=-1;r=-1;
}
q::q(int s)
{
	size=s;
	f=-1;r=-1;
}
void q::enq(dheap* i)
{
	if(r+1%size==f)
		cout<<"queue is full\n";
	else
	{
		r=r+1%size;
		e[r]=i;
		if(f==-1)
			f++;
	}
}
int q::ise()
{
	return f==-1;
}
dheap* q::dq()
{
	if(f==-1)
		{cout<<"q is empty";
		return 0;}
	else
	{dheap* c=e[f];
		if(f==r)
			{f=-1;r=-1;}
		else 
			f=f+1%size;
		return c;
	}
}

void insert(dheap* &t,dheap *&p,dheap* &k,int &i,int &j,int &z,int s)
{if(t==NULL)
{t=k;t->pptr=p;}
else if(t->child[i]==NULL)
{p=t;insert(t->child[i],p,k,i,j,z,s);i++;}
else 
{if(z==s){j++;z=0;}
p=t->child[j];
insert(t->child[j],p,k,i,j,z,s);z++;}
}

void swap(int &a,int &b)
{int t=a;
a=b;
b=t;}

void perup(dheap *&p,dheap *&k)
{q a(30);dheap *t=k->pptr;int f=1;
while(1)
{if(t==NULL)break;
a.enq(t);
t=t->pptr;}
while(!a.ise()&&f)
{t=a.dq();
if(k->data<t->data)
{swap(k->data,t->data);k=t;}
else f=0;}	
}

void printri(dheap *t)
{if(t!=NULL)
{printri(t->child[0]);
cout<<t->data;

printri(t->child[1]);}
}

void print(dheap *t)
{if(t!=NULL)
{cout<<t->data;
print(t->child[0]);
print(t->child[1]);}
}



int main()
{dheap *t=NULL,*p=NULL;
int i=0,j=0,z=0,s,n;
cout<<"enter size of dheap\n";cin>>s;
cout<<"enter els\n";
cin>>n;
while(n!=-1)
{dheap *k=new dheap(n,s);
i=i%s;j=j%s;
insert(t,p,k,i,j,z,s);
perup(t,k);
cin>>n;}

printri(t);
cout<<endl;
print(t);

}



