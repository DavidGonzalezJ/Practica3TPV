#include "MenuPG.h"
#include "PlayPG.h"

MenuPG::MenuPG(JuegoPG* juego):EstadoPG(juego)
{
	play = new Boton(playC, 50);
	exit = new Boton(exitC, 80);
	pObjetos.emplace_back(play);
	pObjetos.emplace_back(exit);
}


MenuPG::~MenuPG()
{
	delete play;
	delete exit;
}

void MenuPG::playC(JuegoPG* juego) {
	juego->changeState(new PlayPG(juego));
}

void MenuPG::exitC(JuegoPG* juego) {
	juego->onExit();
}