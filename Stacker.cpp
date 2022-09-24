#include "Stacker.h"
#include <iostream>
#include <fstream>

using namespace std;

Stacker::Stacker() {
  int width = 0;
  int height = 0;
  int max_color = 0;
  int picCount = 0;
  string magic_number = " ";
  pixels.resize(width, vector<Pixel>(height));
}

Stacker::Stacker(string fileName, int n) {



}

string Stacker::makeName(std::string fileName, int n) {
  if(n < 10)
    fileName = "ppms/" + fileName + "/" + fileName + "_00" + to_string(n) + ".ppm";
  else
    fileName = "ppms/" + fileName + "/" + fileName + "_0" + to_string(n) + ".ppm";
  return fileName;
}


void Stacker::getPixelData(string fileName, int n) {
  struct Pixel p1;
  
  ifstream inputFile;

  string name = makeName(fileName, n);

  inputFile.open(name);

  inputFile >> magic_number >> width >> height >> max_color;

  pixels.resize(width, vector<Pixel>(height));

  for(int r = 0; r < height; r++) {
      for(int c = 0; c < width; c++) {
	  inputFile >> p1.r >> p1.g >> p1.b;
	  pixels[r][c] = pixels[r][c] + p1;
	}
    }
  
  inputFile.close();
}

int Stacker::getWidth() {
  return width;
}

int Stacker::getHeight() {
  return height;
}

int Stacker::getMax_color() {
  return max_color;
}

int Stacker::getpicCount() {
  return picCount;
}
