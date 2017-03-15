#ifndef _COMPUTERCLASS_H_
#define _COMPUTERCLASS_H_

// Computer Class

#include "PlayerClass.h"
#include "HitClass.h"
#include "NodeClass.h"
#include "constants.h"
#include "CellClass.h"
#include "ShipClass.h"

class ComputerClass
{
	private:
		HitClass first;
		HitClass second;
		HitClass third;
		HitClass fourth;
		HitClass fifth;
		HitClass* activePtr;
		int direction; 

		CellClass board[ROW_SIZE][COL_SIZE];
		ShipClass cruiser;
		ShipClass battleship;
		ShipClass carrier;
		ShipClass submarine;
		ShipClass destroyer;
	
		int numSunk;
		

	public:
		ComputerClass();
		void compAttack(PlayerClass &player); // A controller function to determine which type of attack to use
		bool attackCoordinates(PlayerClass &player, int row, int col); // Actually attacks the player's board and updates it accordingly
		void randomAttack(PlayerClass &player); // Determines the location to randomly attack
		void activeAttack(PlayerClass &player); // Attacks when there is an active Ptr
		void randomDirectionAttack(PlayerClass &player); // Attacks when active Ptr but no direction
		void activeDirectionAttack(PlayerClass &player); // Attacks when active Ptr and known direction
		void setNextActive();
      bool checkOpen(PlayerClass &player, int row, int col);
      bool checkSurrounded(PlayerClass &player, int row, int col);
  		 int getOrientation (PlayerClass &player);
   bool checkCapped(PlayerClass &player);
   

   void computerPlaceShips(); //If player two is computer, calls function to place ships
   void computerSetShip(ShipClass &vessel, ShipClass* vesselptr); // Computer sets a ship on the board
		


		void printBoard(char type); // Prints a player's board. During turn-based attacks, the print board will hide the opponent's ship locations
		bool checkInRange(char row, int &intRow, int &col); // Checks that the entered coordinates are on the board. Uses pass-by-reference to return two int values that have been zero-based for direct use with arrays
		void addSunk(); // numSunk + 1
		int getnumSunk(); // Returns the number of ships sunk on that players board
		CellClass *getCell(int row, int col);

				
};

#endif
