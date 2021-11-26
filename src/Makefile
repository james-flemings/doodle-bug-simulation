CFLAGS = -O
CC = g++
SRC = main.cpp World.cpp Organism.cpp Ant.cpp Doodlebug.cpp
OBJ = $(SRC:.cpp = .o)

Simulation: $(OBJ)
	$(CC) $(CFLAGS) -o Simulation $(OBJ)

clean:
	rm -f core *.o
