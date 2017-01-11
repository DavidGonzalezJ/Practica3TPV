#ifndef H_Mariposa_H
#define H_Mariposa_H
#include "ObjetoPG.h"
#include "checkML.h"

class Mariposa: public ObjetoPG{

public:
	Mariposa(int px, int py, JuegoPG* game);
	~Mariposa();
	virtual void draw()const;
	virtual void update();
	virtual bool onClick();
private:
	int contador;
	int posIniX, posIniY;
	int anchoIMG = 441;
	SDL_Rect* RFrame;
};

#endif