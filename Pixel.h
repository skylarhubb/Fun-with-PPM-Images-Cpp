//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/05/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*Image.h*
//The following program contains the class declaration of a class Pixel.
//This file was created in Lab 10.

#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>

using namespace std;

class Pixel {
	private:
		unsigned char red, green, blue;
	public:
		//constructors
			//default constructor
		Pixel();
			//constructor that takes in rgb value
		Pixel(unsigned char r2, unsigned char g2, unsigned char b2);
			//constructor that takes in Pixel variable/cp const
		Pixel(const Pixel &pixel);
		//destructor
		~Pixel();
		//getters for rgb values
		unsigned char r() const;
		unsigned char g() const;
		unsigned char b() const;
		//non-constant reference getters for rgb values
		unsigned char& r();
		unsigned char& g();
		unsigned char& b();
		//assignment operator overload function
		Pixel& operator = (const Pixel &pixel);
		//output stream overload function
		friend std::ostream& operator << (std::ostream& out, const Pixel& pixel);

};


#endif
