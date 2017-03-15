#include <string>
#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

const int DEBUG_ON = 0; //1 for debug on


const int ONLINE = 1;
const int LOCALLY = 2;
const int COMPUTER = 3;
const int HIGH_SCORES = 4;
const int EXIT = 0;

const int ROW_SIZE = 10;
const int COL_SIZE = 10;

const int MIN_COL = 1;
const int MAX_COL = 10;
const char MIN_ROW = 'A';
const char MAX_ROW = 'J';

const int NUM_SHIPS = 5;
const int CRUISER = 1;
const int BATTLESHIP = 2;
const int CARRIER = 3;
const int SUBMARINE = 4;
const int DESTROYER = 5;

const int CRUISER_LENGTH = 5;
const int BATTLESHIP_LENGTH = 4;
const int CARRIER_LENGTH = 3;
const int SUBMARINE_LENGTH = 3;
const int DESTROYER_LENGTH = 2;

const int OPEN_WATER = 0;
const int OCCUPIED = 1;
const int MISS = 2;
const int HIT = 3;

const int PLACE_SHIP = 1;
const int DELETE_SHIP = 2;
const int ACCEPT_ALL = 3;

const char FULL = 'F';
const char HIDDEN = 'H';

const char ATTACK = 'A';
const char BOARD = 'B';
const char CHAREXIT = 'X';

const int UNDETERMINED = 0;
const int NORTH = 1;
const int EAST = 2;
const int SOUTH = 3;
const int WEST = 4;

const int HORIZONTAL = 1;
const int VERTICAL = 2;

const int LENGTH_OF_HIGH_SCORE_LIST = 10;
const std::string NAME_OF_HIGH_SCORE_LIST = "highScores";

#endif
