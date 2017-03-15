#include <iostream>
#include "printMenu.h"
#include "ImageClass.h"
#include "RectangleClass.h"

using namespace std;
int main()
{
  ImageClass uploadPhoto;
  ImageClass annotatePhoto;
  RectangleClass addRectToPhoto;
  uploadPhoto.ImageClass::loadImage();
  int menuSelection = printMenu();
  while (menuSelection != 5)
  {
    if (menuSelection == 1)
    {
//      cout << "1 works!" << endl;
      addRectToPhoto.RectangleClass::makeRectangle();
      menuSelection = printMenu();
    }
    if(menuSelection == 2)
    {
//      cout << "2 works!" << endl;
      annotatePhoto.ImageClass::annotateImage();
      menuSelection = printMenu();
    }
    if(menuSelection == 3)
    {
      cout << "3 works!" << endl;
      menuSelection = printMenu();
    }
    if(menuSelection == 4)
    {
      uploadPhoto.ImageClass::saveImage();
      menuSelection = printMenu();
    }
  }
  if (menuSelection == 5)
  {
    cout << "Thank you for using this program" << endl;
  }
  return(0);
}
