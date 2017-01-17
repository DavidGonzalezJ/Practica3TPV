#include "Pausa.h"
#include "MenuPG.h"

Pausa::Pausa(JuegoPG* juego):EstadoPG(juego)
{
	Resume = new Boton(ResumeC, 50);
	Menu = new Boton(MenuC, 80);
	pObjetos.emplace_back(Resume);
	pObjetos.emplace_back(Menu);
}


Pausa::~Pausa()
{
	delete Resume;
	delete Menu;
}

void Pausa::ResumeC(JuegoPG* juego) {
	juego->popState();
}

void Pausa::MenuC(JuegoPG* juego) {
	juego->changeState(new MenuPG(juego));
}