#ifndef _HITCLASS_H_
#define _HITCLASS_H_

// Hit Class

#include "LocationClass.h"
#include "PlayerClass.h"
#include <list>

class HitClass
{
	private:
		bool openNorth;
		bool openEast;
		bool openSouth;
		bool openWest;
		int multipleShips;
		HitClass* nextHC;
		bool sunk;
   	list <LocationClass> hitList;

	public:
		HitClass();
   	list <LocationClass>* getList();
		void setNextHC(HitClass* address);
		HitClass* getNextHC();
		void setSunk();
		void checkSurroundings(PlayerClass &player);
};

#endif