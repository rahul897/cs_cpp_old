if(i<d)
{bnode *z=new bnode(t->data[d-1]);
bnode *y=new bnode(t,d,2*d+1);
bnode *x=new bnode(t,0,d-1);
merge(x,k);
z->child[0]=x;
z->child[1]=y;
t=z;}
else if(i>d)
{bnode *z=new bnode(t->data[d]);
bnode *x=new bnode(t,0,d);
bnode *y=new bnode(t,d+1,2*d+1);
merge(y,k);
z->child[0]=x;
z->child[1]=y;
t=z;}
else if(i==d)
{bnode *z=new bnode(k);
bnode *y=new bnode(t,d,2*d+1);
bnode *x=new bnode(t,0,d);
y->child[i]=t->child[i]->child[0];
x->child[0]=t->child[i]->child[1];
z->child[0]=x;
z->child[1]=y;
t=z;}	
