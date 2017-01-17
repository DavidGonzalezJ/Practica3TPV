#include "GlobosPG.h"


GlobosPG::GlobosPG(int px, int py, JuegoPG* game) 
{
	textura = TGlobo;
	juego = game;
	puntos = 10;
	if (rand() % 100 < PVIS) vis = true; else vis = false;
	expl = false;
	rect->x = px;
	rect->y = py;
	juego->getTextura(textura)->daTamaño(rect->h, rect->w);
}


GlobosPG::~GlobosPG()
{
}

void GlobosPG::draw() const {
	if (vis && !expl) {
		juego->getTextura(textura)->draw(juego->getRender(), rect, nullptr);
	}
}

//Devuelve true si el globo desaparece
bool GlobosPG::onClick(){
	bool desaparece = false;
	int x, y;
	juego->getMousePos(x, y);
	if (!expl && vis && dentro(x, y)) {
		expl = true;
		desaparece = true;
		vis = false;
		juego->newBaja(this);
		juego->newPuntos(this);
	}
	return desaparece;
}

//Devuelve true si el globo desaparece
void GlobosPG::update(){
	bool desaparece = false;
	if (vis && !expl){
		//Aquí se genera un aleatorio para ver si el globo se deshincha o no
		if (rand() % 100 < PDES) {
			rect->h -= DT;
			rect->w -= DT;
			puntos += AP;
			if (rect->h <= 10| rect->w <= 10) {
				vis = false;
				desaparece = true;
				expl = true;
				juego->newBaja(this);
			}
		}
	}
	if (!expl)
		//Generamos un aleatorio nueva para ver si un globo invisible se vuelve visible
		if (rand() % 100 < PVIS) vis = true; else vis = false;
}