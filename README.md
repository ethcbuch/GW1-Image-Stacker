# GW1-Image-Stacker


The Image Stacker Group Project by Hunter Johnson and Ethan Buchanan

This program takes in a select file name inside of the ppms folder, and then reads in the ppm data from the files and stacks the images to result in a clearer image.

Design Decisions:

Main: we decided to have all the chunky work of the program all in the parameterized constructor so that all main had to do was get the file name and number of pictures from the user and then declare a stacker for that image, so instead of having public functions that get called in main, all you have to do is call the parameterized constructor with a file name and picture count and all the work gets done in there.

Main: getPixelData and storePixelData are the two main functions of the program which do as their name entails; Get pixel data takes and stacks into the 2D pixel vector the values for each respective pixel adding them together as it goes; store Pixel data does exactly as the name entails it takes the 2D pixel vector and divides all values by picCount to get the average of the values and then stores it to an outputFile

Secondary: we made helper functions makeOutputName and makeName just to have an easy way to call and make names as well as unrequired private member variables to use in the helper functions to make life easier

Secondary: because we had made makeName a private member function we made printInfo as a public member function so that main could just call it and it would print the info without too much trouble or needing get functions to pull values to main for printing


How to run:
Requirements: ppm files are all grouped in a folder in the ppms folder, if they are not function will not be able to locate them
1. Open directory
2. type "make" and press enter
3. Pray something hasn't decided to brake
4. type "./stacker" and press enter
5. Enter requested info
6. Boom now you have your stacked image file

Challenges:
Number 1: Getting the struct pixel addition operator to overload and work; it was so finicky and annoying and took the most effort to get to work
Number 2: Deciding who was right and wrong in reference to where {} should go
Number 3: Just as a whole getting the stuff to work
Number 4: Figuring out 2D vectors, it wasn't all that hard but very finicky when it came to getting it to work, once you figure it out though its not nearly as bad as it looks in the beginning


Sharing the work:
First we discussed how we were going to do it and drew out a map
Then Hunter went into a temp.cpp file and figured out the mechanics of a function and compiled and tested it after he got it working Ethan would convert it to use private member values and work in the Stacker.cpp file
And then just like once we got close to a final project we just both looked at the same screen and figured out the bugs

