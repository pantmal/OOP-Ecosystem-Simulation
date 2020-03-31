#ifndef WOLF_H
#define WOLF_H

#include "CARNIVORES.h"

class Wolf: public Carnivores{

private:
	
public:
	Wolf(bool fAdult);
	~Wolf();	
	void move(int);
	void eat(Animals*);
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
