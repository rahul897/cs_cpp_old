#include<iostream>
#include<fstream>
using namespace std;

void sort(int a[],int l)
{int t;
for(int i=0;i<l;i++)
for(int j=0;j<l;j++)
if(a[i]<a[j])
{t=a[i];
a[i]=a[j];
a[j]=t;}}

int min(int a[],int l)
{int b[l],k,i;
for(i=0;i<l;i++)
b[i]=a[i];
sort(b,l);
for(i=0;i<l;i++)
if(b[i]!=-1){k=i;break;}
for(i=0;i<l;i++)
if(a[i]==b[k]){return i;}}

void empty(int a[],int l)
{for(int i=0;i<l;i++)
a[i]=-1;}

int main()
{int x,i,n,k=0,*a,run,y,j,l;
ofstream a1,a2;ifstream fin;
a1.open("A1.txt");a2.open("A2.txt");fin.open("data.txt");
cout<<"enter partition size\n";
cin>>n;a=new int[n];run=2*n;
x=fin.tellg();
fin.seekg(0,ios::end);
y=fin.tellg();
l=y-x;cout<<l;
fin.seekg(0,ios::beg);
while(!fin.eof())
{A1:
	while(1)
	{for(i=0;i<n;i++)if(!fin.eof())fin>>a[i];else a[i]=-1;sort(a,n);
	 for(i=0;i<n;i++)if(a[i]!=-1)a1<<a[i]<<" ";a1<<-1<<" ";break;}
A2:
	while(1)
	{for(i=0;i<n;i++)if(!fin.eof())fin>>a[i];else a[i]=-1;sort(a,n);
	 for(i=0;i<n;i++)if(a[i]!=-1)a2<<a[i]<<" ";a2<<-1<<" ";break;}
}
fin.close();a1.close();a2.close();

int z=0,f[2];

while(1)
{
	if(z==6)break;
	z++;
AB:
	{ifstream a[2];a[0].open("A1.txt");a[1].open("A2.txt");
	ofstream b[2];b[0].open("B1.txt");b[1].open("B2.txt");
	a[0]>>f[0];a[1]>>f[1];int co,j=0;
	while(1)
	{co=0;
	for(i=0;i<2;i++)if(a[j].eof())co++;
	if(co==2)break;
	cout<<"bay\n";
	B1:
		while(1)
		{if(f[0]==-1&&f[1]==-1){b[j]<<-1<<" ";a[0]>>f[0];a[1]>>f[1];j=(j+1)%2;break;}
		int k=min(f,2);cout<<f[k]<<" ";b[j]<<f[k]<<" ";if(!a[k].eof())a[k]>>f[k];else f[k]=-1;
		}
		
	}a[0].close();a[1].close();b[0].close();b[1].close();}
	
BA:
	{ifstream b[2];b[0].open("A1.txt");b[1].open("A2.txt");
	ofstream a[2];a[0].open("B1.txt");a[1].open("B2.txt");
	b[0]>>f[0];b[1]>>f[1];int co,j=0;
	while(1)
	{co=0;
	for(i=0;i<2;i++)if(b[j].eof())co++;
	if(co==2)break;
	cout<<"hai\n";
		while(1)
		{if(f[0]==-1&&f[1]==-1){a[j]<<-1<<" ";b[0]>>f[0];b[1]>>f[1];j=(j+1)%2;break;}
		int k=min(f,2);cout<<f[k]<<" ";a[j]<<f[k]<<" ";if(!b[k].eof())b[k]>>f[k];else f[k]=-1;
		}
		
	}a[0].close();a[1].close();b[0].close();b[1].close();}
	
}



}
