#pragma once
#include "EstadoPG.h"
#include "Boton.h"//hereda el boton en vez de una clase superior. Puede estar mal
class MenuPG : public EstadoPG
{
public:
	MenuPG();
	~MenuPG();
	Boton* play;
	Boton* exit;
	void playC();
	void exitC();
};

