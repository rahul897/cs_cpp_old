#include<iostream>
using namespace std;
struct tnode
{int data;
tnode *lchild;
tnode *rchild;
tnode(int x){data=x;lchild=NULL;rchild=NULL;}
};
void create(tnode *&t,int k)
{if(t==NULL)
t=new tnode(k);
else if(k<t->data)
create(t->lchild,k);
else if(k>t->data)
create(t->rchild,k);
}

void rol(tnode *&k1)
{tnode *k2=k1->lchild;
k1->lchild=k2->rchild;
k2->rchild=k1;
k1=k2;}


void ror(tnode *&k1)
{tnode *k2=k1->rchild;
k1->rchild=k2->lchild;
k2->lchild=k1;
k1=k2;}


void sprint(tnode *t)
{if(t!=NULL)
{sprint(t->lchild);
cout<<t->data;
sprint(t->rchild);}
}
void printri(tnode *t)
{cout<<"(";
if(t!=NULL)
{cout<<t->data;
printri(t->lchild);
printri(t->rchild);cout<<")";}
}
void post(tnode *t)
{if(t!=NULL)
{post(t->lchild);
post(t->rchild);
cout<<" "<<t->data<<" ";
}
}

tnode* fmin(tnode *t)
{if(t->lchild==NULL)return t;
return fmin(t->lchild);}

void search(tnode *&t,int k)
{if(t->data>k)
search(t->lchild,k);
else if(t->data<k)
search(t->rchild,k);
else ror(t);
}

/*tnode* sarch(tnode *t,int k)
{if(t==NULL)return NULL;
if(t->data<k)
return sarch(t->rchild,k);
else if(t->data>k)
return sarch(t->lchild,k);
else return t;}

tnode* prev(tnode *t,int k)
{if(t==NULL)return NULL;
if(t->rchild->data<k)
return prev(t->rchild,k);
else if(t->lchild->data>k)
return prev(t->lchild,k);
else return t;}

tnode* maax(tnode *t)
{if(t->rchild==NULL)return t;
return maax(t->rchild);}

void del(tnode *&t,int k)
{t=sarch(t,k);
if(t->lchild!=NULL&&t->rchild!=NULL)
{t->data=maax(t->lchild)->data;
del(t->lchild,t->data);}
else
{tnode *m=t;
if(t->lchild!=NULL)t=t->lchild;
else t=t->rchild;
delete m;}
}*/

tnode* maax(tnode *t)
{if(t->rchild==NULL)return t;
return maax(t->rchild);}

void del(tnode *&t,int &k)
{if(t==NULL)return;
else if(t->data>k)del(t->lchild,k);
else if(t->data<k)del(t->rchild,k);
else if(t->lchild!=NULL&&t->rchild!=NULL)
{t->data=maax(t->lchild)->data;
del(t->rchild,t->data);}
else
{tnode *m=t;
if(t->rchild!=NULL)
t=t->rchild;
else t=t->lchild;
delete m;}}

int similar(tnode *&t,tnode *&y)
{if(t->data==y->data)return 1;
return similar(t->lchild,y->lchild)&&similar(t->rchild,y->rchild);
}

int getar(tnode *&t,int a[],int &k)
{if(t!=NULL)
{a[k++]=t->data;
getar(t->lchild,a,k);
getar(t->rchild,a,k);}
return k;
}

int main()
{tnode *t=NULL;int n=0,s=0;
cout<<"enter the els\n enter -1 to stop\n";
cin>>n;
while(n!=-1)
{create(t,n);cin>>n;}
cout<<endl;
printri(t);cout<<endl;/*cout<<"enter 1 t0 delte elemnt\n";cin>>n;
if(n==1){cout<<"enter element to delete\n";
cin>>n;
del(t,n);}
cout<<endl;
post(t);
tnode *r=NULL;n=0;
cout<<"enter the els\n enter -1 to stop\n";
cin>>n;
while(n!=-1)
{create(r,n);cin>>n;}
cout<<endl;
printri(r);*/cout<<endl;
cout<<"enter el\n";
cin>>n;
search(t,n);

printri(t);
}

