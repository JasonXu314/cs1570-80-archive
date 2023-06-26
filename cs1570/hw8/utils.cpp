// Author: Jason Xu
// Name: Date Game
// Purpose: Provide utility function implementations

#include "./utils.h"

void seed()
{
	srand(8);
}

int rand(int max)
{
	return rand() % max;
}

double distance(const Coordinate &p1, const Coordinate &p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}