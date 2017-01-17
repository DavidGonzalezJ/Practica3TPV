#pragma once
#include "EstadoPG.h"
#include "Boton.h"//hereda el boton en vez de una clase superior. Puede estar mal
class MenuPG : public EstadoPG
{
public:
	MenuPG(JuegoPG* juego);
	~MenuPG();
	Boton* play;
	Boton* exit;
	static void playC(JuegoPG* juego);
	static void exitC(JuegoPG* juego);
};

