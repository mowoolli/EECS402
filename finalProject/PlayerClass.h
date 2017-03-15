#ifndef _PLAYERCLASS_H_
#define _PLAYERCLASS_H_

// Player Class

#include "CellClass.h"
#include "ShipClass.h"
#include "constants.h"
#include "CheckStream.h"

class PlayerClass
{
	private:
		CellClass board[ROW_SIZE][COL_SIZE];
		ShipClass cruiser;
		ShipClass battleship;
		ShipClass carrier;
		ShipClass submarine;
		ShipClass destroyer;
		int numSunk;
		bool justHit;
	
	public:
		PlayerClass(); // Initializes all five ships and numSunk.
		void printBoard(char type); // Prints a player's board. During turn-based attacks, the print board will hide the opponent's ship locations
		bool placeShips(); // The placement menu to set a ship, delete a ship, or accept all placements
		int selectShip(); // Menu for the player to select which ship he wants to place.
		void setShip(ShipClass &vessel, ShipClass* vesselptr); // Sets a ship on the board
		bool checkInRange(char row, int &intRow, int &col); // Checks that the entered coordinates are on the board. Uses pass-by-reference to return two int values that have been zero-based for direct use with arrays
		void deleteShip(); // During setup, user can enter coordinates to remove a ship placed on their board
		
		





		void addSunk(); // numSunk + 1
		int getnumSunk(); // Returns the number of ships sunk on that players board
		CellClass *getCell(int row, int col);
		
		void setHit(); // Sets hit to true
		bool foundHit(); // Returns true if player found a hit on previous turn
		void printFleet();
		
   
   
   //temp code to randomly place ships
   void computerPlaceShips(); //If player two is computer, calls function to place ships
   void computerSetShip(ShipClass &vessel, ShipClass* vesselptr); // Computer sets a ship on the board
   



template <typename T> 
bool attackBoard(T &opponent) // Player can view their board and attack their opponent. If a ship is hit, it checks if the ship has been sunk and updates numSunk accordingly.
{
	char rowI, menu;
	int row, col;
	int val;
	bool playOn = true;
	bool success = false;
	
	while (playOn && !success)
	{
		cout << "Enter 'A' to attack, 'B' to see your board, or enter 'X' to quit the game: ";
		
		do
		{
			cin >> menu;
		}
		while (!checkStream(cin));
		
		menu = toupper(menu);
	
		if (menu == ATTACK)
		{
			printFleet();
			opponent.printBoard(HIDDEN); // Prints opponent's board without the ships
			cout << "Enter coordinates to attack: ";
			
			do
			{
				cin >> rowI >> col;
			}
			while (!checkStream(cin));
	
			rowI = toupper(rowI);
			
			if (checkInRange(rowI, row, col))
			{
				val = opponent.getCell(row,col)->getValue();
				if (val==OPEN_WATER) // If player misses, updates board appropriately
				{
					cout << "MISS!" << endl;
					opponent.getCell(row,col)->setValue(MISS);
					success = true;
					justHit = false;
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
			justHit = false;
		}
		else
		{
			cout << "Error: Value must be an 'A', 'B', or 'X'" << endl;
		}
	}
	
	return (playOn);
};

};


#endif
