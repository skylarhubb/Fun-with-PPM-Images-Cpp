//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/22/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*Header.cpp*
//The following program contains the class definition of a class Header
//defined in Header.h. It will create a Header for the ppm image.

//DISCLAIMER: Any random cout statements that have been commented out were
//there for the sake of debugging my program. I was going to just leave them in
//the program, but felt like that was inappropriate. I've now left them
//commented out because they made me laugh. I hope they make you laugh too.

#include "Header.h"

using namespace std;

//default constructor
Header::Header() {
  magicNum = "P6";
  width = 1280;
  height = 720;
  maxVal = 255;
}

Header::Header(ifstream& inFile) {
  inFile >> magicNum >> width >> height >> maxVal;
}

Header::Header(string &magicNum, int width, int height, int maxVal) {
  this->magicNum = magicNum;
  this->width = width;
  this->height = height;
  this->maxVal = maxVal;
}

//destructor: purpose unknown
Header::~Header() {
}

//getters here
//const thrown around everywhere to show the terminal who's boss
const int Header::getWidth() const {
  return width;
}

const int Header::getHeight() const {
  return height;
}

const int Header::getMaxVal() const {
  return maxVal;
}

const string Header::getMagicNum() const {
  return magicNum;
}

//overloading operators
istream& operator>>(istream &inFile, Header &hdr) {
  inFile >> hdr.magicNum >> hdr.width >> hdr.height >> hdr.maxVal;
  return inFile;
}

ostream& operator<<(ostream &outFile, Header &hdr) {
  outFile << hdr.magicNum << endl << endl;
  outFile << hdr.width << " " << hdr.height << endl;
  outFile << endl << hdr.maxVal << " " << endl << endl << endl;
  return outFile;

}
