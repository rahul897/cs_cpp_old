#include<iostream>
#include<fstream>
using namespace std;
int main()
{ofstream fout;
fout.open("data.txt");
for(int i=0;i<6;i++)
fout<<i<<"\n";
fout.seekp(4,ios::beg);
fout<<54;
}
