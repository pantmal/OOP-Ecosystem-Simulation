#ifndef OAK_H
#define OAK_H

#include "SEEDED.h"

class Oak: public Seeded{
public:
	Oak();
	~Oak();
	char get_token();
	Plants* breed();
	int get_size();
};

#endif
