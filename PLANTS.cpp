#include <iostream>

#include "PLANTS.h"

using namespace std;

Plants::Plants(){
	
}

Plants::~Plants(){

}

char Plants::get_token(){
	return token;
}

void Plants::set_coords(int x, int y){
	this->coordinatex=x;
	this->coordinatey=y;
}

bool Plants::is_alive(){
	return life;
}

void Plants::set_life(int fl){
	this->life=fl;
}

int Plants::get_life(){
	return life;
}

int Plants::get_illness_prob()const{
	return illnessProb;
}

int Plants::get_breeding_prob()const{
	return breedingProb;
}

int Plants::get_life_factor()const{
	return lifeFactor;
}

int Plants::get_coordinatex()const{
	return coordinatex;
}

int Plants::get_coordinatey()const{
	return coordinatey;
}
	
Plants* Plants::breed(){

}

void Plants::grow(){

}

int Plants::get_size(){

}

void Plants::loselife(int){

}
