// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Insulter class implementations

#include "./Insulter.h"

using namespace std;

void Insulter::print() const
{
	cout << "Insulter: " << _health << " HP, " << _attack << " DMG, " << _speed << " speed" << endl;
}

float Insulter::getSpeed() const
{
	return _speed + 0.1;
}