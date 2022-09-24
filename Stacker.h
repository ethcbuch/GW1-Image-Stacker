#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

class Stacker
{
 public:
  Stacker();
  Stacker(std::string fileName, int picCount);
  void readFile(std::string fileName, int picCount);
  int getWidth();
  int getHeight();
  int getMax_color();
  int getpicCount();
  
 private:
<<<<<<< HEAD
  std::string makeName(int n); 
=======
  struct Pixel {
    int r;
    int g;
    int b;
    Pixel& operator+(const Pixel& rhs) {
       r += rhs.r;
       g += rhs.g;
       b += rhs.b;

       return *this;
    }
  };
<<<<<<< HEAD
  std::string makeName(std::string file, int n); 
>>>>>>> e7732edd561792c766a21ad8914c5c906aa45251
=======
  std::string makeName(std::string fileName, int n);
  void getPixelData(std::string fileName, int n);
>>>>>>> 2373e9f445405e568f33bbb3ac9cc86422fceef4
  std::string magic_number;
  int width;
  int height;
  int max_color;
  int picCount;
  std::string fileName;
  std::vector<std::vector<Pixel>> pixels;
};

#endif 
