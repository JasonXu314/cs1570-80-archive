// Author: Jason Xu
// Name: Date Game
// Purpose: Provide Game class function implementations (alternate solution)

#include "./Game_alternate.h"

using namespace std;

void GameAlter::play(const int size)
{
	int n = size;

	if (n == 0) // if size (and therefore n) is not 0, then the user chose to stay in the same city
	{
		cout << "How big is your city?" << endl;
		cin >> n;

		while (n <= 0)
		{
			cout << "How big is your city? (must be a positive integer)" << endl;
			cin >> n;
		}
	}

	_citySize = n;
	_round = 0;

	cout << "Game Begins:\n"
		 << *this << endl;
	for (int i = 0; i < NUM_ROUNDS; i++)
	{
		Coordinate player;
		cout << "Turn " << (i + 1) << ":\n-------\nChoose an x coordinate:" << endl;
		cin >> player.x;

		while (player.x < 0 || player.x >= _citySize)
		{
			cout << "Choose an x coordinate (must be positive and less than the city size):" << endl;
			cin >> player.x;
		}

		cout << "Choose a y coordinate:" << endl;
		cin >> player.y;

		while (player.y < 0 || player.y >= _citySize)
		{
			cout << "Choose a y coordinate (must be positive and less than the city size):" << endl;
			cin >> player.y;
		}

		cout << *this << endl;
		_playerScore += distance(player, _love[i]);
		_rivalScore += distance(_rival[i], _love[i]);
		_round++;
	}
}

int GameAlter::getSize() const
{
	return _citySize;
}

void GameAlter::results() const
{
	cout << "Player Score: " << _playerScore << "; Rival Score: " << _rivalScore << "; " << (playerWon() ? "Player" : "Rival") << " wins!" << endl;
}

bool GameAlter::playerWon() const
{
	return _playerScore < _rivalScore;
}

ostream &operator<<(ostream &out, const GameAlter &game)
{
	for (int i = 0; i < game._citySize; i++)
	{
		out << i << "| ";
		for (int j = 0; j < game._citySize - 1; j++)
		{
			if (game._love[game._round].y == i && game._love[game._round].x == j)
			{
				out << "L , ";
			}
			else if (game._player[game._round].y == i && game._player[game._round].x == j)
			{
				out << "P , ";
			}
			else if (game._rival[game._round].y == i && game._rival[game._round].x == j)
			{
				out << "R , ";
			}
			else
			{
				out << "  , ";
			}
		}
		if (game._love[game._round].y == i && game._love[game._round].x == game._citySize - 1)
		{
			out << "L |\n";
		}
		else if (game._player[game._round].y == i && game._player[game._round].x == game._citySize - 1)
		{
			out << "P |\n";
		}
		else if (game._rival[game._round].y == i && game._rival[game._round].x == game._citySize - 1)
		{
			out << "R |\n";
		}
		else
		{
			out << "  |\n";
		}
	}
	out << "   ";
	for (int i = 0; i < game._citySize; i++)
	{
		out << i << "   ";
	}
	return out << endl;
}