#include<iostream>
using namespace std;
long long x;

int main()
{x=600851475143ll;
for(int i=2;i<x;i++)
if(x%i==0)
if(x>i)x=x/i;
else break;
cout<<x<<endl;}

