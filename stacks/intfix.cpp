#include<iostream>
using namespace std;
class stack{
	char e[50];
	int top;
	int size;
	public:
	void push(char x);
	int pop();
	int isfull();
	int isempty();
	stack(int s){size=s;top=-1;}
};
int stack::isfull()
{return top==size-1;}
int stack::isempty()
{return top==-1;}
void stack::push(char x){
	if(isfull()) cout<<"stackoverflow\n";
	else e[++top]=x;
}
int stack::pop()
{if(isempty())cout<<"stackunderflow\n";
else return e[top--];}

char op(int j,int l,char c,int a[])
{int m;char e;
switch(c){
	case '*':m=a[j]*a[l];a[j]=m;e=j+97;break;
	case '+':m=a[j]+a[l];a[j]=m;e=j+97;break;
	case '-':m=a[l]-a[j];a[j]=m;e=j+97;break;
	case '/':m=a[l]/a[j];a[j]=m;e=j+97;break;}
	return e;
}

int main()
{stack s1(30),s2(30);char c[30],d[30],e,p;int a[15],b[15],i,l,k=0,m=0,n=97,j;
cout<<"enter eqn.\n";cin>>c;for(i=0;i<15;i++)a[i]=0;
for(l=0;c[l]!='\0';l++);
for(i=0;i<l;i++)
if(c[i]>47&&c[i]<58)
{a[k]=a[k]*10+(c[i]-48);}
else if(c[i]!=40&&c[i]!=41)k++;k++;
for(i=0;i<k;i++)
b[i]=a[i];
for(i=0;i<l;i++)
if(c[i]>47&&c[i]<58)
{if(c[i+1]<=47||c[i+1]>=58)d[m++]=n++;}
else d[m++]=c[i];
n=k;
for(i=0;i<m;i++)
{if(d[i]>96&&d[i]<123)
s2.push(d[i]);
else if(d[i]=='*'||d[i]=='/'||d[i]==40)s1.push(d[i]);

else if(d[i]=='+'||d[i]=='-')
{if(!s1.isempty())e=s1.pop();else e=40;
while(!s1.isempty())
{if(e!=40)
{j=s2.pop()-97;k=s2.pop()-97;
s2.push(op(j,k,e,a));}
if(!s1.isempty())e=s1.pop();else break;}
if(e!=40)
{j=s2.pop()-97;k=s2.pop()-97;
s2.push(op(j,k,e,a));}
 s1.push(d[i]);}
 
 else if(d[i]==41)
{if(!s1.isempty())e=s1.pop();else e=40;
while(e!=40)
 {j=s2.pop()-97;k=s2.pop()-97;
s2.push(op(j,k,e,a));
 if(!s1.isempty())e=s1.pop();else break; }}
}
while(!s1.isempty())
{e=s1.pop();
j=s2.pop()-97;k=s2.pop()-97;
s2.push(op(j,k,e,a));
}

for(i=0;i<n;i++)
if(a[i]!=b[i])
cout<<a[i];
}
