// Author: Jason Xu
// Name: Date Game
// Purpose: Main program for Date Game

#include <iostream>
#include "./Match.h"

using namespace std;

int main()
{
	seed();

	char cont = 'n';
	cout << "Welcome to the Love Triangle Game! Ready for some heartbreak?" << endl;

	do
	{
		Match match;

		if (match.play())
		{
			cout << "Play another match?" << endl;
			cin >> cont;

			while (cont != 'N' && cont != 'n' && cont != 'Y' && cont != 'y')
			{
				cout << "Play another match? (Yy/Nn)" << endl;
				cin >> cont;
			}
		}
		else
		{
			cont = 'n';
		}
	} while (cont != 'N' && cont != 'n');

	return 0;
}