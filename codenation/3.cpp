#include <iostream>
using namespace std;
int find(int *b,int x)
{if(b[x]==0)return x;
else if(b[x]==x)return 1;
 else return b[b[x]];
}
int main() {
    int n,c=0;cin>>n;
    int *a=new int[n+1];
    int *b=new int[n+2];
    for(int i=0;i<n;i++)b[0]=0;
    for(int i=0;i<n;i++)
    {cin>>a[i];b[a[i]-1]=i-1;}
    for(int i=0;i<n;i++)
    {if(i==0)c++;
     else if(b[i]==0)c++;
     else if(find(b,i)==0)c++;
    }  
    cout<<c;
    return 0;
}
