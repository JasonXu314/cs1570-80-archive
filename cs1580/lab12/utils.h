// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Utility function declarations

#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <vector>

using namespace std;

class Boss;
class Person;

// Seeds the RNG
// Pre: The RNG has not been seeded before
// Post: Seeds the RNG with a pre-defined seed
void seed();

// Gets a random number in the range [0, max)
// Pre: None
// Post: Gets a random number from the RNG
int rand(const int max);

// Gets a random number in the range [min, max]
// Pre: min < max
// Post: Gets a random number from the RNG
int randI(const int min, const int max);

// Makes boss fight with people
// Pre: None
// Post: Makes the boss fight with the given people
void fight(Boss &boss, vector<Person *> &people);

// Checks whether the vector has ANY people who are still alive
// Pre: None
// Post: Returns true iff people has at least 1 person who is still alive
bool hasAlive(const vector<Person *> &people);

// Sorts the vector of people using mergesort
// Pre: None
// Post: Returns a sorted vector
vector<Person *> sort(const vector<Person *> &people);

// Merges the 2 given vectors of people in order
// Pre: None
// Post: Returns an ordered vector composed of the elements of a and b
vector<Person *> merge(const vector<Person *> &a, const vector<Person *> &b);

#endif