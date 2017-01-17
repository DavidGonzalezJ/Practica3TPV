#pragma once
#include "EstadoPG.h"
#include "Boton.h"
class Pausa : public EstadoPG
{
public:
	Pausa(JuegoPG* juego);
	~Pausa();
	Boton* Resume;
	Boton* Menu;
	static void ResumeC(JuegoPG* juego);
	static void MenuC(JuegoPG* juego);
};

