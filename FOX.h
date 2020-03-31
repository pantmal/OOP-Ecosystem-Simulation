#ifndef FOX_H
#define FOX_H
 
#include "CARNIVORES.h"
 
class Fox: public Carnivores{
private:
	
public:
	Fox(bool fAdult);
	~Fox();
	void move(int );
	void eat(Animals*);
	void raise();
	int get_speed()const;
	void set_name(std::string );
	std::string get_name()const;
	Animals* breed();
	int get_eaten_food()const;
	int get_needed_food()const;
	int get_eat_count()const;
};
#endif
