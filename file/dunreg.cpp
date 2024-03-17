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

int main()
{
int l=1,i=0,k;student st,t;
while(l)
{

cout<<"enter student rno\n";cin>>st.rno;

fstream is("sda.txt",ios::in|ios::binary|ios::ate);
is.seekp(0,ios::beg);i=0;k=0;
while(i<sno)
{is.read((char*)&t,sizeof(t));i++;cout<<t.rno<<"\n";
if(t.rno==st.rno){k=1;cout<<"kay\n";break;}}
is.close();
if(!k)
{cout<<"enter student name\n";cin>>st.name;
cout<<"enter student cg\n";cin>>st.cg;sno++;
fstream os("sda.txt",ios::out|ios::binary|ios::app);
os.write((char*)&st,sizeof(st));os.close();}
cout<<"enter 1 to enter again 0 to close\n";
cin>>l;}

ofstream fout("sdata.txt");
ifstream is("sda.txt",ios::in|ios::binary);i=0;
while(!is.eof())
{is.read((char*)&t,sizeof(t));
fout<<t.rno<<" "<<t.name<<" "<<t.cg<<" "<<i<<endl;
i++;}

	
}
