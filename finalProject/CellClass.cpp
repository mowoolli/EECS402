#include "constants.h"
#include "CellClass.h"
#include "ShipClass.h"
#include <iostream>
#include <ctype.h>
using namespace std;

CellClass::CellClass()
{
	value = OPEN_WATER;
	occupiedBy = NULL;
}




void CellClass::setOccupiedBy(ShipClass* vesselptr)
{
	value = OCCUPIED;
	occupiedBy = vesselptr;
}




void CellClass::setValue(int num)
{
	value = num;
}




void CellClass::resetCell()
{
	value = OPEN_WATER;
	occupiedBy = NULL;
}




int CellClass::getValue() const
{
	return(value);
}




ShipClass* CellClass::getOccupiedBy()
{
	return (occupiedBy);
}


