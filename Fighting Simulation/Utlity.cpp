#include "stdafx.h"
#include "Utility.h"
#include <ctype.h>

//Generate a random # between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	//static to ensure value calculated only once
	static const double fraction = 1.0 / (static_cast<double> (RAND_MAX) + 1.0);
	
	//evenly distributes the random number across the range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//returns true if the uppercase or lowercase choice is inputted.
bool isChoice(const char input, const char uppercaseChoice)
{
	return (uppercaseChoice == static_cast<char>(toupper(input)));
}

//randomly outputs a success or failure based on
//percentage given
//works only with integers (including 0)
bool doProbability(int percent)
{
	return (getRandomNumber(1, 100) <= percent);
}
