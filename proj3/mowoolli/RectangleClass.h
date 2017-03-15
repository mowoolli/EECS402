#ifndef _RECTCLASS_
#define _RECTCLASS_
class RectangleClass
{
  private:
    bool validRectMenuChoice;
    int rectSpecificationMethod;
    int upperLeftRow;
    int upperLeftColumn;
    int lowerRightRow;
    int lowerRightColumn;
    int numberOfRows;
    int numberOfColumns;
    int centerRow;
    int centerColumn;
    int halfNumberOfRows;
    int halfNumberOfColumns;

  public:
    bool makeRectangle();
};
#endif
