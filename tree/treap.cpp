#include<iostream>
using namespace std;
struct treap
{int data;
char key;
treap *lchild;
treap *rchild;
treap(char k,int x){key=k;data=x;lchild=NULL;rchild=NULL;}
};

class stack{
	treap* e[50];
	int top;
	int size;
	public:
	void push(treap* x);
	treap* pop();
	int isfull();
	int isempty();
	stack(int s){size=s;top=-1;}
};
int stack::isfull()
{return top==size-1;}
int stack::isempty()
{return top==-1;}
void stack::push(treap* x){
	if(isfull())cout<<"stackoverflow\n";
	else e[++top]=x;
}

treap* stack::pop()
{if(isempty())return 0;
else return e[top--];}

void ror(treap *&k1)
{treap *k2=k1->lchild;
k1->lchild=k2->rchild;
k2->rchild=k1;
k1=k2;
}
void rol(treap *&k1)
{treap *k2=k1->rchild;
k1->rchild=k2->lchild;
k2->lchild=k1;
k1=k2;}

void insert(treap* &t,treap* &k)
{if(t==NULL)
t=k;
else if(t->key>k->key)
insert(t->lchild,k);

else if(t->key<k->key)
insert(t->rchild,k);


}

void print(treap *t)
{if(t!=NULL)
{cout<<t->data<<" "<<t->key<<endl;
print(t->lchild);
print(t->rchild);}
}

void ser(treap *&t,treap *&k,int i)
{if(t->key>k->key)
ser(t->lchild,k,i);
else if(t->key<k->key)
ser(t->rchild,k,i);
else 
{if(i)rol(t);
else ror(t);}
}



void perup(treap *&tm,treap *&p,treap* &t,treap *&k)
{stack s(30);int f1=0,f=1,i;
while(1)
{if(t==k)break;
s.push(t);
if(t->key>k->key)
t=t->lchild;
else if(t->key<k->key)
t=t->rchild;}
while(!s.isempty()&&f)
{p=s.pop();
if(p->data>k->data)
{i=k==p->lchild?0:1;
ser(tm,p,i);}
else f=0;
}

}



int main()
{treap *t=NULL,*p=NULL,*t1=NULL;
char c='$';int i;
cout<<"enter char and its prio\n";
cin>>c;
while(c!='$')
{cin>>i;treap *k=new treap(c,i);
insert(t,k);t1=t;
perup(t,p,t1,k);
cin>>c;
}
print(t);

}
