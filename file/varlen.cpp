#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class em
{char c[20];
char buf[500];
char a[30];
public:
	void pack(ofstream &o);
	void unpack(ifstream &i);
};
void em::pack(ofstream &o)
{buf[0]='\0';
cout<<"enter name\n";cin.getline(c,'\n');
strcat(buf,c);strcat(buf,"|");
cout<<"enter adress\n";cin.getline(a,'\n');
strcat(buf,a);strcat(buf,"|");
strcat(buf,"#");
o<<buf;}

void em::unpack(ifstream &i)
{char c;
i>>c;
while(!i.eof())
{if(c!='#')
{if(c!='|')
cout<<c;
else cout<<endl;
}
else cout<<endl<<endl;
i>>c;}}

int main()
{em p;
ofstream o("emdata.txt");
p.pack(o);
o.close();
ifstream i("emdata.txt");
p.unpack(i);
}
