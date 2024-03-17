#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> ran,pos,hol;
int fin(int j,int a,int b)
{int x=0,y=0;
for(int i=hol[j];i<=hol[j+1];i++)
{if(ran[i]==pos[a])x=1;
if(ran[i]==pos[b])y=1;}
return x&&y;
}

int main ()
{
int n,k,p,q,A,B,f;
cin>>n>>k>>p;
for(int i=0;i<n;i++)
{cin>>q;pos.push_back(q);
ran.push_back(q);}
sort(ran.begin(),ran.end());
for(int i=0;i+1<n;i++)
if(ran[i+1]-ran[i]>k){hol.push_back(i);}
hol.insert(hol.begin(),0);hol.push_back(n-1);
while(p--)
{cin>>A>>B;f=1;
for(int i=0;i+1<hol.size();i++)
if(fin(i,A-1,B-1))
{cout<<"Yes\n";f=0;break;}
if(f)cout<<"No\n";
}
}
