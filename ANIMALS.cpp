#include <iostream>

#include "ANIMALS.h"

using namespace std;

Animals::Animals(){

}

int Animals::get_isAdult()const{
	return isAdult;
}

void Animals::set_name(string fname){
	this->name=fname;
}

string Animals::get_name()const{
	return this->name;
}

int Animals::get_speed()const{
	return speed;
}

void Animals::set_coords(int x,int y){
	this->coordinatex=x;
	this->coordinatey=y;
}

char Animals::get_token()const{
	return token;
}

char Animals::get_token2()const{
	return token2;
}

int Animals::get_size()const{
	return size;
}

void Animals::set_life(){
	this->isAlive=0;
}

void Animals::set_eaten_food(int x){
	eatenFood=x;
}

bool Animals::get_is_alive()const{
	return isAlive;
}

void Animals::inc_hunger_count(){
	hungerCount++;
}

int Animals::get_hunger_count()const{
	return this->hungerCount;
}

void Animals::raise(){

}

bool Animals::get_has_moved()const{
	return has_moved;
}

void Animals::move(int){
}

void Animals::move(int x, Tile** t){

}

Animals* Animals::breed(){

}

int Animals::get_coord_x()const{
	return coordinatex;
}

int Animals::get_coord_y()const{
	return coordinatey;
}

int Animals::get_neededFood()const{

}

int Animals::get_eat_count()const{

}

int Animals::get_eaten_food()const{

}

int Animals::get_defence()const{
		 	
}

void Animals::eat(Plants* p){
		 	
}

void Animals::eat(Animals* p){
		 	
}

void Animals::set_inHibernation( int val){
	this->inHibernation=val;
}

int Animals::get_inHibernation()const{
	return this->inHibernation;
}

int Animals::get_hibernates()const{
	return this->hibernates;
}

 Animals::~Animals(){

}
