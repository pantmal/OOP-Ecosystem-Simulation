#ifndef GRASS_H
#define GRASS_H

#include "SEEDLESS.h"

class Grass: public Seedless{
public:
	Grass();
	~Grass();
	char get_token();
	Plants* breed();
	int get_size();
};

#endif
