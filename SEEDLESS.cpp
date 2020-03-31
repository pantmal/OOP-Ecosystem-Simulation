#include <iostream>

#include "SEEDLESS.h"

using namespace std;

void Seedless::grow(){
	
	life=life+lifeFactor;
}

void Seedless::loselife(int x){
	life=life-x;
	if (life <= 0){
		life=0;
	}
}

char Seedless::get_token(){
	return token;
}

