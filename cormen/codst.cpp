#include<iostream>
#include<list>
using namespace std;
list<int> a;
int main()
{
	int t,n;int num,s;
	list<int>::iterator i;
	cin>>t;
	while(t--)
	{cin>>n;a.push_back(1000055);s=0;
	for(int j=0;j<n;j++)
	{cin>>num;
	for(i=a.begin();i!=a.end();i++)
	{if(num==*i)break;
	if(num<*i){a.insert(i,num);s++;break;}}}
	cout<<s<<"\n";a.clear();
	}
}
