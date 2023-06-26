// Author: Jason Xu
// Name: Date Game
// Purpose: Provide Match class function implementations

#include "./Match.h"

using namespace std;

bool Match::play()
{
	char cont, sameCity = 'n';

	do
	{
		if (sameCity == 'Y' || sameCity == 'y')
		{
			_games[_gamesPlayed] = Game(_games[_gamesPlayed - 1]); // because we have to for some reason
			_games[_gamesPlayed].reset();
			_games[_gamesPlayed].play();
		}
		else
		{
			_games[_gamesPlayed].play();
		}

		cout << "Game " << (_gamesPlayed + 1) << ":" << endl;
		_games[_gamesPlayed].results();

		if (_games[_gamesPlayed].playerWon())
		{
			_wins++;
		}

		_gamesPlayed++;

		if (_gamesPlayed < 20)
		{
			cout << "Continue Playing?" << endl;
			cin >> cont;

			while (cont != 'N' && cont != 'n' && cont != 'Y' && cont != 'y')
			{
				cout << "Continue Playing? (Yy/Nn)" << endl;
				cin >> cont;
			}

			if (cont == 'Y' || cont == 'y')
			{
				cout << "Do you want to keep the same city?" << endl;
				cin >> sameCity;

				while (sameCity != 'Y' && sameCity != 'y' && sameCity != 'N' && sameCity != 'n')
				{
					cout << "Do you want to keep the same city? (Yy/Nn)" << endl;
					cin >> sameCity;
				}
			}
		}
	} while (cont != 'N' && cont != 'n' && _gamesPlayed <= 20); // exit if answer no, but also exit if limit reached

	cout << "Win Rate: " << _wins << "/" << _gamesPlayed << " (" << (_wins / static_cast<double>(_gamesPlayed) * 100) << "%)" << endl;
	return cont == 'Y' || cont == 'y';
}