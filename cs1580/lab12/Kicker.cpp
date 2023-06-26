// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Kicker class implementations

#include "./Kicker.h"

using namespace std;

void Kicker::print() const
{
	cout << "Kicker: " << _health << " HP, " << _attack << " DMG, " << _speed << " speed" << endl;
}

float Kicker::getSpeed() const
{
	return _speed + 0.2;
}