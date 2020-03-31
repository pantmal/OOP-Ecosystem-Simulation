#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H

#include "ANIMALS.h"
#include "TILE.h"

class Animals;
class Tile;

struct dayOfYear{
	int day;
	int hour;
};

struct Node{
	Animals* panimal;
	Node* pnext;
	Node();
};

class Ecosystem{
	std::string Season;
	int Plants_Growth_Period;
	int	Animals_Growth_Period;
	int	Plants_Breeding_Rep_Period;
	int	Herbs_Breeding_Rep_Period;
	int	Carns_Breeding_Rep_Period;
	dayOfYear Dayofyear;
	int terrainSize;
	Tile** terrain;
	int lakeSize;
	int noOfHills;
	int pcounter;
	int seedcounter;
	int seedlesscounter;
	int grcounter;
	int alcounter;
	int mcounter;
	int ocounter;
	int picounter;
	int hcounter;
	int ccounter;
	int dcounter;
	int rcounter;
	int gcounter;
	int scounter;
	int fcounter;
	int wcounter;
	int bcounter;
	
	public:
		
		Ecosystem(int , int );
		
		~Ecosystem();
	
		void MapGenerator();	
		
		void GenerateRiver();		
		
		void GenerateLake();		
		
		void GenerateHills();	
		
		void GenerateMeadow();	
			
		void PrintSystem();			
		
		void PlacePlants(int cgrass , int calgae, int coak , int cpine, int cmaple );        
		
		void PlaceAnimals(int cdeer,int cghog,int crabbit,int csalmon,int cfox,int cwolf,int cbear); 
		
		Tile get_tile(int,int);
		
		void AnimalMovement();
		
		void AnimalEating();
		
		void RunEcosystem(int ,std::string );
		
		void ApplySeason(std::string );
		
		void Sleep();
		
		void WakeUp();
		
		void DailyReset();
		
		void GrowAll();
		
		void CheckDeadEntities();
		
		void CheckHunger();
		
		void AnimalBreeding();
		
		int FindFreeTile(Plants*);
		
		void PlantBreeding();
		
		void Print_Animal_Statistics();
		
		void Print_Plant_Statistics();
		
};

#endif
