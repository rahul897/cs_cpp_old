#include<iostream>
#include<cmath>
using namespace std;

int check(int x)
{float ss=x,r,s;
r=sqrt(ss);
s=floor(r);
return ss==s ;
}

int main()
{int i,j,k,s=0;

for(i=200;;i++)
for(j=1;j<i;j++)
for(k=1;k<j;k++)
{s=i+j+k;
if(check(i+j)&&check(i-j)&&check(k+j)&&check(j-k)&&check(i+k)&&check(i-k))goto l;}
	
	l:
	cout<<s;
}
