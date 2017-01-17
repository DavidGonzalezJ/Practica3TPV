#pragma once
#include "EstadoPG.h"
class PlayPG: public EstadoPG
{
public:
	PlayPG(JuegoPG* juego);
	~PlayPG();
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po);
	void newPremio(ObjetoJuego* po);
	virtual void draw() const;
	virtual void onClick();///
	virtual void update();

private:
	int numGlobos = 6;
	int puntuacion;
	bool gameOver();
	bool initGlobos();///
	void freeGlobos();///
};

