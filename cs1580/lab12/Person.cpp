// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Person class implementations

#include "./Person.h"

using namespace std;

bool Person::isAlive() const
{
	return _health > 0;
}

void Person::attack(Person &person) const
{
	person._health -= _attack;
}

string Person::getType() const
{
	return _type;
}