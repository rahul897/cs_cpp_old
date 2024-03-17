#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define gc getchar_unlocked
	long long int m,n,v,ans=-1,ans1=3 ;
void scanint(int &x)
{
	
}
using namespace std;
int main()
{
	cin>>m>>n>>v;
	if(m*n==v)
	{
		ans=0;
		ans1=0;
	}
	long long int i,q,t;
	for(i=1;i<v;i++)
	{
		if(v%i==0)
		{
			q=v/i;
				if(q==m||q==n)
			{
				if(q=m&&i<n)
					ans=1;
				if(q=n&&i<m)
					ans=1;
			}
			else if(q<m||q<n)
			{
				//cout<<q<<endl;
				if(q<m)
				{
					if(i<n)
						ans=2;
					if(i==n)
						ans==1;
				}
				if(q<n)
				{
					if(i<m)
						ans=2;
					if(i==m)
						ans=1;
				}
			}
		}
		if(ans1>=ans)
			ans1=ans;
	}
/*	t=q;
	q=i;
	i=t;
	if(q==m||q==n)
			{
				if(q=m&&i<n)
					ans1=1;
				if(q=n&&i<m)
					ans1=1;
			}
			else if(q<m||q<n)
			{
				//cout<<q<<endl;
				if(q<m)
				{
					if(i<n)
						ans1=2;
					if(i==n)
						ans1=1;
				}
				if(q<n)
				{
					if(i<m)
						ans1=2;
					if(i==m)
						ans1=1;
				}
			}*/
		cout<<ans1<<endl;
	return 0;
}
