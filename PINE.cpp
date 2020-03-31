#include <iostream>
#include <sstream>

#include "PINE.h"

using namespace std;

Pine::Pine(){
	token='P';
	size=5;
	seeds=20;
	foliage=40;
	life=foliage;
	breedingProb=0.15;
	illnessProb=0.15;
	lifeFactor=0.15;
		
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name=token+new_string; //so each name is different. For example P1, P2 and so on..	
	x++;
		
	
}
	
Pine::~Pine(){
		
}

char Pine::get_token(){
	return token;
}

Plants* Pine::breed(){
	
	Plants* neopine = new Pine();
	return neopine;
}

int Pine::get_size(){
	return size;
}
