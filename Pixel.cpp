//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/05/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*Pixel.cpp*
//The following program contains the class definition of a class Pixel
//defined in Pixel.h. This was created in Lab 10.

#include "Pixel.h"
using namespace std;

//default constructor
Pixel::Pixel() {
  red = 0;
  green = 0;
  blue = 0;
}

//constructor that takes in rgb value
Pixel::Pixel(unsigned char r2, unsigned char g2, unsigned char b2) {
  red = r2;
  green = g2;
  blue = b2;
}

//constructor that takes in Pixel variable/cp const
Pixel::Pixel(const Pixel &pixel) {
  red = pixel.red;
  green = pixel.green;
  blue = pixel.blue;
}

//destructor
Pixel::~Pixel() {
  return;
}

//getters for rgb values
unsigned char Pixel::r() const {
  return red;
}
unsigned char Pixel::g() const {
  return green;
}
unsigned char Pixel::b() const {
  return blue;
}
//non-constant reference getters for rgb values
unsigned char& Pixel::r() {
  return red;
}
unsigned char& Pixel::g() {
  return green;
}
unsigned char& Pixel::b() {
  return blue;
}
//assignment operator overload function
Pixel& Pixel::operator = (const Pixel& pixel) {
  red = pixel.red;
  green = pixel.green;
  blue = pixel.blue;
  return *this;
}
//output stream overload function
ostream& operator << (ostream& out, const Pixel& pixel) {
  out << pixel.red << pixel.green << pixel.blue;
  return out;
}
