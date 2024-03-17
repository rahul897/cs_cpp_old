#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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

int min(int a[],int l)
{int b[l],k,i;
for(i=0;i<l;i++)
b[i]=a[i];
sort(b,l);
for(i=0;i<l;i++)
if(b[i]!=-1){k=i;break;}
for(i=0;i<l;i++)
if(a[i]==b[k]){return i;}
return l;}

int main () 
{	int m,d[3],l,j=0,i,x,y;
	cout<<"enter m\n";cin>>m;
	ofstream a[m],b[m];
	string af[m],bf[m];
    for (i=0;i<m;i++)
    {af[i]="A" + IntToStr(i) +".txt";
	a[i].open(af[i].c_str());
	bf[i]="B" +IntToStr(i) +".txt";}
	ifstream fin;fin.open("data.txt");
	
	x=fin.tellg();
	fin.seekg(0,ios::end);y=fin.tellg();l=y-x;
	fin.seekg(0,ios::beg);
	
	while(!fin.eof())
	{while(1)
	{for(i=0;i<3;i++)if(!fin.eof())fin>>d[i];else d[i]=-1;sort(d,3);
	for(i=0;i<3;i++)if(d[i]!=-1)a[j]<<d[i]<<" ";a[j]<<-1<<" ";j=(j+1)%m;break;}}
	for(i=0;i<m;i++){a[i].close();b[i].close();}fin.close();
	
	int flag=0,f[m];
	
	{ifstream a[m];
	for(i=0;i<m;i++){a[i].open(af[i].c_str());if(!a[i].eof())a[i]>>f[i];else f[i]=-1;}
	ofstream b[m];int co;j=0;
	for(i=0;i<m;i++)b[i].open(bf[i].c_str());
	while(1)
	{co=0;
	for(i=0;i<m;i++)if(a[i].eof())co++;
	if(co==m){cout<<"Tata\n";break;}
	cout<<j<<"\n";
	while(1)
		{co=0;
		int k=min(f,m);if(k!=m){b[j]<<f[k]<<" ";if(!a[k].eof())a[k]>>f[k];else f[k]=-1;}
		for(i=0;i<m;i++)if(f[i]==-1)co++;
		if(co==m){b[j]<<-1<<" ";for(i=0;i<m;i++)if(!a[i].eof())a[i]>>f[i];else f[i]=-1;j=(j+1)%m;break;}
	}}}
	if(!b[1].eof())cout<<"AD\n";
	for(i=0;i<m;i++){a[i].close();b[i].close();}
	/*while(1)
	{ifstream a[m],b[m];
	{for(i=0;i<m;i++)	
	{a[i].open(af[i].c_str());
	x=a[i].tellg();a[i].seekg(0,ios::end);y=a[i].tellg();
	if(y-x>=l+1){cout<<"a"<<i;a[i].close();flag=1;break;}
	a[i].close();
	b[i].open(bf[i].c_str());
	x=b[i].tellg();b[i].seekg(0,ios::end);y=b[i].tellg();
	if(y-x>=l+1){cout<<"b"<<i;b[i].close();flag=1;break;}
	b[i].close();}
	if(flag)break;}
	
AB:
	{ifstream a[m];
	for(i=0;i<m;i++){a[i].open(af[i].c_str());if(!a[i].eof())a[i]>>f[i];else f[i]=-1;}
	ofstream b[m];int co;j=0;
	for(i=0;i<m;i++)b[i].open(bf[i].c_str());
	while(1)
	{co=0;
	for(i=0;i<m;i++)if(a[i].eof())co++;
	if(co==m)break;
	while(1)
		{co=0;
		for(i=0;i<m;i++)if(f[i]==-1)co++;
		if(co==m){b[j]<<-1<<" ";for(i=0;i<m;i++)if(!a[i].eof())a[i]>>f[i];else f[i]=-1;j=(j+1)%m;break;}
		else {int k=min(f,m);b[j]<<f[k]<<" ";if(!a[k].eof())a[k]>>f[k];else f[k]=-1;}
	}for(i=0;i<m;i++){a[i].close();b[i].close();}}}

BA:
	{ifstream b[m];
	for(i=0;i<m;i++){b[i].open(bf[i].c_str());b[i]>>f[i];}
	ofstream a[m];int co;j=0;
	for(i=0;i<m;i++)a[i].open(af[i].c_str());
	while(1)
	{co=0;
	for(i=0;i<m;i++)if(b[i].eof())co++;
	if(co==m)break;
		while(1)
		{co=0;
		for(i=0;i<m;i++)if(f[i]==-1)co++;
		if(co==m){a[j]<<-1<<" ";for(i=0;i<m;i++)if(!a[i].eof())b[i]>>f[i];else f[i]=-1;j=(j+1)%m;break;}
		else {int k=min(f,m);a[j]<<f[k]<<" ";if(!a[k].eof())b[k]>>f[k];else f[k]=-1;}
	}for(i=0;i<m;i++){a[i].close();b[i].close();}}}
}
	 */

}
