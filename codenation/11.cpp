#include<iostream>
using namespace std;
int a[20][20],*ho,*vis,m,n;
int ind(int q)
{for(int i=0;i<q;i++)
  if(vis[i]==0)return i;
  return -1;
}
int hof(int q,int in)
{for(int i=0;i<q;i++)
  if(ho[i]==in)return i;
}
void fin(int q,int in,int x,int y)
{vis[hof(q,in)]=1;
 if(x!=0&&y!=0&&a[x-1][y-1]==1&&!vis[hof(q,(x-1)*n+(y-1))])fin(q,(x-1)*n+(y-1),x-1,y-1);
 if(x!=0&&y!=n&&a[x-1][y+1]==1&&!vis[hof(q,(x-1)*n+(y+1))])fin(q,(x-1)*n+(y+1),x-1,y+1);
 if(x!=m&&y!=0&&a[x+1][y-1]==1&&!vis[hof(q,(x+1)*n+(y-1))])fin(q,(x+1)*n+(y-1),x+1,y-1);
 if(x!=m&&y!=n&&a[x+1][y+1]==1&&!vis[hof(q,(x+1)*n+(y+1))])fin(q,(x+1)*n+(y+1),x+1,y+1);
 if(x!=0&&a[x-1][y]==1&&!vis[hof(q,(x-1)*n+(y))])fin(q,(x-1)*n+(y),x-1,y);
 if(x!=m&&a[x+1][y]==1&&!vis[hof(q,(x+1)*n+(y))])fin(q,(x+1)*n+(y),x+1,y);
 if(y!=0&&a[x][y-1]==1&&!vis[hof(q,(x)*n+(y-1))])fin(q,(x)*n+(y-1),x,y-1);
 if(y!=n&&a[x][y+1]==1&&!vis[hof(q,(x)*n+(y+1))])fin(q,(x)*n+(y+1),x,y+1);
}

int main(){
	int tem,q=0,s_n=0,in;
  cin>>m>>n;
  ho=new int[m*n];
  vis=new int[m*n];
  for(int i=0;i<m;i++)
  {for(int j=0;j<n;j++)
  {cin>>tem;a[i][j]=tem;
   vis[q]=0;
   if(tem==1)ho[q++]=i*m+j;
  }
  }
  tem=ind(q);
  while(tem!=-1)
  {in=ho[tem];
   fin(q,in,in/m,in%n);
   s_n++;tem=ind(q);
  }
  cout<<s_n;
}
