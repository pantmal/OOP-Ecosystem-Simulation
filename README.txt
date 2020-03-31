Ονόματα και Αριθμοί Μητρώου: Θεοφάνης Μπιρμπίλης 1115201600110

			     Παντελεήμων Μαλέκας 1115201600268


                 

Compilation command 1(through makefile): make
Compilation command 2(without makefile): g++ -o main ALGAE.cpp ANIMALS.cpp BEAR.cpp CARNIVORES.cpp DEER.cpp ECOSYSTEM.cpp FOX.cpp GHOG.cpp GRASS.cpp HERBIVORES.cpp MAIN.cpp MAPLE.cpp OAK.cpp PINE.cpp PLANTS.cpp RABBIT.cpp SALMON.cpp SEEDED.cpp SEEDLESS.cpp TILE.cpp WOLF.cpp



Run command: ./main TerrainSize LakeSize Days Season

Example:     ./main 20 3 200 spring



Regarding the arguments: TerrainSize is the size of the map (must be at least 10).

LakeSize is the size of the lake (i.e. for 3 we have a lake of 3x3).

Days is how many days the simulation will run.

Season is the starting season of the simulation. Must be either "spring", "summer", "fall" or "winter".



Methodology: In order to represent the animals, a Animals mother class was used (respectively a Plants class was used for the plants). Similarly a different class is used for Herbivores/Carnivores and Seedless/Seeded). So for example Deer class inhererits from Herbivores class which inherits from Animals class. The mother classes have protected data members so each child can access them quickly. The mother classes also have some virtual functions that are overriden if needed so (more on that later).

To represent the ecosystem an Ecosystem class is used. It has a 2D array of class Tile in order to represent the map, a struct Dayofyear with hour/year data members and a string Season.

The Tile class has a list of pointers to pointers of class Animals, a single pointer to a pointer of class Plants, and two tokens. The first one is the one it receives from the MapGenerator and the plant token is what it will receive from the PlacePlants function.

The functions will be explained below.



Description of how the program works: When the program begins, the command line arguments are passed on their respective variables. Then, we determine how many entities of each species will be placed (all plants are of TerrainSize/3 and all animals are of TerrainSize*2). 

After that, an Ecosystem object is created with TerrainSize and LakeSize arguments. The constructor of Ecosystem class also creates the tiles that will be used. (If terrain size is 20 we will have a terrain[20][20] array). 

Then the MapGenerator method is called to initialize the tokens of all tiles. It calls in that order: GenerateRiver, GenerateLake, GenerateHills and GenerateMeadow functions. Each function is implemented based on the presentation.

Then PlacePlants and PlaceAnimals methods are called to place all the plants and arguments on the map. To place the plants a loop is used which works as follows: if there are still plants of one entity (grass for example) run the loop until all grasses are placed. After all of them have been placed proceed to the next entity and repeat. Same thing is done for the animals. A tile may have one plant and many animals (through a list). Also each animal and plant is passed using a pointer to its mother class. If we need to do something distinct for a child class virtual functions are used.

After all these functions, the simulation begins using the RunEcosystem function. It uses an ApplySeason to set the starting season as well as the growth and breeding periods. Then the simulation runs for as many days as the user typed. 
Each day, DailyReset function sets eaten food as 0 for all animals and GrowAll calls the grow function of all entities if the day is the right one. 
Then, for 24 hours: AnimalMovement and AnimalEating functions are called. AnimalMovement makes each animal switch tiles. If it wasn't able to do so (because it couldn't go to the desired tile, for example) it will remain in its previous tile. In AnimalEating the first herbivore eats the plant in the tile it inhabits. The carnivores eat other herbivores (or other carnivores after 10 days of hunger) based on the order of the list. The first carnovire will eat thea animal after it and so on. After those 24 hours the next functions are called.

Next function is CheckDeadEntities which removes all dead plants and animals from the map. Then CheckHunger function does the necessary work for the hungry animals. Animals that are hungry for 10 consecutive days die are also removed from the map. 
Then AnimalBreeding function places makes all animals (if the day is right) place a new animal in the same tile it inhabits. PlantBreeding on the other hand uses a FindFreeTile function to place a new plant if it is possible (either the next tile up,down,left,right). If there is no free spot, it won't breed.

After every 90 days the season changes and sets the new growth and breeding periods. Also WakeUp and Sleep functions are called for the hibernating animals (whether the new season is spring or winter, respectively). Hibernating animals cannot breed, eat and move but they can grow and they can be eaten. 

Finally, PrintSystem function is called to print the map as well as how many plants and animals are in the simulation. It is called at the beginning of the simulation, at the change of every season and at the end of the simulation.
  
