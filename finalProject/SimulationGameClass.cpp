//
//  SimulationGameClass.cpp
//  b5
//
//  Created by Jordan Fleischer on 4/19/13.
//  Copyright (c) 2013 Jordan Fleischer. All rights reserved.
//

#include "SimulationGameClass.h"
SimulationGameClass::SimulationGameClass(int difficulty){
     	comp.setDif(difficulty);
}


bool SimulationGameClass::setUp()
{
	p1.computerPlaceShips();// use this to have random placement
	
	
	return (true);
}




void SimulationGameClass::play()
{
	p1ShotCounter = 0;
	compShotCounter = 0;
   
	bool playOn = true;
	while (playOn)
	{
		if (playOn)
		{
			comp.compAttack(p1); // comp attacks Player 1's board
         p1.printBoard(FULL);
			compShotCounter++;
         cout << compShotCounter << endl;
         
			if (p1.getnumSunk() == NUM_SHIPS) // Checks if Player 1 has lost
			{
				cout << "Game over! Computer wins!" << endl;
				playOn = false;
				
				ofstream outFile;
               
				outFile.open(NAME_OF_RESULTS_FILE.c_str(), ios::app);
				if (outFile.fail())
				{
					cout << "Unable to open output file" << endl;
					exit(1);
				}
            outFile << compShotCounter << endl;
				cout << "Computer won in " << compShotCounter << " shots\n";
				outFile.close();
         
			}
		}
	}
}

