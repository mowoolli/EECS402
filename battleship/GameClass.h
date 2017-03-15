#ifndef _GAMECLASS_H_
#define _GAMECLASS_H_

// Game Class

#include "CellClass.h"
#include "ShipClass.h"
#include "PlayerClass.h"
#include "HighScoreClass.h"

class GameClass
{
	private:
		PlayerClass p1;
		PlayerClass p2;
		int p1ShotCounter;
		int p2ShotCounter;

   
	public:

   
		bool setUp(); // Players place their ships on their boards
		void play(); // Players take turns attacking each other's boards
};

#endif
