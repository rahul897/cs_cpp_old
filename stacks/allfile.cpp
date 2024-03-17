#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
union job
{char c[20];
char d[8];
};
class child
{public:
char n[20];
char l[2];
};
class em
{char c[20];
char d[2];
job x;
int nofc;
char buff[500];
public:
	void pack(ofstream &o);
	void unpack(ifstream &i);
};
void em::pack(ofstream &o)
{char q[20];
cout<<"enter name: ";cin.getline(c,19,'\n');strcat(buff,c);strcat(buff,"|");
cout<<"enter job type\nt for temporary\np for permanent: ";
cin>>d;strcat(buff,d);strcat(buff,"|");
if(d[0]=='p')
{cout<<"enter salary :";cin.ignore();cin.getline(q,19,'\n');
strcat(buff,q);strcat(buff,"|");}
else {cout<<"enter salary :";cin.ignore();cin.getline(q,7,'\n');strcat(buff,q);strcat(buff,"|");}
cout<<"enter no.of children :";cin>>nofc;
if(nofc>0){
	child z[nofc];
	for(int i=0;i<nofc;i++)
	{cout<<"enter name of child :";cin.getline(z[i].n,19,'\n');strcat(buff,z[i].n);strcat(buff,"|");
	cout<<"enter the class : ";cin>>z[i].l;strcat(buff,z[i].l);strcat(buff,"|");
    }}
strcat(buff,"#");
o<<buff;
}
void em::unpack(ifstream &i)
{char c;
i>>c;
while(!i.eof())
{if(c!='#')
{if(c!='|')
cout<<c;
else cout<<endl;
}
else cout<<endl<<endl;}}

int main()
{em p;
ofstream o("emdata.txt");
p.pack(o);
ifstream i("emdata.txt");
p.unpack(i);
char c;
i>>c;
while(!i.eof())
{if(c!='#')
{if(c!='|')
cout<<c;
else cout<<endl;
}
else cout<<endl<<endl;}
}
