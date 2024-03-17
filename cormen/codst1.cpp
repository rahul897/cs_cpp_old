#include<iostream>
using namespace std;
int main()
{
	int n,m,q;
	int f,l,d;
	cin>>n>>m;
	f=2+n;l=n+2*n;
	while(m--)
	{cin>>q;
	if(q<f||q>l)cout<<"0\n";
	else
	{d=(f+l)/2;
	d=d-q;if(d<0)d*=-1;
	cout<<n-d<<"\n";}
	}
}
