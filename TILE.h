#ifndef TILE_H
#define TILE_H

#include <iostream>

#include "ANIMALS.h"
#include "PLANTS.h"
#include "TILE.h"
#include "ECOSYSTEM.h"

class Node;
class Animals;

class Tile{
	
	private:
		int x;
		int y;
		int tts;
		char token;
		char plant_token;
		Plants* pplant;
		Node* pnode;
	
	public:
		Tile();
		Animals* return_animal();
		void set_token(char);
		void set_plant_token(char);
		char get_token();
		char get_plant_token();
		void link_tile_plant(Plants* );
		void link_tile_animal(Animals* );
		void add_element(Animals*);
		void remove_element(Animals*);
		void print_list();
		Plants* get_plant();
		Animals* get_animal(std::string);
		Animals* get_animal(Animals*);
		Node* get_pnode(){
			return pnode;
		}
		void kill_element(Animals*);
		~Tile();
	
};

#endif
