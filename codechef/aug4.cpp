#include<iostream>
#include<vector>
using namespace std;
int a[401][401],*b;
int m,n;
int find(int q)
{for(int i=0;i<n;i++)
if(b[i]==q)return i;
return -1;
}
int minu(int q)
{for(int i=1;i<401;i++)
if(a[i][q]!=-1)return 0;
return 1;
}
int max(int q)
{int ma=-1,mai;
for(int i=1;i<401;i++)
if(ma<a[i][q]){ma=a[i][q];mai=i;}
return mai;
}
int main()
{int t,q,co=0;
cin>>t;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
a[i][j]=-1;
while(t--)
{cin>>n>>m;b= new int[n];co=0;
for(int i=0;i<m;i++)
{cin>>q;if(find(q)!=-1){b[co++]=q;}
for(int j=1;j<401;j++)
if(a[q][j]==-1||a[q][j]==1000){a[q][j]=i;a[q][j+1]=1000;break;}}
if(m>n)
{for(int i=2;i<401;i++)
{if(minu(i))break;int x=max(i),z=find(x);
if(z==-1&&x!=-1){cout<<x<<" "<<z;;co++;b[z]=x;}}
cout<<co<<endl;}
}
}
