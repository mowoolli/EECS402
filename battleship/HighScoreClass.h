#include <list>

#ifndef HIGHSCORECLASS_H
#define HIGHSCORECLASS_H

using namespace std;

class HighScoreClass
{
  private:
    int currentScore;
    std::string multiplayerTitle;
    std::string singlePlayerTitle;
    std::string currentInitials;
    std::list<int> multiplayerScores;
    std::list<int> singlePlayerScores;
    std::list<std::string> multiplayerInitials;
    std::list<std::string> singlePlayerInitials;
    int existingMultiplayerScore;
    std::string existingMultiplayerInitials;
    int existingSinglePlayerScore;
    std::string existingSinglePlayerInitials;
    std::list<int>::iterator k;
    std::list<std::string>::iterator p;
    std::list<std::string>::iterator l;
    std::list<int>::iterator q;
    std::list<std::string>::iterator r;
    std::list<int>::iterator s;
    std::list<int>::iterator v;
    std::list<std::string>::iterator t;
    std::list<std::string>::iterator g;
    std::list<int>::iterator x;
    std::list<std::string>::iterator y;
    std::list<int>::iterator z;

  public:
    void handleMultiplayerScore(int inScore); 
    void handleSinglePlayerScore(int inScore);
    void printHighScoreList();
};

#endif // HIGHSCORECLASS_H
