#include<iostream>
#include<fstream>
using namespace std;
struct student
{int rno;
char name[20];
float cg;};
int main()
{fstream file;
file.open("dat.txt",ios::out|ios::binary);student s,t;
cout<<"enter roll\n";cin>>s.rno;
cout<<"enter name\n";cin>>s.name;
cout<<"enter cg\n";cin>>s.cg;
file.write((char*)&s,sizeof(s));
ofstream fout;
fout.open("dat1.txt");
file.read((char*)&t,sizeof(t));
fout<<t.rno<<" "<<t.name<<" "<<t.cg;
}
