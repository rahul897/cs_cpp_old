#include<iostream>
#include<fstream>
using namespace std;
class stack{
	char e[50];
	int top;
	int size;
	public:
	void push(char x);
	int pop();
	int isfull();
	int isempty();
	stack(int s){size=s;top=-1;}
};
int stack::isfull()
{return top==size-1;}
int stack::isempty()
{return top==-1;}
void stack::push(char x){
	if(isfull())cout<<"stackoverflow\n";
	else e[++top]=x;
}
int stack::pop()
{if(isempty())cout<<"stackunderflow\n";
else return e[top--];}

int main()
{stack s(20);ifstream fin;ofstream fout;fin.open("bal eqn.cpp");fout.open("newbal.cpp");
char c,d;int sp=3,i;
while(!fin.eof())
{c=fin.get();
l:
fout<<c;
if(c=='\n'){if(!s.isempty())for(i=0;i<sp;i++)fout<<" ";}
else if(c==';'){fin.get(c);if(c==125)sp-=3;if(!s.isempty()){fout<<'\n';for(i=0;i<sp;i++)fout<<" ";}goto l;}
else if(c==40){s.push(c);}
else if(c==41){s.pop();fin.get(c);if(c!='\n'){fout<<'\n';for(i=0;i<sp;i++)fout<<" ";goto l;}}
else if(c==123){s.push(c);sp+=3;}
else if(c=125){s.pop();}
}
}
