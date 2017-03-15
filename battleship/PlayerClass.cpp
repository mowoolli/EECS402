#include "constants.h"
#include "PlayerClass.h"
#include <iostream>
#include <cstdlib>
using namespace std;

PlayerClass::PlayerClass()
{
	cruiser.setLength(CRUISER_LENGTH, "cruiser");
	battleship.setLength(BATTLESHIP_LENGTH, "battleship");
	carrier.setLength(CARRIER_LENGTH, "carrier");
	submarine.setLength(SUBMARINE_LENGTH, "submarine");
	destroyer.setLength(DESTROYER_LENGTH, "destroyer");
	numSunk = 0;
}




void PlayerClass::printBoard(char type)
{
	char row = MIN_ROW; // Controls printing the row labels
	int val;
	
	cout << endl << "  ";
	
	for (int j=MIN_COL; j<=COL_SIZE; j++) // Prints the column labels
	{
		cout << j << " ";
	}
	
	cout << endl;
	
	for (int i=0; i<ROW_SIZE; i++)
	{
		cout << row << " "; // Prints the appropriate row label
		for (int k=0; k<COL_SIZE; k++) // Prints the values in each cell
		{
			val = board[i][k].getValue();
			if (type == HIDDEN && val == OCCUPIED) // Hides all ships if printing an opponents board for attack
			{
				cout << OPEN_WATER << " ";
			}
			else
			{
				cout << val << " ";
			}
		}
		row++;
		cout << endl;
	}
	
	cout << endl;
}




bool PlayerClass::placeShips()
{
	bool validBoard = false;
	int option = 1;
	int ship;
	
	while (validBoard == false && option != EXIT)
	{
		printBoard(FULL);
		
		cout << "Select an option:" << endl <<
		"1. Place a ship" << endl <<
		"2. Delete a ship" << endl <<
		"3. Accept all placements" << endl <<
		"0. Exit menu" << endl;
		
		cin >> option;
		
		if (option == PLACE_SHIP)
		{
			ship = selectShip();
			
			switch (ship)
			{
				case CRUISER:
				{
					setShip(cruiser, &cruiser);
					break;
				}
				case BATTLESHIP:
				{
					setShip(battleship, &battleship);
					break;
				}
				case CARRIER:
				{
					setShip(carrier, &carrier);
					break;
				}
				case SUBMARINE:
				{
					setShip(submarine, &submarine);
					break;
				}
				case DESTROYER:
				{
					setShip(destroyer, &destroyer);
					break;
				}
			}
		}
		
		else if (option == DELETE_SHIP)
		{
			deleteShip();
		}
		
		else if (option == ACCEPT_ALL)
		{
			validBoard = true;
			
			if (!cruiser.isPlaced())
			{
				cout << "Error: Cruiser has not been placed." << endl;
				validBoard = false;
			}
			
			if (!battleship.isPlaced())
			{
				cout << "Error: Battleship has not been placed." << endl;
				validBoard = false;
			}
			
			if (!carrier.isPlaced())
			{
				cout << "Error: Carrier has not been placed." << endl;
				validBoard = false;
			}
			
			if (!submarine.isPlaced())
			{
				cout << "Error: Submarine has not been placed." << endl;
				validBoard = false;
			}
			
			if (!destroyer.isPlaced())
			{
				cout << "Error: Destroyer has not been placed." << endl;
				validBoard = false;
			}
		}
		
		else if (option != EXIT)
		{
			cout << "Error: Invalid option. Please enter a value 0-3." << endl;
		}
	}
	
	return (validBoard);
}




int PlayerClass::selectShip()
{
	bool validChoice = false;
	int choice;
	
	printBoard(FULL);
	
	while (validChoice == false)
	{
		cout << "Select a ship:" << endl;
		
		if (!cruiser.isPlaced())
		{
			cout << "1. Cruiser (5)" << endl;
		}
		
		if (!battleship.isPlaced())
		{
			cout << "2. Battleship (4)" << endl;
		}
		
		if (!carrier.isPlaced())
		{
			cout << "3. Carrier (3)" << endl;
		}
		
		if (!submarine.isPlaced())
		{
			cout << "4. Submarine (3)" << endl;
		}
		
		if (!destroyer.isPlaced())
		{
			cout << "5. Destroyer (2)" << endl;
		}
		
		cout << "0. Exit menu" << endl;
		
		cin >> choice;
		
		if (0 <= choice && choice <= 5)
		{
			validChoice = true;
		}
		
		else
		{
			cout << "Error: Invalid option. Please enter a value 0-5." << endl;
		}
	}
	
	return (choice);
}




void PlayerClass::setShip(ShipClass &vessel, ShipClass* vesselptr)
{
	char rowI, rowF;
	int colStart, colEnd;
	int rowStart, rowEnd;
	bool inOpenWater = true;
	
	if (!vessel.isPlaced())
	{
		printBoard(FULL);
		cout << "Enter the starting coordinates: ";
		cin >> rowI >> colStart;
		
		if (checkInRange(rowI, rowStart, colStart))
		{
			cout << "Enter the ending coordinates " << vessel.getLength() << " spaces away: ";
			cin >> rowF >> colEnd;
		
			if (checkInRange(rowF, rowEnd, colEnd))
			{
		
				if (rowStart > rowEnd) // Ensures the for loops run correctly by having the start values less than the end values
				{
					swap(rowStart, rowEnd);
				}
				else if (colStart > colEnd)
				{
					swap(colStart, colEnd);
				}
		
				if (rowStart == rowEnd) // Placement of a horizontal ship
				{
			
					if (abs(colEnd-colStart)+1 == vessel.getLength()) // Checks the coordinates entered match the ship size
					{
				
						for (int i=colStart; i<=colEnd; i++) // Runs through each location in the ship's path. If a ship already occupies the space, sets inOpenWater to false.
						{
						
							if (board[rowStart][i].getValue() == OCCUPIED && inOpenWater == true)
							{
								cout << "Error: Placement conflicts with an existing ship" << endl;
								inOpenWater = false;
							}
						}
					
						if (inOpenWater)
						{
							for (int i=colStart; i<=colEnd; i++) // Sets each spot on the ship to point to a corresponding cell and vice versa
							{;
								vessel.setPointer(&board[rowStart][i], i-colStart);
								board[rowStart][i].setOccupiedBy(vesselptr);
							}
						}
					}
					
					else
					{
						cout << "Error: Coordinates do not match ship size." << endl;
					}
				}
			
				else if (colStart == colEnd) // Placement of a vertical ship
				{
				
					if (abs(rowEnd-rowStart)+1 == vessel.getLength()) // Checks the coordinates entered match the ship size
					{
					
						for (int i=rowStart; i<=rowEnd; i++) // Runs through each location in the ship's path. If a ship already occupies the space, sets inOpenWater to false.
						{
						
							if (board[i][colStart].getValue() == OCCUPIED && inOpenWater == true)
							{
								cout << "Error: Placement conflicts with an existing ship" << endl;
								inOpenWater = false;
							}
						}
					
						if (inOpenWater)
						{
							for (int i=rowStart; i<=rowEnd; i++) // Sets each spot on the ship to point to a corresponding cell and vice versa
							{
								vessel.setPointer(&board[i][colStart], i-rowStart);
								board[i][colStart].setOccupiedBy(vesselptr);
							}
						}
					}
					
					else
					{
						cout << "Error: Coordinates do not match ship size." << endl;
					}
				}
				
				else
				{
					cout << "Error: Cannot place ships on a diagonal." << endl;
				}
			}
		}
	}
	
	else
	{
		cout << "Error: Ship has already been placed."<< endl;
	}
}




bool PlayerClass::checkInRange(char row, int &intRow, int &col)
{
	bool withinRange = true;
	
	row = toupper(row);
	
	if (row < MIN_ROW || row > MAX_ROW)
	{
		cout << "Error: Row must be between A and J." << endl;
		withinRange = false;
	}
	else
	{
		intRow = int(row-MIN_ROW); // Turns the char row into an int value on a zero-based number system
	}
	
	if (col < MIN_COL || col > MAX_COL)
	{
		cout << "Error: Column must be between 1 and 10." << endl;
		withinRange = false;
	}
	else
	{
		col -= MIN_COL; // Turns the col value into a zero-based number system
	}
	
	return (withinRange);
}




void PlayerClass::deleteShip()
{
	char rowI;
	int row, col;
	
	cout << "Enter coordinates of ship to remove: ";
	
	cin >> rowI >> col;
	
	checkInRange(rowI, row, col);
	
	if(board[row][col].getValue() == OCCUPIED)
	{
		board[row][col].getOccupiedBy()->resetValues();
	}
	else
	{
		cout << "Error: No ship occupies that location." << endl;
	}
}

/*

bool PlayerClass::attackBoard(PlayerClass &opponent)
{
	char rowI, menu;
	int row, col;
	int val;
	bool playOn = true;
	bool success = false;
	
	while (playOn && !success)
	{
		cout << "Enter 'A' to attack, 'B' to see your board, or enter 'X' to quit the game: ";
		cin >> menu;
		menu = toupper(menu);
	
		if (menu == ATTACK)
		{
			opponent.printBoard(HIDDEN); // Prints opponent's board without the ships
			cout << "Enter coordinates to attack: ";
			cin >> rowI >> col;
			rowI = toupper(rowI);
			
			if (checkInRange(rowI, row, col))
			{
				val = opponent.getCell(row,col)->getValue();
				if (val==OPEN_WATER) // If player misses, updates board appropriately
				{
					cout << "MISS!" << endl;
					opponent.getCell(row,col)->setValue(MISS);
					success = true;
				}
				else if (val==OCCUPIED) // If player hits, updates board and checks if ship was sunk. If ship was sunk, adds to opponent's numSunk.
				{
					cout << "HIT!" << endl;
					opponent.getCell(row,col)->setValue(HIT);
					if (opponent.getCell(row,col)->getOccupiedBy()->checkSunk())
					{
						opponent.addSunk();
					}
					success = true;
				}
				else if (val==MISS || val==HIT)
				{
					cout << "Error: Coordinates have already been attacked!" << endl;
				}
			}
		}
		else if (menu == BOARD)
		{
			printBoard(FULL);
		}
		else if (menu == CHAREXIT)
		{
			playOn = false;
		}
		else
		{
			cout << "Error: Value must be an 'A', 'B', or 'X'" << endl;
		}
	}
	
	return (playOn);
}


*/

void PlayerClass::addSunk()
{
	numSunk++;
}




int PlayerClass::getnumSunk()
{
	return(numSunk);
}




CellClass* PlayerClass::getCell(int row, int col)
{
	return (&board[row][col]);
}








//TEMP FUNCTIONS TO RANDOMLY PLACE SHIPS

void PlayerClass::computerPlaceShips(){
   computerSetShip(cruiser, &cruiser);
   computerSetShip(battleship, &battleship);
   computerSetShip(carrier, &carrier);
   computerSetShip(submarine, &submarine);
   computerSetShip(destroyer, &destroyer);
   cout << "Computer has placed ships\n";
}

void PlayerClass::computerSetShip(ShipClass &vessel, ShipClass* vesselptr){
   srand((unsigned)time(0));
   int shipLength = vessel.getLength();
   const int RIGHT = 0;
   const int LEFT = 1;
   const int UP = 2;
   const int DOWN = 3;
   bool status = false;
   
   while (status == false) {
      int row = rand() % 10; //random number 0-10
      int col = rand() % 10;
      int direction = rand() % 4; // 0 for right, 1 for left, 2 for up, 3 for down
      
      status = true;
      
      switch (direction) {
         case RIGHT:
            if (col + shipLength > COL_SIZE - 1) { //make sure doesnt exceed boundaries
               status = false;
            }
            if (status) { //make sure no existing ships
               for (int i = 0; i < shipLength; i++) {
                  if (board[row][i+col].getValue() == OCCUPIED){
                     status = false;
                  }
               }
            }
            if (status) { //place ship
               for (int i = 0; i < shipLength; i++) {
                  vessel.setPointer(&board[row][col+i], i);
                  board[row][col+i].setOccupiedBy(vesselptr);
               }
            }
            break;
            
         case LEFT:
            if (col - shipLength < 0) {
               status = false;
            }
            if (status) {
               for (int i = 0; i < shipLength; i++) {
                  if (board[row][col-i].getValue() == OCCUPIED){
                     status = false;
                  }
               }
            }
            if (status) { //place ship
               for (int i = 0; i < shipLength; i++) {
                  vessel.setPointer(&board[row][col-i], shipLength-i);
                  board[row][col-i].setOccupiedBy(vesselptr);
               }
            }
            break;
            
         case UP:
            if (row - shipLength < 0) {
               status = false;
            }
            if (status) {
               for (int i = 0; i < shipLength; i++) {
                  if (board[row-i][col].getValue() == OCCUPIED){
                     status = false;
                  }
               }
            }
            if (status) { //place ship
               for (int i = 0; i < shipLength; i++) {
                  vessel.setPointer(&board[row-i][col], shipLength-i);
                  board[row-i][col].setOccupiedBy(vesselptr);
               }
            }
            break;
            
         case DOWN:
            if (row + shipLength > ROW_SIZE - 1) {
               status = false;
            }
            if (status) {
               for (int i = 0; i < shipLength; i++) {
                  if (board[row+i][col].getValue() == OCCUPIED){
                     status = false;
                  }
               }
            }
            if (status) { //place ship
               for (int i = 0; i < shipLength; i++) {
                  vessel.setPointer(&board[row+i][col], i);
                  board[row+i][col].setOccupiedBy(vesselptr);
               }
            }
            break;
         default:
            break;
      }
      
      
   }

}




