//DEER FILE
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "DEER.h"
#include "PLANTS.h"

using namespace std;

Deer::Deer(bool fAdult){
			
	if(fAdult==false){
			
		size=2;
		speed=4;
		neededFood=4;
		canClimb=false;
		isAdult=0;
	}else{
			
		size=5;
	    speed=8;
		neededFood=8;
		canClimb=false;
		isAdult=1;
			
	}
		
	eatenFood=0;
	
	stringstream ss; //creating different names for the entities
	static int x=1;  //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name="D"+new_string; //so each name is different. For example D1, D2 and so on..	
	x++;
	
	token='H';
	token2='D';
	hours_of_hunger=168;
	isAlive=1;
			
	
	eatCount=2;
	has_moved=0;
	hungerCount=0;
		
			
}
			
Deer::~Deer(){
	
}

Animals* Deer::breed(){
	
	if(isAdult==1){
		Animals* neodeer = new Deer(false);
		return neodeer;
	}else{
		return NULL;
	}
	
}

void Deer::move(int ts){
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

void Deer::eat(Plants* pplant){
	
if(hours_of_hunger>=168){  //herbivores eat 7 days after fulfilling their needs
	
	if(eatenFood<get_needed_food()){		//if it hasn't fulfilled its needs 	
		if(pplant->get_size()<size+4){		//make sure the plant it's going to eat is of the right size		
			if(pplant->get_life()<eatCount){ //this is used in cases where the plant's life is less than the animal's eatcount (meaning it may not fulfill its needs)
				eatenFood+=pplant->get_life(); //in such cases, the animal will eat its life
				pplant->set_life(0);           //and kill it
			}else{
				pplant->loselife(eatCount); //othewise it may eat eatcount amount
				eatenFood+=eatCount;
			}
		}
	}else{
		hours_of_hunger=0; //deer has eaten something, the 7 days are set to 0
		hungerCount=0; //hungercount is different variable. it refers to 10 days after haven't eaten anything
	}
	
}else{
		hours_of_hunger++; //deer didn't eat something, its hunger is increased
}

}

void Deer::raise(){ //raise is the "grow" function used by animals
	{	
			if(get_isAdult()==0){
				size++;
				if(size>=5){
					isAdult=true;	
				} 
				speed=speed+2;
				if(speed>8) speed=8;
				neededFood=neededFood+2;
				if(neededFood>8) neededFood=8;
			}
		}
}
		
int Deer::get_speed()const{
	return speed;
}

void Deer::set_name(string fname){
	name=fname;
}

string Deer::get_name()const{
	return name;
}
int Deer::get_needed_food()const{
	return neededFood;
}
int Deer::get_eaten_food()const{
	return eatenFood;
}
int Deer::get_eat_count()const{
	return eatCount;	
}
