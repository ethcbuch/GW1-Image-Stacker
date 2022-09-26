#include "Stacker.h"
#include <iostream>
using namespace std;

int main() {
  string file;
  int n;
  cout << "Please enter the image you wish to stack: ";
  cin >> file;
  cout << "Please enter the number of images: ";
  cin >> n;
  Stacker image(file, n);
  return 0;
}
