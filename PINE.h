#ifndef PINE_H
#define PINE_H

#include "SEEDED.h"

class Pine: public Seeded{
public:
	Pine();
	~Pine();
	char get_token();	
	Plants* breed();
	int get_size();
};

#endif
