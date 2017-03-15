//
//  ComputerGameClass.h
//  b3
//
//  Created by Jordan Fleischer on 4/16/13.
//  Copyright (c) 2013 Jordan Fleischer. All rights reserved.
//

#ifndef __b3__ComputerGameClass__
#define __b3__ComputerGameClass__

#include <iostream>
#include "CellClass.h"
#include "ShipClass.h"
#include "PlayerClass.h"
#include "constants.h"
#include "ShipClass.h"
#include "CellClass.h"
#include "ComputerClass.h"


class ComputerGameClass
{
private:
  PlayerClass p1;
  ComputerClass comp;
	int p1ShotCounter;
	int compShotCounter;  
   
   
public:
   
   bool setUp(); // Players place their ships on their boards
   void play(bool rally); // Players take turns attacking each other's boards
};

#endif /* defined(__b3__ComputerGameClass__) */
