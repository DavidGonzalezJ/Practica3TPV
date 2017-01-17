#include "MenuPG.h"
#include "PlayPG.h"

MenuPG::MenuPG(JuegoPG* juego):EstadoPG(juego)
{
	play = new Boton(playC);

	pObjetos.emplace_back(play);
	pObjetos.emplace_back(exit);
}


MenuPG::~MenuPG()
{
}

void MenuPG::playC() {
	juego->changeState(new PlayPG(juego));

}

void MenuPG::exitC() {


}