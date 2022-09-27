//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/22/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*Image.h*
//The following program contains the class declaration of a class Image.


#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Header.h"
#include "Pixel.h"

using namespace std;

class Image {
  private:
    Header myHeader;
    vector<Pixel> pixels; //vector of pixels for the image
  public:
    //constructor to instantiate from an input file
    Image(const Image& image);
    //constructor to instantiate from another image
    Image(ifstream &inFile);
    //destructor
    ~Image();

    //methods used by constructors to build the image
    vector<Pixel> read_pixels(Header theHeader, ifstream &inFile);
    Header read_header(ifstream &inFile);

    //overloading operators
    Pixel& operator() (int x, int y);
    //assignment operators
    Image& operator= (const Image& obj);

    //methods to write an output file
    void write_header(ofstream &outFile);
    void write_to(ofstream &outFile);

    //getters
    const Header getHeader() const; //returns Header
    const vector<Pixel> getPixels() const; //returns the vector of Pixels


};





#endif
