#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class child
{public:
char n[20];
char l[2];
};
class em
{char c[20];
char a[30];
char nofc[2];
char buf[500];
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
cout<<"enter the no.of children\n";
cin.getline(nofc,'\n');strcat(buf,nofc);strcat(buf,"|");int k=nofc[0]-48;
if(k>0){
	child z[k];
	for(int i=0;i<k;i++)
	{cout<<"enter name of child :";cin.getline(z[i].n,19,'\n');strcat(buf,z[i].n);strcat(buf,"|");
	cout<<"enter the class : ";cin.getline(z[i].l,19,'\n');strcat(buf,z[i].l);strcat(buf,"|");
    }}
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
