#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

class Stacker
{
 public:
  Stacker();
  Stacker(std::string inputFile, int picCount);
  void readFile(std::string inputFile, int picCount);
  int getWidth();
  int getHeight();
  int getMax_color();
  int getpicCount();
  int getFileName();



 private:
  struct Pixel {
    int r;
    int g;
    int b;
  };
  std::string makeName(std::string file, int n); 
  std::string magic_number;
  int width;
  int height;
  int max_color;
  int picCount;
  std::string fileName;
  std::vector<Pixel> pixels;

};

#endif 
