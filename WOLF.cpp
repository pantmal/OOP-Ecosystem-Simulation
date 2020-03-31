//WOLF FILE
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "WOLF.h"

using namespace std; 

Wolf::Wolf(bool fAdult){
	
	if(fAdult==false){
		size=1;
		attack=2;
		defence=2;
		speed=2;
		neededFood=2;
		isAdult=0;
			
	}else{
			
		size=7;
		attack=8;
		defence=6;
		speed=8;
		neededFood=8;
		isAdult=1;
	}
	
	eatCount=neededFood;	
	has_moved=0;
	
	stringstream ss;//creating different names for the entities
	static int x=1;//static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name="W"+new_string;//so each name is different. For example W1, W2 and so on..	
	x++;
	
	token='C';
	token2='W';
	
	hungerCount=0;
	hours_of_hunger=192;
	isAlive=1;		
			
		
}
		
		
Wolf::~Wolf(){
	
}

Animals* Wolf::breed(){
	
	if(isAdult==1){
		Animals* neowolf = new Wolf(false);
		return neowolf;
	}else{
		return NULL;
	}
	
}

void Wolf::eat(Animals* panimal){
	
	if(eatenFood<get_needed_food()){	//if it hasn't fulfilled its needs 		
		if(panimal->get_token()=='H'){ //eating herbivores here		
			if((panimal->get_size()<=size && panimal->get_speed()<=speed) || panimal->get_token()=='S'){ //making sure the wolf can eat its enemy
				panimal->set_life();//set_life sets the animal's life to 0, thus killing it
				eatenFood+=eatCount;	
			}
		}else if(panimal->get_token()=='C' && hours_of_hunger>=192){ //carnivores may eat other carnivores only after 8 days without eating anything (note: hours are used for those 8 days)
			if( (panimal->get_size()==size && attack>panimal->get_defence() ) || panimal->get_size()<size){ //making sure the wolf can eat its enemy
					panimal->set_life();//set_life sets the animal's life to 0, thus killing it
					eatenFood+=eatCount;
			}
		}
		hours_of_hunger=0;//wolf has eaten something, the 7 days are set to 0
		hungerCount=0; //hungercount is different variable. it refers to 10 days after haven't eaten anything
	}else{
		hours_of_hunger++; //wolf didn't eat something, its hunger is increased
	}
}

void Wolf::move(int ts ){

	int x=rand()%get_speed()+1;	//how many tiles the animal will move (dependent on its speed)
	int y=rand()%4+1;	 //the direction it will move (order: up-right-down-left)
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

void Wolf::raise(){
	
	if(get_isAdult()==0){
		size++;
		if(size>=7) isAdult=true;
		speed=speed+2;
		if(speed>8) speed=8;
		neededFood=neededFood+2;
		if(neededFood>8) neededFood=8;
		attack=attack+2;
		if(attack>8) attack=8;
		defence=defence+2;
		if(defence>6) defence=6;
	}
		
}

int Wolf::get_speed()const{
	return speed;
}

void Wolf::set_name(string fname){
	name=fname;
}

string Wolf::get_name()const{
	return name;
}

int Wolf::get_needed_food()const{
	return neededFood;
}

int Wolf::get_eat_count()const{
	return eatCount;
}

int Wolf::get_eaten_food()const{
	return eatenFood;
}
