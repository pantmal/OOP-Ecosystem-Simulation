//FOX FILE
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "FOX.h"

using namespace std;

Fox::Fox(bool fAdult){
		
	if(fAdult==false){
			
		size=1;
		attack=1;
		defence=1;
		speed=1;
		neededFood=2;
		isAdult=0;
			
	}else{
			
		size=4;
		attack=5;
		defence=5;
		speed=6;
		neededFood=6;
		isAdult=1;
			
	}
	
	stringstream ss; //creating different names for the entities
	static int x=1;  //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name="F"+new_string; //so each name is different. For example F1, F2 and so on..	
	x++;
	
	token='C';
	token2='F';
	
	hours_of_hunger=192;
	hungerCount=0;
	isAlive=1;
	eatCount=neededFood;
	has_moved=0;
		
}
	
Fox::~Fox(){
	
}

Animals* Fox::breed(){
	
	if(isAdult==1){
		Animals* neofox = new Fox(false);
		return neofox;
	}else{
		return NULL;
	}
	
}

void Fox::eat(Animals* panimal){ 

	if(eatenFood<get_needed_food()){		//if it hasn't fulfilled its needs 	
		if(panimal->get_token()=='H'){   //eating herbivores here			
			if((panimal->get_size()<=size && panimal->get_speed()<=speed) || panimal->get_token()=='S'){ //making sure the fox can eat its enemy
				panimal->set_life(); //set_life sets the animal's life to 0, thus killing it
				eatenFood+=eatCount;	
			}
		}else if(panimal->get_token()=='C' && hours_of_hunger>=192){ //carnivores may eat other carnivores only after 8 days without eating anything (note: hours are used for those 8 days)
			if((panimal->get_size()==size && attack>panimal->get_defence() ) || panimal->get_size()<size){ //making sure the fox can eat its enemy
					panimal->set_life(); //set_life sets the animal's life to 0, thus killing it
					eatenFood+=eatCount;
			}
		}
		hours_of_hunger=0; //fox has eaten something, the 7 days are set to 0
		hungerCount=0; //hungercount is different variable. it refers to 10 days after haven't eaten anything
	}else{
		hours_of_hunger++; //fox didn't eat something, its hunger is increased
	}
}

void Fox::move(int ts){
	
	int x=rand()%get_speed()+1;	//how many tiles the animal will move (dependent on its speed)
	int y=rand()%4+1;	//the direction it will move (order: up-right-down-left)
	if(y==1 && coordinatex-x>=0){
		coordinatex=coordinatex-x;
		has_moved=1;
	}else if(y==2 && coordinatey+x<ts){
		coordinatey=coordinatey+x;
		has_moved=1;
	}else if(y==3 && coordinatex+x<ts){
		coordinatex=coordinatex+x;
		has_moved=1;
	}else if(y==4 && coordinatey-x>=0){
		coordinatey=coordinatey-x;
		has_moved=1;
	}	
	//has_moved variable is used so each animal may move one time each hour
}

void Fox::raise(){	 //raise is the "grow" function used by animals
	
	if(get_isAdult()==0){
		size++;
		if(size>=4) isAdult=true;
		speed++;
		if(speed>5) speed=5;
		neededFood++;
		if(neededFood>5) neededFood=5;
		attack++;
		if(attack>6) attack=6;
		defence++;
		if(defence>6) defence=6;
	}
	
}

int Fox::get_speed()const{
	return speed;
}

void Fox::set_name(string fname){
	name=fname;
}

string Fox::get_name()const{
	return name;
}

int Fox::get_needed_food()const{
	return neededFood;
}

int Fox::get_eat_count()const{
	return eatCount;
}

int Fox::get_eaten_food()const{
	return eatenFood;
}
