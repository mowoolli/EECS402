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
#include "CheckStream.h"
#include "HighScoreClass.h"
#include "SimulationGameClass.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <list>

using namespace std;

int printStartMenu(bool rally);




int main()
{
	int menu = 1;
	bool rally = false;
	
	cout << "Welcome to Battleship!" << endl;
	
	while (menu != EXIT)
	{
		menu = printStartMenu(rally);
	
		switch (menu)
		{
			case LOCALLY:
			{
				GameClass game;
	
				if (game.setUp())
				{
					game.play(rally);
				}
				break;
			}
		
			case COMPUTER:
			{
				ComputerGameClass game;
         
				if (game.setUp())
				{
					game.play(rally);
				}
				break;
			}
			
			case SIMULATION:
		{
         ofstream outFile;
         
         outFile.open("/Users/Jordan/Desktop/bship/bship/results.txt", ios::trunc);
         outFile.close(); //clear results file
         
        
         int numGames;
         int difficulty;
         cout << "Enter number of games to run: ";
         cin >> numGames;
         
         cout<< "SELECT DIFFICULTY\n"
         << "1. EASY\n"
         << "2. MEDIUM\n"
         << "3. HARD\n"
         << "4. VERY HARD\n";
         cin >> difficulty;
         for (int i = 0; i < numGames; i++) {
            
         SimulationGameClass game(difficulty);
            if (game.setUp())
            {
               game.play();
            }
         }
         

         
				break;
			}
		
			case HIGH_SCORES:
			{
				HighScoreClass print;
				print.HighScoreClass::printHighScoreList();
				break;
			}
			
		
			
			case RALLY_MODE:
			{
				rally = !rally;
				break;
			}
		}
	
	}
	
	cout << "Thanks for playing Battleship!" << endl;
}





int printStartMenu(bool rally) // Determines what type of game the user would like to play
{
	int choice;
	
	cout << "What would you like to do?" << endl <<
	"1. Play 2 player game locally" << endl <<
	"2. Play against the computer" << endl <<
	"3. Run simulation" << endl <<
	"4. View high scores" << endl <<
	"5. Toggle rally mode" << endl <<
	"0. Exit" << endl <<
	"Rally mode is currently ";
	
	if (rally == true)
	{
		cout << "on." << endl;
	}
	else
	{
		cout << "off." << endl;
	}
	
	
	do
	{
		cin >> choice;
	}
	while (!checkStream(cin));
	
	return (choice);
}

