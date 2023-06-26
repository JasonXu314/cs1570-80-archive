#include <iostream>
using namespace std;

class Game
{
public:
	Game() {}
	Game(string mName) { name = mName; }
	void setName(string mName) { name = mName; }

	// Prints the name of this game to the given stream
	// Pre: None
	// Post: Writes to out with the game's name
	friend ostream &operator<<(ostream &out, const Game &game) { return out << game.name << endl; }

private:
	string name;
};
