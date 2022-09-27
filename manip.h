//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/22/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*manip.h*
//The following program contains the function prototypes for the image
//manipulation functions, defined in manip.cpp.

#ifndef MANIP_H
#define MANIP_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Image.h"
#include "Pixel.h"
#include "Header.h"

using namespace std;

void gray_scale(Image &image);
void mirror(Image &image);
void green_screen(Image &image1, Image &image2);


#endif
