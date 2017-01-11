//#pragma once
#ifndef H_Premio_H
#define H_Premio_H
#include "ObjetoPG.h"
#include "checkML.h"
class Premio: public ObjetoPG{
public:
	Premio(int px, int py, JuegoPG* game);
	~Premio();
	virtual void draw()const;
	virtual void update();
	virtual bool onClick();
	void reiniciarP();

private:
	bool visible;
	int contador;
};

#endif