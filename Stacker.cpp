#include "Stacker.h"
#include <iostream>
#include <fstream>
using namespace std;

Stacker::Stacker()
{
  width = 0;
  height = 0;
  max_color = 0;
  picCount = 0;
  magic_number = " ";
  pixels.resize(height, vector<pixel> (width));
}

Stacker::Stacker(string fileName, int n)
{
  struct pixel p1;
  string name;
  ifstream inputFile;
  this->fileName = fileName;
  name = makeName(1);
  p1.red = 0;
  p1.green = 0;
  p1.blue = 0;
  picCount = n;
  inputFile.open(name);
  inputFile >> magic_number >> width >> height >> max_color;
  inputFile.close();
  pixels.resize(height, vector<pixel> (width));
  for(int r = 0; r < height; r++)
    {
      for(int c = 0; c < width; c++)
	{
	  pixels[r][c] = p1;
	}
    }
  for(int i = 1; i <= picCount; i++)
    {
      getPixelData(i);
    }
  storePixelData();
}

void Stacker::storePixelData()
{
  struct pixel p1;
  ofstream outputFile;
  outputFile.open(makeOutputName());
  outputFile << magic_number << endl;
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

string Stacker::makeOutputName()
{
  string name = fileName + ".ppm";
  return name;
}

string Stacker::makeName(int n)
{
  string file;
  if(n < 10)
    file = "ppms/" + fileName + "/" + fileName + "_00" + to_string(n) + ".ppm";
  else
    file = "ppms/" + fileName + "/" + fileName + "_0" + to_string(n) + ".ppm";
  return file;
}

void Stacker::getPixelData(int n)
{
  struct pixel p1;  
  ifstream inputFile;
  string name = makeName(n);
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

Stacker::pixel Stacker::pixel::operator+(pixel a)
{
  struct pixel p1;
  p1.red = this->red + a.red;
  p1.green = this->green + a.green;
  p1.blue = this->blue + a.blue;
  return p1;
}

void Stacker::printInfo()
{
  cout << "Stacking Images: " << endl;
  for(int i = 1; i <= picCount; i++)
    {
      cout << "\t" << makeName(i) << endl;
    }
  cout << "Stacking succeeded." << endl;
  cout << "Output written to: " << makeOutputName() << endl;
}
