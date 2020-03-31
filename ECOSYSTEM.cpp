#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ECOSYSTEM.h"
#include "TILE.h"
#include "GRASS.h"
#include "OAK.h"
#include "PINE.h"
#include "MAPLE.h"
#include "ALGAE.h"
#include "BEAR.h"
#include "DEER.h"
#include "RABBIT.h"
#include "GROUNDHOG.h"
#include "SALMON.h"
#include "FOX.h"
#include "WOLF.h"


using namespace std;

extern int TerrainSize;
extern int LakeSize;

Node::Node(){
	panimal=NULL;
	pnext=NULL;
}

Ecosystem::Ecosystem(int ts,int ls):terrainSize(ts),lakeSize(ls){
    
	Season="default season";
	Dayofyear.day=1;
	Dayofyear.hour=1, 
	
	
	terrain= new Tile*[ts]; //creating a 2d array for tiles
	for(int i=0; i<ts;i++){
		
		terrain[i] = new Tile[ts];
	}
	

}

Ecosystem::~Ecosystem(){
	
	for(int x=0;x<terrainSize;x++){
		
		delete[] terrain[x];
		
	}

	delete[] terrain;

	
}

void Ecosystem::MapGenerator(){
	
	GenerateRiver();	
	GenerateLake();
	GenerateHills();
	GenerateMeadow();
}

		
void Ecosystem::GenerateRiver(){ //creating the river
	
	int y = rand()%(terrainSize-9); //y is the column where the river will begin
	y+=5;       
	for(int ts=0; ts<terrainSize-1; ts++){
		terrain[ts][y].set_token('#');
		int x1=rand()%5; //x1 gives 4 random options of where the next river tile will be placed 	
		if(x1 == 0 && y-2>=0){	//deviating 2 tiles left
			terrain[ts+1][y].set_token('#');
			terrain[ts+1][y-1].set_token('#');
			y=y-2;
		}
		if(x1 == 1 && y-1>=0){	//deviating one tile left
			terrain[ts+1][y].set_token('#');
			y=y-1;
		}
		if(x1 == 3 && y+1<terrainSize){	//deviating one tile right
			terrain[ts+1][y].set_token('#');
			y=y+1;
		}
		if(x1 == 4 && y+2<=terrainSize){	//deviating two tiles right
			terrain[ts+1][y].set_token('#');
			terrain[ts+1][y+1].set_token('#');
			y=y+2;
		}
			
	}
}
		
void Ecosystem::GenerateLake(){
	bool flag1=1;	//if the spot is valid
	bool flag=0;	//if there is already a lake, stop the loop
	int x=terrainSize+4;
	int y=x;
	while(flag==0 ){
			for(int k=x;k<x+lakeSize;k++){
					for(int l=y;l<y+lakeSize;l++){
						if(k>=terrainSize || l>=terrainSize) flag1=0;
					}
		}
		if(flag1==1){	//there is a vaild spot for the lake 
					for(int k=x;k<x+lakeSize;k++){
					for(int l=y;l<y+lakeSize;l++){
						terrain[k][l].set_token('#');
						flag=1;
					}
				}
			}
			flag1=1;
			x=rand()%terrainSize;
			y=x;
		}
}	

void Ecosystem::GenerateHills(){
	int temp1;
	bool flag=1;
	int temp;
	bool at_least1=0;
	for(int x=0;x<terrainSize-1;x++){
		for(int y=0;y<terrainSize-1;y++){
			temp=rand()%20;	//chance to get a hill
			if(temp==1){
				temp1=rand()%3+2;		//size of a hill (it may be square of 2x2, 3x3 or 4x4)
				for(int k=x;k<x+temp1;k++){
					for(int l=y;l<y+temp1;l++){
						if(k>=terrainSize || l>=terrainSize){
							flag=0;
						}else{
							if(terrain[k][l].get_token()=='^') flag=0;
							if(terrain[k][l].get_token()=='#') flag=0;
						}
					}
					if(flag==0) break;
				}
				if(flag==1){
					for(int k=x;k<x+temp1;k++){
					for(int l=y;l<y+temp1;l++){
						terrain[k][l].set_token('^');
						at_least1=1;
					
					}
				}
			}	}
			flag=1;
}}
	if(at_least1==0){ //this is used because in small maps (i.e. 10x10) the generator may not be able to create any hill at all. in this case 2x2 hills are placed at the first available corner
		if(terrain[0][0].get_token()=='!' && terrain[0][1].get_token()=='!' && terrain[1][0].get_token()=='!' && terrain[1][1].get_token()=='!' ){
			terrain[0][0].set_token('^');
			terrain[0][1].set_token('^');
			terrain[1][0].set_token('^');
			terrain[1][1].set_token('^');
		}else if(terrain[0][terrainSize-2].get_token()=='!' && terrain[0][terrainSize-1].get_token()=='!' && terrain[1][terrainSize-2].get_token()=='!' && terrain[1][terrainSize-1].get_token()=='!' ){
			terrain[0][terrainSize-2].set_token('^');
			terrain[0][terrainSize-1].set_token('^');
			terrain[1][terrainSize-2].set_token('^');
			terrain[1][terrainSize-1].set_token('^');
		}else if(terrain[terrainSize-2][0].get_token()=='!' && terrain[terrainSize-2][1].get_token()=='!' && terrain[terrainSize-1][0].get_token()=='!' && terrain[terrainSize-1][1].get_token()=='!' ){
			terrain[terrainSize-2][0].set_token('^');
			terrain[terrainSize-2][1].set_token('^');
			terrain[terrainSize-1][0].set_token('^');
			terrain[terrainSize-1][1].set_token('^');
		}else if(terrain[terrainSize-2][terrainSize-2].get_token()=='!' && terrain[terrainSize-2][terrainSize-1].get_token()=='!' && terrain[terrainSize-1][terrainSize-2].get_token()=='!' && terrain[terrainSize-1][terrainSize-1].get_token()=='!' ){
			terrain[terrainSize-2][terrainSize-2].set_token('^');
			terrain[terrainSize-2][terrainSize-1].set_token('^');
			terrain[terrainSize-1][terrainSize-2].set_token('^');
			terrain[terrainSize-1][terrainSize-1].set_token('^');
		}
	}

}

void Ecosystem::GenerateMeadow(){
	for(int x=0;x<terrainSize;x++){
		for(int y=0;y<terrainSize;y++){
			if(terrain[x][y].get_token()=='!') terrain[x][y].set_token('"'); //since ! is the default token, meadow token is placed wherever it is spotted. water and hill tokens are in every other spot
		}
	}
}

void Ecosystem::PrintSystem(){
	
	for(int ts=0; ts<terrainSize; ts++){ //printing the map
		for(int y=0; y<terrainSize; y++){
			if(terrain[ts][y].get_plant_token()=='!'){
				cout<<terrain[ts][y].get_token()<<" ";
			}else{
				cout<<terrain[ts][y].get_plant_token()<<" ";
			}
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	cout<<"Total Plants: "<<pcounter<<endl;
	cout<<"Total Seedless: "<<seedlesscounter<<endl;
	cout<<"Total Seeded: "<<seedcounter<<endl;
	Print_Plant_Statistics();
	
	cout<<endl;
	
	cout<<"Total Animals: "<<hcounter+ccounter<<endl;
	cout<<"Total Herbivores: "<<hcounter<<endl;
	cout<<"Total Carnivores: "<<ccounter<<endl;
	Print_Animal_Statistics();
		
	//the statistics functions print the counters of each separate entity	
}
	

void Ecosystem::PlacePlants(int cgrass, int calgae, int coak, int cpine, int cmaple ){
	
	pcounter=0;
	seedcounter=0;
	seedlesscounter=0;
	grcounter=0;
	alcounter=0;
	mcounter=0;
	ocounter=0;
	picounter=0;
	int cg=0;
	int big_counter=1; 
	int x;
	int y;
	
	//the loop works as follows: if there are still plants of one entity (grass for example) run the loop until all grasses are placed. after all of them have been placed proceed to the next entity and repeat
	while(big_counter<= cgrass + calgae + coak + cpine + cmaple ){ 
		x=rand()%terrainSize;
		y=rand()%terrainSize;
		if (big_counter<= cgrass ){	//grass placement
		if(terrain[x][y].get_token()=='"' && terrain[x][y].get_plant_token()=='!'){
			Plants *neoplant = new Grass();
			neoplant->set_coords(x,y);
			terrain[x][y].link_tile_plant(neoplant);
			terrain[x][y].set_plant_token(neoplant->get_token()); 
			big_counter++; 
			
			pcounter++;
			seedlesscounter++;
			grcounter++;
		}
		
		}else if(big_counter>cgrass && big_counter<= cgrass + calgae){		//algae placement
		
			if(terrain[x][y].get_token()=='#' && terrain[x][y].get_plant_token()=='!'){
			Plants *neoplant = new Algae();
			neoplant->set_coords(x,y);
			terrain[x][y].link_tile_plant(neoplant);
			terrain[x][y].set_plant_token(neoplant->get_token()); 
			big_counter++; 
			
			pcounter++;
			seedlesscounter++;
			alcounter++;

			}
		
		}else if(big_counter>cgrass + calgae && big_counter<= cgrass + calgae + coak){	//oak placement
	
			if(terrain[x][y].get_token()=='"' && terrain[x][y].get_plant_token()=='!'){
			Plants *neoplant = new Oak();
			neoplant->set_coords(x,y);
			terrain[x][y].link_tile_plant(neoplant);
			terrain[x][y].set_plant_token(neoplant->get_token());
			big_counter++;
			
			pcounter++;
			seedcounter++;
			ocounter++;
			
			}		
			
		}else if(big_counter> cgrass + calgae + coak && big_counter<= cgrass + calgae + coak + cpine){	//pine placement
			
			if(terrain[x][y].get_token()=='^' && terrain[x][y].get_plant_token()=='!'){
			Plants *neoplant = new Pine();
			neoplant->set_coords(x,y);
			terrain[x][y].link_tile_plant(neoplant);
			terrain[x][y].set_plant_token(neoplant->get_token()); 
			big_counter++; 
			
			pcounter++;
			seedcounter++;
			picounter++;
			}
			
		}else if(big_counter> cgrass + calgae + coak + cpine && big_counter<= cgrass + calgae + coak + cpine + cmaple ){	//maple placement

			if(terrain[x][y].get_token()=='"' || terrain[x][y].get_token()=='^'  && terrain[x][y].get_plant_token()=='!'){
			Plants *neoplant = new Maple();
			neoplant->set_coords(x,y);
			terrain[x][y].link_tile_plant(neoplant);
			terrain[x][y].set_plant_token(neoplant->get_token()); 
			big_counter++; 	
			
			pcounter++;
			seedcounter++;
			mcounter++;
			}
							
		}	
}
}	

void Ecosystem::PlaceAnimals(int cdeer,int cghog,int crabbit,int csalmon,int cfox,int cwolf,int cbear){
	int counter=1;
	
    hcounter=0;
	ccounter=0;
	dcounter=0;
	rcounter=0;
	gcounter=0;
	scounter=0;
	fcounter=0;
	wcounter=0;
	bcounter=0;
	int x,y;
	
	//the loop works as follows: if there are still plants of one entity (deers for example) run the loop until all deers are placed. after all of them have been placed proceed to the next entity and repeat
	//a linked list is used to keep multiple animals in one tile
	while(counter<=cdeer+cghog+crabbit+csalmon+cfox+cwolf+cbear){
	
		x=rand()%terrainSize;
		y=rand()%terrainSize;
		if(counter<=cdeer){ //deer placement
			if(terrain[x][y].get_token()=='"' ){ 
				Animals* neoanimal=new Deer(true);
				terrain[x][y].add_element(neoanimal);
				neoanimal->set_coords(x,y);
				counter++;
				
				hcounter++;
				dcounter++;
			}
			
		}else if(counter>cdeer && counter<= cdeer + cghog ){ //groundhog placement
			if(terrain[x][y].get_token()=='"' ){
				Animals* neoanimal=new Groundhog(true);
				terrain[x][y].add_element(neoanimal);
				neoanimal->set_coords(x,y);
				counter++;
	
				hcounter++;
				gcounter++;
			}
			
		}else if(counter>cdeer + cghog && counter<= cdeer + cghog + crabbit ){ //rabbit placement
			if(terrain[x][y].get_token()=='"'  ){
				Animals* neoanimal=new Rabbit(true);
				terrain[x][y].add_element(neoanimal);
				neoanimal->set_coords(x,y);
				counter++;
				
				hcounter++;
				rcounter++;
			}
			
		}else if(counter>cdeer + cghog + crabbit && counter <= cdeer + cghog + crabbit + csalmon){ //salmon placement
			if(terrain[x][y].get_token()=='#' ){
				Animals* neoanimal = new Salmon();
				terrain[x][y].add_element(neoanimal);
				neoanimal->set_coords(x,y);
				counter++;
				
				hcounter++;
				scounter++;
			}
			
		}else if(counter>cdeer + cghog + crabbit + csalmon && counter <= cdeer + cghog + crabbit + csalmon + cfox){ //fox placement
			if(terrain[x][y].get_token()=='"'  ){
				Animals* neoanimal=new Fox(true);
				terrain[x][y].add_element(neoanimal);
				neoanimal->set_coords(x,y);
				counter++;
				
				ccounter++;
				fcounter++;
			}
			
		}else if(counter> cdeer + cghog + crabbit + csalmon + cfox && counter <= cdeer + cghog + crabbit + csalmon + cfox + cwolf){ //wolf placement
			if(terrain[x][y].get_token()=='"' || terrain[x][y].get_token()=='^'  ){
				Animals* neoanimal=new Wolf(true);
				terrain[x][y].add_element(neoanimal);
				neoanimal->set_coords(x,y);
				counter++;

				ccounter++;
				wcounter++;
			}
			
		}else if(counter> cdeer + cghog + crabbit + csalmon + cfox + cwolf && counter<= cdeer + cghog + crabbit + csalmon + cfox + cwolf + cbear ){ //bear placement
			if(terrain[x][y].get_token()=='^'  ){
				Animals* neoanimal=new Bear(true);
				terrain[x][y].add_element(neoanimal);
				neoanimal->set_coords(x,y);
				counter++;
				
				ccounter++;
				bcounter++;
				
			}
		}
		
	}
	
}


Tile Ecosystem::get_tile(int x,int y){
	return terrain[x][y];
}

void Ecosystem::AnimalMovement(){
	for(int x=0;x<terrainSize;x++){
		for(int y=0;y<terrainSize;y++){
			
			Node* temp=terrain[x][y].get_pnode();
			while(temp!=NULL){
			if(temp->panimal->get_has_moved()==0)	{ //each animal may move once every hour
			
			if(temp->panimal->get_token2()=='G' || temp->panimal->get_token2()=='R' || temp->panimal->get_token2()=='S' ){
				terrain[x][y].get_animal(temp->panimal)->move(terrainSize,terrain);  //overloaded move function is used for groundhogs, rabbits and salmons, because they cannot go at every tile type, so we need to pass the tile as an argument
				
			}
			else {
				terrain[x][y].get_animal(temp->panimal)->move(terrainSize); //both move functions set the new coordinates of the next position
				} 
			}
			if(x!=temp->panimal->get_coord_x() || y!=temp->panimal->get_coord_y()){ //if the animal managed to move
			Animals* neoanimal=temp->panimal;
			int newx=temp->panimal->get_coord_x(); //keep its new coordinates
			int newy=temp->panimal->get_coord_y();
			terrain[x][y].remove_element(temp->panimal); //remove it the previous tile	
			terrain[newx][newy].add_element(neoanimal); //and place it in the new one
			
		}
			temp=temp->pnext;
			}
	}
}}


void Ecosystem::WakeUp(){ //wake up function is used to wake up the hibernating animals
	
	for(int x=0;x<terrainSize;x++){
		for(int y=0;y<terrainSize;y++){
			Node* temp=terrain[x][y].get_pnode();
			while(temp!=NULL){
				if(temp->panimal->get_hibernates()==1){
					temp->panimal->set_inHibernation(0);
				}
				temp=temp->pnext;
			}
		}
	}
			
}

void Ecosystem::Sleep(){ //sleep function is used to put the hibernating animals to sleep
	
	for(int x=0;x<terrainSize;x++){
		for(int y=0;y<terrainSize;y++){
			Node* temp=terrain[x][y].get_pnode();
			while(temp!=NULL){
				if(temp->panimal->get_hibernates()==1){
					temp->panimal->set_inHibernation(1);
				}
				temp=temp->pnext;
			}
		}
	}
			
}

void Ecosystem::ApplySeason(string season){ //sets the appropiate season to the season data member and changes the growth and breeding periods
	
	this->Season=season;
	if(season=="spring"){
		Plants_Growth_Period=5;
		Animals_Growth_Period=20;
		Plants_Breeding_Rep_Period=10;
		Herbs_Breeding_Rep_Period=12;
		Carns_Breeding_Rep_Period=11;
		WakeUp();
		
	}else if(season=="summer"){
		Plants_Growth_Period=10;
		Animals_Growth_Period=30;
		Plants_Breeding_Rep_Period=10;
		Herbs_Breeding_Rep_Period=8;
		Carns_Breeding_Rep_Period=9;		
		
	}else if(season=="fall"){
		Plants_Growth_Period=0;
		Animals_Growth_Period=15;
		Plants_Breeding_Rep_Period=20;
		Herbs_Breeding_Rep_Period=5;
		Carns_Breeding_Rep_Period=9;
		
	}else if(season=="winter"){
		Sleep();
		Plants_Growth_Period=10;
		Animals_Growth_Period=30;
		Plants_Breeding_Rep_Period=0;
		Herbs_Breeding_Rep_Period=18;
		Carns_Breeding_Rep_Period=10;
	}	
}

void Ecosystem::RunEcosystem(int days ,string season){ 
	PrintSystem(); 
	
	cout<<endl;
	
	int season_counter=0;
	
	//set the starting season
	
	if(season=="spring"){
		ApplySeason("spring");
	}else if(season=="summer"){
		ApplySeason("summer");
	}else if(season=="fall"){
		ApplySeason("fall");
	}else if(season=="winter"){
		ApplySeason("winter");
	}
	
	cout<<Season<<" has come"<<endl;
	
	for (int i=1;i<=days;i++){ //the run ecosystem function will run for the days the user has entered 
		
		DailyReset(); 
		GrowAll();
		
		for(;Dayofyear.hour<=24;Dayofyear.hour++){ //movement and eating take place at every hour
			AnimalMovement();
			AnimalEating();
		}
		
		CheckDeadEntities();
		CheckHunger();
		
		AnimalBreeding();
		
		PlantBreeding();
		
		cout<<"Day:"<< i <<endl; 
		season_counter++; 
		if(season_counter == 90){ //after 90 days the season must change
		if(this->Season=="spring"){
			ApplySeason("summer");
		}else if(this->Season=="summer"){
			ApplySeason("fall");
		}else if(this->Season=="fall"){
			ApplySeason("winter");
		}else if(this->Season=="winter"){
			ApplySeason("spring");
		}
		
		season_counter=0; //reset the counter for the next season
		cout<<endl;
		
		cout<<Season<<" has come"<<endl;
		
		cout<<endl;
		
		PrintSystem();
		
		cout<<endl;
		}
	}
	
	PrintSystem();
	
}

void Ecosystem::DailyReset(){
		Dayofyear.day++;
		Dayofyear.hour=0;
		for(int x=0;x<terrainSize;x++){
				for(int y=0;y<terrainSize;y++){
				Node* temp=terrain[x][y].get_pnode();
					while(temp!=NULL){
							temp->panimal->set_eaten_food(0); //reset the hunger of the animals
							temp=temp->pnext;
			}
				}
		}
}

void Ecosystem::GrowAll(){
	for(int x=0;x<terrainSize;x++){
	    for(int y=0;y<terrainSize;y++){
						if(Season!="fall"){ //plants cannot grow during fall
						if(Dayofyear.day%Plants_Growth_Period==0){
							
							int k=rand()%100+1;
							Plants* temp=terrain[x][y].get_plant();
							if(temp!=NULL){
							if(k<=temp->get_illness_prob()){	//the plant is ill 
								temp->loselife(temp->get_life_factor());
							}else{								//the plant is healthy
								 temp->grow();
							
						}
					}
					}
				}
					if(Dayofyear.day%Animals_Growth_Period==0){
						
						Node* temp=terrain[x][y].get_pnode();
						while(temp!=NULL && temp->panimal->get_inHibernation()!=1){
						temp->panimal->raise();
						temp=temp->pnext;
					}
					}
	    }
}
}

void Ecosystem::AnimalEating(){
	for(int x=0;x<terrainSize;x++){
		for(int y=0;y<terrainSize;y++){
			
			Node* temp=terrain[x][y].get_pnode();		//plants are being eaten
			Plants* ptemp=terrain[x][y].get_plant();
			
			
			if(ptemp!=NULL && temp!=NULL && temp->panimal->get_token()=='H'){
				
				temp->panimal->eat(ptemp);
			}
			
		
			if(terrain[x][y].get_pnode()!=NULL && terrain[x][y].return_animal()->get_token()=='C'){		//animals are being eaten
			Node* atemp=terrain[x][y].get_pnode();
			Node* atemp2=terrain[x][y].get_pnode()->pnext;
			while(atemp!=NULL && atemp2!=NULL){
				if(atemp2->panimal->get_is_alive() && atemp->panimal->get_is_alive()) atemp->panimal->eat(atemp2->panimal);
				atemp=atemp2;
				atemp2=atemp2->pnext;
			}
			
		}
		}
	}
}


void Ecosystem::CheckDeadEntities(){
	
	for(int x=0;x<terrainSize;x++){
		for(int y=0;y<terrainSize;y++){
			
			
			Plants* temp=terrain[x][y].get_plant();
			if(temp!=NULL && temp->is_alive()==0){ 
				if(temp->get_token()=='G'){
					pcounter--;
					seedlesscounter--;
					grcounter--;

				}else if(temp->get_token()=='A'){
					pcounter--;
					seedlesscounter--;
				}else if(temp->get_token()=='P'){
					pcounter--;
					seedcounter--;
					picounter--;
				}else if(temp->get_token()=='M'){
					pcounter--;
					seedcounter--;
					mcounter--;
				}else if(temp->get_token()=='O'){
					pcounter--;
					seedcounter--;
					ocounter--;
				}

				terrain[x][y].set_plant_token('!');
				
				delete temp;
				
				terrain[x][y].link_tile_plant(NULL);
				
				
			}
			Node* temp2=terrain[x][y].get_pnode();
			while(temp2!=NULL && temp2->panimal->get_is_alive()==0){
				if(temp2->panimal->get_token2()=='D'){
					hcounter--;
					dcounter--;
				}else if(temp2->panimal->get_token2()=='R'){
					hcounter--;
					rcounter--;
				}else if(temp2->panimal->get_token2()=='G'){
					hcounter--;
					gcounter--;
				}else if(temp2->panimal->get_token2()=='S'){
					hcounter--;
					scounter--;
				}else if(temp2->panimal->get_token2()=='B'){
					ccounter--;
					bcounter--;	
				}else if(temp2->panimal->get_token2()=='F'){
					ccounter--;
					fcounter--;
				}else if(temp2->panimal->get_token2()=='W'){
					ccounter--;
					wcounter--;
				}
				
				terrain[x][y].kill_element(temp2->panimal);
				
				temp2=temp2->pnext;
			}
	}
	}
}

void Ecosystem::CheckHunger(){
	for(int x=0;x<terrainSize;x++){
		for(int y=0;y<terrainSize;y++){
			Node* temp=terrain[x][y].get_pnode();
			while(temp!=NULL){
			
				if(temp->panimal->get_eaten_food()<temp->panimal->get_neededFood()){ //the animal didn't manage to eat for this day
					temp->panimal->inc_hunger_count();
				}
				if(temp->panimal->get_hunger_count()==10){
					temp->panimal->set_life(); //death from hunger
					terrain[x][y].kill_element(temp->panimal); //if it died remove it, otherwise dead animals start breeding 
				}
				
				temp=temp->pnext;
			}
	}
	}
}

void Ecosystem::AnimalBreeding(){
	for(int x=0;x<terrainSize;x++){
	    for(int y=0;y<terrainSize;y++){
	    			
					if(Dayofyear.day%Herbs_Breeding_Rep_Period==0){					
						Node* temp=terrain[x][y].get_pnode();
						while(temp!=NULL ){
						
						if(temp->panimal->get_token()=='H'){
						
						Animals* mikro = temp->panimal->breed(); 
						if(mikro!=NULL){
		  				terrain[x][y].add_element(mikro);
		  				mikro->set_coords(x,y);
		  				
		  					  if(temp->panimal->get_token2()=='D'){
								hcounter++;
								dcounter++;
							  }
							  if(temp->panimal->get_token2()=='G'){
								hcounter++;
								gcounter++;
							  }
							  if(temp->panimal->get_token2()=='R'){
								hcounter++;
								rcounter++;
							  }
							  if(temp->panimal->get_token2()=='S'){
								hcounter++;
								scounter++;
							  }
							  
						  }
		  				
		  				
						}
						temp=temp->pnext;
					}
					
					} if(Dayofyear.day%Carns_Breeding_Rep_Period==0){
						Node* temp=terrain[x][y].get_pnode();
						while(temp!=NULL ){
						
						if(temp->panimal->get_token()=='C'){
							
						Animals* mikro = temp->panimal->breed(); 
						if (mikro!=NULL){
						
		  				terrain[x][y].add_element(mikro);
		  				mikro->set_coords(x,y);
		  				  
		  					if(temp->panimal->get_token2()=='B'){
								ccounter++;
								bcounter++;
							  }
							  if(temp->panimal->get_token2()=='F'){
								ccounter++;
								fcounter++;
							  }
							  if(temp->panimal->get_token2()=='W'){
								ccounter++;
								wcounter++;
							  }
						  }
		  				
						}
						temp=temp->pnext;
					}
				}
	    }
}
	
	
}

int Ecosystem::FindFreeTile(Plants* pplant){
	
	int x=pplant->get_coordinatex();
	int y=pplant->get_coordinatey();
	int x_plus_1=pplant->get_coordinatex()+1;
	int x_minus_1=pplant->get_coordinatex()-1;
	int y_plus_1=pplant->get_coordinatey()+1;
	int y_minus_1=pplant->get_coordinatey()-1;
	
	
	
	if(x_plus_1<terrainSize && x_minus_1>0 && y_plus_1<terrainSize && y_minus_1>0){
	
	
	if(pplant->get_token()=='G' || pplant->get_token()=='O') {
		if(terrain[x_plus_1][y].get_token()=='"' && terrain[x_plus_1][y].get_plant_token()=='!'){
			return 1;
		
		}else if(terrain[x_minus_1][y].get_token()=='"' && terrain[x_minus_1][y].get_plant_token()=='!'){
			return 2;
		}else if(terrain[x][y_plus_1].get_token()=='"' && terrain[x][y_plus_1].get_plant_token()=='!'){
			return 3;
		}else if(terrain[x][y_minus_1].get_token()=='"' && terrain[x][y_minus_1].get_plant_token()=='!'){
			return 4;
		}
	}
	
	if(pplant->get_token()=='A') {
		if(terrain[x_plus_1][y].get_token()=='#' && terrain[x_plus_1][y].get_plant_token()=='!'){
			return 1;
		
		}else if(terrain[x_minus_1][y].get_token()=='#' && terrain[x_minus_1][y].get_plant_token()=='!'){
			return 2;
		}else if(terrain[x][y_plus_1].get_token()=='#' && terrain[x][y_plus_1].get_plant_token()=='!'){
			return 3;
		}else if(terrain[x][y_minus_1].get_token()=='#' && terrain[x][y_minus_1].get_plant_token()=='!'){
			return 4;
		}
	}
	
	if(pplant->get_token()=='M' || pplant->get_token()=='P') {
		if((terrain[x_plus_1][y].get_token()=='"' && terrain[x_plus_1][y].get_plant_token()=='!') || (terrain[x_plus_1][y].get_token()=='^' && terrain[x_plus_1][y].get_plant_token()=='!')){
			return 1;
		
		}else if((terrain[x_minus_1][y].get_token()=='"' && terrain[x_minus_1][y].get_plant_token()=='!') || (terrain[x_minus_1][y].get_token()=='^' && terrain[x_minus_1][y].get_plant_token()=='!')){
			return 2;
		}else if((terrain[x][y_plus_1].get_token()=='"' && terrain[x][y_plus_1].get_plant_token()=='!') || (terrain[x][y_plus_1].get_token()=='^' && terrain[x][y_plus_1].get_plant_token()=='!')){
			return 3;
		}else if((terrain[x][y_minus_1].get_token()=='"' && terrain[x][y_minus_1].get_plant_token()=='!') || (terrain[x][y_minus_1].get_token()=='^' && terrain[x][y_minus_1].get_plant_token()=='!')){
			return 4;
		}
	}
	
}
	
	return 0;
}

void Ecosystem::PlantBreeding(){
		for(int x=0;x<terrainSize;x++){
	    for(int y=0;y<terrainSize;y++){
						if(Season!="winter"){
						if(Dayofyear.day%Plants_Breeding_Rep_Period==0){
							
							int k=rand()%100+1;
							Plants* temp=terrain[x][y].get_plant();
							if(temp!=NULL){
								
							if(k>temp->get_breeding_prob()){
									
							int position=FindFreeTile(temp);
							if(position!=0){
								
								
								if(position==1){
								Plants* mikro = temp->breed();
							
								if(x+1<terrainSize){
								mikro->set_coords(x+1,y);	
								terrain[x+1][y].link_tile_plant(mikro);
								terrain[x+1][y].set_plant_token(mikro->get_token()); 
								}
								
								if(temp->get_token()=='G'){
									pcounter++;
									seedlesscounter++;
									grcounter++;
								}
								if(temp->get_token()=='A'){
									pcounter++;
									seedlesscounter++;
									alcounter++;
								}
								if(temp->get_token()=='P'){
									pcounter++;
									seedcounter++;
									picounter++;
								}
								if(temp->get_token()=='O'){
									pcounter++;
									seedcounter++;
									ocounter++;
								}
								if(temp->get_token()=='M'){
									pcounter++;
									seedcounter++;
									mcounter++;
								}
								
								}
								
								if(position==2){
								Plants* mikro = temp->breed();
								if(x-1>0){
								mikro->set_coords(x-1,y);
								terrain[x-1][y].link_tile_plant(mikro);
								terrain[x-1][y].set_plant_token(mikro->get_token()); 
								}
								
								if(temp->get_token()=='G'){
									pcounter++;
									seedlesscounter++;
									grcounter++;
								}
								if(temp->get_token()=='A'){
									pcounter++;
									seedlesscounter++;
									alcounter++;
								}
								if(temp->get_token()=='P'){
									pcounter++;
									seedcounter++;
									picounter++;
								}
								if(temp->get_token()=='O'){
									pcounter++;
									seedcounter++;
									ocounter++;
								}
								if(temp->get_token()=='M'){
									pcounter++;
									seedcounter++;
									mcounter++;
								}
								
								}
								
								
								if(position==3){
								Plants* mikro = temp->breed();
								if(y+1<terrainSize){
								mikro->set_coords(x,y+1);
								terrain[x][y+1].link_tile_plant(mikro);
								terrain[x][y+1].set_plant_token(mikro->get_token()); 
								}
								
								if(temp->get_token()=='G'){
									pcounter++;
									seedlesscounter++;
									grcounter++;
								}
								if(temp->get_token()=='A'){
									pcounter++;
									seedlesscounter++;
									alcounter++;
								}
								if(temp->get_token()=='P'){
									pcounter++;
									seedcounter++;
									picounter++;
								}
								if(temp->get_token()=='O'){
									pcounter++;
									seedcounter++;
									ocounter++;
								}
								if(temp->get_token()=='M'){
									pcounter++;
									seedcounter++;
									mcounter++;
								}
								
								}
								
								
								if(position==4){
								Plants* mikro = temp->breed();
								if(y-1>0){
								mikro->set_coords(x,y-1);
								terrain[x][y-1].link_tile_plant(mikro);
								terrain[x][y-1].set_plant_token(mikro->get_token()); 
								}
								
								if(temp->get_token()=='G'){
									pcounter++;
									seedlesscounter++;
									grcounter++;
								}
								if(temp->get_token()=='A'){
									pcounter++;
									seedlesscounter++;
									alcounter++;
								}
								if(temp->get_token()=='P'){
									pcounter++;
									seedcounter++;
									picounter++;
								}
								if(temp->get_token()=='O'){
									pcounter++;
									seedcounter++;
									ocounter++;
								}
								if(temp->get_token()=='M'){
									pcounter++;
									seedcounter++;
									mcounter++;
								}
								
								}
								
								
								
								
								
								}
							}
						}
					}
					}
				}
					
					
	    }
}
	
	

void Ecosystem::Print_Animal_Statistics(){
	
	cout<<"Deers are: "<<dcounter<<endl;
	cout<<"Rabbits are: "<<rcounter<<endl;
	cout<<"Groundhogs are: "<<gcounter<<endl;
	cout<<"Salmons are: "<<scounter<<endl;
	cout<<"Bears are: "<<bcounter<<endl;
	cout<<"Foxes are: "<<fcounter<<endl;
	cout<<"Wolfs are: "<<wcounter<<endl;
}

void Ecosystem::Print_Plant_Statistics(){
	
	cout<<"Grasses are: "<<grcounter<<endl;
	cout<<"Algaes are: "<<alcounter<<endl;
	cout<<"Pines are: "<<picounter<<endl;
	cout<<"Oaks are: "<<ocounter<<endl;
	cout<<"Maples are: "<<mcounter<<endl;

}

