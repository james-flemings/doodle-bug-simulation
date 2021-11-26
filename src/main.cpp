#include "World.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));
	World w;
	w.simulate();
}
