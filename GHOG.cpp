//GROUNDHOG FILE
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "GROUNDHOG.h"
#include "PLANTS.h"
#include "TILE.h"

using namespace std;

Groundhog::Groundhog(bool fAdult){
	
	if(fAdult==false){
		size=2;
		speed=3;
		neededFood=3;
		canClimb=false;
		isAdult=0;
		
	}else{
		size=3;
		speed=5;
		neededFood=5;
		canClimb=true;
		isAdult=1;
	}
		
	has_moved=0;
	eatCount=1;
	hibernates=1;
	
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name="GH"+new_string; //so each name is different. For example GH1, GH2 and so on..	
	x++;
	
	hours_of_hunger=168;
	hungerCount=0;
	isAlive=1;	
			
	
	token='H';
	token2='G';
	
}

Groundhog::~Groundhog(){
	
}

Animals* Groundhog::breed(){
	
	if(inHibernation==0 && isAdult==1){ //Groundhog cannot breed if it hibernates
		Animals* neoghog = new Groundhog(false);
		return neoghog;
	}else{
		return NULL;
	}
	
}

void Groundhog::eat(Plants* pplant){


if(inHibernation==0){ //Groundhog cannot eat if it hibernates

if(hours_of_hunger>=168){ //herbivores eat 7 days after fulfilling their needs
	
if(get_isAdult()==0){	//isadult is used because groundhogs can climb when they're adults, thus they behave differently

	if(pplant->get_token()!='A'){
	if(eatenFood<get_needed_food()){		//if it hasn't fulfilled its needs 	
		if(pplant->get_size()<=size){		//make sure the plant it's going to eat is of the right size				
			if(pplant->get_life()<eatCount){ //this is used in cases where the plant's life is less than the animal's eatcount (meaning it may not fulfill its needs)		
				eatenFood+=pplant->get_life(); //in such cases, the animal will eat its life
				pplant->set_life(0); //and kill it
			}else{
				pplant->loselife(eatCount); //othewise it may eat eatcount amount
				eatenFood+=eatCount;
			}
		
		}
	}else{
		hours_of_hunger=0; //groundhog has eaten something, the 7 days are set to 0
		hungerCount=0; //hungercount is different variable. it refers to 10 days after haven't eaten anything
	}
}

}else{
	if(pplant->get_token()!='A'){
	if(eatenFood<get_needed_food()){	//if it hasn't fulfilled its needs 		
		if(3*size<pplant->get_size()){			//make sure the plant it's going to eat is of the right size (different for adult groundhogs)						
			if(pplant->get_life()<eatCount){ //this is used in cases where the plant's life is less than the animal's eatcount (meaning it may not fulfill its needs)				
				eatenFood+=pplant->get_life(); //in such cases, the animal will eat its life
				pplant->set_life(0); //and kill it
			}else{
				pplant->loselife(eatCount); //othewise it may eat eatcount amount
				eatenFood+=eatCount;
			}
		}
	}else{
		hours_of_hunger=0; //groundhog has eaten something, the 7 days are set to 0
		hungerCount=0; //hungercount is different variable. it refers to 10 days after haven't eaten anything
	}
}
}

}else{
	hours_of_hunger++; //groundhog didn't eat something, its hunger is increased
}

}

}


void Groundhog::move(int ts, Tile** terrain){

if(inHibernation==0){ //Groundhog cannot move if it hibernates
	
	
	int x=rand()%get_speed()+1;	//how many tiles the animal will move (dependent on its speed)
	int y=rand()%4+1;	//the direction it will move (order: up-right-down-left)
	int flag=0;
	
	if(y==1 && coordinatex-x>0){
		int i = coordinatex-x;
		while( flag==0 && i<coordinatex){
			if(terrain[i][coordinatey].get_token()=='#'){
				flag=1;
			}	
			i++;
		}
		if(flag==0){
			coordinatex=coordinatex-x;
			has_moved=1;
		}
	}else if(y==2 && coordinatey+x<ts){
		int i = coordinatey;
		while( flag==0 && i<coordinatey+x ){
			if(terrain[i][coordinatey].get_token()=='#'){
				flag=1;
			}
			i++;
		}
		if(flag==0){
			coordinatey=coordinatey+x;
			has_moved=1;
		}
	}else if(y==3 && coordinatex+x<ts){
		int i = coordinatex;
		while( flag==0 && i<coordinatex+x){
			if(terrain[i][coordinatey].get_token()=='#'){
				flag=1;
			}
			i++;
		}
		if(flag==0){
			coordinatex=coordinatex+x;
			has_moved=1;
		}
	}else if(y==4 && coordinatey-x>=0){
		int i = coordinatey-x;
		while( flag==0 && i<coordinatey){
			if(terrain[i][coordinatey].get_token()=='#'){
				flag=1;
			}
			i++;
		}
		if(flag==0){
			coordinatey=coordinatey-x;
			has_moved=1;
		}
	}
	flag=0;
	//flag checks if the tile it's about to go is of type 'water'. groundhogs cannot go there
	//has_moved variable is used so each animal may move one time each hour
	
}

}

void Groundhog::raise(){ //raise is the "grow" function used by animals
	if(get_isAdult()==0){
		size++;
		if(size>=3) isAdult=true;
		speed++;
		if(speed>5) speed=5;
		neededFood++;
	    if(neededFood>5) neededFood=5;
				
	}
}
		
int Groundhog::get_speed()const{
	return speed;
}

void Groundhog::set_name(string fname){
	name=fname;
}

string Groundhog::get_name()const{
	return name;
}

int Groundhog::get_needed_food()const{
	return neededFood;
}

int Groundhog::get_eat_count()const{
	return eatCount;
}

int Groundhog::get_eaten_food()const{
	return eatenFood;
}
