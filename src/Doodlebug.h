#ifndef DOODLE_H
#define DOODLE_H
#include "Organism.h"

class Doodlebug : public Organism
{
	public:
		Doodlebug();
		Doodlebug(int x, int y, int mod, char symbol);
		void move(Organism *grid[SIZE][SIZE]);
		int ate;	
};

#endif
