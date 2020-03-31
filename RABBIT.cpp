//ARXEIO RABBIT
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "RABBIT.h"
#include "PLANTS.h"
#include "TILE.h"
using namespace std;

Rabbit::Rabbit(bool fAdult){
	
	if(fAdult==false){
			
		size=1;
		speed=2;
		neededFood=2;
		canClimb=false;
		isAdult=0;
		
	}else{
			
		size=2;
		speed=6;
		neededFood=4;
		canClimb=false;
		isAdult=1;
	}
	
	has_moved=0;
	
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name="R"+new_string; //so each name is different. For example R1, R2 and so on..	
	x++;
	
	eatCount=1;
	
	token='H';
	token2='R';
	
	isAlive=1;
	
	hours_of_hunger=168;
	hungerCount=0;
		
}

Rabbit::~Rabbit(){
	
}

Animals* Rabbit::breed(){
	
	if(isAdult==1){
		Animals* neorabbit = new Rabbit(false);
		return neorabbit;
	}else{
		return NULL;
	}
	
}

void Rabbit::eat(Plants* pplant){
	
	
if(hours_of_hunger>=168){ //herbivores eat 7 days after fulfilling their needs
	
	if(pplant->get_token()!='A'){
	if(eatenFood<get_needed_food()){		//if it hasn't fulfilled its needs 	
		if(pplant->get_size()<=size){			//make sure the plant it's going to eat is of the right size	
			if(pplant->get_life()<eatCount){	//this is used in cases where the plant's life is less than the animal's eatcount (meaning it may not fulfill its needs)		
				eatenFood+=pplant->get_life(); //in such cases, the animal will eat its life
				pplant->set_life(0); //and kill it
			}else{
				pplant->loselife(eatCount); //othewise it may eat eatcount amount
				eatenFood+=eatCount;
			}
		
		}
	}else{
		hours_of_hunger=0; //rabbit has eaten something, the 7 days are set to 0
		hungerCount=0; //hungercount is different variable. it refers to 10 days after haven't eaten anything
	}
	}
	
}else{
		hours_of_hunger++; //rabbit didn't eat something, its hunger is increased
}
	
}




void Rabbit::move(int ts, Tile** terrain){
	int x=rand()%get_speed()+1;	//how many tiles the animal will move (dependent on its speed)
	int y=rand()%4+1;	//the direction it will move (order: up-right-down-left)
	int flag=0;
	
	if(y==1 && coordinatex-x>0){
		int i = coordinatex-x;
		while( flag==0 && i<coordinatex){
			if(terrain[i][coordinatey].get_token()=='^'){
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
			if(terrain[i][coordinatey].get_token()=='^'){
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
			if(terrain[i][coordinatey].get_token()=='^'){
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
			if(terrain[i][coordinatey].get_token()=='^'){
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
	//flag checks if the tile it's about to go is of type 'hill'. rabbits cannot go there
	//has_moved variable is used so each animal may move one time each hour
	
}

void Rabbit::raise(){	//raise is the "grow" function used by animals
	if(get_isAdult()==0){
		size++;
		if(size>=2) isAdult=true;
		speed=speed+2;
		if(speed>6) speed=6;
		neededFood=neededFood+2;
		if(neededFood>4) neededFood=4;	
			
	}
}

int Rabbit::get_speed()const{
	return speed;
}

void Rabbit::set_name(string fname){
	name=fname;
}

string Rabbit::get_name()const{
	return name;
}

int Rabbit::get_needed_food()const{
	return neededFood;
}

int Rabbit::get_eaten_food()const{
	return eatenFood;
}

int Rabbit::get_eat_count()const{
	return eatCount;	
}
