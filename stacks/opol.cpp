#include<iostream>
#include<fstream>
using namespace std;
class student{public:
	int rn;
	char c[20];
	float cg;
};
istream &operator >> (istream &i,student &s)
{i>>s.rn>>s.c>>s.cg;
return i;}
ostream &operator <<(ostream &o,student &s)
{o<<s.rn<<endl<<s.c<<endl<<s.cg<<endl;
return o;}
int main()
{student s;
ifstream fin;
fin.open("a.txt");
fin>>s;
cout<<s;
}
