// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Main program for Sir Rig's-A-Lot Deathmatch

#include <iostream>
#include <vector>
#include "./utils.h"
#include "./Person.h"
#include "./Boss.h"
#include "./Puncher.h"
#include "./Insulter.h"
#include "./Kicker.h"

using namespace std;

int main()
{
	seed();

	vector<Person *> people;
	Boss boss;

	people.push_back(new Kicker());
	people.push_back(new Puncher());
	people.push_back(new Insulter());

	boss.print();
	for (size_t i = 0; i < people.size(); i++)
	{
		people[i]->print();
	}

	fight(boss, people);
	return 0;
}