//
//  SimulationGameClass.h
//  b5
//
//  Created by Jordan Fleischer on 4/19/13.
//  Copyright (c) 2013 Jordan Fleischer. All rights reserved.
//

#ifndef __b5__SimulationGameClass__
#define __b5__SimulationGameClass__

#include <iostream>
#include <cstdlib>
#include "CellClass.h"
#include "ShipClass.h"
#include "PlayerClass.h"
#include "constants.h"
#include "ShipClass.h"
#include "CellClass.h"
#include "ComputerClass.h"
#include <fstream>


class SimulationGameClass
{
private:
   PlayerClass p1;
	ComputerClass comp;
	int p1ShotCounter;
	int compShotCounter;


   
public:
	SimulationGameClass(int difficulty);
   bool setUp(); // Players place their ships on their boards
   void play(); // Players take turns attacking each other's boards

};
#endif /* defined(__b5__SimulationGameClass__) */
