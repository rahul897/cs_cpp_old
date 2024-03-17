#include <iostream>
#include <algorithm>
#include <vector>
int n,k=0,s[3]={1,2,5};
int fun(int *a)
{int s=0;
for(int i=0;i<n;i++)
s=s+a[i];
if(s==n*(n+1)/2)return 1;
return 0;
}

void min(int* a,int r)
{if(fun(a))return;
else
{for(int i=r;i<n;i++)
for(int j=0;j<3;j++)
{a[i]+=s[j];k++;
min(a,r+1);
if(fun())return;else k--;}
}
}
using namespace std;
int main() {
    int in;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
	{cin>>in;a.push_back(in);}
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    cout<<a[i]<<"\n";
    if(a[n-1]-a[0]>n)
	cout<<-1<<"\n";
	if(a[0]==0)k++;
	min(a,0);	
	cout<<k;
    return 0;
}
