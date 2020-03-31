#include <iostream>
#include <sstream>

#include "OAK.h"

using namespace std;

Oak::Oak(){
	token='O';
	size=5;
	seeds=15;
	foliage=30;
	life=foliage;
	breedingProb=0.20;
	illnessProb=0.20;
	lifeFactor=15;
	
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name=token+new_string; //so each name is different. For example O1, O2 and so on..	
	x++;
	
	
}	

Oak::~Oak(){
		
}

char Oak::get_token(){
	return token;
}

Plants* Oak::breed(){
	Plants* neooak = new Oak();
	return neooak;
}

int Oak::get_size(){
	return size;
}
