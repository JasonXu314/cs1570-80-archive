// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Boss class declarations

#ifndef BOSS_H
#define BOSS_H

#include <iostream>
#include <vector>
#include "./Person.h"
#include "./utils.h"

class Boss : public Person
{
public:
	// Creates a kicker
	// Pre: None
	// Post: Constructs a kicker
	Boss() : Person(randI(5, 15), randI(200, 450), randI(0, 100), "boss") {}

	// Prints out the data of this person in a human-readable format
	// Pre: None
	// Post: Writes to stdout with the data of this person
	void print() const override;

	// Attacks all the given people at the same time
	// Pre: None
	// Post: Calls the default attack on each person one at a time
	void attack(vector<Person *> people) const;

	// Gets the speed of this person, taking priority into account
	// Pre: None
	// Post: Returns the speed of this person
	float getSpeed() const override;
};

#endif
