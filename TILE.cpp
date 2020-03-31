#include <iostream>

#include "TILE.h"

extern int TerrainSize;

using namespace std;

Tile::Tile(){
	
	static int temp1=0;
	static int temp2=0;
	x=temp1;
	y=temp2;

	temp2++;
	if(temp2==TerrainSize){
		temp2=0;
		temp1++;
	}
	
	pnode=NULL;
	pplant=NULL;
	token='!';    //desing choice: ! is the default token used by tiles
	plant_token='!'; 
}

Tile::~Tile(){
	Node* temp=pnode;
	Node* temp2=pnode;
	
	while(temp!=NULL){
		temp2=temp;
		delete temp2->panimal;
		temp=temp2->pnext;
		delete temp2;
		
	}
	
	if(pplant!=NULL){
		delete pplant;
	}
	
}

Plants* Tile::get_plant(){
	return pplant;
}

Animals* Tile::return_animal(){

	return pnode->panimal;
}

Animals* Tile::get_animal(string onoma){
	Node* temp=pnode;
	Node* temp2=NULL;
	bool found = false;	
	return temp->panimal;	
	
}

Animals* Tile::get_animal(Animals* tempanimal){

	Node* temp=pnode;
	while(temp!=NULL && temp->panimal!=tempanimal){
		temp=temp->pnext;
	}
	if(temp==NULL){
		return NULL;
	}
	else{
		return temp->panimal;
	}
}

void Tile::set_token(char t1){
	this->token=t1;
}

void Tile::set_plant_token(char t1){
	this->plant_token=t1;
}

char Tile::get_token(){
	return token;
}

char Tile::get_plant_token(){
	return plant_token;
}

void Tile::link_tile_plant( Plants* p1 ){ 
	pplant=p1;
	
}

void Tile::add_element(Animals* anim){
	
	if(pnode==NULL){
		pnode=new Node();
		pnode->panimal=anim;
		pnode->pnext=NULL;
	
	}else{
		
		Node* temp= pnode;
		while(temp->pnext != NULL){
			temp = temp->pnext;
		}
		Node* new_node=new Node();
		new_node->panimal=anim;
		new_node->pnext=NULL;
		temp->pnext=new_node;
		
	}
}

void Tile::remove_element(Animals* anim){ //remove element is used during animal movement to remove an animal from its previous tile

	Node* temp=pnode;
	Node* prev=NULL;
	
	while(temp->pnext!=NULL && temp->panimal->get_name()!=anim->get_name()){
		prev=temp;
		temp=temp->pnext;
	}
	
	if(temp->panimal->get_name() == anim->get_name()){
		
		if(prev==NULL){
			Node* tnext=temp->pnext;
			
			pnode=tnext;
		}else{
			Node* tnext=temp->pnext;
			
			prev->pnext=tnext;
			
		}
		
	}
	
}

void Tile::kill_element(Animals* anim){ //kill element behaves similarly, but it also deletes the animal it removes

	Node* temp=pnode;
	Node* prev=NULL;
	
	while(temp->pnext!=NULL && temp->panimal->get_name()!=anim->get_name()){
		prev=temp;
		temp=temp->pnext;
	}

	
	if(temp->panimal->get_name() == anim->get_name()){
	
		if(prev==NULL){
			Node* tnext=temp->pnext;
			delete temp->panimal;
			delete temp;
			pnode=tnext;
		}else{
			Node* tnext=temp->pnext;
			delete temp->panimal;
			delete temp;
			prev->pnext=tnext;
			
		}
		
	}
	
}


