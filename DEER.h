#ifndef DEER_H
#define DEER_H
 
#include "HERBIVORES.h"
 
class Deer: public Herbivores{
	
private:
	
public:
	Deer(bool fAdult);
	~Deer();
	void move(int);
	void eat(Plants*);
	void raise();
	int get_speed()const;
	void set_name(std::string );
	std::string get_name()const;
	Animals* breed();
	int get_needed_food()const;
	int get_eat_count()const;
	int get_eaten_food()const;
};
#endif
