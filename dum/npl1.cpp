#include<iostream>
using namespace std;
int fun(int x,int y)
{while(x!=y)
{if(x>y)x=x-y;
if(y>x)y=y-x;}
return x;}
int lcm(int x,int y)
{return (y/fun(x,y))*x;}
int main()
{int t,a,b,c,d,k;
cin>>t;int m[t];
for(int i=0;i<t;i++)
{cin>>a>>b>>c;
d=lcm(a,b);
for(k=1;k<=c;k++)
{if(c/d==0){m[i]=d;break;}
d=d*k;}}
for(int i=0;i<t;i++)
cout<<m[i]<<endl;
}
