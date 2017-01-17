#pragma once
#include "EstadoPG.h"
#include "Boton.h"
class GameOver : public EstadoPG
{

public:
	GameOver();
	~GameOver();
	Boton* Score;
	Boton* Menu;
	void ScoreC();
	void MenucC();

};

