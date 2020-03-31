//SALMON FILE
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "PLANTS.h"
#include "SALMON.h"
#include "TILE.h"

using namespace std;

Salmon::Salmon(){
	
	isAdult=1;		
	size=1;
	speed=5;
	neededFood=1;	
	canClimb=false;
	eatCount=1;
	
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name="S"+new_string; //so each name is different. For example S1, S2 and so on..
	x++;
			
	token='H';		
	token2='S';

	has_moved=0;
	hungerCount=0;
	isAlive=1;
	hours_of_hunger=168;
	just_bred=0;
	
}

Salmon::~Salmon(){
	
}

Animals* Salmon::breed(){
	
    static int x=0;
	x++;


	if(just_bred!=1){
		
		Animals* neosalmon = new Salmon();
		neosalmon->just_bred=1;
		if(x==10){
			x=0;
			neosalmon->just_bred=0;		
		}
		return neosalmon;
		
	}else{
		return NULL;
	}
	
	//just_bred is used so salmons may not breed endlessly (they do so otherwise because they are always adults)
    //after ten days just_bred is set to 0 so new salmons may reproduce
	
}

void Salmon::eat(Plants* pplant){
	
	
if(hours_of_hunger>=168){ //herbivores eat 7 days after fulfilling their needs
	
	if(pplant->get_token()=='A'){  
	if(eatenFood<get_needed_food()){ 		//if it hasn't fulfilled its needs 	
		if(pplant->get_size()<=size){		//make sure the plant it's going to eat is of the right size	 	
			if(pplant->get_life()<eatCount){ //this is used in cases where the plant's life is less than the animal's eatcount (meaning it may not fulfill its needs)				
				eatenFood+=pplant->get_life(); //in such cases, the animal will eat its life
				pplant->set_life(0);  //and kill it
			}else{
				pplant->loselife(eatCount); //othewise it may eat eatcount amount
				eatenFood+=eatCount;
			}
		
		}
	}else{
		hours_of_hunger=0; //salmon has eaten something, the 7 days are set to 0
		hungerCount=0; //hungercount is different variable. it refers to 10 days after haven't eaten anything
	}
	}
	
}else{
		hours_of_hunger++; //salmon didn't eat something, its hunger is increased
}
	
}
	


void Salmon::move(int ts, Tile** terrain){
	int x=rand()%get_speed()+1;	//how many tiles the animal will move (dependent on its speed)
	int y=rand()%4+1;	//the direction it will move (order: up-right-down-left)
	int flag=0;
	
	if(y==1 && coordinatex-x>0){
		int i = coordinatex-x;
		while( flag==0 && i<coordinatex){
			if(terrain[i][coordinatey].get_token()=='^' || terrain[i][coordinatey].get_token()=='"' ){
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
			if(terrain[i][coordinatey].get_token()=='^' || terrain[i][coordinatey].get_token()=='"' ){
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
			if(terrain[i][coordinatey].get_token()=='^' || terrain[i][coordinatey].get_token()=='"' ){
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
			if(terrain[i][coordinatey].get_token()=='^' || terrain[i][coordinatey].get_token()=='"' ){
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
	//flag checks if the tile it's about to go is not of type 'water'. salmons move only at water
	//has_moved variable is used so each animal may move one time each hour
	
}

int Salmon::get_speed()const{
	return speed;
}

void Salmon::set_name(string fname){
	name=fname;
}

string Salmon::get_name()const{
	return name;
}

int Salmon::get_needed_food()const{
	return neededFood;
}

int Salmon::get_eaten_food()const{
	return eatenFood;
}

int Salmon::get_eat_count()const{
	return eatCount;	
}

