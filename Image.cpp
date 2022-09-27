//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/22/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*Image.cpp*
//The following program contains the class definition of a class Image
//defined in Image.h. It will put the image components together.

//DISCLAIMER: Any random cout statements that have been commented out were
//there for the sake of debugging my program. I was going to just leave them in
//the program, but felt like that was inappropriate. I've now left them
//commented out because they made me laugh. I hope they make you laugh too.

#include "Image.h"

using namespace std;

Image::Image(const Image& image) {
  myHeader = image.myHeader;
  pixels = image.pixels;
}

//constructor to instantiate from another image
Image::Image(ifstream &inFile) {
  Header myHeader = read_header(inFile);
  pixels = read_pixels(myHeader, inFile);
  //cout << "GOOD THIS WORKS" << myHeader.getMagicNum() << myHeader.getWidth()
  //<< myHeader.getHeight() << myHeader.getMaxVal();
}

//destructor
Image::~Image() {
}

//methods used by constructors to build the image
vector<Pixel> Image::read_pixels(Header myHeader, ifstream &inFile) {
  //int row = 0, col = 0;
  //red = green = blue = 0;
  int dimensions = myHeader.getWidth() * myHeader.getHeight();

  vector<Pixel> pixels(dimensions);
  unsigned char red, green, blue;

  for(int i = 0; i < dimensions; i++) {
    red = inFile.get();
    green = inFile.get();
    blue = inFile.get();

    Pixel temp(red,green,blue);
    pixels[i] = temp;
  }

  return pixels;
}

Header Image::read_header(ifstream &inFile) {
  string magicNum;
  int width, height, maxVal;
  //Header myHeader;
  inFile >> magicNum;
  inFile >> width;
  inFile >> height;
  inFile >> maxVal;
  inFile.ignore(256, '\n'); //necessary or will cause more coloring errors
  return Header(magicNum, width, height, maxVal);

}

//overloading operators
Pixel& Image::operator()(int x, int y) {
  //cout << "Before operator() " << myHeader.getMagicNum()
  //<< myHeader.getWidth() << myHeader.getHeight()
  //<< myHeader.getMaxVal() << endl;
  int temp = (myHeader.getWidth() * x) + y;
  //cout << "After operator() " << myHeader.getMagicNum()
  //<< myHeader.getWidth() << myHeader.getHeight()
  //<< myHeader.getMaxVal() << endl;

  return this->pixels[temp];

}

//assignment operators
Image& Image::operator = (const Image& obj) {

  pixels = obj.getPixels();
  myHeader = obj.getHeader();

  return *this;
} //not sure if this is necessary tbh

//methods to write an output file
void Image::write_header(ofstream &outFile) {
  //Header myHeader = myHeader;
  outFile << myHeader.getMagicNum() << endl << myHeader.getWidth() << " "
    << myHeader.getHeight() << endl << myHeader.getMaxVal() << endl;

}

void Image::write_to(ofstream &outFile) {
  write_header(outFile);

  for (Pixel& pix : this->pixels) {
    outFile << pix.r() << pix.g() << pix.b();
  }

}

//getters
const Header Image::getHeader() const {
  return myHeader;
}

const vector<Pixel> Image::getPixels() const {
  return pixels;
}
