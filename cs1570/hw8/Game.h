// Author: Jason Xu
// Name: Date Game
// Purpose: Provide Game class declarations

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "./Coordinate.h"
#include "./utils.h"

using namespace std;

const int NUM_ROUNDS = 5;

class Game
{
public:
	// Constructs a game with nothing in it
	// Pre: None
	// Post: A "empty" game will be constructed
	Game() : _city(nullptr) {}

	// Constructs a game as a clone of the other
	// Pre: None
	// Post: Creates a game as a clone of other
	Game(const Game &other);

	// Resets the game
	// Pre: None
	// Post: Sets the 2 scores to 0, and generates new coordinates for the love interest and rival and wipes the coordinates of the player and the city grid
	void reset();

	// Starts this game; prompts the user for the city size and begins play
	// Pre: This game has not been played yet
	// Post: Writes to cout and reads from cin for city size
	void play();

	// Prints out the results of this game
	// Pre: This game has been played
	// Post: Writes to stdout with the results of the game
	void results() const;

	// Determines whether the player won this game or not
	// Pre: This game has been played in full
	// Post: Returns whether the player won or not (_playerScore < _rivalScore)
	bool playerWon() const;

	// Cleans up after the instance
	// Pre: None
	// Post: Deallocates the memory associated with this game
	~Game();

	// Assigns the other game to this game
	// Pre: None
	// Post: The other game will be assigned to this one
	Game &operator=(const Game &other);

	// Writes to the given stream with the 2d array of the game, formatted in a human readable format
	// Pre: None
	// Post: Out will be written to with the contents of the game's _city array
	friend ostream &operator<<(ostream &out, const Game &game);

private:
	char **_city;
	int _citySize;
	double _playerScore;
	double _rivalScore;
	Coordinate _love[NUM_ROUNDS]; // including these here for keeping history, but it's not quite necessary in the scope of the project (mainly for extendability)
	Coordinate _rival[NUM_ROUNDS];
	Coordinate _player[NUM_ROUNDS];
};

#endif