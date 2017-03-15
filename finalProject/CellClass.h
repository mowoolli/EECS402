#ifndef _BOARDCLASS_H_
#define _BOARDCLASS_H_

// Board Class

class ShipClass;

class CellClass
{
	private:
		int value;
		ShipClass* occupiedBy;

	public:
		CellClass(); // Initializes the CellClass variables
		void setOccupiedBy(ShipClass* vesselptr); // Points the cell to a ship and sets it to OCCUPIED
		void setValue(int num); // Sets the value of a cell
		void resetCell(); // Resets all the cell variables
		int getValue() const; // Returns the value of a cell
		ShipClass* getOccupiedBy(); // Returns the pointer to the occupying ship
};

#endif