#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

class Stacker
{
 public:
  Stacker();
  Stacker(std::string fileName, int picCount);
  void printInfo();
 private:
  struct pixel {
    int red;
    int green;
    int blue;
    pixel operator+(pixel a);
  };
  void storePixelData();
  std::string makeOutputName();
  std::string makeName(int n);
  void getPixelData(int n);
  std::string magic_number;
  int width;
  int height;
  int max_color;
  int picCount;
  std::string fileName;
  std::vector<std::vector<pixel>> pixels;
};

#endif 
