// Author: Jason Xu
// Name: Date Game
// Purpose: Provide Game class function implementations

#include "./Game.h"

using namespace std;

Game::Game(const Game &other)
{
	if (other._city == nullptr)
	{
		_city = nullptr;
	}
	else
	{
		_citySize = other._citySize;
		_city = new char *[_citySize];

		for (int i = 0; i < _citySize; i++)
		{
			_city[i] = new char[_citySize];
			for (int j = 0; j < _citySize; j++)
			{
				_city[i][j] = other._city[i][j]; // note: this could be done much more efficiently by just resetting here instead of calling reset later
			}
		}

		for (int i = 0; i < NUM_ROUNDS; i++)
		{
			_love[i] = other._love[i];
			_rival[i] = other._rival[i];
			_player[i] = other._player[i];
		}

		_playerScore = other._playerScore;
		_rivalScore = other._rivalScore;
	}
}

void Game::reset()
{
	for (int i = 0; i < _citySize; i++)
	{
		for (int j = 0; j < _citySize; j++)
		{
			_city[i][j] = ' ';
		}
	}

	_playerScore = 0;
	_rivalScore = 0;

	for (int i = 0; i < NUM_ROUNDS; i++)
	{
		_rival[i].x = rand(_citySize);
		_rival[i].y = rand(_citySize);
		_love[i].x = rand(_citySize);
		_love[i].y = rand(_citySize);
		_player[i] = Coordinate{0, 0};
	}
}

void Game::play()
{
	if (_city == nullptr) // setup only needs to be performed if _city hasn't been initialized yet, otherwise we know that reset is guaranteed to hoave been
	{					  // called because the city has been cloned from another (ie. if the player answers yes to same city)
		int n;
		cout << "How big is your city?" << endl;
		cin >> n;

		while (n <= 0)
		{
			cout << "How big is your city? (must be a positive integer)" << endl;
			cin >> n;
		}
		_citySize = n;

		_city = new char *[n];
		for (int i = 0; i < n; i++)
		{
			_city[i] = new char[n];
			for (int j = 0; j < n; j++)
			{
				_city[i][j] = ' ';
			}
		}

		// Perform setup for game (initialize scores and pre-determine love & rival coordinates)
		for (int i = 0; i < NUM_ROUNDS; i++)
		{
			_rival[i].x = rand(n);
			_rival[i].y = rand(n);
			_love[i].x = rand(n);
			_love[i].y = rand(n);
		}
		_playerScore = 0;
		_rivalScore = 0;
	}

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

		_city[_rival[i].y][_rival[i].x] = 'R';
		_city[player.y][player.x] = 'P';
		_city[_love[i].y][_love[i].x] = 'L'; // inserted in this order so that in the event of same coordinates selected, overrides as specified

		cout << *this << endl;
		_playerScore += distance(player, _love[i]);
		_rivalScore += distance(_rival[i], _love[i]);

		_city[_rival[i].y][_rival[i].x] = ' '; // reset squares for next match
		_city[player.y][player.x] = ' ';
		_city[_love[i].y][_love[i].x] = ' ';
	}
}

void Game::results() const
{
	cout << "Player Score: " << _playerScore << "; Rival Score: " << _rivalScore << "; " << (playerWon() ? "Player" : "Rival") << " wins!" << endl;
}

bool Game::playerWon() const
{
	return _playerScore < _rivalScore;
}

Game::~Game()
{
	if (_city != nullptr) // if the game has been played, then we need to dispose of stuff
	{
		for (int i = 0; i < _citySize; i++)
		{
			delete[] _city[i];
		}
		delete[] _city;
	}
}

Game &Game::operator=(const Game &other)
{
	if (other._city == nullptr)
	{
		_citySize = other._citySize;
		_city = nullptr;

		for (int i = 0; i < NUM_ROUNDS; i++)
		{
			_love[i] = other._love[i];
			_rival[i] = other._rival[i];
			_player[i] = other._player[i];
		}

		_playerScore = other._playerScore;
		_rivalScore = other._rivalScore;
		return *this;
	}
	else
	{
		_citySize = other._citySize;
		_city = new char *[_citySize];

		for (int i = 0; i < _citySize; i++)
		{
			_city[i] = new char[_citySize];
			for (int j = 0; j < _citySize; j++)
			{
				_city[i][j] = other._city[i][j]; // note: this could be done much more efficiently by just resetting here instead of calling reset later
			}
		}

		for (int i = 0; i < NUM_ROUNDS; i++)
		{
			_love[i] = other._love[i];
			_rival[i] = other._rival[i];
		}

		_playerScore = other._playerScore;
		_rivalScore = other._rivalScore;
		return *this;
	}
}

ostream &operator<<(ostream &out, const Game &game)
{
	for (int i = 0; i < game._citySize; i++)
	{
		out << i;
		if (game._citySize > 9 && i < 10) // ie. the left side column of numbers will need to be normalized to 2 character spaces
		{
			out << " ";
		}
		if (game._citySize > 99 && i < 100) // ie. the left side column of numbers will need to be normalized 3 or more character spaces
		{
			out << " ";
		}
		out << "| ";
		for (int j = 0; j < game._citySize - 1; j++)
		{
			out << game._city[i][j] << " , ";
		}
		out << game._city[i][game._citySize - 1] << " |\n";
	}
	out << "   ";
	if (game._citySize > 9) // ie. the left side column of numbers will require 2 character spaces to fit
	{
		out << " ";
	}
	if (game._citySize > 99) // ie. the left side column of numbers will require 3 or more character spaces to fit
	{
		out << " ";
	}
	for (int i = 0; i < game._citySize; i++)
	{
		out << i;
		if (i + 1 > 99) // ie. the next number will require 3 or more character spaces to fit
		{
			out << " ";
		}
		else if (i + 1 > 9) // ie. the next number will require 2 character spaces to fit
		{
			out << "  ";
		}
		else
		{
			out << "   ";
		}
	}
	return out << endl;
}