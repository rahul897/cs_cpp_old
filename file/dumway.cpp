#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string IntToStr(int n) 
{
    stringstream result;
    result << n;
    return result.str();
}

int main () 
{
    ofstream outFile;
    int Number_of_files=20;
    string filename;


  for (int i=0;i<Number_of_files;i++)
  {
        filename="file_" + IntToStr(i) +".txt";
        cout<< filename << "  \n";

        outFile.open(filename.c_str());
        outFile << filename<<" : Writing this to a file.\n";
        outFile.close();
  }


  return 0;
}
