#include "constants.h"
#include "PlayerClass.h"
#include "GameClass.h"
#include "ShipClass.h"
#include "CellClass.h"
#include "HighScoreClass.h"
#include <iostream>
using namespace std;


bool GameClass::setUp()
{
	bool playOn;
	cout << "Player 1's turn to place their ships" << endl;
	playOn = p1.placeShips();
	
	if (playOn == true)
	{
		cout << "Player 2's turn to place their ships" << endl;
		playOn = p2.placeShips();
	}
	
	return (playOn);
}




void GameClass::play(bool rally)
{
	bool playOn = true;
	p1ShotCounter = 0;
	p2ShotCounter = 0;
	
	while (playOn)
	{
		p1.setHit();
		do
		{
			cout << endl << "Player 1" << endl;
			playOn = p1.attackBoard(p2); // Player 1 attacks Player 2's board
			
			p1ShotCounter = p1ShotCounter++;
		
			if (p2.getnumSunk() == NUM_SHIPS) // Checks if Player 2 has lost
			{
				cout << "Game over! Player 1 wins!" << endl;
				HighScoreClass score;
				score.HighScoreClass::handleMultiplayerScore(p1ShotCounter);
				playOn = false;
				rally = false;
			}
		}
		while (rally && p1.foundHit());
		
		p2.setHit();
		if (playOn)
		{
			do
			{
				cout << endl << "Player 2" << endl;
				playOn = p2.attackBoard(p1); // Player 2 attacks Player 1's board
				
				p2ShotCounter = p2ShotCounter++;
			
				if (p1.getnumSunk() == NUM_SHIPS) // Checks if Player 1 has lost
				{
					cout << "Game over! Player 2 wins!" << endl;
					HighScoreClass score;
					score.HighScoreClass::handleMultiplayerScore(p2ShotCounter);
					playOn = false;
					rally = false;
				}
			}
			while (rally && p2.foundHit());
		}
	}
}