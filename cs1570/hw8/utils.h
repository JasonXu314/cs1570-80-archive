// Author: Jason Xu
// Name: Date Game
// Purpose: Provide utility function declarations

#ifndef UTILS_H
#define UTILS_H

#include "./Coordinate.h"
#include <cmath>

// Seed the RNG
// Pre: The RNG has not been seeded before
// Post: The RNG will be seeded with the value of 8
void seed();

// Gets a random int from the RNG in the interval [0, max)
// Pre: The RNG has been previously seeded
// Post: Gets a random int from the RNG
int rand(int max);

// Calculates the distance between the 2 coordinates
// Pre: None
// Post: Returns the distance between the 2 coordinates
double distance(const Coordinate &p1, const Coordinate &p2);

#endif