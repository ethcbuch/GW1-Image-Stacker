/**
 * @file Stacker.h
 * @author Ethan Buchanan and Hunter Johnson
 * @date 2022-09-26
 * @brief Class Declartion for Stacker class
 * 
 * The stacker class can take ppm images and overlay them to create a more clear image
 */

#ifndef STACKER_H
#define STACKER_H
#include <string>
#include <vector>


/**
 * Stacker Class which takes .ppms files and overlays them to create a clearer image
 *
 * @class Stacker Stacker.h "GW1-Image-Stacker/Stacker.h"
 * @brief Stacks images
 *
 */
class Stacker {
 public:

/**
 * Default Constuctor for Stacker class, sets everything to 0
 *
 * @post Resizes the Pixel Vector to the height and width 
 * 
 */
  Stacker();
  

/**
 * Parameterized Constuctor for stacker class, resizes, stacks, and creates output file of final image
 *
 * @param std::string fileName name of the image the user wants to stack
 * @param int picCount The number of layers the user wants to stack
 * @pre 
 * @post An output file with the final stacked image has been created in the main directory
 * 
 */
  Stacker(std::string fileName, int picCount);
  
 private:

/**
 * A struct of three ints
 *
 * @Stuct pixel
 * @brief Red, Green, and BLue values of a pixel of a image
 *
 */
  struct pixel {
    int red = 0;
    int green = 0;
    int blue = 0;
    pixel operator+(pixel a);
  };

/**
 * Retrieves data from a ppm file and sets Stacker member variables to the values from file, adds the values from the previous to the next, stacking the images
 *
 * @param int n the number of layers the image has stacked
 * @pre A vector of vectors of pixels exsists of a proper size
 * @return void 
 * @post All member varaibles of Stacker class have proper values from the file
 * 
 */
  void getPixelData(int n);

/**
 * Outputs the Pixel vector to the output file named after the image you are stacking
 *
 * @pre The ppm files have been read from and the image has been stacked
 * @return void 
 * @post A proper clear image ppm is created and outputed to a file
 * 
 */
  void storePixelData();

/**
 * Prints info to console showing file has been read
 * 
 * 
 */
  void printInfo();

/**
 * Creates the proper file path for each of the ppm files from 1-10
 *
 * @param int n What number of ppm file you are on 
 * @return std::string Returns a created filename that leads to a ppm file
 * 
 */
  std::string makeName(int n);

/**
 * Creates a name based on the image stacked to name the output file
 *
 * @return std::string Returns output file name
 * 
 */
  std::string makeOutputName();

  //PPM file type P3 or P6
  std::string magic_number;
  int width;
  int height;
  int max_color;
  int picCount;
  std::string fileName;
  std::vector<std::vector<pixel>> pixels;
};

#endif
