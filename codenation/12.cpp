#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{string txt,pat;
cin>>txt>>pat;
int n=txt.length(),m=pat.length(),f=0,k=0,*chec=new int[n];
for(int j=0;j<m;j++)
    chec[j]=0;
 for(int i=0;i<n;i++)
 {f=0;
   for(int j=0;j<m;j++)
   if(i+j<n&&txt.at(i+j)==pat.at(j))chec[j]=1;
  for(int j=0;j<m;j++)
    if(chec[j]==0){f=1;break;}
    for(int j=0;j<m;j++)
    chec[j]=0;
  if(f==0){cout<<i<<" ";k++;}
 }
 if(k==0)cout<<-1;
}
