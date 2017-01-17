#include "GameOver.h"
#include "MenuPG.h"

GameOver::GameOver(JuegoPG* juego):EstadoPG(juego)
{
	Score = new Boton(ScoreC, 50);
	Menu = new Boton(MenuC, 80);
	pObjetos.emplace_back(Score);
	pObjetos.emplace_back(Menu);
}


GameOver::~GameOver()
{
	delete Score;
	delete Menu;
}

void GameOver::ScoreC(JuegoPG* juego) {
	int puntos = juego->getPuntos();
	juego->muestraMensaje("Puntuación: " + puntos, "CONGRATS!");

}

void GameOver::MenuC(JuegoPG* juego) {
	juego->changeState(new MenuPG(juego));
}