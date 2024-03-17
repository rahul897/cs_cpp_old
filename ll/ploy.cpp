#include<iostream>
using namespace std;
int c=0;
struct node
{
	int co;
	int exp;
	node *next;
};
void del(node* &c) 
{
	node *t;
	t=c->next;
	c->next=t->next;
	t->next=NULL;
	delete(t);
}
node* sort(node* L)
{
	node *c;
	c=L;
	int s=0;
	while(L!=NULL)
	{
	L=L->next;s++;}
	for(int i=0;i<s-1;i++)
	{
		L=c;
		for(int j=i+1;j<s;j++)
		{
			if(L->exp<L->next->exp)
			{
				int t=L->exp;
				L->exp=L->next->exp;
				L->next->exp=t;
				t=L->co;
				L->co=L->next->co;
				L->next->co=t;
			}
			L=L->next;
		}
	}
	return c;
}
void addend(node *a,int x,int y)
{

        while(a->next!=NULL)
	    a=a->next;
	    a->next=new(node);
	    a=a->next;
	a->co=x;
	a->exp=y;
	a->next=NULL;
}
void display(node *a)
{
	if(a!=NULL)
	{
		cout<<a->co<<"X("<<a->exp<<")"<<"  ";
		display(a->next);
	}
}
node* app(node *a,node *b)
{
	node *t=new(node);
	t->co=a->co;
	t->exp=a->exp;
	t->next=NULL;
	a=a->next;
	while(a!=NULL)
    {
    	addend(t,a->co,a->exp);
    	a=a->next;
    }
    while(b!=NULL)
    {
    	addend(t,b->co,b->exp);
    	b=b->next;
    }
    return t;
}
node* sub(node *a,node *b)
{
	node *t=new(node);
	t->co=a->co;
	t->exp=a->exp;
	t->next=NULL;
	a=a->next;
	while(a!=NULL)
    {
    	addend(t,a->co,a->exp);
    	a=a->next;
    }
    while(b!=NULL)
    {
    	int b = (-1)*(b->co);
    	addend(t,b,b->exp);
    	b=b->next;
    }
    return t;
}
node* add(node *c)
{
	node *t;
	t=c;
	while(c->next!=NULL&&c!=NULL)
	{
		if(c->exp==c->next->exp)
		{
			c->co = c->co + c->next->co;
			del(c);
		}
		else
		c=c->next;
	}
	return t;
}
node* multiply(node *a,node *b,node *c)
{
	node *t2,*t1;
	t2=b;
	c=NULL;
	int c=1;
	while(a!=NULL)
	{
		b=t2;
		while(b!=NULL)
		{
			if(c!=1)
		    addend(c,(a->co*b->co),(a->exp+b->exp));
		    else
		    {
		    	c=new(node);
		    	t1=c;
		    	c++;
		    	c->next=NULL;
		    	c->co=a->co*b->co;
		    	c->exp=a->exp+b->exp;
		    }
			b=b->next;	
		}
		a=a->next;
	}
	return t1;
}
int main()
{
	node *a,*b,*c,*c1,*c2;
	cout<<"polynomial 1\nEnter coeff and power : ";
	int co,exp;
	cin>>co>>exp;
	a=new(node);
	a->co=co;
	a->exp=exp;
	a->next=NULL;
	cout<<"Enter remaining coeffs and powers: (coeff of 0 to exit) ";
	cin>>co;
	while(co!=0)
	{
		cin>>exp;
		addend(a,co,exp);
		cout<<"coeff and exp : ";
		cin>>co;
	}
	b=new(node);
	cout<<"polynomial 2\nEnter coeff and power : ";
	cin>>co>>exp;
	b->co=co;
	b->exp=exp;
	b->next=NULL;
	cout<<"Enter remaining coeffs and powers: (coeff of 0 to exit) ";
	cin>>co;
	while(co!=0)
	{
		cin>>exp;
		addend(b,co,exp);
		cout<<"coeff and exp : ";
		cin>>co;
	}
	c=app(a,b);
	c=sort(c);
	c=add(c);
	display(c);
    c1=sub(a,b);
    c1=sort(c1);
	c1=add(c1);
	cout<<endl;
	display(c1);
    c2=multiply(a,b,c2);
	c2=sort(c2);
	c2=add(c2);
	cout<<endl;
	display(c2);
	return 0;
}
