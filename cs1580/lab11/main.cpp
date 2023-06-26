/* 
	Header stuff goes here
*/

#include <iostream>
#include <cmath>
#include "Game.h"
using namespace std;

int main()
{
	srand(419);

	const int NUM_GAMES = 9;
	string gameNames[NUM_GAMES] = {"Guac-A-Mole",
								   "Bling Toss",
								   "Irish Roulette",
								   "Fortune Tent",
								   "Duck Shot",
								   "Archery Den",
								   "Skee Ball",
								   "Bingo?",
								   "House Of Mirrors"};
	string adjectives[NUM_GAMES] = {"unfortunate",
									"burnt",
									"distant",
									"painful",
									"long forgotten",
									"sleeping",
									"once loved",
									"pitiful",
									"charred"};
	string nouns[NUM_GAMES] = {"pile",
							   "ashes",
							   "memory",
							   "aftermath",
							   "husk",
							   "remnants",
							   "relic",
							   "debris",
							   "remains"};

	Game *games = new Game[NUM_GAMES];

	for (int i = 0; i < NUM_GAMES; i++)
	{
		games[i].setName(gameNames[i]);
	}

	for (int i = 0; i < NUM_GAMES; i++)
	{
		cout << games[i];
	}

	cout << "---Commencing Protest---" << endl;

	for (int i = 0; i < NUM_GAMES; i++)
	{
		games[i].setName("The " + adjectives[rand() % NUM_GAMES] + " " + nouns[rand() % NUM_GAMES] + " of " + gameNames[i]);
	}

	for (int i = 0; i < NUM_GAMES; i++)
	{
		cout << games[i];
	}

	delete[] games;

	return 0;
}
