#include <iostream>
#include "printMenu.h"

using namespace std;
int printMenu()
{
  int menuChoice;
  bool validMenuChoice;

  cout << endl;
  cout << "1. Annotate image with rectangle" << endl;
  cout << "2. Annotate image with pattern from file" << endl;
  cout << "3. Insert another image" << endl;
  cout << "4. Write out current image" << endl;
  cout << "5. Exit the program" << endl;
  cout << endl;
  cout << "Enter int for main menu choice: ";
  
  validMenuChoice = false;

  while (!validMenuChoice)
  {
    cin >> menuChoice;
    cout << endl;
    if (cin.fail() || (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 
        4 && menuChoice != 5))
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout << "Error: The menu choice must be an integer from 1 to 5! " << endl;
      cout << endl;
      cout << "1. Annotate image with rectangle" << endl;
      cout << "2. Annotate image with pattern from file" << endl;
      cout << "3. Insert another image" << endl;
      cout << "4. Write out current image" << endl;
      cout << "5. Exit the program" << endl;
      cout << endl;
      cout << "Enter int for main menu choice: ";
    }
    else
    {
      validMenuChoice = true;
    }
  }

  return (menuChoice);
}

