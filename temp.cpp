
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


string makeName(string file, int n)
{
  string name;
  if(n < 10)
    name = "ppms/" + file + "/" + file + "_00" + to_string(n) + ".ppm";
  else
    name = "ppms/" + file + "/" + file + "_0" + to_string(n) + ".ppm";
  return name;
}

struct pixel {
  int red;
  int blue;
  int green;
};

pixel operator+(pixel a, pixel b)
{
  struct pixel p1;
  p1.red = a.red + b.red;
  p1.green = a.green + b.green;
  p1.blue = a.blue + b.blue;
  return p1;
}

void getPixelData(string file, n) //Can just use private member 
{
  struct pixel p1;
  struct pixel p2;
  ifstream inputFile;
  string name = makeName(file, n);
  string magic_number;
  int col,row,max;
  vector<vector<pixel>> pixels;
  inputFile.open(name);
  inputFile >> magic_number >> col >> row >> max;
  pixels.resize(col, vector<pixel> (row));
  for(int r = 0; r < row; r++)
    {
      
    }



  
  for(int r = 0; r < row; r++)
    {
      for(int c = 0; c < col; c++)
	{
	  inputFile >> p1.red >> p1.green >> p1.blue;
	  pixels[r][c] = pixels[r][c] + p1;
	}
    }
  inputFile.close();
}
  





int main()
{
  string file;
  cin >> file;
  getPixelData(file);




  
  return 0;
}
