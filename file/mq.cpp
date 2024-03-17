#include<iostream>
#include<fstream>
using namespace std;
struct student
{int rno;
int cno;
};
istream &operator >> (istream &i,student &s)
{i>>s.rno>>s.cno;
return i;}

int main()
{student s[30];
int i,k=0,j,x,y,l=0,c[30],t;
ifstream fin;
fin.open("data.txt");
while(!fin.eof())
{fin>>s[k];k++;}k--;
for(i=0;i<k;i++)
for(j=0;j<k;j++)
{if(s[i].rno==s[j].rno)
c[l++]=s[i].rno;
for(x=0;x<l;x++)
for(y=0;y<l;y++)
if(c[x]==c[y]&&x!=y)l--;}

for(i=0;i<l;i++)
for(j=0;j<l;j++)
if(c[i]>c[j])
{t=c[i];c[i]=c[j];c[j]=t;}

ofstream fout;
fout.open("index.txt");
for(i=0;i<l;i++)
{fout<<c[i]<<" ";
for(j=0;j<k;j++)
if(c[i]==s[j].rno)
fout<<j<<" ";
}
}
