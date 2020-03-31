#ifndef PLANTS_H
#define PLANTS_H


class Plants{
	
protected:
	int size;
	std::string name;
	int coordinatex;
	int coordinatey;
	char token;
	double breedingProb;
	double illnessProb;
	int life;
	int lifeFactor;	
	
public:
	Plants();
	virtual int get_size();
	virtual void loselife(int);
	virtual char get_token();
	void set_coords(int, int);
	virtual bool is_alive();
	virtual Plants* breed();
	virtual void grow();
	void set_life(int);
	int get_life();
	int get_illness_prob()const;
	int get_breeding_prob()const;
	int get_life_factor()const;
	int get_coordinatex()const;
	int get_coordinatey()const;
	virtual ~Plants();
};

#endif
