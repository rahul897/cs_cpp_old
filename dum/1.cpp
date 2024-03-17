#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream fin;
ofstream fout;
int a[100],b[100],i=0,j=0,k;
fin.open("a.txt");
while(!fin.eof())
{fin>>a[i];i++;}
fin.close();
fin.open("b.txt");
while(!fin.eof())
{fin>>b[j];j++;}
fin.close();cout<<i<<j;
fout.open("c.txt");int x=0,y=0;
for(k=0;k<i+j;k++)
{if(x>=i){fout<<b[y];y++;}
else if(y>=j){fout<<a[x];x++;}
else if(a[x]>=b[y]){fout<<b[y];y++;}
else {fout<<a[x];x++;}
}
return 0;
}
