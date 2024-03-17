#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
union job
{char p[20];
char t[8];
};
class em
{char c[20];
char d[2];
job x;
char buf[500];
public:
	void pack(ofstream &o);
	void unpack(ifstream &i);
};
void em::pack(ofstream &o)
{buf[0]='\0';
cout<<"enter name\n";cin.getline(c,'\n');
strcat(buf,c);strcat(buf,"|");
cout<<"enter job type\nt for temporary\np for permanent: ";
cin.getline(d,'\n');strcat(buf,d);strcat(buf,"|");
if(d[0]=='p')
{cout<<"enter salary\n";cin.getline(x.p,'\n');strcat(buf,x.p);strcat(buf,"|");}
else
{cout<<"enter salary\n";cin.getline(x.t,'\n');strcat(buf,x.t);strcat(buf,"|");}
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
