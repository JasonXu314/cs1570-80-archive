// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Puncher class implementations

#include "./Puncher.h"

using namespace std;

void Puncher::print() const
{
	cout << "Puncher: " << _health << " HP, " << _attack << " DMG, " << _speed << " speed" << endl;
}

float Puncher::getSpeed() const
{
	return _speed + 0.3;
}