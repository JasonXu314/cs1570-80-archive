// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Kicker class declarations

#ifndef KICKER_H
#define KICKER_H

#include <iostream>
#include "./Person.h"
#include "./utils.h"

class Kicker : public Person
{
public:
	// Creates a kicker
	// Pre: None
	// Post: Constructs a kicker
	Kicker() : Person(randI(20, 40), randI(30, 50), randI(0, 100), "kicker") {}

	// Prints out the data of this person in a human-readable format
	// Pre: None
	// Post: Writes to stdout with the data of this person
	void print() const override;

	// Gets the speed of this person, taking priority into account
	// Pre: None
	// Post: Returns the speed of this person
	float getSpeed() const override;
};

#endif
