#include<iostream>
#include <string>
using namespace std;
class sai{
	public:
int a,b,c;
string x[100],y[100],z[100];
void input()
{cin>>a>>b>>c;

for(int i=0;i<a;i++)
cin>>x[i];
for(int i=0;i<b;i++)
cin>>y[i];
for(int i=0;i<c;i++)
cin>>z[i];
}};
void win(sai a){
	int p=a.a*3,q=a.b*3,r=a.c*3;
	
	for(int i=0;i<a.a;i++)
	for(int j=0;j<a.b;i++)
	{if(a.x[i].compare(a.y[j])==0)
	p--;
	}	
	for(int i=0;i<a.a;i++)
	for(int j=0;j<a.c;i++)
	{if(a.x[i].compare(a.z[j])==0)
	p--;
	}
	for(int i=0;i<a.b;i++)
	for(int j=0;j<a.a;i++)
	{if(a.y[i].compare(a.x[j])==0)
	q--;
	}	
	for(int i=0;i<a.b;i++)
	for(int j=0;j<a.c;i++)
	{if(a.y[i].compare(a.z[j])==0)
	q--;
	}	
		for(int i=0;i<a.c;i++)
	for(int j=0;j<a.a;i++)
	{if(a.z[i].compare(a.x[j])==0)
	r--;
	}	
		for(int i=0;i<a.c;i++)
	for(int j=0;j<a.b;i++)
	{if(a.z[i].compare(a.y[j])==0)
	r--;
	}	
	if(p>q&&p>r)
	cout<<"Raju";
	else if(q>p&&q>r)
	cout<<"Ramu";
	else if(r>p&&r>q)
	cout<<"Rakesh";
	else
	cout<<"Tie";
}
int main()
{
int T;
cin>>T;
if(T>0&&T<100){
sai s[100];
for(int i=0;i<T;i++)
s[i].input();
for(int i=0;i<T;i++)
win(s[i]);}
return 0;
}
