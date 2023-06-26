// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Puncher class declarations

#ifndef PUNCHER_H
#define PUNCHER_H

#include <iostream>
#include "./Person.h"
#include "./utils.h"

class Puncher : public Person
{
public:
	// Creates a puncher
	// Pre: None
	// Post: Constructs a puncher
	Puncher() : Person(randI(5, 20), randI(70, 100), randI(0, 100), "puncher") {}

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
