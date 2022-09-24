
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

vector<vector<pixel>> getPixelData(vector<vector<pixel>> temp,string file, int n) //Can just use private member 
{
  struct pixel p1;
  int row,col;
  ifstream inputFile;
  vector<vector<pixel>> pixels;
  pixels = temp;
  if(n >= 1)
    {
      string name = makeName(file, n);
      string magic_number;
      int max;
      inputFile.open(name);
      inputFile >> magic_number >> col >> row >> max;
      for(int r = 0; r < row; r++)
	{
	  for(int c = 0; c < col; c++)
	    {
	      inputFile >> p1.red >> p1.green >> p1.blue;
	      pixels[r][c] = pixels[r][c] + p1;
	    }
	}
      inputFile.close();
      return getPixelData(pixels, file, n - 1);
    }
  else if(n == 0)
    {
      return pixels;
    }
  return temp;
}



string makeOutputName(string fileName)
{
  string name = fileName + ".ppm";
  return name;
}

void storePixelData()
{
  struct pixel p1;
  ofstream outputFile;
  outputFile.open(makeOutputName(fileName));
  if(!outputFile)
    {
      cout << "Error: could not open output file" << endl;
      exit(1);
    }
  outputFile << P3 << endl;
  outputFile << width << " " << height << endl;
  outputFile << max_color << endl;
  for(int r = 0; r < height; r++)
    {
      for(int c = 0; c < width; c++)
	{
	  p1 = pixels[r][c];
	  outputFile << p1.red / picCount << " " << p1.green / picCount << " " << p1.blue / picCount << endl;
	}
    }
  outputFile.close(); 
}


int main()
{
  string file;
  cin >> file;
  storePixelData(file, 600, 600, 255, "P3", 10);
  return 0;
}
