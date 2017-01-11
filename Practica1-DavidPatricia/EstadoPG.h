#pragma once
#include "EstadoJuego.h"
#include "JuegoPG.h"
#include <vector>

class EstadoPG: public EstadoJuego
{
public:
	EstadoPG();
	virtual ~EstadoPG();

protected:
	JuegoPG* juego;
	std::vector<ObjetoJuego*> objetosJuego;
};

