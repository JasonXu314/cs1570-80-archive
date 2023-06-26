// Author: Jason Xu
// Name: Date Game
// Purpose: Provide Game class declarations (alternate solution)

#ifndef GAME_ALTERNATE_H
#define GAME_ALTERNATE_H

#include <iostream>
#include "./Coordinate.h"
#include "./utils.h"

using namespace std;

const int NUM_ROUNDS = 5;

class GameAlter
{
public:
	// Constructs a game with nothing in it
	// Pre: None
	// Post: A "empty" game will be constructed
	GameAlter() {}

	// Starts this game; prompts the user for the city size and begins play
	// Pre: This game has not been played yet
	// Post: Writes to cout and reads from cin for city size
	void play(const int size = 0);

	// Prints out the results of this game
	// Pre: This game has been played
	// Post: Writes to stdout with the results of the game
	void results() const;

	// Determines whether the player won this game or not
	// Pre: This game has been played in full
	// Post: Returns whether the player won or not (_playerScore < _rivalScore)
	bool playerWon() const;

	// Gets the size of the city in this game
	// Pre: None
	// Post: Returns the size of the city
	int getSize() const;

	// Writes to the given stream with the 2d array of the game, formatted in a human readable format
	// Pre: None
	// Post: Out will be written to with the contents of the game's _city array
	friend ostream &operator<<(ostream &out, const GameAlter &game);

private:
	int _citySize;
	int _round;
	double _playerScore;
	double _rivalScore;
	Coordinate _love[NUM_ROUNDS]; // including these here for keeping history, but it's not quite necessary in the scope of the project (mainly for extendability)
	Coordinate _rival[NUM_ROUNDS];
	Coordinate _player[NUM_ROUNDS];
};

#endif