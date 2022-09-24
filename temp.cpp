#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


string makeName(string file, int n)
{
  string name;
  name = file + "/" + file + "_00" + n + ".ppms";
  return name;
}


int main()
{
  string file;
  cin >> file;
  for(int i = 1; i < 11; i++)
    {
      file = makeName(file, i);
      cout <<  file << endl;
    }
  return 0;
}





  
}
