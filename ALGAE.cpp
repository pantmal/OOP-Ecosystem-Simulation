#include <iostream>
#include <sstream>

#include "ALGAE.h"

using namespace std;

Algae::Algae(){
	size=1;		//desing choice: size is set to 1 for seedless plants
	life=5;
	breedingProb=0.15;
	illnessProb=0.15;
	lifeFactor=4;
	token='A';
	
	stringstream ss; //creating different names for the entities
	static int x=1; //static variable x is increased every time the constructor is called
	ss<<x<<endl;    
	string new_string = ss.str(); 
	name=token+new_string;		//so each name is different. For example A1, A2 and so on..	
	x++;
	
}	

Algae::~Algae(){
		
}

char Algae::get_token(){
	return token;
}

Plants* Algae::breed(){ 	
	Plants* neoalgae=new Algae();		
	return neoalgae;		
}
	
int Algae::get_size(){
	return size;
}
