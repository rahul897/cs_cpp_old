#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;int t,k,n,i,f,l;
    v.push_back(0);
    v.push_back(1);
    for(i=2;i<=10000000;i++)
        {
        	k=v[i-2]+v[i-1];
        	if(k>999999999){l=i;break;}
            v.push_back(k);
        }
    cin>>t;
    while(t--)
    {
        cin>>n;f=0;
        for(i=0;i<l;i++)
        {
            if(v[i]==n){f=1;break;}
        }
        if(f)cout<<"IsFibo\n";
        else cout<<"IsNotFibo\n";
    }
}
