#ifndef _IMAGECLASS_
#define _IMAGECLASS_

#include "ColorClass.h"

class ImageClass
{
  private:
    bool validInputFound;
    std::string magicNumber;
    int imageWidth;
    int imageHeight;
    int maxColor;
    int widthOfPixel;   

  public:
    ColorClass pixel;
    ColorClass **pixelTwoDArray;
//    int **photoTwoDArray;
    bool loadImage();
    bool saveImage();
    bool annotateImage();
};
#endif
