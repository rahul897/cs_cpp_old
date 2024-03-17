#include <iostream>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
map<int,int> m;
int pime[10000],p1,p2,qt[2],sp[4];

void prim()
{
	for(int i=1;i<10000;i++)
	{
		if(pime[i]==0)pime[i]=1;
		if(i>1&&pime[i]==1)
		{
			for(int j=2*i;j<10000;j+=i)pime[j]=-1;
		}
	}
}

int mins()
{
	queue<int> q;
	q.push(p1);m.clear();
	while(!q.empty())
	{
		qt[0]=qt[1]=q.front();q.pop();
		if(qt[0]==p2)return m[p2];
		for(int i=0;i<4;i++)
			{
				sp[i]=qt[0]%10;
				qt[0]/=10;
			}
		qt[0]=qt[1];
		for(int i=0;i<4;i++)
			for(int j=0;j<10;j++)
			{
					if(j!=sp[i])
					{qt[0]=qt[0]+(j-sp[i])*pow(10,i);
					if(pime[qt[0]]==1&&qt[0]>1000&&m[qt[0]]==0)
					{
						q.push(qt[0]);m[qt[0]]=m[qt[1]]+1;
						if(qt[0]==p2)return m[p2];
					}}
					qt[0]=qt[1];
			}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	prim();int t;cin>>t;
	while(t--)
	{
		cin>>p1>>p2;
		cout<<mins()<<endl;
	}
	return 0;
}