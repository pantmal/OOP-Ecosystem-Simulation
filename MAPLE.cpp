#include <iostream>
#include <sstream>

#include "MAPLE.h"

using namespace std;

Maple::Maple(){
	
	token='M';
	size=5;
	seeds=10;
	foliage=20;
	life=foliage;
	breedingProb=0.05;
	illnessProb=0.05;
	lifeFactor=10;
	 
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;
	string new_string = ss.str();
	name=token+new_string; //so each name is different. For example M1, M2 and so on..	
	x++;
	 
}
	
Maple::~Maple(){
		
}

char Maple::get_token(){
	return token;
}

Plants* Maple::breed(){
	
	Plants* neomaple = new Maple();
	return neomaple;
}

int Maple::get_size(){
	return size;
}

