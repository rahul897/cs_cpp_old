#include<iostream>
#include<fstream>
using namespace std;
struct student{
	int rno;
	char name[30];
	float cg;
	int ind;
};
struct course {
	int no;
	char name[8];
	int cr;
	int ind;
};
struct reglist
{int r;int rf;int rb;
int n;int nf;int nb;int ind;
reglist(){}
reglist(int rno,int no,int ip){ind=ip;r=rno;n=no;rf=-1;rb=-1;nf=-1;nb=-1;}
};
int recno=0,sno=0,cno=0;
int ssearch(int d)
{student s;int f=0,i=0;
fstream in;in.open("sdata.txt",ios::in|ios::ate|ios::binary);
in.seekp(0,ios::beg);
cout<<sno<<" "<<d;
while(i<sno)
{in.read((char*)&s,sizeof(s));
cout<<s.rno<<endl;
if(s.rno==d)
{f=1;break;}
i++;}in.close();
cout<<"$"<<f<<"$\n";
return f;}

int csearch(int d)
{course c;int f=0,i=0;
fstream in;in.open("cdata.txt",ios::in|ios::ate|ios::binary);
in.seekp(0,ios::beg);
cout<<cno;
while(i<cno)
{in.read((char*)&c,sizeof(c));
if(c.no==d)
{f=1;break;}
i++;}in.close();
cout<<"$"<<f<<"$\n";
return f;}

int regedits(int d)
{reglist regi;int t=-1,i=0,k=0;
fstream in;in.open("reg.txt",ios::in|ios::ate|ios::binary);
in.seekp(0,ios::beg);
	while(k<recno)
	{in.read((char*)&regi,sizeof(regi));
		if(regi.r==d)t=i;
	i++;k++;
	}in.close();
return t;
}

int regeditc(int d)
{reglist regi;int t=-1,i=0,k=0;
fstream in;in.open("reg.txt",ios::in|ios::ate|ios::binary);
in.seekp(0,ios::beg);
	while(k<recno)
	{in.read((char*)&regi,sizeof(regi));
		if(regi.n==d)t=i;
	i++;k++;
	}in.close();
return t;
}

int main()
{fstream os,oc,ro;
os.open("sdata.txt",ios::out|ios::binary);
oc.open("cdata.txt",ios::out|ios::binary);
ro.open("reg.txt",ios::out|ios::binary);

int l=1,i=0,t;student st;course co;
while(l)
{cout<<"enter student details\n";
cout<<"enter rollno\n";cin>>st.rno;
if(!ssearch(st.rno))
{st.ind=i;
cout<<"enter name\n";cin>>st.name;
cout<<"enter cg\n";cin>>st.cg;
os.write((char*)&st,sizeof(st));sno++;}


cout<<"enter course details\n";
cout<<"enter no\n";cin>>co.no;
if(!csearch(co.no))
{co.ind=i;
cout<<"enter name\n";cin>>co.name;
cout<<"enter credits\n";cin>>co.cr;
oc.write((char*)&co,sizeof(co));cno++;}


reglist reg(st.rno,co.no,i);
reg.rb=regedits(st.rno);reg.nb=regeditc(co.no);

ro.write((char*)&reg,sizeof(reg));recno++;
cout<<"to register another entry press 1\nelse 0\n";cin>>l;i++;
}
	
}
