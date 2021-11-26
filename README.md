# Doodle Bug Simulation

This is a small project that runs a simulation with ants and doodlebugs. The rules are 
simple:

1. Move-- Both ants and doodlebugs probabilistically choose a direction (up, down, left,
right) to move 1 cell. However, doodlebugs first look if there is an ant adjacent to them. If
so, then they move to the adjacent ant and "eat" it.

2. Breed-- Ants breed every 3 turns while doodlebugs breed every 8 turns. Breeding
occurs at the end of the turn. Again, both ants and doodlebugs probabilistically 
choose a direction to place their offspring in an adjacent cell. 

3. Starve-- If a doodlebug doesn't eat for three turns, then at the end of the third turn,
the doodlbug "dies". Ants do not starve.

And that concludes all the rules. This was an assignment from my second programming class
at the University of Alaska Anchorage. When I submited my program, it was
very messy. There was redundant code and possibly better methods to be used, but the mindset
was "it works, don't touch it."

This is my second attempt at it. I tried keeping my code as compact as possible while using
more clever methods than the first attempt. Obviously, this is an imperfectly written
project with probabilty better ways of wrriting it. I mainly wrote this just for interest.

To run this program, you can either manually compile it or use the make utility. Manual
compilation requires the following command:
g++ main.cpp Organism.cpp World.cpp Ant.cpp Doodlebug.cpp

The make utility will generate an executable labeled "Simulation". To run it, use:
./Simulation 

The program will generate a grid with ants labeled 'O' and doodlebugs labeled 'X'.
It starts with 100 ants and 5 doodlebugs. Every one second, the grid updates. To
exit the program, you'll have to stop the program process (Ctrl-c). 
