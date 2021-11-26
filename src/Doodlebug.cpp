#include <algorithm>
#include <stdio.h>
#include "Doodlebug.h"

Doodlebug::Doodlebug() : Organism()
{
}

Doodlebug::Doodlebug(int x, int y, int mod, char symbol) : Organism(x, y, mod, symbol)
{
}

void Doodlebug::move(Organism *grid[SIZE][SIZE])
{
	int eat[4] = {0, 1, 2, 3};
	std::random_shuffle(eat, eat+4);
	for (int i = 0; i < 4; i++)
	{
		int x = get_x_pos(), y = get_y_pos();
		switch(eat[i])
		{
			case 0: 
				if (x != 0)
					x--;
				break;
			case 1:
				if (x != (SIZE - 1))
					x++;
				break;
			case 2:
				if (y != 0)
					y--;
				break;
			case 3:
				if (y != (SIZE - 1))
					y++;
				break;
		}
		if (grid[y][x] != nullptr && grid[y][x]->getSymbol() == 'O')
		{
			Organism *temp = grid[y][x];
			grid[y][x] = grid[get_y_pos()][get_x_pos()];
			grid[get_y_pos()][get_x_pos()] = nullptr;
			set_x_pos(x);
			set_y_pos(y);
			set_ate(0);
			delete temp;
			return;
		}
	}
	Organism::move(grid);
	set_ate((get_ate()+1));
}
