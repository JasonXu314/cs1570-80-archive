// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Boss class implementations

#include "./Boss.h"

using namespace std;

void Boss::print() const
{
	cout << "Boss: " << _health << " HP, " << _attack << " DMG, " << _speed << " speed" << endl;
}

void Boss::attack(vector<Person *> people) const
{
	for (size_t i = 0; i < people.size(); i++)
	{
		Person::attack(*people[i]);
	}
}

float Boss::getSpeed() const
{
	return _speed + 0.4;
}