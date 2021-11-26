#include "Organism.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>

Organism::Organism() : x_pos(0), y_pos(0), step(0), mod(0), symbol(' '), ate(0) {}

Organism::Organism(int x, int y, int mod, char symbol) : x_pos(x), y_pos(y), step(0),
			mod(mod), symbol(symbol), ate(0) {}

void Organism::set_x_pos(int x)
{
	x_pos = x;	
}

void Organism::set_y_pos(int y)
{
	y_pos = y;
}

void Organism::inc_step()
{
	step++;
}

void Organism::set_ate(int a)
{
	ate = a;
}

int Organism::get_x_pos()
{
	return x_pos;
}

int Organism::get_y_pos()
{
	return y_pos;
}

int Organism::get_step()
{
	return step;
}

int Organism::get_ate()
{
	return ate;
}

char Organism::getSymbol()
{
	return symbol;
}

void Organism::move(Organism *grid[SIZE][SIZE])
{
	int moves[4] = {0, 1, 2 ,3};
	std::random_shuffle(moves, moves + 4); // randomize direction
	for (int i = 0; i < 4; i++)
	{
		int x = get_x_pos(), y = get_y_pos();
		// Perform checks if organism isn't on border 
		switch (moves[i])
		{
			case 0: // move left 
				if (x != 0)  
					x--;
				break;
			case 1: // move right
				if (x != (SIZE-1))
					x++;
				break;
			case 2: // move up
				if (y != 0)
					y--;
				break;
			case 3: // move down
				if (y != (SIZE-1))
					y++;
				break;
		}
		if (grid[y][x] == nullptr) // is direction occupied
		{
			grid[y][x] = grid[get_y_pos()][get_x_pos()];
			grid[get_y_pos()][get_x_pos()] = nullptr;
			set_x_pos(x);
			set_y_pos(y);
			return;
		}
	}		
}

std::pair<int, int> Organism::breed(Organism *grid[SIZE][SIZE])
{
	if ((get_step() % mod == 0))
	{
		int breeds[4] = {0, 1, 2, 3};
		std::random_shuffle(breeds, breeds+4);
					
		for (int i = 0; i < 4; i++)
		{
			int x = get_x_pos(), y = get_y_pos();
			// Perform checks if organism isn't on border 
			switch (breeds[i])
			{
				case 0: // breed left 
					if (x != 0)  
						x--;
					break;
				case 1: // breed right
					if (x != (SIZE-1))
						x++;
					break;
				case 2: // breed up
					if (y != 0)
						y--;
					break;
				case 3: // breed down
					if (y != (SIZE-1))
						y++;
					break;
			}
			if (grid[y][x] == nullptr) // is direction occupied
				return std::make_pair(x, y);
		}		
	}
	return std::make_pair(-1, -1); // default value to indicate no breeding 
}

void Organism::starve(Organism *grid[SIZE][SIZE])
{
	if (get_ate() == STARVE) 
	{
		Organism *temp = grid[get_y_pos()][get_x_pos()];
		grid[get_y_pos()][get_x_pos()] = nullptr;
		delete temp;
	}
}
