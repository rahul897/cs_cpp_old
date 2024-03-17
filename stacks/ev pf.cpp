#include<iostream>
using namespace std;
class stack{
	char e[50];
	int top;
	int size;
	public:
	void push(char x);
char pop();
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
char stack::pop()
{if(isempty())cout<<"stackunderflow\n";
else return e[top--];}

int main()
{stack s(30);char c[30],d[30],e;int a[15],i,l,k=0,m=0,n=97,j;
cout<<"enter eqn.\n";cin>>c;for(i=0;i<15;i++)a[i]=0;
for(l=0;c[l]!='\0';l++);
for(i=0;i<l;i++)
if(c[i]>47&&c[i]<58)
{a[k]=a[k]*10+(c[i]-48);}
else if(c[i]!=40&&c[i]!=41)k++;k++;
for(i=0;i<l;i++)
if(c[i]>47&&c[i]<58)
{if(c[i+1]<=47||c[i+1]>=58)d[m++]=n++;}
else d[m++]=c[i];
for(i=0;i<m;i++)
c[i]=d[i];k=0;
for(int i=0;i<m;i++)
{if((c[i]>47&&c[i]<58)||(c[i]>96&&c[i]<123))
{d[k]=c[i];k++;}
else if(c[i]=='*'||c[i]=='/'||c[i]==40)s.push(c[i]);
else if(c[i]=='+'||c[i]=='-')
{if(!s.isempty())e=s.pop();else e=40;
while(!s.isempty())
{if(e!=40)
d[k++]=e;
else break;
if(!s.isempty())e=s.pop();else break;}
if(e!=40)d[k++]=e;s.push(c[i]);}
else if(c[i]==41)
{if(!s.isempty())e=s.pop();else e=40;
while(e!=40)
{d[k++]=e;
if(!s.isempty())e=s.pop();else break;}}
}
while(!s.isempty()){e=s.pop();d[k++]=e;}
for(i=0;i<k;i++)
{if(d[i]>96&&d[i]<123)
s.push(d[i]);
else
{j=s.pop()-97;
l=s.pop()-97;
switch(d[i]){
	case '*':m=a[j]*a[l];a[j]=m;e=j+97;s.push(e);break;
	case '+':m=a[j]+a[l];a[j]=m;e=j+97;s.push(e);break;
	case '-':m=a[l]-a[j];a[j]=m;e=j+97;s.push(e);break;
	case '/':m=a[l]/a[j];a[j]=m;e=j+97;s.push(e);break;}
}
}
	cout<<endl<<a[j];
}
