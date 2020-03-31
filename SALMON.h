#ifndef SALMON_H
#define SALMON_H

#include "HERBIVORES.h"

class Salmon: public Herbivores{
public:
	Salmon();
	~Salmon();
	void move(int, Tile**);
	void eat(Plants*);
	int get_speed()const;
	void set_name(std::string);
	std::string get_name()const;
	Animals* breed();
	int get_eaten_food()const;
	int get_needed_food()const;
	int get_eat_count()const;
};
#endif
