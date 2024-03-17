#include<iostream>
#include<cmath>
using namespace std;
int main()
{int i,j,k,t;
for(i=1;i<1000;i++)
for(j=1;j<1000;j++)
{t=i*i+j*j;
for(k=1;k<=sqrt(t);k++)
if(i+j+k==1000&&k*k==t)
{cout<<i<<" "<<j<<" "<<k<<" "<<i*j*k<<endl;break;}
}


}
