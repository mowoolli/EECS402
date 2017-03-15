#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "ImageClass.h"

using namespace std;
bool ImageClass::loadImage()
{
  ifstream inFile;
  string ifname;
  cout << "Enter string for PPM image file name to load: ";
  cin >> ifname;
  inFile.open(ifname.c_str());
  if (inFile.fail())
  {
    cout << "Unable to open input file! " << endl;
    exit(1);
  }

  validInputFound = false;
  while (!validInputFound)
  {
    inFile >> magicNumber;
    if (inFile.eof())
    {
      cout << "EOF before reading magic number: P3!" << endl;
      exit(2);
    }
    else if (magicNumber != "P3")
    {
      cout << "File does not begin with magic number: P3!" << endl;
      exit(2);
    }
//    else if (inFile.fail())
//    {
//      inFile.clear();
//      inFile.ignore(200, '\n');
//    }
    else
    {
      validInputFound = true;
    }
  }

  validInputFound = false;
  while (!validInputFound)
  {
    inFile >> imageWidth;
    if (inFile.eof())
    {
      cout << "EOF before reading image width!" << endl;
      exit(2);
    }
    else if (imageWidth <= 0)
    {
      cout << "Image width must be greater than zero!" << endl;
      exit(2);
    }
//    else if (inFile.fail())
//    {
//      inFile.clear();
//      inFile.ignore(200, '\n');
//    }
    else
    {
      validInputFound = true;
    }
  }

  validInputFound = false;
  while (!validInputFound)
  {
    inFile >> imageHeight;
    if (inFile.eof())
    {
      cout << "EOF before reading image height!" << endl;
      exit(2);
    }
    else if (imageHeight <= 0)
    {
      cout << "Image height must be greater than zero!" << endl;
      exit(2);
    }
//    else if (inFile.fail())
//    {
//      inFile.clear();
//      inFile.ignore(200, '\n');
//    }
    else
    {
      validInputFound = true;
    }
  }

  validInputFound = false;
  while (!validInputFound)
  {
    inFile >> maxColor;
    if (inFile.eof())
    {
      cout << "No maximum color specified in file!" << endl;
      exit(2);
    }
    else if (maxColor < 0)
    {
      cout << "Maximum color must be int between 0 and 255!" << endl;
      exit(2);
    }
    else if (maxColor > 255)
    {
      cout << "Maximum color must be int between 0 and 255!" << endl;
      exit(2);
    }
//    else if (inFile.fail())
//    {
//      inFile.clear();
//      inFile.ignore(200, '\n');
//    }
    else
    {
      validInputFound = true;
    }
  }

//  photoTwoDArray = new int*[imageHeight];
//  for (int r = 0; r < imageHeight; r++)
//  {
//    photoTwoDArray[r] = new int[imageWidth];
//  }

//  widthOfPixel = 3;

  pixelTwoDArray = new ColorClass*[imageHeight];
  for (int r = 0; r < imageHeight; r++)
  {
    pixelTwoDArray[r] = new ColorClass[imageWidth];
//    pixelTwoDArray[r] = new ColorClass[imageWidth/widthOfPixel];
  }

  for (int r = 0; r < imageHeight; r++)
  {
    for (int c = 0; c < imageWidth; c++)
    {
      inFile >> pixelTwoDArray[r][c].red;
      inFile >> pixelTwoDArray[r][c].green;
      inFile >> pixelTwoDArray[r][c].blue;
//      inFile >> pixel.red;
//      inFile >> pixel.green;
//      inFile >> pixel.blue;
    }
  }

  cout << "magic number: " << magicNumber << endl;
  cout << "image width: " << imageWidth << endl;
  cout << "image height: " << imageHeight << endl;
  cout << "max color: " << maxColor << endl;

  return (true);
}
bool ImageClass::saveImage()
{
  ofstream outFile;
  string ofname;
  cout << "Enter string for PPM file name to output: ";
  cin >> ofname;
  outFile.open(ofname.c_str());
  if (outFile.fail())
  {
    cout << "Unable to open output file!" << endl;
    return (false);
  }
  outFile << magicNumber << endl;
  outFile << imageWidth << " " << imageHeight << endl;
  outFile << maxColor << endl;
  for (int r = 0; r < imageHeight; r++)
  {
    for (int c = 0; c < imageWidth; c++)
    {
      outFile << pixelTwoDArray[r][c].red << " ";
      outFile << pixelTwoDArray[r][c].green << " ";
      outFile << pixelTwoDArray[r][c].blue << " ";
//      outFile << pixel.red << " ";
//      outFile << pixel.green << " ";
//      outFile << pixel.blue << " ";
    }
    outFile << endl;
  }
  outFile.close();
  return (true);  
}
bool ImageClass::annotateImage()
{
  ifstream annotationFile;
  string ifname;
  cout << "Enter string for PPM image file name to load: ";
  cin >> ifname;
  annotationFile.open(ifname.c_str());
  if (annotationFile.fail())
  {
    cout << "Unable to open the file containing pattern! " << endl;
    return (false);
  }
  return (true);
}
