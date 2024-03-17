#include<iostream>
using namespace std;

struct rnode;
struct student
{int rno;
char name[20];
float cg;
student * right;
rnode *down;
};
struct course
{int no;
char name[8];
int cr;
course *down;
rnode *right;
};
union r
{student *nex;
rnode *next;
};
union d 
{course *nex;
rnode *next;
};
struct rnode
{r right;
d down;
};


int main()
{cout<<"no of students\n";int n;
cin>>n;

}
