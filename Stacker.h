#ifndef STACKER_H
#define STACKER_H
#include <string>
#include <vector>

class Stacker {
 public:
  Stacker();
  Stacker(std::string fileName, int picCount);
  
 private:
  struct pixel {
    int red = 0;
    int green = 0;
    int blue = 0;
    pixel operator+(pixel a);
  };
  void getPixelData(int n);
  void storePixelData();
  void printInfo();
  std::string makeName(int n);
  std::string makeOutputName();
  std::string magic_number;
  int width;
  int height;
  int max_color;
  int picCount;
  std::string fileName;
  std::vector<std::vector<pixel>> pixels;
};

#endif
