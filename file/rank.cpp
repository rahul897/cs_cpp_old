#include<iostream>
#include<fstream>
using namespace std;
struct student{
	int sno;
	int r;
	char n[6];
	float c;
};
istream &operator >> (istream &i,student &s)
{i>>s.sno;
i>>s.r;
i>>s.n;
i>>s.c;
return i;}
ostream &operator <<(ostream &o,student &s)
{o<<s.sno<<" "<<s.r<<" "<<s.n<<" "<<s.c<<endl;
return o;}
int main()
{student s[30],t;
ifstream fin;ofstream fout;
fout.open("data.txt");int l=1,k=0,i,j;
while(l)
{cout<<"roll no  :";cin>>s[k].r;
cout<<"\n name  :";cin>>s[k].n;
cout<<"\ncgpa  :";cin>>s[k].c;s[k].sno=k+1;
fout<<s[k];k++;
cout<<"to enter again press 1\nelse 0;\n";cin>>l;}
fout.close();
fout.open("index.txt");
fin.open("data.txt");k=0;
while(!fin.eof())
{fin>>s[k];k++;}k--;
for(i=0;i<k;i++)
for(j=0;j<k-i;j++)
if(s[j].c < s[j+1].c)
{t=s[j];s[j]=s[j+1];s[j+1]=t;}

for(i=0;i<k;i++)
s[i].sno=i+1;
for(i=0;i<k;i++)
fout<<s[i];
}

