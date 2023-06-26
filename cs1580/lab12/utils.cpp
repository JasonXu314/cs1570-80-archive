// Author: Jason Xu
// Student ID: jx6pc
// Section: 306
// Date: 12/1/2021
// Purpose: Utility function implementations

#include "./utils.h"
#include "./Person.h"
#include "./Boss.h"

using namespace std;

void seed()
{
	srand(2);
}

int rand(const int max)
{
	return rand() % max;
}

int randI(const int min, const int max)
{
	return rand(max - min + 1) + min;
}

bool hasAlive(const vector<Person *> &people)
{
	for (size_t i = 0; i < people.size(); i++)
	{
		if (people[i]->isAlive())
		{
			return true;
		}
	}
	return false;
}

void fight(Boss &boss, vector<Person *> &people)
{
	bool bossWin = false;
	vector<Person *> sortedPeople = sort(people);

	while (hasAlive(sortedPeople))
	{
		for (size_t i = 0; i < sortedPeople.size(); i++)
		{
			if (sortedPeople[i]->getSpeed() < boss.getSpeed())
			{
				boss.attack(sortedPeople);
				if (!hasAlive(sortedPeople))
				{
					bossWin = true;
					break;
				}
			}
			sortedPeople[i]->attack(boss);
		}
		if (boss.getSpeed() < sortedPeople[sortedPeople.size() - 1]->getSpeed()) // if the boss is the slowest, he will not have attacked in the for loop
		{
			boss.attack(sortedPeople);
			if (!hasAlive(sortedPeople))
			{
				bossWin = true;
				break;
			}
		}
	}

	if (bossWin)
	{
		cout << "Boss Win!" << endl;
		boss.print();
	}
	else
	{
		cout << "Players Win!" << endl;
		for (size_t i = 0; i < sortedPeople.size(); i++)
		{
			sortedPeople[i]->print();
		}
	}
}

vector<Person *> sort(const vector<Person *> &people)
{
	if (people.size() <= 1)
	{
		return people;
	}
	else
	{
		size_t half = people.size() / 2;
		vector<Person *> firstHalf, secondHalf;

		for (size_t i = 0; i < half; i++)
		{
			firstHalf.push_back(people[i]);
		}
		for (size_t i = half; i < people.size(); i++)
		{
			secondHalf.push_back(people[i]);
		}

		return merge(sort(firstHalf), sort(secondHalf));
	}
}

vector<Person *> merge(const vector<Person *> &a, const vector<Person *> &b)
{
	vector<Person *> out;
	size_t maxSize = max(a.size(), b.size());

	for (size_t i = 0; i < maxSize; i++)
	{
		if (i > a.size())
		{
			out.push_back(b[i]);
		}
		else if (i > b.size())
		{
			out.push_back(a[i]);
		}
		else
		{
			if (a[i]->getSpeed() > b[i]->getSpeed())
			{
				out.push_back(a[i]);
			}
			else
			{
				out.push_back(b[i]);
			}
		}
	}

	return out;
}