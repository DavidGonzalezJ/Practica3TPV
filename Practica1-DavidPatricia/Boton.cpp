#include "Boton.h"


Boton::Boton(CallBack_t* callback):cb(callback)
{
	textura = TBoton;
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
}