#ifndef GROUNDHOG_H
#define GROUNDHOG_H

#include "HERBIVORES.h"

class Groundhog: public Herbivores{
private:
	
public:	
	Groundhog(bool fAdult);
	~Groundhog();
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
