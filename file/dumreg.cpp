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
{int l=1,i=0,k,ind=0,t1;
student st,t;course cs,s;reglist regi,regt;
while(l)
{{
cout<<"enter student rno\n";cin>>st.rno;
fstream is("sda.txt",ios::in|ios::binary|ios::ate);
is.seekp(0,ios::beg);i=0;k=0;
while(i<sno)
{is.read((char*)&t,sizeof(t));i++;
if(t.rno==st.rno){k=1;break;}}
is.close();
if(!k)
{cout<<"enter student name\n";cin>>st.name;
cout<<"enter student cg\n";cin>>st.cg;st.ind=ind;sno++;
fstream os("sda.txt",ios::out|ios::binary|ios::app);
os.write((char*)&st,sizeof(st));os.close();}}

{cout<<"enter course rno\n";cin>>cs.no;
fstream is("cda.txt",ios::in|ios::binary|ios::ate);
is.seekp(0,ios::beg);i=0;k=0;
while(i<cno)
{is.read((char*)&s,sizeof(s));i++;
if(s.no==cs.no){k=1;break;}}
is.close();
if(!k)
{cout<<"enter course name\n";cin>>cs.name;
cout<<"enter course credits\n";cin>>cs.cr;cs.ind=ind;cno++;
fstream os("cda.txt",ios::out|ios::binary|ios::app);
os.write((char*)&cs,sizeof(cs));os.close();}}

reglist reg(st.rno,cs.no,ind);
{fstream in("re.txt",ios::in|ios::out|ios::ate|ios::binary);
in.seekp(0,ios::beg);t1=-1;
while(k<recno)
{in.read((char*)&regi,sizeof(regi));
if(regi.r==st.rno){t1=i;regt=regi;}
i++;k++;}reg.rb=t1;regt.rf=ind;
in.seekp((t1-1)*sizeof(reg),ios::beg);
in.write((char*)&regt,sizeof(regt));
in.close();}

{fstream in("re.txt",ios::in|ios::out|ios::ate|ios::binary);
in.seekp(0,ios::beg);t1=-1;
while(k<recno)
{in.read((char*)&regi,sizeof(regi));
if(regi.r==cs.no){t1=i;regt=regi;}
i++;k++;}reg.rb=t1;regt.rf=ind;
in.seekp((t1-1)*sizeof(reg),ios::beg);
in.write((char*)&regt,sizeof(regt));
in.close();}

fstream in("re.txt",ios::out|ios::app);
in.write((char*)&reg,sizeof(reg));recno++;

ind++;
cout<<"enter 1 to enter again 0 to close\n";
cin>>l;}

{ofstream fout("sdata.txt");
ifstream is("sda.txt",ios::in|ios::binary);
while(!is.eof())
{is.read((char*)&t,sizeof(t));
fout<<t.rno<<" "<<t.name<<" "<<t.cg<<" "<<t.ind<<endl;}
is.close();fout.close();}

{ofstream fout("cdata.txt");
ifstream is("cda.txt",ios::in|ios::binary);
while(!is.eof())
{is.read((char*)&s,sizeof(s));
fout<<s.no<<" "<<s.name<<" "<<s.cr<<" "<<s.ind<<endl;}
is.close();fout.close();}

{ofstream fout("reg.txt");
ifstream is("re.txt",ios::in|ios::binary);
while(!is.eof())
{is.read((char*)&regt,sizeof(regt));
fout<<regt.ind<<" "<<regt.r<<" "<<regt.rf<<" "<<regt.rb<<" "<<regt.n<<" "<<regt.nf<<" "<<regt.nb<<endl;}
is.close();fout.close();}

}
