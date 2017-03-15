#include "constants.h"
#include "ShipClass.h"
#include "CellClass.h"
#include <iostream>
using namespace std;

void ShipClass::setLength(int num, string shipname)
{
	hits = 0;
	placed = false;
	length = num;
	name = shipname;
	Ptr = new CellClass*[length]; // Creates an array of CellClass pointers the length of the ship
   
   sunkShip = false;
}




bool ShipClass::isPlaced()
{
	return (placed);
}




void ShipClass::setPointer(CellClass* cellptr, int num)
{
	Ptr[num] = cellptr; // Assigns a cell address to the num spot on the ship
	placed = true;
}




void ShipClass::resetValues()
{
	for (int i=0; i<length; i++)
	{
		Ptr[i]->resetCell(); // Resets the information stored in the cell pointed to by each spot on the ship
		Ptr[i] = NULL; // Resets the ship pointer of each spot to null
	}
	placed = false;
}




int ShipClass::getLength() const
{
	return (length);
}




bool ShipClass::checkSunk()
{
	bool sunk = false;
	hits++;
	if (hits == length)
	{
		cout << "You sunk their " << name << "!" << endl;
		sunk = true;
      sunkShip = true;
	}
	
	return(sunk);
}


bool ShipClass::getSunk(){
   return sunkShip;
}