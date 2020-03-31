#ifndef MAPLE_H
#define MAPLE_H

#include "SEEDED.h"

class Maple: public Seeded{
	
public:
	Maple();
	~Maple();
	char get_token();
	Plants* breed();
	int get_size();
	
};

#endif
