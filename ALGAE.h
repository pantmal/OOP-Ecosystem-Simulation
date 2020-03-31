#ifndef ALGAE_H
#define ALGAE_H

#include "SEEDLESS.h"

class Algae: public Seedless{
public:
	Algae();
	~Algae();
	char get_token();
	Plants* breed();
	int get_size();
};

#endif
