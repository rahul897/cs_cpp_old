#include <iostream>
#include <algorithm>
#include <vector>
int n,k=0,*a,*b,s[4]={0,1,2,5};
int fun()
{for(int i=0;i<n;i++)
b[i]=0;
for(int i=0;i<n;i++)
if(a[i]>0&&a[i]<=n)b[a[i]-1]=1;else return 0;
for(int i=0;i<n;i++)
if(b[i]==0)return 0;
return 1;
}

void min(int r)
{for(int i=r;i<n;i++)
{a[i]+=s[0];
min(r+1);if(fun())return;
a[i]+=s[1];k++;
min(r+1);if(fun())return;else {k--;a[i]-=s[1];}
a[i]+=s[2];k++;
min(r+1);if(fun())return;else {k--;a[i]-=s[2];}
a[i]+=s[3];k++;
min(r+1);if(fun())return;else {k--;a[i]-=s[3];}
}
}
using namespace std;
int main() {
    int in,f=0;
    cin>>n;
    a=new int[n];
    b=new int[n];
	for(int i=0;i<n;i++)
	{cin>>a[i];}
    min(0);
	if(k!=0)cout<<k;else {
	if(fun())cout<<0;
	else cout<<-1;}
    return 0;
}
