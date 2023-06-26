// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Person class declarations

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
	// Creates a "null" person
	// Pre: None
	// Post: Constructs a person to represent no person
	Person() : _attack(-1), _health(-1), _speed(-1), _type("") {}

	// Creates a person with the given stats
	// Pre: None
	// Post: Constructs a person with the given stats
	Person(const int attack, const int health, const int speed, const string type) : _attack(attack), _health(health), _speed(speed), _type(type) {}

	// Gets the speed of this person, taking priority into account
	// Pre: None
	// Post: Returns the speed of this person
	virtual float getSpeed() const { return _speed; }

	// Checks if this person is still alive
	// Pre: None
	// Post: Returns true iff the person is still alive (health > 0)
	bool isAlive() const;

	// Prints out the data of this person in a human-readable format
	// Pre: None
	// Post: Writes to stdout with the data of this person
	virtual void print() const {}

	// Attacks the given other person
	// Pre: None
	// Post: person's health will be depleted by this person's attack
	void attack(Person &person) const;

	// Gets the type of this person
	// Pre: None
	// Post: Returns this person's type (puncher, kicker, or insulter)
	string getType() const;

protected:
	int _attack;
	int _health;
	int _speed;
	string _type;
};

#endif
