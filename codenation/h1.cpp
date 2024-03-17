#include<iostream>
using namespace std;
int w,h,n,k=0;
int check(int w,int h)
{if(w>0&&h>0)if(w*h==n)
return 1;
else
{int a=check(w-1,h),b=check(w,h-1);
if(a||b)k++;return 0;}
}
int main()
{cin>>w>>h>>n;
check(w,h);
cout<<k;
}
