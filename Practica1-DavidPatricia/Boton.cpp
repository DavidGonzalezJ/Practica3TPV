#include "Boton.h"


Boton::Boton(CallBack_t* callback, int py):cb(callback)
{
	textura = TBoton;
	rect->x = juego->getWindowWidth()/2;
	rect->y = py;
	juego->getTextura(textura)->daTamaño(rect->h, rect->w);
}


Boton::~Boton()
{
}

void Boton::draw()const {
	juego->getTextura(textura)->draw(juego->getRender(), rect, nullptr);
}

void Boton::update() {
	//Implementar si sobra tiempo
}

bool Boton::onClick() {
	int x, y;
	juego->getMousePos(x, y);
	if (dentro(x, y))
		cb;
	return true;/////NO
}