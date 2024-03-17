#include<iostream>
using namespace std;
struct bnode
{int data[2];
bnode* child[3];
bnode(){for(int i=0;i<3;i++)child[i]=NULL;}
bnode(int a[],int s,int l)
{for(int i=0;i<3;i++)child[i]=NULL;
for(int i=s;i<l;i++)data[i]=a[i];}
};

void insort(int a[],int k,int l)
{int i=0;
while(1)
{if(a[i]==-1){a[i]=k;break;}
else if(a[i]>k)break;
else 
{for(int t=l-1;t!=i;t--)
a[t]=a[t-1];
a[t]=k;break;}}
}

void mempty(int a[],int l)
{for(int i=0;i<l;i++)
a[i]=-1;
}

int full(int a[],int l)
{for(int i=0;i<l;i++)
if(a[i]==-1)
return 0;
return 1;
}

int isleaf(btree*& t,int l)
{for(int i=0;i<l;i++)
if(t->child[i]!=NULL)return 0;
return 1;
}

int index(btree *&t,int k,int l)
{for(int i=0;i<l;i++)
if(t->data[i]<k)
return i;
return i;
}

void ar(int a[],int b[],int k)
{for(int i=0;i<l;i++)
insort(b,a[i],l);
insort(b,k,l+1);
}

void add(btree *&t,btree*& p,btree *&z[],int a[],int k,int l)
{if(t==NULL)
{t=new btree;
insort(t->data,p,a,k,l);}
if(!isleaf(t,l))
{p=t;
add(t->child[index(t,k,l)],p,a,k,l);}
if(!full(t->data,l))
insort(t->data,k,l);
else
{ar(t->data,a,k);
mempty(t->data);
if(p==NULL)
{add(t,p,a,a[l/2+1],l);
btree* z[0]=new btree(a,0,l/2+1);
btree *z[1]=new btree(a,l/2+2,l+1);
adjust(t,z[],l+1);}
else
{add(p,p,a,a[l/2+1],l);
btree *z[0]=
	
	
}	
	
	
}




}


