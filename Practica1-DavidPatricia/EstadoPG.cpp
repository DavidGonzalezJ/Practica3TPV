#include "EstadoPG.h"


EstadoPG::EstadoPG(JuegoPG* juego):juego(juego)
{
}


EstadoPG::~EstadoPG()
{
}

void EstadoPG::draw()const {
	SDL_Renderer* pRender = juego->getRender();
	SDL_RenderClear(pRender);
	juego->getTextura(TFondo)->draw(pRender, nullptr, nullptr);
	//pTexturaG[TFondo]->draw(pRender, *fRect, nullptr);

	for each (ObjetoJuego* g in pObjetos)
	{
		g->draw();
	}
	SDL_RenderPresent(pRender);

}

void EstadoPG::onClick() {
	bool click = false;
	int i = 0;
	while (!click && i<pObjetos.size()) {
		if (pObjetos[i]->onClick()) {
			click = true;
		}
		i++;
	}
}

void EstadoPG::update() {
	for each (ObjetoJuego* g in pObjetos)
	{
		g->update();
	}
}