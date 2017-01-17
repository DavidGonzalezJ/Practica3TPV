#ifndef H_ObjetoPG_H
#define H_ObjetoPG_H
#include "ObjetoJuego.h"
#include "JuegoPG.h"
#include "checkML.h"

class ObjetoPG : public ObjetoJuego{
public:
	ObjetoPG();
	virtual ~ObjetoPG();
	virtual bool dentro(int x, int y)const;
	int puntos;

protected:
	Texturas_t textura;
	JuegoPG* juego;
	SDL_Rect* rect;
};

#endif