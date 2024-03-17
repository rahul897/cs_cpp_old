#include<iostream>
#include<fstream>
using namespace std;
struct student{
	int sno;
	int r;
	char n[30];
	float c;
};
istream &operator >> (istream &i,student &s)
{i>>s.sno;
i>>s.r;
i>>s.n;
i>>s.c;
return i;}

void search(int n,ifstream &fin)
{int k=0;char ch;
while(!fin.eof())
{if(n==k&&ch!='\n')
{fin>>ch;cout<<ch;}
else if(ch=='\n')k++;}
}

int main()
{student s[30],t;
ifstream fin;ofstream fout;
fout.open("data.txt");int l=1,k=0,i,j,n;
while(l)
{s[k].sno=k+1;fout<<s[k].sno<<" ";
cout<<"roll no  :";cin>>s[k].r;fout<<s[k].r<<" ";
cout<<"\n name  :";cin>>s[k].n;fout<<s[k].n<<" ";
cout<<"\ncgpa  :";cin>>s[k].c;fout<<s[k].c<<"\n";k++;
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
fout<<s[i].sno<<" "<<s[i].c<<"\n";
fout.close();
cout<<"enter index of cg\n";
cin>>i;fin.open("index.txt");
k=0;char ch[30];
while(!fin.eof())
{if(n==k)
{fin.getline(ch,29,'\n');cout<<ch;}
else {fin.getline(ch,29,'\n');k++;}
}
}
