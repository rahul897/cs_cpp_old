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
int i,k=0,j,x,y,l=1,c[30],t;
ofstream fout;fout.open("data.txt");
while(l)
{cout<<"roll no  :";cin>>s[k].rno;
cout<<"\n course no :";cin>>s[k].cno;
fout<<s[k].rno<<" "<<s[k].cno<<" ";k++;
cout<<"to enter again press 1\nelse 0;\n";cin>>l;}
fout.close();k=0;
ifstream fin;
fin.open("data.txt");
while(!fin.eof())
{fin>>s[k];k++;}k--;
cout<<k;
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

ofstream fou;
fou.open("index.txt");
for(i=0;i<l;i++)
{fou<<c[i]<<" ";
for(j=0;j<k;j++)
if(c[i]==s[j].rno)
fou<<j<<" ";
}
}
