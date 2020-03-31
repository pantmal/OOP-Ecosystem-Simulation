//FILE BEAR

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "BEAR.h"

using namespace std;

Bear::Bear(bool fAdult){
	
	if(fAdult==false){
			
		size=3;
		attack=6;
		defence=6;
		speed=4;
		neededFood=5;
		isAdult=0;
	}else{
			
		size=10;
		attack=10;
		defence=10;
		speed=4;
		neededFood=10;
		isAdult=1;
	}
		
	eatenFood=0;
	has_moved=0;
	
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name="B"+new_string;    //so each name is different. For example B1, B2 and so on..	
	x++;
	
	token='C';
	token2='B';
			
	isAlive=1;		
	eatCount=neededFood;
	hibernates=1;
	hours_of_hunger=192;
	hungerCount=0;
		
	
	
}

Bear::~Bear(){
	

}

Animals* Bear::breed(){
	
	if(inHibernation==0 && isAdult==1){   //Bear cannot breed if it hibernates
		Animals* neobear = new Bear(false);
		return neobear;
	}else{
		return NULL;
	}
	
}

void Bear::eat(Animals* panimal){

if(inHibernation==0){     //Bear cannot eat if it hibernates
	if(eatenFood<get_needed_food()){	//if it hasn't fulfilled its needs 	
		if(panimal->get_token()=='H'){	//eating herbivores here			
			panimal->set_life();		//set_life sets the animal's life to 0, thus killing it
			eatenFood+=eatCount;	    //if a carnivore eats anything it fullfills its needs
		}else if(panimal->get_token()=='C' && hours_of_hunger>=192){ //carnivores may eat other carnivores only after 8 days without eating anything (note: hours are used for those 8 days)
			if(get_isAdult()==0){ //if the bear is not an adult it behaves similarly to the other carnivores
				if( (panimal->get_size()==size && attack>panimal->get_defence() ) || panimal->get_size()<size){
					panimal->set_life(); //set_life sets the animal's life to 0, thus killing it
					eatenFood+=eatCount;
				}
			}else{ //if it is adult it wins the fight instantly
				panimal->set_life(); //set_life sets the animal's life to 0, thus killing it
				eatenFood+=eatCount;	
			}
		}
		hours_of_hunger=0; //bear has eaten something, the 8 days are set to 0
		hungerCount=0; //hungercount is different variable. it refers to 10 days after haven't eaten anything
	}else{
		hours_of_hunger++; //bear didn't eat something, its hunger is increased
	}

}
	
}


void Bear::raise(){	//raise is the "grow" function used by animals
	
	if(get_isAdult()==0){
		size=size+2;
		if(size>=10) isAdult=true;
		neededFood=neededFood+2;
		if(neededFood>10) neededFood=4;
		attack=attack+2;
		if(attack>10) attack=10;
		defence=defence+2;
		if(defence>10) defence=10;
		
	}
}

int Bear::get_speed()const{
	return speed;
}

void Bear::set_name(string fname){
	name=fname;
}

string Bear::get_name()const{
	return name;
}

void Bear::move(int ts){
	
if(inHibernation==0){ //Bear cannot move if it hibernates
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
	
}

int Bear::get_needed_food()const{
	return neededFood;
}

int Bear::get_eaten_food()const{
	return eatenFood;
}

int Bear::get_eat_count()const{
	return eatCount;	
}
