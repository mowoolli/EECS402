// BATTLESHIP

/*
NOTES:
I was unable to make a Ship constructor work inside the Player declaration (probably something you just can't do.
May need to do additional trouble shooting.... cin of the wrong datatype
Did not delete pointers

Clear the output screen (probably after each option is selected... especially between each player)3

Removing ships from list that have already been placed or cannot be deleted

p2.attackBoard(p1)... may want to flip the function call.
*/

#include "constants.h"
#include "CellClass.h"
#include "ShipClass.h"
#include "PlayerClass.h"
#include "GameClass.h"
#include "ComputerGameClass.h"
#include "HighScoreClass.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <list>

using namespace std;

int printStartMenu();




int main()
{
	int menu;
	
	menu = printStartMenu();
	
	switch (menu)
	{
		case ONLINE:
		{
			// Online version here
			break;
		}
		
		case LOCALLY:
		{
			GameClass game;
	
			if (game.setUp())
			{
				game.play();
			}
			break;
		}
		
		case COMPUTER:
		{
			ComputerGameClass game;
         
			if (game.setUp())
			{
				game.play();
			}
			break;
		}
		
		case HIGH_SCORES:
		{
			// High score table here
			HighScoreClass print;
                        print.HighScoreClass::printHighScoreList();
			break;
		}
	}
	
	cout << "Thanks for playing Battleship!" << endl;

}





int printStartMenu() // Determines what type of game the user would like to play
{
	int choice;
	
	cout << "Welcome to Battleship!" << endl <<
	"What would you like to do?" << endl <<
	"1. Play 2 player game online" << endl <<
	"2. Play 2 player game locally" << endl <<
	"3. Play against the computer" << endl <<
	"4. View high scores" << endl <<
	"0. Exit" << endl;
	
	cin >> choice;
	
	return (choice);
}

