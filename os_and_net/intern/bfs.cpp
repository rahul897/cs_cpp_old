#include<iostream>
#include<queue>
using namespace std;
int a[8][8],edge,u,v,visited[8];
void empty()
{
	for(int i=0;i<8;i++)
		visited[i]=0;
}
void bfs(int u)
{queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();q.pop();
		if(!visited[u])cout<<u+1<<endl;
		visited[u]=1;
		for(int v=0;v<8;v++)
			if(!visited[v]&&a[u][v])
				{
					//cout<<v<<" "<<visited[v]<<" ";
					q.push(v);
				}
		//cout<<endl;
	}
}

void dfs(int u)
{
	visited[u]=1;
	cout<<u+1<<endl;
	for(int v=0;v<8;v++)
		if(!visited[v]&&a[u][v])
			dfs(v);
}
/*8
1 2
2 3
2 8
3 4
3 5
5 6
5 7
5 8
*/
int main()
{
	cout<<"enter no.of edges\n";cin>>edge;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		a[u-1][v-1]=1;
		a[v-1][u-1]=1;
	}
	empty();
	bfs(0);
	cout<<endl;
	empty();
	//dfs(0);
}