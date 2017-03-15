#include "ComputerClass.h"
#include "HitClass.h"
#include "NodeClass.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ComputerClass::ComputerClass()
{
   activePtr = &first;
	first.setNextHC(&second);
	second.setNextHC(&third);
	third.setNextHC(&fourth);
	fourth.setNextHC(&fifth);
   fifth.setNextHC(NULL);


	cruiser.setLength(CRUISER_LENGTH, "cruiser");
	battleship.setLength(BATTLESHIP_LENGTH, "battleship");
	carrier.setLength(CARRIER_LENGTH, "carrier");
	submarine.setLength(SUBMARINE_LENGTH, "submarine");
	destroyer.setLength(DESTROYER_LENGTH, "destroyer");
	numSunk = 0;


   



}


void ComputerClass::setNextActive()
{
	activePtr = activePtr->getNextHC();
}

void ComputerClass::compAttack(PlayerClass &player)
{
   
   cout << "LENGTH OF ATTACK " << activePtr->getList()->size() << endl;
	if (activePtr->getList()->empty() || difficulty == EASY) //check if activePtr list is empty
	{
		randomAttack(player);
	}
	
	else
	{
		activeAttack(player);
	}
}

void ComputerClass::activeAttack(PlayerClass &player)
{
   
	if (activePtr->getList()->size() == 1)// if length =1
	{
		// attackRandomDirection
      LocationClass loc = activePtr->getList()->front();
      int row = loc.getRow();
      int col = loc.getCol();
      bool surrounded = checkSurrounded(player, row, col);
      int direction;
      
      bool foundLoc = false;
      while (!foundLoc) {
         if (surrounded) {
            direction = 0;
         } else{
            direction = rand()%4 + 1;
         }

         
         if (difficulty == VERYHARD) {
               int lengthLeft = 0;
               int lengthRight = 0;
               int lengthUp = 0;
            	int lengthDown = 0;
               for (int i = col -1; i >= 0,
                    checkOpen(player, row, i) ; i--) {
                  lengthLeft ++;
               }
               for (int i = col + 1; i <= 9,
                    checkOpen(player, row, i) ; i++) {
                  lengthRight ++;
               }
               for (int i = row -1; i >= 0,
                    checkOpen(player, i, col) ; i--) {
                  lengthUp ++;
               }
               for (int i = row + 1; i <= 9,
                    checkOpen(player, i, col) ; i++) {
                  lengthDown ++;
               }
         
            
            int directions [4] = {lengthUp, lengthDown, lengthRight, lengthLeft};
            int maxDir = lengthUp;
         	int index;
            for (int i = 0; i < 4; i++) {
               if (directions[i] > maxDir) {
                  maxDir = directions[i] ;
                  index = i;
               }
            }
            switch (index) {
               case 0:
                  direction = NORTH;
                  break;
               case 1:
                  direction = SOUTH;
                  break;
               case 2:
                  direction = EAST;
                  break;
               case 3:
                  direction = WEST;
                  break;
               default:
                  break;
            }
         }
         
            
            
         

         
         
         switch (direction) {
            case NORTH:
               if (checkOpen(player, row -1, col)) {
                  attackCoordinates(player, row-1, col);
                  foundLoc = true;
               }
               
               break;
            case EAST:
               if (checkOpen(player, row, col+1)) {
                  attackCoordinates(player, row, col+1);
                  foundLoc = true;
               }
               break;
            case SOUTH:
               if (checkOpen(player, row +1, col)) {
                  attackCoordinates(player, row+1, col);
                  foundLoc = true;
               }
               break;
            case WEST:
               if (checkOpen(player, row, col -1)) {
                  attackCoordinates(player, row, col-1);
                  foundLoc = true;
               }
               break;
               
            default:
               randomAttack(player);
               break;
         }
         
      }
      
	}
	else // length > 1
	{
      //determine orientation of line, randomly attack  one end
		// attack with direction
      int orientation = getOrientation(player);
      int randSide;
      bool foundLoc = false;
      
      LocationClass loc = activePtr->getList()->front();
      int activeLength = activePtr->getList()->size();
      int row = loc.getRow();
      int col = loc.getCol();

      while (foundLoc == false) {
         randSide = rand()%2 + 1;
      
         if (difficulty == VERYHARD) {
         	if (orientation == HORIZONTAL){
               int lengthLeft = 0;
                int lengthRight = 0;
               for (int i = col -1; i >= 0,
                    checkOpen(player, row, i) ; i--) {
                  lengthLeft ++;
               }
               for (int i = col + activeLength; i <= 9,
                    checkOpen(player, row, i) ; i++) {
                  lengthRight ++;
               }
               if (lengthLeft > lengthRight) {
                  randSide = 2;
               } else{
                  randSide = 1;
               }
               
            }
            if (orientation == VERTICAL){
               int lengthUp = 0;
               int lengthDown = 0;
               for (int i = row -1; i >= 0,
                    checkOpen(player, i, col) ; i--) {
                  lengthUp ++;
               }
               for (int i = row + activeLength; i <= 9,
                    checkOpen(player, i, col) ; i++) {
                  lengthDown ++;
               }
               if (lengthUp > lengthDown) {
                  randSide = 2;
               }else{
                  randSide = 1;
               }
               
            }
            
         }
         
         
         
         
         switch (randSide) {
            case 1:
               if (orientation == HORIZONTAL && checkOpen(player, row, col+activeLength)) {
                  attackCoordinates(player, row, col+activeLength);
                  foundLoc = true;
               } else if(orientation == VERTICAL&& checkOpen(player, row+activeLength, col)){
                  attackCoordinates(player, row+activeLength, col);
                  foundLoc = true;
               }
               
               break;
            case 2:
               if (orientation == HORIZONTAL && checkOpen(player, row, col-1)) {
                  attackCoordinates(player, row, col-1);
                  foundLoc = true;
               } else if(orientation == VERTICAL&& checkOpen(player, row-1, col)){
                  attackCoordinates(player, row-1, col);
                  foundLoc = true;
               }
               break;
               
            default:
               randomAttack(player);
               foundLoc = true;
               break;
         }
      }

         
   }
   
	
}

//Targeted pseudo-Code
//If(ActiveHitPtr.len() == 1)
//	validHits = N, S, E, W //Excluding edge, miss, sunk

void ComputerClass::randomAttack(PlayerClass &player)
{

   bool status = false;
   int row;
   int col;
   int val;
   
   
   if (difficulty == EASY || difficulty == MEDIUM) {
      while (status == false) {
         row = rand()%10;
         col = rand()%10;
         val = player.getCell(row,col)->getValue();
         if (val == HIT || val == MISS) {
            status = false;
         } else{
            status = true;
         }
         
      }
   }else{
      while (status == false) {
         row = rand()%10;
         if (row % 2 == 0) {// if row is even, col must be odd
            col = 1 + ((rand()/2*2)%10);
         } else{
            col = (((rand()/2)*2)%10);
         }
         
         
         val = player.getCell(row,col)->getValue();
         if (val == HIT || val == MISS) {
            status = false;
         } else{
            status = true;
         }
         
      }
   }
	attackCoordinates(player, row, col);
}

bool ComputerClass::attackCoordinates(PlayerClass &player, int row, int col)
{
   
	bool hit;
	int val;
	char rowC = 'A' + row;
	
	cout << endl << "Computer attacked at location " << rowC << col+1 << "." << endl;
	
	val = player.getCell(row,col)->getValue();
	if (val==OPEN_WATER) // If player misses, updates board appropriately
	{
			cout << "MISS!" << endl;
			player.getCell(row,col)->setValue(MISS);
			hit = false;
      
	}
	else if (val==OCCUPIED) // If player hits, updates board and checks if ship was sunk. If ship was sunk, adds to opponent's numSunk.
	{
      
      
			cout << "HIT!" << endl;
			player.getCell(row,col)->setValue(HIT);
			hit = true;
      
      if (difficulty == EASY) {
         if (player.getCell(row,col)->getOccupiedBy()->checkSunk())  //handle case where ship is sunk
         {
            player.addSunk();
            
         }
      }

      
      if (difficulty != EASY) {
         LocationClass location(row, col);
			activePtr->getList()->push_back(location);  //add location of hit to current hitList
      	activePtr->getList()->sort();

         if (player.getCell(row,col)->getOccupiedBy()->checkSunk())  //handle case where ship is sunk
			{
            player.addSunk();
            activePtr->setSunk();
            
            
            
            HitClass* nextPointer = activePtr->getNextHC();
   
            
            
            int tester = activePtr->getList()->size();
            for (int i = 0; i <  tester; i++) {
               LocationClass tempLoc = activePtr->getList()->front();
      			int tempRow = tempLoc.getRow();
               int tempCol = tempLoc.getCol();
               if (!player.getCell(tempRow,tempCol)->getOccupiedBy()->getSunk()) {  //if hit from unsunk ship, remove and put in next hitclass
                  
                  
                  activePtr->getList()->pop_front();											//added sunk ship because getSunk adds value to hits...
                  nextPointer->getList()->push_front(tempLoc);
                  
                  cout << "is not sunk" << endl;
               } else {//take from front and put on back
                  activePtr->getList()->pop_front();
                  activePtr->getList()->push_back(tempLoc);
                  cout << "is sunk" << endl;
               }
            }
      
      if (activePtr != NULL)cout << activePtr->getList()->size() << "TEST" << endl;
      if (activePtr->getNextHC() != NULL) {
         cout << activePtr->getNextHC()->getList()->size() << "TEST" << endl;
      }
    
            activePtr = activePtr->getNextHC();
            if (activePtr != NULL){
               activePtr->getList()->sort();
            }

			}
      }
      
      

	}
   
   

   
   
   if (activePtr != NULL) {
      if (activePtr->getList()->size() > 1) {
         
         int orientation = getOrientation (player);
         while (orientation==0) {
            cout << "DEFAULT\n";
            orientation = getOrientation(player);
         }
         
         
         if (checkCapped(player)){  // handle capped situation
            cout << "CAPPED!" << endl;

            HitClass* nextPointer = activePtr->getNextHC();
            
            
            while (activePtr->getList()->size() != 1) {
               LocationClass tempLoc = activePtr->getList()->back();  //remove last location on add to new attack
               activePtr->getList()->pop_back();
               nextPointer->getList()->push_front(tempLoc);
            }
         }
      }
   }

	return (hit);
}

bool ComputerClass::checkOpen(PlayerClass &player, int row, int col){
   bool status = true;
   if (row >= ROW_SIZE || row < 0 || col >= COL_SIZE || col < 0) {
      status = false;

   }else if ( (player.getCell(row,col)->getValue() == MISS
                || (player.getCell(row,col)->getValue() == HIT))) {
       status = false;
	
   }
   return status;
}


bool ComputerClass::checkSurrounded(PlayerClass &player, int row, int col){
   bool status = false;
   if (!checkOpen(player, row+1, col)
       && !checkOpen(player, row-1, col)
       && !checkOpen(player, row, col+1)
      && !checkOpen(player, row, col-1)
       ) {
      status = true;
   }
   
   return status;
   
}

int  ComputerClass::getOrientation (PlayerClass &player){
   int orientation;
   activePtr->getList()->sort();
  	int row1 = activePtr->getList()->front().getRow();
	int row2 = activePtr->getList()->back().getRow();
	int col1 = activePtr->getList()->front().getCol();
   int col2 = activePtr->getList()->back().getCol();
   
   
   cout << "CELLS " << row1 << col1 << " and " << row2 << col2 << endl;
   
   
   if (row1 == row2) {
      orientation = HORIZONTAL;
   }else if(col1 == col2){
      orientation = VERTICAL;
   } else{
      cout << "ERROR EXPECTED LINE BUT DID NOT FIND ONE\n";
      
      HitClass* nextPointer;
    	nextPointer = activePtr->getNextHC();

      LocationClass tempLoc = activePtr->getList()->back();  //remove last location on add to new attack
      activePtr->getList()->pop_back();
      nextPointer->getList()->push_front(tempLoc);
      
      return(0);
   }
   return orientation;
}


bool ComputerClass::checkCapped(PlayerClass &player){
   LocationClass tempLoc = activePtr->getList()->front();
   int tempRow1 = tempLoc.getRow();
   int tempCol1 = tempLoc.getCol();
   tempLoc = activePtr->getList()->back();
   int tempRow2 = tempLoc.getRow();
   int tempCol2 = tempLoc.getCol();
   int orientation = getOrientation (player);
   bool capped = false;
   bool leftBlocked = false;
   bool rightBlocked = false;
   bool upBlocked = false;
   bool downBlocked = false;
   
   
   switch (orientation) {
      case HORIZONTAL:
         cout << "HORIZONTAL LOC" << tempRow1 << tempCol1 << " and " << tempRow2 << tempCol2 << endl;
         if (tempCol1 - 1 < 0) {
            leftBlocked = true;
         }else if(player.getCell(tempRow1, tempCol1 - 1)->getValue() == MISS ||
                  player.getCell(tempRow1, tempCol1 - 1)->getValue() == HIT ){
            leftBlocked = true;
         }
         if (tempCol2 + 1 >= MAX_COL) {
            rightBlocked = true;
         }else if(player.getCell(tempRow2, tempCol2 + 1)->getValue() == MISS||
                  player.getCell(tempRow2, tempCol2 + 1)->getValue() == HIT){
            rightBlocked = true;
         }
         if (rightBlocked && leftBlocked) {
            capped = true;
         }
         
         break;
      case VERTICAL:
         cout << "VERTICAL LOC" << tempRow1 << tempCol1 << " and " << tempRow2 << tempCol2 << endl;
         if (tempRow1 - 1 < 0) {
            upBlocked = true;
         }else if(player.getCell(tempRow1 -1, tempCol1 )->getValue() == MISS ||
                  player.getCell(tempRow1 -1, tempCol1 )->getValue() == HIT){
            upBlocked = true;
         }
         if (tempRow2 + 1 >= MAX_COL) {
            downBlocked = true;
         }else if(player.getCell(tempRow2+1, tempCol2)->getValue() == MISS||
                  player.getCell(tempRow2+1, tempCol2)->getValue() == HIT){
            downBlocked = true;
         }
         if (upBlocked && downBlocked) {
            capped = true;
         }
         
         break;
      default:
        
         break;
   }
   return capped;
   
}
/*follow line
 
 hit->continue
 miss->continue
 edge->continue
 sunk->split by length of sunk ship (if needed)
 capped-> (valid is 0), cut one off
 

*/

void ComputerClass::computerPlaceShips(){
   computerSetShip(cruiser, &cruiser);
   computerSetShip(battleship, &battleship);
   computerSetShip(carrier, &carrier);
   computerSetShip(submarine, &submarine);
   computerSetShip(destroyer, &destroyer);
   cout << "Computer has placed ships\n";
}

void ComputerClass::computerSetShip(ShipClass &vessel, ShipClass* vesselptr){
   srand((unsigned)time(0));
   int shipLength = vessel.getLength();
   const int RIGHT = 0;
   const int LEFT = 1;
   const int UP = 2;
   const int DOWN = 3;
   bool status = false;
   
   while (status == false) {
      int row = rand() % 10; //random number 0-10
      int col = rand() % 10;
      int direction = rand() % 4; // 0 for right, 1 for left, 2 for up, 3 for down
      
      status = true;
      
      switch (direction) {
         case RIGHT:
            if (col + shipLength > COL_SIZE - 1) { //make sure doesnt exceed boundaries
               status = false;
            }
            if (status) { //make sure no existing ships
               for (int i = 0; i < shipLength; i++) {
                  if (board[row][i+col].getValue() == OCCUPIED){
                     status = false;
                  }
               }
            }
            if (status) { //place ship
               for (int i = 0; i < shipLength; i++) {
                  vessel.setPointer(&board[row][col+i], i);
                  board[row][col+i].setOccupiedBy(vesselptr);
               }
            }
            break;
            
         case LEFT:
            if (col - shipLength < 0) {
               status = false;
            }
            if (status) {
               for (int i = 0; i < shipLength; i++) {
                  if (board[row][col-i].getValue() == OCCUPIED){
                     status = false;
                  }
               }
            }
            if (status) { //place ship
               for (int i = 0; i < shipLength; i++) {
                  vessel.setPointer(&board[row][col-i], shipLength-i);
                  board[row][col-i].setOccupiedBy(vesselptr);
               }
            }
            break;
            
         case UP:
            if (row - shipLength < 0) {
               status = false;
            }
            if (status) {
               for (int i = 0; i < shipLength; i++) {
                  if (board[row-i][col].getValue() == OCCUPIED){
                     status = false;
                  }
               }
            }
            if (status) { //place ship
               for (int i = 0; i < shipLength; i++) {
                  vessel.setPointer(&board[row-i][col], shipLength-i);
                  board[row-i][col].setOccupiedBy(vesselptr);
               }
            }
            break;
            
         case DOWN:
            if (row + shipLength > ROW_SIZE - 1) {
               status = false;
            }
            if (status) {
               for (int i = 0; i < shipLength; i++) {
                  if (board[row+i][col].getValue() == OCCUPIED){
                     status = false;
                  }
               }
            }
            if (status) { //place ship
               for (int i = 0; i < shipLength; i++) {
                  vessel.setPointer(&board[row+i][col], i);
                  board[row+i][col].setOccupiedBy(vesselptr);
               }
            }
            break;
         default:
            break;
      }
      
      
   }

}



void ComputerClass::printBoard(char type)
{
	char row = MIN_ROW; // Controls printing the row labels
	int val;
	
	cout << endl << "  ";
	
	for (int j=MIN_COL; j<=COL_SIZE; j++) // Prints the column labels
	{
		cout << j << " ";
	}
	
	cout << endl;
	
	for (int i=0; i<ROW_SIZE; i++)
	{
		cout << row << " "; // Prints the appropriate row label
		for (int k=0; k<COL_SIZE; k++) // Prints the values in each cell
		{
			val = board[i][k].getValue();
			if (type == HIDDEN && val == OCCUPIED) // Hides all ships if printing an opponents board for attack
			{
				cout << "-" << " ";
			}
			else if (val == OPEN_WATER)
			{
				cout << "-" << " ";
			}
			else if (val == OCCUPIED)
			{
				cout << "#" << " ";
			}
			else if (val == MISS)
			{
				cout << "O" << " ";
			}
			else if (val == HIT)
			{
				cout << "X" << " ";
			}
		}
		row++;
		cout << endl;
	}
	
	cout << endl;
}



bool ComputerClass::checkInRange(char row, int &intRow, int &col)
{
	bool withinRange = true;
	
	row = toupper(row);
	
	if (row < MIN_ROW || row > MAX_ROW)
	{
		cout << "Error: Row must be between A and J." << endl;
		withinRange = false;
	}
	else
	{
		intRow = int(row-MIN_ROW); // Turns the char row into an int value on a zero-based number system
	}
	
	if (col < MIN_COL || col > MAX_COL)
	{
		cout << "Error: Column must be between 1 and 10." << endl;
		withinRange = false;
	}
	else
	{
		col -= MIN_COL; // Turns the col value into a zero-based number system
	}
	
	return (withinRange);
}


void ComputerClass::addSunk()
{
	numSunk++;
}




int ComputerClass::getnumSunk()
{
	return(numSunk);
}




CellClass* ComputerClass::getCell(int row, int col)
{
	return (&board[row][col]);
}


void ComputerClass::setDif(int dif)
{
   difficulty = dif;
}

void ComputerClass::setHit()
{
	justHit = true;
}

bool ComputerClass::foundHit()
{
	return(justHit);
}




