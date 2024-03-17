#include<iostream>
using namespace std;
struct sai{
	char b[6];
};
int get(sai s)
{int *z,l,m=0;
z=new int[6];
for(l=0;s.b[l]!='\0';l++);
for (int i=0;i<l;i++)
z[i]=s.b[i]-48;
int r[10]={0,0,0,0,0,0,0,0,0,0};
for (int i=0;i<=9;i++)
for (int j=0;j<l;j++)
if(i==z[j])
r[i]++;
for (int i=0;i<=9;i++)
m=m+i*r[i];
delete[] z;
return m;
}
int main()
{sai a[10];
int t;
cin>>t;
for (int i=0;i<t;i++)
cin>>a[i].b;
for (int i=0;i<t;i++)
cout<<get(a[i]);
}
