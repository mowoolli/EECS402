#ifndef _NODECLASS_H_
#define _NODECLASS_H_

// Node Class

#include "CellClass.h"

class NodeClass
{
	private:
		NodeClass* next;
		NodeClass* prev;
		int row;
		int col;

	public:
		NodeClass(int rval, int cval);
		void setNext(NodeClass* next);
		void setPrev(NodeClass* prev);
		int getRow();
		int getCol();
};

#endif