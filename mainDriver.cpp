//CPSC1020 FALL2021
//PROGRAMMING ASSIGNMENT #2 (PA2)
//Skylar Hubbarth
//Last revised: 11/22/2021
//Cathy Kittelstad
//This program as a whole is designed to take images and manipulate them,
//based on the user's choice, to be either grayscaled, mirrored, green screened,
//or any combination of the three.

//*mainDriver.cpp*
//The following program includes the main function for this program. Here
//is where we wil call the functions created in the other .cpp files
//in order to complete our program.

//DISCLAIMER: Any random cout statements that have been commented out were
//there for the sake of debugging my program. I was going to just leave them in
//the program, but felt like that was inappropriate. I've now left them
//commented out because they made me laugh. I hope they make you laugh too.

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include "Header.h"
#include "Image.h"
#include "manip.h"
#include "Pixel.h"

using namespace std;

int printMenu();
int whichImage(string oldImage1, string oldImage2);

int main(int argc, char* argv[]) {
    // check that 3 arguments were entered at the command-line
    if(argc != 3) {
        printf("USAGE: <executable> <oldImage> <newImage>\n\n");
        return -1;
    }

    // open the two files sent in via the command line arguments
    ifstream oldImage1(argv[1]);
    ifstream oldImage2(argv[2]);

    if(!oldImage1 || !oldImage2) {
      cout << "ERROR: File(s) could not be opened." << endl;
      return -1;
   }

    //instantiating Images for each, sending file ptr to constructor
    Image inImage1(oldImage1);
    //cout << "no problems here" << inImage1.getHeader().getMagicNum() << endl;
    Image inImage2(oldImage2);

    int printChoice;
    int imageCount = 0;

    do {
      cout << endl;
      printChoice = printMenu();
      if(printChoice == 0) {
        return 0;
      }
      //create output file name using image count
      string count = to_string(imageCount);
      string outImage = "out_"+count+".ppm";
      //create ofstream file pointer using file name created
      ofstream imageFileName(outImage);
      //if choice is gray scale
      if (printChoice == 1) {
        int imageChoice;
        imageChoice = whichImage(argv[1], argv[2]); //gets string name of files
        //if choice is clemson paw
        if (imageChoice == 1) {
          //cout << "HAPPENING" << inImage1.getHeader().getMagicNum() << endl;
          Image copyImage = inImage1;
          //cout << "RUNNING 1101 0110" << copyImage.getHeader().getMagicNum();
          gray_scale(copyImage);
          copyImage.write_to(imageFileName);
        }
        //if choice is disney
        else if (imageChoice == 2) {
          Image copyImage = inImage2;
          gray_scale(copyImage);
          copyImage.write_to(imageFileName);
        }
        imageCount++;
      }
      //if choice is mirror
      else if (printChoice == 2) {
        int imageChoice;
        imageChoice = whichImage(argv[1], argv[2]); //gets string name of files
        //if choice is clemson paw
        if (imageChoice == 1) {
          //cout << "beep boop" << endl << endl;
          Image copyImage = inImage1;
          mirror(copyImage);
          copyImage.write_to(imageFileName);
        }
        //if choice is disney
        else if (imageChoice == 2) {
          Image copyImage = inImage2;
          mirror(copyImage);
          copyImage.write_to(imageFileName);
        }
        imageCount++;
      }
      //if choice is green screen
      else if (printChoice == 3) {
        cout << endl << "The Clemson Paw will be copied" << endl;
        cout << "on top of the Disney image." << endl;
        //create copy of Disney
        Image copyImage = inImage2;
        green_screen(copyImage, inImage1);
        copyImage.write_to(imageFileName);
        imageCount++;
      }

    }


    while(printChoice != 0);
    //close both input file pointers
    oldImage1.close();
    oldImage2.close();
}

//FUNCTION PRINTMENU
//Prints the menu of choices to the user.
//inputs: none
//outputs: the menu choice
int printMenu() {
  cout << "PA2 Image Manipulation" << endl;
  cout << "0. exit program " << endl << "1. gray scale" << endl;
  cout << "2. mirror" << endl << "3. green screen" << endl;
  cout << setw(9) << "- - > ";

  int choice;

  cin >> choice;

  return choice;
}

//FUNCTION WHICHIMAGE
//Prints the menu of image choices to the user.
//inputs: the names of the images
//outputs: the image choice
int whichImage(string oldImage1, string oldImage2) {
  int imageChoice = 0;
  while ((imageChoice != 1) && (imageChoice!= 2)) {
    cerr << endl << "PA2 Image Manipulation" << endl;
    cerr << "1. " << oldImage1 << endl;
    cerr << "2. " << oldImage2 << endl;
    cerr << setw(9) << "- - > ";
    cin >> imageChoice;
  }

  return imageChoice;
}




















//blah blah balah
