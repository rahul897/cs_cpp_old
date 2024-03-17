#include<iostream>
#include<cmath>
using namespace std;

int f(long long x)
{int c=0;
long long d=sqrt(x);
for(long long i=1;i<d;i++)
if(x%i==0)c+=2;
if(d*d==x)c++;
return c;}

long long t(int i)
{long long sum=0ll;
for(int j=1;j<=i;j++)
sum+=j;
return sum;}

int main()
{int i=12730,k;
long long n;
while(1)
{n=t(i++);
k=f(n);cout<<n<<" "<<k<<endl;
if(k>=500)break;}
cout<<i<<endl;
}
