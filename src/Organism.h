#ifndef ORG_H
#define ORG_H
#include <utility>

const int SIZE = 20;
const int STARVE = 3;

class Organism
{
	public:
		Organism();
		Organism(int x, int y, int mod, char symbol);
		void set_x_pos(int x);
		void set_y_pos(int y);
		void inc_step();
		void set_ate(int a);
		int get_x_pos();
		int get_y_pos();
		int get_step();
		int get_ate();
		char getSymbol();
		virtual void move(Organism *grid[SIZE][SIZE]);
		void starve(Organism *grid[SIZE][SIZE]);
		std::pair<int, int> breed(Organism *grid[SIZE][SIZE]);

	private:
		int x_pos, y_pos, step, mod, ate;
		char symbol; 
};

#endif
