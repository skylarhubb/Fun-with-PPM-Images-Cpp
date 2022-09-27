//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/22/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*Header.h*
//The following program contains the class declaration of a class Header.

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

class Header {
  private:
    string magicNum;
    int width, height, maxVal;
  public:
    Header();
    //more constructors?
    //Header(const Header &hdr); (NOT NECESSARY)
    Header(ifstream& inFile);
    Header(string &magicNum, int width, int height, int maxVal);
    //destructor
    ~Header();
    //getters here?
    const string getMagicNum() const;
    const int getWidth() const;
    const int getHeight() const;
    const int getMaxVal() const;

    //overloading operators?
    friend ostream& operator<<(ostream &outFile, Header &hdr);
    friend istream& operator>>(istream &inFile, Header &hdr);
    //Header& operator=(const Header &hdr); (NOT NECESSARY)

};



#endif
