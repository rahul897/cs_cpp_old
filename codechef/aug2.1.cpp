#include<iostream>
using namespace std;
int main()
{int t,x,y;
cin>>t;
while(t--)
{cin>>x>>y;
if(x>=0&&x%2==1&&y<=x+1&&y>=-(x-1))cout<<"YES\n";
else if(x<=0&&x%2==0&&y<=-x&&y>=x)cout<<"YES\n";
else if(y>=0&&y%2==0&&x<=y-1&&x>=-y)cout<<"YES\n";
else if(y<=0&&y%2==0&&x<=(1-y)&&x>=y)cout<<"YES\n";
else cout<<"NO\n";
}
}
