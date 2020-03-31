#include <iostream>
#include <sstream>

#include "GRASS.h"

using namespace std;

Grass::Grass(){
	
	size=1;		//desing choice: size is set to 1 for seedless plants
	life=5;
	breedingProb=0.15;
	illnessProb=0.15;
	lifeFactor=4;
	token='G';
			
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name=token+new_string; //so each name is different. For example G1, G2 and so on..	
	x++;
			
	
}
		
Grass::~Grass(){
	
}	

char Grass::get_token(){
	return token;
}

Plants* Grass::breed(){
	
	Plants* neograss = new Grass();
	return neograss;
}

int Grass::get_size(){
	return size;
}
