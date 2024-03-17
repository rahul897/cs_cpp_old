# include <iostream>
# include <cstdlib>
using namespace std;
int main ()
{char ch ;
cout<<"Do you want to shutdown your computer now(y/n)\n";
cin>>ch;
if (ch=='y'||ch=='Y')
system ( "C:\\WINDOWS\\System32\\shutdown /s" ) ;
return 0 ;
}
