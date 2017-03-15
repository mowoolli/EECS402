#include <iostream>
#include "RectangleClass.h"

using namespace std;
bool RectangleClass::makeRectangle()
{
  cout << "1. Specify upper left and lower right corners of rectangle" << endl;
  cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
  cout << "3. Specify extent from center of rectangle" << endl;
  cout << "Enter int for rectangle specification method: ";

  validRectMenuChoice = false;

  while (!validRectMenuChoice)
  {
    cin >> rectSpecificationMethod;
    cout << endl;
    if (cin.fail() || (rectSpecificationMethod != 1 && rectSpecificationMethod
        != 2 && rectSpecificationMethod != 3))
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout << "Error: The menu choice must be an integer from 1 to 3! " << endl;
      cout << endl;
      cout << "1. Specify upper left and lower right corners of rectangle" << endl;
      cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
      cout << "3. Specify extent from center of rectangle" << endl;
      cout << "Enter int for rectangle specification method: ";
//      return (false);
    }
    else
    {
      validRectMenuChoice = true;
    }
  }

  if (rectSpecificationMethod == 1)
  {
    cout << "Enter upper left corner row and then column: ";
    cin >> upperLeftRow;
    cin >> upperLeftColumn;
    cout << "Enter lower right corner row and then column: ";
    cin >> lowerRightRow;
    cin >> lowerRightColumn;
  }
  else if (rectSpecificationMethod == 2)
  {
    cout << "Enter upper left corner row and then column: ";
    cin >> upperLeftRow;
    cin >> upperLeftColumn;
    cout << "Enter int for number of rows: ";
    cin >> numberOfRows;
    cout << "Enter int for number of columns: ";
    cin >> numberOfColumns;
  }
  else if (rectSpecificationMethod == 3)
  {
    cout << "Enter rectangle center row and then column: ";
    cin >> centerRow;
    cin >> centerColumn;
    cout << "Enter int for half number of rows: ";
    cin >> halfNumberOfRows;
    cout << "Enter int for half number of columns: ";
    cin >> halfNumberOfColumns;
  }

  return (true);
}
