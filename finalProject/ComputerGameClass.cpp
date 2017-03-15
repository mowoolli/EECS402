//
//  ComputerGameClass.cpp
//  b3
//
//  Created by Jordan Fleischer on 4/16/13.
//  Copyright (c) 2013 Jordan Fleischer. All rights reserved.
//

#include "ComputerGameClass.h"
#include "HighScoreClass.h"



bool ComputerGameClass::setUp()
{
	bool playOn = true;
	int difficulty;
  
	cout<< "SELECT DIFFICULTY\n"
   << "1. EASY\n"
   << "2. MEDIUM\n"
   << "3. HARD\n"
   << "4. VERY HARD\n";
   cin >> difficulty;
   comp.setDif(difficulty);
	
	cout << "Player 1's turn to place their ships" << endl;
	p1.placeShips();
//p1.computerPlaceShips();
	if (playOn == true)
	{	
		comp.computerPlaceShips(); // add this after inheritance is done

	}
	
	return (playOn);
}




void ComputerGameClass::play(bool rally)
{
	p1ShotCounter = 0;
	compShotCounter = 0;
	bool playOn = true;
	
	while (playOn)
	{
		p1.setHit();
		do
		{
			cout << endl << "Player 1" << endl;
			comp.printBoard(HIDDEN);
		
			playOn = p1.attackBoard(comp); // Player 1 attacks comp's board NEED TO TEMPLATE PLAYER1 ATTACK
			
			p1ShotCounter = p1ShotCounter++;
		
			if (comp.getnumSunk() == NUM_SHIPS) // Checks if Player 2 has lost
			{
				cout << "Game over! Player 1 wins!" << endl;
				HighScoreClass score;
				score.HighScoreClass::handleSinglePlayerScore(p1ShotCounter);
				playOn = false;
				rally = false;
			}
		}
		while (rally && p1.foundHit());
		
		comp.setHit();
		if (playOn == true)
		{
			do
			{
				comp.compAttack(p1); // comp attacks Player 1's board
				
				compShotCounter = compShotCounter++;
         
				if (p1.getnumSunk() == NUM_SHIPS) // Checks if Player 1 has lost
				{
					cout << "Game over! Computer wins!" << endl;
					HighScoreClass score;
					score.HighScoreClass::handleSinglePlayerScore(compShotCounter);
					playOn = false;
					rally = false;
				}
			}
			while (rally && comp.foundHit());
		}
	}
}
