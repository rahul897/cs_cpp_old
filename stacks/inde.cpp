#include<iostream>
#include<fstream>
using namespace std;

int main()
{ifstream fin;ofstream fout;fin.open("asdf.cpp");fout.open("nad.cpp");
char c,d,b[10000];int sp=3,i,l;
fin.unsetf(ios::skipws);
for(l=0;!fin.eof();l++)
fin>>b[l];
for(i=0;i<l;i++)
{
if(b[i]=='#')
{for(;b[i]!='>';i++)
fout<<b[i];
fout<<">\n";}

else if(b[i]==41)
{fout<<b[i];
if(b[i+1]!=';'){fout<<"\n";for(int k=0;k<sp;k++)fout<<" ";}}

else if(b[i]==';')
{fout<<b[i];
if(b[i+1]==125){fout<<"\n";sp-=3;for(int k=0;k<sp;k++)fout<<" ";}}

else if(b[i]=='\n')
{fout<<b[i];fout<<"\n";for(int k=0;k<sp;k++)fout<<" ";}

else if(b[i]==123)
{fout<<b[i];
if(b[i+1]<123&&b[i+1]>96||b[i+1]>64&&b[i+1]<91)
{fout<<"\n";for(int k=0;k<sp;k++)fout<<" ";}}

else if(b[i]==125)
{fout<<b[i];
fout<<"\n";for(int k=0;k<sp;k++)fout<<" ";}

else fout<<b[i];

}
}
