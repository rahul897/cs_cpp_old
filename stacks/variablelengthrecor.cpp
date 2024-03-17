#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;



class Person
{ public:
  char name[30];
  char address[50];
  char ph[13];
  char delim[2];
  char Buffer[200];

    void pack(ofstream &outf)
    { cout<<"Enter name ,address ,phone seperated by | \n";
      cin.getline(name,30,'|');strcat(name,"|");
      cin.getline(address,30,'|');strcat(address,"|");
      cin.getline(ph,11,'|');strcat(ph,"| #");
      strcat(Buffer,name);strcat(Buffer,address);strcat(Buffer,ph);
      outf<<Buffer;

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
/*istream & operator >>(istream & inp ,Person & p)
{//read fields from file
    cout<<"Reading name , address ,phone from file seperated by delimiter\n\n\n ";
    inp.getline(p.name,30,'|');
    inp.getline(p.address,50,'|');
    inp.getline(p.ph,10,'|');
    return inp;
}
ostream & operator <<(ostream &outp ,Person & p)
{
outp<<p.name<<"   "<<p.address<<"  "<<p.ph <<endl;
}*/
int main()
{
 Person p;
ofstream outf("details.txt",ios::app);
p.pack(outf);
outf.close();

 ifstream inp("personfile.txt");
 inp.unsetf(ios::skipws);
  //include white space in read
 p.unpack(inp);


return 0;

}
