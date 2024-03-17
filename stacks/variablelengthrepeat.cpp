#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class child
{public:
  char numofchild;
  char nameofch[30];
  char age[2];
};

class Employee : public child
{ public:
  char name[30];
 char address[50];
  char ph[12];

  char delim[2];
  char Buffer[200];


    void pack(ofstream &outf)
    { cout<<"Enter name ,address ,phone seperated by | \n";
      cin.getline(name,30,'|');strcat(name,"|");
      cin.getline(address,50,'|');strcat(address,"|");
      cin.getline(ph,12,'|');strcat(ph,"|");
       cout<<"How many child do u have  :  ";
        cin.ignore();
       cin>>numofchild;

       int num=numofchild-'0';

       child c[numofchild];

        for(int k=0;k<numofchild;k++)
        {
         cout<<"Enter Child name : ";
         cin.getline(c[k].nameofch,30,'|');strcat(nameofch,"|");
         cin.ignore();
        cout<<"Enter Child age : ";
          cin.getline(c[k].age,2,'|');strcat(age,"|");
        }
        strcat(age,"#");
      strcat(Buffer,name);strcat(Buffer,address);strcat(Buffer,ph);

      outf<<Buffer;




     cin.getline(delim,2);
     strcat(Buffer,name);strcat(Buffer,ph);
    strcat(Buffer,delim);
    }
void unpack (ifstream &inp)
{ char c;inp>>c;
    while(!inp.eof())
    { if(c=='#')
        cout<<endl;
        else
        {
        if(c!='|')
          {
            cout<<c;
           }
        }

    inp>>c;
   }


}
};
/*istream & operator >>(istream & inp ,Employee & p)
{//read fields from file
    cout<<"Reading name , address ,phone from file seperated by delimiter\n\n\n ";
    inp.getline(p.name,30,'|');

    inp.getline(p.ph,10,'|');
    return inp;
}
ostream & operator <<(ostream &outp ,Employee & p)
{
outp<<p.name<<"  "<<p.ph <<endl;
}*/
int main()
{
 Employee p;
 ofstream outf("Employeefile.txt");
 p.pack(outf);
outf.close();
 ifstream inp("Employeefile.txt");
 inp.unsetf(ios::skipws); //include white space in read
 p.unpack(inp);

}

