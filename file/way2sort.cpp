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

int main()
{int x,i,n,t=-1,*a,y,j,z,l;a=new int[3];
ofstream a1,a2;ifstream fin;
a1.open("A1.txt");a2.open("A2.txt");fin.open("data.txt");


x=fin.tellg();
fin.seekg(0,ios::end);
y=fin.tellg();
l=y-x;cout<<l;
fin.seekg(0,ios::beg);
fin>>a[0]>>a[1]>>a[2];
while(!fin.eof())
{A1:
	while(1)
	{sort(a,3);
	if(t<a[0]){a1<<a[0]<<" ";t=a[0];fin>>a[0];}
	else{a1<<a[1]<<" "<<a[2]<<" "<<-1<<" ";fin>>a[1]>>a[2];t=-1;break;}}
A2:
	while(1)
	{sort(a,3);
	if(t<a[0]){a2<<a[0]<<" ";t=a[0];fin>>a[0];}
	else{a2<<a[1]<<" "<<a[2]<<" "<<-1<<" ";fin>>a[1]>>a[2];t=-1;break;}}		
}
fin.close();a1.close();a2.close();

while(1)
{
AB:
	{ifstream a1,a2;a1.open("A1.txt");a2.open("A2.txt");
	ofstream b1,b2;b1.open("B1.txt");b2.open("B2.txt");
	a1>>x;a2>>y;
	while(!a1.eof()||!a2.eof())
	{B1:
		while(1)
		{if(x==-1&&y==-1){b1<<-1<<" ";a1>>x;a2>>y;break;}
		if(x==-1){b1<<y<<" ";a2>>y;}
		else if(y==-1){b1<<x<<" ";a1>>x;}
		else if(x<y){b1<<x<<" ";a1>>x;}
		else {b1<<y<<" ";a2>>y;}}
	B2:
		while(1)
		{if(x==-1&&y==-1){b2<<-1<<" ";a1>>x;a2>>y;break;}
		if(x==-1){b2<<y<<" ";a2>>y;}
		else if(y==-1){b2<<x<<" ";a1>>x;}
		else if(x<y){b2<<x<<" ";a1>>x;}
		else {b2<<y<<" ";a2>>y;}}	
	}a1.close();a2.close();b1.close();b2.close();}
BA:
	{ifstream b1,b2;b1.open("B1.txt");b2.open("B2.txt");
	ofstream a1,a2;a1.open("A1.txt");a2.open("A2.txt");
	b1>>x;b2>>y;
	while(!b1.eof()||!b2.eof())
	{A21:
		while(1)
		{if(x==-1&&y==-1){a1<<-1<<" ";b1>>x;b2>>y;break;}
		if(x==-1){a1<<y<<" ";b2>>y;}
		else if(y==-1){a1<<x<<" ";b1>>x;}
		else if(x<y){a1<<x<<" ";b1>>x;}
		else {a1<<y<<" ";b2>>y;}}
	A22:
		while(1)
		{if(x==-1&&y==-1){a2<<-1<<" ";b1>>x;b2>>y;break;}
		if(x==-1){a2<<y<<" ";b2>>y;}
		else if(y==-1){a2<<x<<" ";b1>>x;}
		else if(x<y){a2<<x<<" ";b1>>x;}
		else {a2<<y<<" ";b2>>y;}}	
	}a1.close();a2.close();b1.close();b2.close();}
	
	{ifstream a1;a1.open("A1.txt");
	x=a1.tellg();a1.seekg(0,ios::end);y=a1.tellg();
	if(y-x>=l+1){cout<<"a1";a1.close();break;}
	a1.close();
	ifstream a2;a2.open("A2.txt");
	x=a2.tellg();a2.seekg(0,ios::end);y=a2.tellg();
	if(y-x>=l+1){cout<<"a2";a2.close();break;}
	a2.close();
	ifstream b1;b1.open("B1.txt");
	x=b1.tellg();b1.seekg(0,ios::end);y=b1.tellg();
	if(y-x>=l+1){cout<<"b1";b1.close();break;}
	b1.close();
	ifstream b2;b2.open("B2.txt");
	x=b2.tellg();b2.seekg(0,ios::end);y=b2.tellg();
	if(y-x>=l+1){cout<<"b2";b2.close();break;}
	b2.close();}

}

}
