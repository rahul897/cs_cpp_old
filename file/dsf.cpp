#include<iostream>
#include<fstream>
using namespace std;

int main()
{ifstream fin;fin.open("data.txt");

fin>>a[0]>>a[1]>>a[2];
x=fin.tellg();
fin.seekg(0,ios::end);
y=fin.tellg();
l=y-x;cout<<l;
fin.seekg(0,ios::beg);
}
