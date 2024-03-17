#include<iostream>
#include<cmath>
using namespace std;
struct node
{int data;
 node *next;
};

int main()
{node *l,*s,*b[10],*bs[10],*t;

int j,n,r,max=0,k=0;
 l=new node;
s=l;
cout<<"Enter element.press -1 to stop entering  : \n";
do {
t=new node;
cin>> t->data;
if(t->data!=-1)
{l->data=t->data;
t->next=NULL;
l->next=t;
l=t;
}
} while(t->data!=-1);
l->next=NULL;
l=s;


 for(k=0;k<4;k++)
{for( j=0;j<10;j++)  
{b[j]=new node;
bs[j]=b[j];
}
  while(l->next!=NULL)  
  {
   r=(l->data/pow(10,k));
   r%=10;
t=new node;
t->data=l->data;
b[r]->data=t->data;
t->next=NULL;
b[r]->next=t;
b[r]=t;
l=l->next;
   }

  for( j=0;j<10;j++)
  {b[j]->next=NULL;
  b[j]=bs[j];
  }
l=s;
  for(j=0;j<10;j++)
  {
  while(b[j]->next!=NULL)
  {
  l->data=b[j]->data;
  if(k==3) cout<<l->data<<" ";
  l=l->next;
  b[j]=b[j]->next;
  }
  }
l=s;
 }


}



