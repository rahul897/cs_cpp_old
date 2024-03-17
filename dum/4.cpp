#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream fin,fn;
ofstream fout;
int a[100],b[100],c[100],i=0,j=0,k=0;
fin.open("a.txt");fn.open("b.txt");fout.open("c.txt");
while(!fin.eof()||!fn.eof())
{if(!fin.eof()){fin>>a[i];i++;}
if(!fn.eof()){fn>>b[j];j++;}}
int x=0,y=0;
for(k=0;k<i+j;k++)
{if(x>=i){cout<<b[y];fout<<b[y];y++;}
else if(y>=j){cout<<a[x];fout<<a[x];x++;}
else if(a[x]>b[y]){cout<<b[y];fout<<b[y];y++;}
else if(a[x]<b[y]){cout<<a[x];fout<<a[x];x++;}
else {cout<<b[y];fout<<b[y];y++;x++;k++;}
}
return 0;}

