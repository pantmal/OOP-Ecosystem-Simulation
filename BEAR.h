#ifndef BEAR_H
#define BEAR_H

#include "CARNIVORES.h"

class Bear: public Carnivores{
	
private:
	
public:
	Bear(bool fAdult);
	~Bear();
	void move(int);
	void eat(Animals*);
	void raise();
	int get_speed()const;
	void set_name(std::string);
	std::string get_name()const;
	Animals* breed();
	int get_eat_count()const;
	int get_eaten_food()const;
	int get_needed_food()const;
};
#endif
