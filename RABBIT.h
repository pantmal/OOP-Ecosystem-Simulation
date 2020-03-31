#ifndef RABBIT_H
#define RABBIT_H

#include "HERBIVORES.h"

class Rabbit: public Herbivores{

private:
	
public:
	Rabbit(bool fAdult);
	~Rabbit();
	void move(int, Tile**);
	void eat(Plants*);
	void raise();
	int get_speed()const;
	void set_name(std::string );
	std::string get_name()const;
	Animals* breed();
	int get_eat_count()const;
	int get_eaten_food()const;
	int get_needed_food()const;
};
#endif 
