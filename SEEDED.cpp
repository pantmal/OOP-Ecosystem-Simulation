#include <iostream>

#include "SEEDED.h"

using namespace std;

void Seeded::grow(){
	
	foliage=foliage+lifeFactor;
	seeds=seeds+2*lifeFactor;
	if (foliage>=lifeFactor){
		size++;
	}
	
}

void Seeded::loselife(int x){
	
	
	if (seeds-x>0){
		seeds=seeds-x;	
	}else{
		int y=seeds-x;
		seeds=0;
		foliage=foliage+y; //life == foliage for seeded plants (design choice)
		life=foliage;
		if (foliage<=0){
			life=0;
		}
	}
	
	
}

char Seeded::get_token(){
	return token;
}
 

