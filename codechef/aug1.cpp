#include<iostream>
#include<vector>
using namespace std;
int main()
{int t,n,k;
vector<int> v;
cin>>t;
while(t--)
{cin>>n>>k;int q=k,i,f=0;
int *a=new int[n];
for(i=0;i<n;i++)
{cin>>a[i];if(a[i]%2==1)f++;}
for(i=0;i<n;i++)
{if(q<=0)break;
if(a[i]%2==0)q--;
}
if(f>0&&k==0) cout<<"YES\n";  
else if(q<=0&&k!=0)cout<<"YES\n";
else cout<<"NO\n";
}
}
