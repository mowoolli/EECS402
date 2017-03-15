#ifndef _SHIPCLASS_H_
#define _SHIPCLASS_H_

//#include "CellClass.h"
// Ship Class

#include <iostream>
using namespace std;

class CellClass;

class ShipClass
{
	private:
		int length;
		CellClass** Ptr;
		bool placed;
		string name;
		int hits;
  		 bool sunkShip;

	public:
		void setLength(int num, string shipname); // Initializes all the variables of the ShipClass
		bool isPlaced(); // Returns true if the ship is already on the board
		void setPointer(CellClass* cellptr, int num); // Points the ship's num array location to it's corresponding cell
		void resetValues(); // Deletes a ship by removing all associated values
		int getLength() const; // Returns the length of the ship
		bool checkSunk(); // Returns true if the ship has been sunk
   
   bool getSunk();
};


#endif