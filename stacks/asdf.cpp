#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char c;
	ifstream fin("bal eqn.cpp");
	c=fin.seekg(4,ios::beg);
	cout<<c;
}
