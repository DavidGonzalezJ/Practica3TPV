#pragma once
#include "EstadoJuego.h"
#include "JuegoPG.h"
#include <vector>

class EstadoPG: public EstadoJuego
{
public:
	EstadoPG(JuegoPG* juego);
	virtual ~EstadoPG();
	virtual void draw()const;
	virtual void onClick();
	virtual void update();

protected:
	JuegoPG* juego;
	std::vector<ObjetoJuego*> pObjetos;
};

