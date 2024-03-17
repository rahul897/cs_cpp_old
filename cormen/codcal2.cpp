#include<iostream>
using namespace std;
long long c;
int main()
{ int t,n;char d;
cin>>t;
while(t--)
{c=0;
cin>>n;
for(int i=0;i<n;i++)
{cin>>d;if(d=='1')c++;}
c=c*(c-1)/2+c;
cout<<c<<"\n";
}
}
