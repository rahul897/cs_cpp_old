#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student
{int rno;
char name[20];
float cg;
student(){rno=-1;strcpy(name,"                    ");cg=0;}
};
int main()
{student s[30];int i,r,t,l,j,h,n;char c[20];float f;
ofstream fout;
fout.open("data.txt");
cout<<"enter n\n";cin>>n;
for(i=0;i<n;i++)
{cout<<"enter std rol.no\n";cin>>r;
cout<<"enter name\n";cin>>c;
cout<<"enter cg\n";cin>>f;
h=r%10;j=h;
if(s[j].rno==-1);
else
for(j=(h+1)%10;j!=h;j++)
if(s[j].rno==-1)break;

s[j].rno=r;strcpy(s[j].name,c);s[j].cg=f;}
for(i=0;i<10;i++)
fout<<i<<" "<<s[i].rno<<" "<<s[i].name<<" "<<s[i].cg<<"\n";
}
