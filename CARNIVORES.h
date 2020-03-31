#ifndef CARNIVORES_H
#define CARNIVORES_H

#include "ANIMALS.h"

class Carnivores: public Animals{
protected:
	int attack;
	int defence;
	int neededFood;
public:
	Carnivores();
	int get_defence();
	
};
#endif
