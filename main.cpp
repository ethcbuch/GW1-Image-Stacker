/**
 * @file main.cpp
 * @author Ethan Buchanan and Hunter Johnson
 * @date 2022-09-27
 * @brief Main implementation
 * 
 * Prompts user for file and stacks that image
 */

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
