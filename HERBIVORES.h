#ifndef HERBIVORES_H
#define HERBIVORES_H

#include "ANIMALS.h"

class Herbivores: public Animals{

protected:	
	bool canClimb;
	int neededFood;
	
public:
		Herbivores();

};
#endif
