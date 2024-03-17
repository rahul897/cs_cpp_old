#include<iostream>
using namespace std;

struct rnode;

struct student
{int rno;
char name[10];
float cg;
student * right;
rnode *down;
student(int x,char c[],float g){rno=x;name=c;cg=g;right=NULL;down=NULL;}
};
struct course
{int no;
char name[10];
float cr;
course *down;
rnode *right;
course(int x,char c[],float g){no=x;name=c;cr=g;right=NULL;down=NULL;}
};
union r
{student *nex;
rnode *next;
};
union d 
{course *nex;
rnode *next;
};
struct rnode
{r right;
d down;
int rtag;
int dtag;
rnode(){rtag=0;dtag=0;}
};

void abs(student *&t,student *&s,int x,char c[],float f)
{if(t==s)
{student *k=new student(x,c,f);
k->right=t;
s=k;}
else 
{student *l=s;
while(l->right->data!=t->data)
l=l->right;
student *k=new student(x,c,f);
k->rightt=l->right;
l->right=k;}
}

void ris(student *&t,student *&s,int x,char c[],float f)
{if(t==NULL)
{student *k=new student(x,c,f);t=k;}
else if(t->data<x)
ris(t->right,s,x,c,f);
else
abs(t,s,x,c,f);
}

void abc(course *&t,course *&s,int x,char c[],float f)
{if(t==s)
{course *k=new course(x,c,f);
k->down=t;
s=k;}
else 
{course *l=s;
while(l->down->data!=t->data)
l=l->down;
course *k=new course(x,c,f);
k->down=l->down;
l->down=k;}
}

void ric(course *&t,course *&s,int x,char c[],float f)
{if(t==NULL)
{course *k=new course(x,c,f);t=k;}
else if(t->data<x)
ris(t->down,s,x,c,f);
else
abc(t,s,x,c,f);
}

int seas(student *&t,int r)
{if(t!==NULL)
{if(r==t->rno)
	return 1;
return seas(t->right,r);}
return 0;
}

int seac(course *&t,int r)
{if(t!==NULL)
{if(r==t->no)
	return 1;
return seac(t->down,r);}
return 0;
}

student* getst(student *&t,int r)
{if(t!==NULL)
{if(r==t->no)
	return t;
return seac(t->right,r);}
return NULL;
}

course* getcr(course *&t,int r)
{if(t!==NULL)
{if(r==t->no)
	return c1;
return seac(t->down,r);}
return NULL;
}
int main()
{student *st=NULL,*sts;course *co=NULL,*cso;int c=0,l=1,x;char ch[20],float
while(l)
{
	cout<<"enter student rno\n";cin>>x;
	if(!seas(st,x))
	{	if(c!=0)st=sts;
		cout<<"enter student name\n";cin>>ch;
		cout<<"enter student cg\n";cin>>f;
		ris(st,sts,x,ch,f);
		if(c==0){sts=st;}
		st=sts;
		st=getst(st,x);
	}
	else st=getst(st,x);
	while(st->down.dtag==1)
	st->down.down->next=st->down.down->next->next;
	st->down.down->next=new rnode;

	
	cout<<"enter course rno\n";cin>>x;
	if(!seac(st,x))
	{	if(c!=0)co=cso;
		cout<<"enter student name\n";cin>>ch;
		cout<<"enter student cg\n";cin>>f;
		ris(co,cso,x,ch,f);
		if(c==0){cso=co;c++;}
		co=cso;
	}
	co=getst(co,x);
	while(co->right.rtag==1)
	cs->right.right->next=cs->right.right->next->next;
	st->down.down->next=cs->right.right;
	


}


}
