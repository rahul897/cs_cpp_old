#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class student
{
public:
int roll,fp,bp; //"roll" for roll number, "fp" for forwardpointer, "bp" for backward pointer.
char name[20],cell[13]; //"name" for name of the student and "cell" for mobile no. of the student;
}s;
class buffer
{
public:
void pack();
void unpack(ifstream &);
}b;
class file:public buffer
{
public:
void getdata(); //to insert the records of students.
void read_all(); //to view all records on visual displayunit
void find(int &,int); //to search a particular record.
void remov(int &); //to remove a particular record.
void modify(int &); //to update a particular record.
void view_file(); //to view the data file.
}f;
//Variable Declarations.
int flag=0; //returns the true value if a family recordhas been found.
int found=0; //whether the record being searched hasbeen found or not.
int position=-1; //tells the position of record which is found.

int main()
{
char choice; //for choosing the operation to beprocessed.
ifstream filein; //to check whether the file "five.dat" exists ornot;
int rol; //roll no. to be operated for search/modify/remove;
student free;
filein.open("five.dat");
if(filein.fail())
{
strcpy(s.name," ");
strcpy(s.cell," ");
s.roll=-1;
s.fp=-1;
s.bp=-1;
ofstream fileout;
fileout.open("five.dat",ios::out|ios::app|ios::binary);
for(int i=0;i<10;i++)
fileout.write((char*)&s,sizeof(student));
fileout.close();
}
filein.close();
display:
cout<<"\n\t____________________________________________________________\n";
cout<<"\t*****\"HASHING AND CHAINING WITHOUT REPLACEMENTPROGRAM\"*****\n";
cout<<"\t-------------------------------------------------------------\n";
cout<<"\n\t\t\t1.Insert a Record.";
cout<<"\n\t\t\t2.View all Records.";
cout<<"\n\t\t\t3.Search a Record.";
cout<<"\n\t\t\t4.Modify a Record.";
cout<<"\n\t\t\t5.Remove a Record.";
cout<<"\n\t\t\t6.View Data File.";
cout<<"\n\t\t\t7.Exit from Program";
cout<<"\n\n\t\t\tEnter Your choice:";
cin>>choice;
int k=-1,empty=1,full=1;
switch(choice)
{
case '1':
filein.open("five.dat",ios::in|ios::binary);
k=-1;
while(full==1&&k!=9)
{
filein.read((char *)&free,sizeof(student));
k++;
if(free.roll==-1)
full=0;
}
filein.close();
if(full)
cout<<"\n\n\t\t\tFile is Full!!! \n";
else
f.getdata();
goto display;
break;
case '2':
filein.open("five.dat",ios::in|ios::binary);
k=-1;
while(empty==1&&k!=9)
{
filein.read((char *)&free,sizeof(student));
k++;
if(free.roll!=-1)
empty=0;
}
filein.close();
if(empty)
cout<<"\n File has no records !!! \n";
else
f.read_all();
goto display;
break;
case '3':
cout<<"\nEnter the roll no. to be searched:";
cin>>rol;
f.find(rol,0);
goto display;
break;
case '4':
cout<<"\nEnter the roll no. to be modified:";
cin>>rol;
f.modify(rol);
goto display;
break;
case '5':
cout<<"\nEnter the roll no. to be removed:";
cin>>rol;
f.remov(rol);
goto display;
break;
case '6':
cout<<"\n\t\t\tData File is as follows:\n";
f.view_file();
goto display;
break;
case '7':
cout<<"\nAborting!!!\nThank You !!!\n";
return 0;
break;
default:
cout<<"\nWrong Input.\nPlease enter a no. between1 to 6.\n";
goto display;
break;
}
return 0;
}
void file::getdata()
{
cout<<"\n\n\t\t\tEnter The Record:\n";
cout<<"\nRoll No:";
cin>>s.roll;
find(s.roll,1);
if(found==1)
{
cout<<"\nA Record with SAME ROLL NO. already exists.\n";
return;
}
cout<<"Name :";
cin.sync();
cin.getline(s.name,20);
cout<<"Mobile :";
cin.getline(s.cell,13);
s.fp=-1;
s.bp=-1;
b.pack(); // 'b' is the buffer object
}
void buffer::pack()
{
int key=s.roll%10; //key determines the position ofwriting the record.
flag=0;
student st,stud;
fstream io;
io.open("five.dat",ios::in|ios::out|ios::ate|ios::binary);
io.seekg(key*sizeof(student),ios::beg);
io.read((char *)&st,sizeof(student));
if(st.roll==-1)
{
io.seekp(key*sizeof(student),ios::beg);
io.write((char *)&s,sizeof(student));
}
else
{
stud=st;
int cnt =key, x=key;
while(stud.roll!=-1)
{
if((stud.roll)%10==key && stud.fp==-1)
{
st=stud;
x=cnt;
flag=1;
}
if(cnt==9)
io.seekg(0,ios::beg);
io.read((char *)&stud, sizeof(stud));
cnt=(cnt+1)%10;
}
if(flag==1) //if family record with null forward pointer is found.
{
st.fp=cnt;
io.seekp(x*sizeof(student),ios::beg);
io.write((char *)&st,sizeof(student));
s.bp=x;
}
io.seekp(cnt*sizeof(student),ios::beg);
io.write((char *)&s,sizeof(student));
}
io.close();
}
void buffer::unpack(ifstream &inf)
{
student st;
inf.read((char *)&st,sizeof(student));
cout<<"\nRoll No.: "<<st.roll<<"\nName : "<<st.name<<"\nCell :"<<st.cell<<"\n\n";
}
void file::read_all()
{
student stu;
ifstream inf;
inf.open("five.dat",ios::in|ios::binary);
cout<<"\n\t\tAll Records present in the file are:\n\n";
while(inf.read((char *)&stu,sizeof(student)))
if(stu.roll!=-1)
cout<<"Roll:"<<stu.roll<<"\nName:"<<stu.name<<"\nCell:"<<stu.cell<<"\n\n";
inf.close();
}
void file::find(int &search, int z)
{
found=0;
student std;
ifstream fin;
fin.open("five.dat",ios::in|ios::binary);
position=search%10;int count=0;
fin.seekg(position*sizeof(student),ios::beg);
fin.read((char *)&std,sizeof(student));
while(count<10)
{
if(std.roll==search)
{
if(z==0)
cout<<"\nRecord Found\n";
found=1;
cout<<"\nRoll No.:"<<std.roll<<"\nName : "<<std.name<<"\nCell : "<<std.cell<<"\n\n";
break;
}
if((std.roll)%10==search%10)
position=std.fp;
else
position=(position+1)%10;
fin.seekg(position*sizeof(student),ios::beg);
fin.read((char *)&std,sizeof(student));
count++;
}
if(count==10&&z!=1)
cout<<"\nRecord Not Found\n";
fin.close();
}
void file::remov(int& del)
{
find(del,2);
student std,other;
fstream file;
file.open("five.dat",ios::in|ios::out|ios::binary);
file.seekg(position*sizeof(student),ios::beg);
file.read((char *)&std,sizeof(student));
int forward=std.fp,backward=std.bp,travel=position;
if(forward!=-1&&backward!=-1)
{
file.seekg(backward*sizeof(student),ios::beg);
file.read((char *)&std,sizeof(student));
std.fp=forward;
file.seekp(backward*sizeof(student),ios::beg);
file.write((char *)&std,sizeof(student));
file.seekg(forward*sizeof(student),ios::beg);
file.read((char *)&std,sizeof(student));
std.bp=backward;
file.seekp(forward*sizeof(student),ios::beg);
file.write((char *)&std,sizeof(student));
}
else if(forward!=-1&&backward==-1)
{
file.seekg(forward*sizeof(student),ios::beg);
file.read((char *)&other,sizeof(student));
other.bp=-1;
file.seekp(forward*sizeof(student),ios::beg);
file.write((char *)&other,sizeof(student));
}
else if(forward==-1&&backward!=-1)
{
file.seekg(backward*sizeof(student),ios::beg);
file.read((char *)&std,sizeof(student));
std.fp=-1;
file.seekp(backward*sizeof(student),ios::beg);
file.write((char *)&std,sizeof(student));
}
std.roll=-1;
strcpy(std.name," ");
strcpy(std.cell," ");
std.fp=-1;
std.bp=-1;
file.seekp(travel*sizeof(student),ios::beg);
file.write((char *)&std,sizeof(student)); //deletes the currentvalues of the record
if(found==1)
cout<<"\nRecord Removed Successfully.\n";
file.close();
}
void file::modify(int &mod)
{
remov(mod);
if(found==1)
getdata();
}
void file::view_file()
{
student stud;
int i=0;
ifstream file;
file.open("five.dat",ios::in|ios::binary);
while(file.read((char *)&stud,sizeof(student)))
cout<<"Record"<<i++<<":\tRoll="<<stud.roll<<"\tName="<<stud.name<<"\tCell="<<stud.cell<<"\tFP="<<stud.fp<<" BP="<<stud.bp<<endl;
file.close();
}
