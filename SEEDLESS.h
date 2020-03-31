#ifndef SEEDLESS_H
#define SEEDLESS_H

#include "PLANTS.h"

class Seedless: public Plants{
public:
	void loselife(int);
	char get_token();
	void grow();
	int get_size(){
	}
	
};

#endif
