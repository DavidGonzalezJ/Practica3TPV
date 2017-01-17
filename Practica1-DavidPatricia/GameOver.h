#pragma once
#include "EstadoPG.h"
#include "Boton.h"
class GameOver : public EstadoPG
{

public:
	GameOver(JuegoPG* juego);
	~GameOver();
	Boton* Score;
	Boton* Menu;
	static void ScoreC(JuegoPG* juego);
	static void MenuC(JuegoPG* juego);

};

