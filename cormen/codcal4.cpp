#include<iostream>
#include<string>
using namespace std;
string ar="GCAT";
int main()
{int t,n,m,k;
cin>>t;
while(t--)
{cin>>n>>m>>k;
for(int i=0;i<n;i++)
{for(int j=0;j<m;j++)
cout<<ar[(t+2)%4]<<" ";
cout<<"\n";}}
}
