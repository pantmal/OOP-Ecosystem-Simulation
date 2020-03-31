#ifndef ANIMALS_H
#define ANIMALS_H

#include "TILE.h"
#include "PLANTS.h"
class Tile;  

class Animals{
	
	protected:         //desing choice: every animal entity has access to the data members of Animals class, because they're protected 
		std::string name;
		int coordinatex;
		int coordinatey;
		int size;
		int hungerCount;
		int eatenFood;
		int eatCount;
		bool isAlive;
		bool isHungry;
		bool inHeat;
		int speed;
		bool hibernates;
		bool inHibernation;
		bool isAdult;
		char token;  //token refers to the token of herbivores/carnivore type
		char token2; //token2 refers to the token of each entity (i.e. Bear has B token)
		int hours_of_hunger;//hours of hunger will be explained in the eat() function
		bool has_moved; //hours of hunger will be explained in the move function
		
	public:
		bool just_bred; //will be explained in the salmon class
		Animals();
		virtual bool get_has_moved()const;
		bool get_is_alive()const;
		void inc_hunger_count(); //increases the hungercount data member
		int get_hunger_count()const;
		virtual void raise(); 
		void set_eaten_food(int);
		virtual int get_speed()const;
		virtual void set_name(std::string);
		virtual std::string get_name()const;
 	    int get_isAdult()const;
 		void set_coords(int x,int y);
 		virtual void move(int);
		virtual void move(int, Tile**);
		virtual Animals* breed();
		int get_coord_x()const;
		int get_coord_y()const;
		virtual int get_neededFood()const;
		virtual int get_eat_count()const;
		virtual int get_eaten_food()const;
		char get_token()const;
		char get_token2()const;
		int get_size()const;
		void set_life();
		virtual int get_defence()const;
		virtual void eat(Plants*);
		virtual void eat(Animals*);
		void set_inHibernation( int val);
		int get_inHibernation()const;
		int get_hibernates()const;
		virtual ~Animals();
};
#endif 
