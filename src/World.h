#ifndef WOLRD_H
#define WORLD_H
#include "Ant.h"
#include "Doodlebug.h"
#include <queue>

class Ant;
class Doodlebug;

class World
{
	public:
		World();
		void simulate();
		void printGrid(int &numOfAnts, int &numOfDoodles);
		void queueOrg(char symbol, std::queue <Organism*> &q);
	private:
		int row, col;
		Organism *grid[SIZE][SIZE];
};

#endif
