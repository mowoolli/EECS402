#include "NodeClass.h"
#include <iostream>
using namespace std;

NodeClass::NodeClass(int rval, int cval)
{
	row = rval;
	col = cval;
	next = NULL;
	prev = NULL;
}

int NodeClass::getRow()
{
	return (row);
}

int NodeClass::getCol()
{
	return (col);
}