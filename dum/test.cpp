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
	int p=a.a*3;

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
	cout<<p;
}
int main()
{
sai s;
s.input();
win(s);
return 0;
}
