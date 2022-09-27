//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/22/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*manip.cpp*
//The following program contains the function definitions for the manipulation
//functions defined in manip.h. It will manipulate the image based on the
//user's choice.

//DISCLAIMER: Any random cout statements that have been commented out were
//there for the sake of debugging my program. I was going to just leave them in
//the program, but felt like that was inappropriate. I've now left them
//commented out because they made me laugh. I hope they make you laugh too.

#include "manip.h"

using namespace std;

// GRAY SCALE FUNCTION
// make each color pixel the average of the r, g, b components
// which will gray-scale the image
// inputs:  the image pointer
// outputs:  none
void gray_scale(Image &image) {
  int row = 0;
  int col = 0;
  int avg = 0;

  Header header = image.getHeader();
  Pixel pix = image(row,col);

  for (row = 0; row < header.getHeight(); row++) {
    for (col = 0; col < header.getWidth(); col++) {
      avg = (image(row, col).r() + image(row,col).g() +
              image(row,col).b()) / 3;
      image(row,col) = Pixel(avg, avg, avg);

    }
  }

}


//MIRROR FUNCTION
// flips an image's pixels over the y-axis
// which will mirror the image
// inputs:  the image pointer
// outputs:  none
void mirror(Image &image) {
  //cout << "hacking" << endl;
  //Header header = image.getHeader();
  Image copy1(image);

  int row, col;
  int height = image.getHeader().getHeight();
  int width = image.getHeader().getWidth();

  for (row = 0; row < height; row++) {
    //cout << "ok";
    for (col = 0; col < (width / 2 + 1); col++) {
      //cout << "cool";
      image(row, col).r() = copy1(row, width-col-1).r();
      image(row, width-col-1).r() = copy1(row, col).r();

      //cout << "hi";

      image(row, col).g() = copy1(row, width-col-1).g();
      image(row, width-col-1).g() = copy1(row, col).g();

      image(row, col).b() = copy1(row, width-col-1).b();
      image(row, width-col-1).b() = copy1(row, col).b();
    }
  }
}


//GREEN SCREEN FUNCTION
// remove any non g components from the r g b pixels
// which will green screen the image
// inputs:  the image pointer
// outputs:  none
void green_screen(Image &image1, Image &image2) { //clemson, disney
  int row, col;

  for (row = 0; row < image1.getHeader().getHeight(); row++) {
    for (col = 0; col < image1.getHeader().getWidth(); col ++) {

      if ((image2(row, col).r() != 0) && (image2(row, col).g() != 255) &&
      (image2(row,col).b() != 0)) {
            image1(row, col).r() = image2(row,col).r();
            image1(row, col).g() = image2(row,col).g();
            image1(row, col).b() = image2(row,col).b();
          }

    }
  }

}
