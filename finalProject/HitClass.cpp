#include "HitClass.h"

#include <iostream>
using namespace std;

HitClass::HitClass()
{

	openNorth = true;
	openEast = true;
	openWest = true;
	openSouth = true;
	multipleShips = 0;
	sunk = false;
}

void HitClass::setNextHC(HitClass* address)
{
	nextHC = address;
}

HitClass* HitClass::getNextHC()
{
	return (nextHC);
}


void HitClass::setSunk()
{
	sunk = true;
}

void HitClass::checkSurroundings(PlayerClass &player)
{
   openEast = openNorth	=openSouth = openWest = true;
   
   LocationClass loc = hitList.front();
	int row = loc.getRow();
   int col = loc.getCol();

	if (row + 1 < ROW_SIZE) {
      if (!(player.getCell(row+1,col)->getValue() == OPEN_WATER))
          {
             openSouth = false;
          }
   }else{openSouth = false;}
   
   if (row - 1 >= 0) {
      if (!(player.getCell(row-1,col)->getValue() == OPEN_WATER))
      {
         openNorth = false;
      }
   }else{openNorth = false;}
   
   if (col + 1 < COL_SIZE) {
      if (!(player.getCell(row,col+1)->getValue() == OPEN_WATER))
      {
         openEast = false;
      }
   }else{openEast = false;}
   
   if (col - 1 >= 0) {
      if (!(player.getCell(row,col-1)->getValue() == OPEN_WATER))
      {
         openWest = false;
      }
   }else{openWest = false;}
   
	
	
}

list <LocationClass> *HitClass::getList(){
   return &hitList;
}


