template <typename T> 
bool attackBoard(T &opponent) // Player can view their board and attack their opponent. If a ship is hit, it checks if the ship has been sunk and updates numSunk accordingly.{
	char rowI, menu;
	int row, col;
	int val;
	bool playOn = true;
	bool success = false;
	
	while (playOn && !success)
	{
		cout << "Enter 'A' to attack, 'B' to see your board, or enter 'X' to quit the game: ";
		cin >> menu;
		menu = toupper(menu);
	
		if (menu == ATTACK)
		{
			opponent.printBoard(HIDDEN); // Prints opponent's board without the ships
			cout << "Enter coordinates to attack: ";
			cin >> rowI >> col;
			rowI = toupper(rowI);
			
			if (checkInRange(rowI, row, col))
			{
				val = opponent.getCell(row,col)->getValue();
				if (val==OPEN_WATER) // If player misses, updates board appropriately
				{
					cout << "MISS!" << endl;
					opponent.getCell(row,col)->setValue(MISS);
					success = true;
				}
				else if (val==OCCUPIED) // If player hits, updates board and checks if ship was sunk. If ship was sunk, adds to opponent's numSunk.
				{
					cout << "HIT!" << endl;
					opponent.getCell(row,col)->setValue(HIT);
					if (opponent.getCell(row,col)->getOccupiedBy()->checkSunk())
					{
						opponent.addSunk();
					}
					success = true;
				}
				else if (val==MISS || val==HIT)
				{
					cout << "Error: Coordinates have already been attacked!" << endl;
				}
			}
		}
		else if (menu == BOARD)
		{
			printBoard(FULL);
		}
		else if (menu == CHAREXIT)
		{
			playOn = false;
		}
		else
		{
			cout << "Error: Value must be an 'A', 'B', or 'X'" << endl;
		}
	}
	
	return (playOn);
};
