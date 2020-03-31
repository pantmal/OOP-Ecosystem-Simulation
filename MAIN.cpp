#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

#include "ECOSYSTEM.h"

using namespace std;

int TerrainSize;
int LakeSize;
int NoOfHills;
int days;
string season;

int main(int argc, char* argv[]){
	
	srand(time(NULL));
	
	if(argc < 1){
        cout<<"Error of argc"<<endl;
    }
    else if(argc < 5){
        cout<<"Error of argc"<<endl;
    }
	else{
		TerrainSize=atoi(argv[1]); //the user may determine terrainSize, lakeSize, how many days the program will run, as well as its starting season 
		LakeSize=atoi(argv[2]);
		days = atoi(argv[3]);
		season = argv[4];
	}
	
	
	int cgrass=TerrainSize/3; //the different amount of each entity is based on terrainSize
	int calgae=TerrainSize/3;
	int cmaple=TerrainSize/3;
	int cpine=TerrainSize/3;
	int coak=TerrainSize/3;
	int cbear=TerrainSize*2;
	int cwolf=TerrainSize*2;
	int cfox=TerrainSize*2;
	int csalmon=TerrainSize*2;
	int cghog=TerrainSize*2;
	int cdeer=TerrainSize*2;
	int crabbit=TerrainSize*2;
	

	Ecosystem E1(TerrainSize,LakeSize);		
	E1.MapGenerator();
	E1.PlacePlants(cgrass,calgae,cmaple,cpine,coak);
    E1.PlaceAnimals(cdeer,cghog,crabbit,csalmon,cfox,cwolf,cbear);
    E1.RunEcosystem(days,season);
	
	
	
}
