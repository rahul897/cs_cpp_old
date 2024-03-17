#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

string IntToStr(int n) 
{
    stringstream result;
    result << n;
    return result.str();
}

void sort(int a[],int l)
{int t;
for(int i=0;i<l;i++)
for(int j=0;j<l;j++)
if(a[i]<a[j])
{t=a[i];
a[i]=a[j];
a[j]=t;}}

int par(int a[])
{int c=0,b[4];
for(int i=0;i<4;i++)
b[i]=a[i]+1;
for(int i=0;i<4;i++)
if(b[i])c++;
return c==1;}

int least(int a[])
{int t=1000,b[4];
for(int i=0;i<4;i++)
b[i]=a[i]+1;
for(int i=0;i<4;i++)
if(t>b[i]&&b[i]!=0)t=b[i];
for(int i=0;i<4;i++)
if(t==b[i])return i;}

int min(int a[],int l)
{int b[l],k,i;
for(i=0;i<l;i++)
b[i]=a[i];
sort(b,l);
for(i=0;i<l;i++)
if(b[i]!=-1&&b[i]!=-2){k=i;break;}
for(i=0;i<l;i++)
if(a[i]==b[k])return i;}

int main () 
{	int d[3],j=0,k=0,i,part[]={6,5,3,0};
	ofstream a[4];string af[4];
    for (i=0;i<4;i++)
    {af[i]="A" + IntToStr(i) +".txt";
	a[i].open(af[i].c_str());}
	ifstream fin;fin.open("data.txt");

	for(;k<4;j=0)
	{while(1)
	{for(i=0;i<3;i++)if(!fin.eof())fin>>d[i];else d[i]=-1;sort(d,3);
	for(i=0;i<3;i++)if(d[i]!=-1)a[k]<<d[i]<<" ";a[k]<<-1<<" ";if(j++==part[k]){k++;break;}}}
	for (i=0;i<4;i++)a[i].close();fin.close();
	
	int f[4],em=3,co,l;part[3]=-1;
	
	while(!par(part))
	{ifstream a[3];l=least(part);ofstream b;
	for(i=0;i<4;i++)
	if(part[i]!=-1){a[i].open(af[i].c_str());if(!a[i].eof())a[i]>>f[i];else f[i]=-1;}
	else {b.open(af[i].c_str());em=i;f[i]=-2;}
	
	for(i=0;i<4;i++)cout<<f[i]<<" ";cout<<endl;
	
	while(!a[l].eof())
	{co=0;
		for(i=0;i<4;i++)if(f[i]==-1)co++;
		if(co==3){b<<-1<<" ";
		for(i=0;i<4;i++)if(i!=em){if(!a[i].eof())a[i]>>f[i];else f[i]=-1;}}
		else {k=min(f,4);b<<f[k]<<" ";if(!a[k].eof())a[k]>>f[k];else f[k]=-1;}}
	part[em]=part[l];for(i=0;i<4;i++)if(i!=em)part[i]-=part[em]+1;
	for(i=0;i<3;i++)a[i].close();b.close();
	//for(i=0;i<4;i++)cout<<part[i]<<" ";cout<<endl;
	}

}
