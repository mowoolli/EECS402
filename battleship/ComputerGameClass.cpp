//
//  ComputerGameClass.cpp
//  b3
//
//  Created by Jordan Fleischer on 4/16/13.
//  Copyright (c) 2013 Jordan Fleischer. All rights reserved.
//

#include "ComputerGameClass.h"

bool ComputerGameClass::setUp()
{

	bool playOn = true;
	cout << "Player 1's turn to place their ships" << endl;
	p1.computerPlaceShips();// use this to have random placement
p1.printBoard(FULL);
   //p1.placeShips();
	
	if (playOn == true)
	{	
		comp.computerPlaceShips(); // add this after inheritance is done

	}
	
	return (playOn);
}




void ComputerGameClass::play()
{
	p1ShotCounter = 0;
	compShotCounter = 0;

	bool playOn = true;
	while (playOn)
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
		}
		
		if (playOn)
		{
			cout << endl << "Comp" << endl;
			comp.compAttack(p1); // comp attacks Player 1's board
			//p1.printBoard(HIDDEN);//print players board for testing
         
			compShotCounter = compShotCounter++;

			if (p1.getnumSunk() == NUM_SHIPS) // Checks if Player 1 has lost
			{
				cout << "Game over! Computer wins!" << endl;

                                HighScoreClass score;
                                score.HighScoreClass::handleSinglePlayerScore(compShotCounter);

				playOn = false;
			}
		}
	}
}
