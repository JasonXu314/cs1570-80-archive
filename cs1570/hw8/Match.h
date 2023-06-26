// Author: Jason Xu
// Name: Date Game
// Purpose: Provide Match class declarations

#ifndef MATCH_H
#define MATCH_H

#include "./Game.h"
#include <iostream>

class Match
{
public:
	// Creates a match
	// Pre: None
	// Post: Constructs a new match
	Match() : _gamesPlayed(0), _wins(0) {}

	// Plays the match (repeatedly creates games and plays the games until player exits)
	// Pre: This match has not been played yet
	// Post: Creates a game and plays it, then prompts player on whether or not they want to continue playing, etc., returns true if the player did not
	//		 manually terminate the game (ie. they played all 20 rounds)
	bool play();

private:
	Game _games[20];
	int _gamesPlayed;
	int _wins;
};

#endif