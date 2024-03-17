#include<iostream>
using namespace std;
long long mov=0;
long long i,j;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{mov=0;
	cin>>i>>j;if(i<0)i*=-1;if(j<0)j*=-1;
	if(i>j){i=i-j;mov=2*j;
	if(i%2==0)mov=mov+2*i;
	else if(i>0)mov=mov+2*i+1;}
	else {j=j-i;mov=2*i;
	if(j%2==0)mov=mov+2*j;
	else if(j>0)mov=mov+2*j-1;}
	cout<<mov<<"\n";}
	
}
