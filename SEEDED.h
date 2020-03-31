#ifndef SEEDED_H
#define SEEDED_H

#include "PLANTS.h"

class Seeded: public Plants{
protected:
	int foliage;
	int seeds;
public:
	void loselife(int);
	char get_token();
	void grow();
	int get_size(){
	}
};

#endif
