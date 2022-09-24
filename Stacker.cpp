#include "Stacker.h"
#include <iostream>
#include <fstream>
using namespace std;




Stacker::Stacker()
{
  int width = 0;
  int height = 0;
  int max_color = 0;
  int picCount = 0;
  string magic_number = " ";
  pixels.resize(width, vector<pixel> (height));
}

Stacker::Stacker(string fileName, int n)
{
  struct pixel p1;
  string name;
  ifstream inputFile;
  name = makeName(fileName, 1);
  p1.red = 0;
  p1.green = 0;
  p1.blue = 0;
  this->fileName = fileName;
  picCount = n;
  inputFile.open(name);
  inputFile >> magic_number >> width >> height >> max_color;
  inputFile.close();
  pixels.resize(width, vector<pixel> (height));
  for(int r = 0; r < height; r++)
    {
      for(int c = 0; c < width; c++)
	{
	  pixels[r][c] = p1;
	}
    }
  for(int i = 1; i <= picCount; i++)
    {
      getPixelData(this->fileName, i);
    }


  
}




string Stacker::makeName(std::string fileName, int n)
{
  if(n < 10)
    fileName = "ppms/" + fileName + "/" + fileName + "_00" + to_string(n) + ".ppm";
  else
    fileName = "ppms/" + fileName + "/" + fileName + "_0" + to_string(n) + ".ppm";
  return fileName;
}


void Stacker::getPixelData(string fileName, int n)
{
  struct pixel p1;  
  ifstream inputFile;
  string name = makeName(fileName, n);
  inputFile.open(name);
  inputFile >> magic_number >> width >> height >> max_color;
  for(int r = 0; r < height; r++)
    {
      for(int c = 0; c < width; c++)
	{
	  inputFile >> p1.red >> p1.green >> p1.blue;
	  pixels[r][c] = pixels[r][c] + p1;
	}
    }
  inputFile.close();
}





int Stacker::getWidth()
{
  return width;
}

int Stacker::getHeight()
{
  return height;
}

int Stacker::getMax_color()
{
  return max_color;
}

int Stacker::getpicCount()
{
  return picCount;
}
