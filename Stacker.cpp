#include "Stacker.h"
#include <iostream>
#include <fstream>
using namespace std;

Stacker::Stacker() {
  width = 0;
  height = 0;
  max_color = 0;
  picCount = 0;
  magic_number = "";
  pixels.resize(height, vector<pixel> (width));
}

Stacker::Stacker(string fileName, int n) {
  struct pixel p1;
  ifstream inputFile;
  this->fileName = fileName;
  picCount = n;
  inputFile.open(makeName(1));
  inputFile >> magic_number >> width >> height >> max_color;
  inputFile.close();
  pixels.resize(height, vector<pixel> (width));
  for(int r = 0; r < height; r++)
    for(int c = 0; c < width; c++)
      pixels[r][c] = p1;
  for(int i = 1; i <= picCount; i++)
    getPixelData(i);
  storePixelData();
  printInfo();
}

Stacker::pixel Stacker::pixel::operator+(pixel a) {
  this->red += a.red;
  this->green += a.green;
  this->blue += a.blue;
  return *this;
}

void Stacker::getPixelData(int n) {
  struct pixel p1;  
  ifstream inputFile;
  inputFile.open(makeName(n));
  inputFile >> magic_number >> width >> height >> max_color;
  for(int r = 0; r < height; r++)
    for(int c = 0; c < width; c++) {
      inputFile >> p1.red >> p1.green >> p1.blue;
      pixels[r][c] = pixels[r][c] + p1;
    }
  inputFile.close();
}

void Stacker::storePixelData()
{
  struct pixel p1;
  ofstream outputFile;
  outputFile.open(makeOutputName());
  outputFile << magic_number << endl << width << " " << height << endl << max_color << endl;
  for(int r = 0; r < height; r++)
    for(int c = 0; c < width; c++) {
      p1 = pixels[r][c];
      outputFile << p1.red / picCount << " " << p1.green / picCount << " " << p1.blue / picCount << endl;
    }
  outputFile.close(); 
}

void Stacker::printInfo() {
  cout << "Stacking Images: " << endl;
  for(int i = 1; i <= picCount; i++)
    cout << "\t" << makeName(i) << endl;
  cout << "Stacking succeeded." << endl << "Output written to: " << makeOutputName() << endl;
}

string Stacker::makeName(int n) {
  if(n < 10)
    return "ppms/" + fileName + "/" + fileName + "_00" + to_string(n) + ".ppm";
  else
    return "ppms/" + fileName + "/" + fileName + "_0" + to_string(n) + ".ppm";
}

string Stacker::makeOutputName() {
  return fileName + ".ppm";
}


