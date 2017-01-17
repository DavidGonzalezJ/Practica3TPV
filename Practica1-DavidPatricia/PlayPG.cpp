#include "PlayPG.h"


PlayPG::PlayPG(JuegoPG* juego):EstadoPG(juego)
{
}


PlayPG::~PlayPG()
{
}

void PlayPG::newBaja(ObjetoJuego* po) {
	if (typeid(*po) == typeid(GlobosPG) || typeid(*po) == typeid(GloboA)) {
		--numGlobos;
	}
	else if (typeid(*po) == typeid(Premio)) {
		sonido->playEffect();
	}
}

void PlayPG::newPuntos(ObjetoJuego* po) {
	sonido->playEffect();
	puntuacion += dynamic_cast<ObjetoPG*>(po)->puntos;
}

void PlayPG::newPremio(ObjetoJuego* po) {
	pObjetos.emplace_back(new Premio(rand() % 720, rand() % 480, this));
	dynamic_cast<Premio*>(pObjetos[pObjetos.size() - 1])->reiniciarP();
}

bool PlayPG::initGlobos() {
	bool success = true;
	//Creo un int que me servirá para almacenar el aleatorio
	int r;

	for (int n = 0; n < numGlobos; ++n) {
		//Aquí lanzo la moneda y creo uno de los dos globos
		r = rand() % 2;
		if (r == 1)
			pObjetos.emplace_back(new GlobosPG(rand() % 720, rand() % 480, this));
		else
			pObjetos.emplace_back(new GloboA(rand() % 720, rand() % 480, this));
	}
	pObjetos.emplace_back(new Mariposa(rand() % 720, rand() % 480, this));
	pObjetos.emplace_back(new Mariposa(rand() % 720, rand() % 480, this));
	//pObjetos.emplace_back(new Premio(rand() % 720, rand() % 480, this));
	return success;
}

void PlayPG::freeGlobos() {
	for (int n = 0; n < pObjetos.size(); ++n) {
		delete pObjetos[n];
		pObjetos[n] = nullptr;
	}
}

bool PlayPG::gameOver() {
	return numGlobos <= 0;
}

void PlayPG::draw()const {
	SDL_RenderClear(pRender);
	pTexturaG[TFondo]->draw(pRender, *fRect, nullptr);

	for each (ObjetoJuego* g in pObjetos)
	{
		g->draw();
	}
	std::string puntos = std::to_string(puntuacion);
	pTexturaG[pTexturaG.size() - 1]->renderText(pRender, puntos);
	SDL_RenderPresent(pRender);
}

void PlayPG::update() {
	for each (ObjetoJuego* g in pObjetos)
	{
		g->update();
	}
}

void PlayPG::onClick(){
	bool click = false;
	int i = 0;
	while (!click && i<pObjetos.size()){
		if (pObjetos[i]->onClick()) {
		click = true;
		}
	i++;
	}
}