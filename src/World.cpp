#include "World.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

World::World()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			grid[i][j] = nullptr;
	
	int num = 0;

	while (true) // initialize ants
	{
		int x = rand() % SIZE;
		int y = rand() % SIZE;
			if (grid[y][x] == nullptr)
			{
				grid[y][x] = new Ant(x, y, 3, 'O'); 
				num++;
			}
			if (num == 100)
				break;
	}

	num = 0;
	while (true) //initialize doodlebugs
	{
		int x = rand() % SIZE;
		int y = rand() % SIZE;
			if (grid[y][x] == nullptr)
			{
				grid[y][x] = new Doodlebug(x, y, 8, 'X'); 
				num++;
			}
			if (num == 5)
				break;
	}
}

void World::printGrid(int &numOfAnts, int &numOfDoodles)
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (grid[y][x] == nullptr)
				std::cout << " ";
			else
			{
				std::cout << grid[y][x]->getSymbol();
				if (grid[y][x]->getSymbol() == 'O')
					numOfAnts++;
				else
					numOfDoodles++;
			}
		}
		std::cout << std::endl;
	}
}

// Used to make each organism move/breed(/starve)
void World::queueOrg(char symbol, std::queue<Organism*> &q)
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (grid[y][x] != nullptr && grid[y][x]->getSymbol() == symbol)
				q.push(grid[y][x]);
		}
	}
}

void World::simulate()
{
	std::queue<Organism*> q_ant; // Used to track which ants need to move
	std::queue<Organism*> q_doodle; // track which doodlebugs need to move
	std::pair<int, int> cord;
	int step = 1, numOfAnts, numOfDoodles; 
	while (true)
	{
		numOfAnts = 0;
		numOfDoodles = 0;
		printGrid(numOfAnts, numOfDoodles);
		std::cout << " \n";
		printf("Time step: %d \t Number of ants: %d \t Number of doodlebugs: "
			      "%d \n", step, numOfAnts, numOfDoodles);

		queueOrg('X', q_doodle);
		while (!q_doodle.empty()) // Doodlebugs move/breed/starve
		{
			q_doodle.front()->move(grid);
			q_doodle.front()->inc_step();
			cord = q_doodle.front()->breed(grid);
			if (cord.first != -1)
				grid[cord.second][cord.first] = 
				new Doodlebug(cord.first, cord.second, 8, 'X');
			q_doodle.front()->starve(grid);
			q_doodle.pop();
		}
		printf("\n");

		queueOrg('O', q_ant);
		while (!q_ant.empty()) // ants move/breed
		{	
			q_ant.front()->move(grid);
			q_ant.front()->inc_step();
			cord = q_ant.front()->breed(grid);
			if (cord.first != -1) //step != 3
				grid[cord.second][cord.first] = 
				new Ant(cord.first, cord.second, 3, 'O');
			q_ant.pop();	
		}

	step++;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
