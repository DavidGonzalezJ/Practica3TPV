#include "Premio.h"



Premio::Premio(int px, int py, JuegoPG* game)
{
	textura = TPremio;
	visible = false;
	juego = game;
	puntos = 300;
	contador = 3;
	rect->x = px;
	rect->y = py;
	juego->getTextura(textura)->daTamaño(rect->h, rect->w);
}


Premio::~Premio()
{
}

void Premio::draw()const {
	if(visible)
		juego->getTextura(textura)->draw(juego->getRender(), rect, nullptr);
}

void Premio::update() {
	if (visible && contador > 0) {
		contador--;
		puntos -= 100;
	}else visible = false;
}

bool Premio::onClick() {
	bool premio = false;
	int x, y;
	juego->getMousePos(x, y);
	if (visible && dentro(x, y)) {
		visible = false;
		premio = true;
		juego->newBaja(this);
		juego->newPuntos(this);
	}
	return premio;
}

void Premio::reiniciarP() {
	visible = true;
	contador = 3;
	puntos = 300;

}