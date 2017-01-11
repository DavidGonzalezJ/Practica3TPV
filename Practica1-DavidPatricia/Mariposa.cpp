#include "Mariposa.h"


Mariposa::Mariposa(int px, int py, JuegoPG* game)
{
	puntos = 0;
	textura = TMariposa;
	RFrame = new SDL_Rect;
	RFrame->w = 63;
	RFrame->h = 58;
	RFrame->x = 0;
	RFrame->y = 0;
	contador = 3;
	juego = game;
	rect->x = px;
	rect->y = py;
	rect->w = 63;
	rect->h = 58;
	posIniX = px;
	posIniY = py;
}


Mariposa::~Mariposa()
{
	delete RFrame;
}

void Mariposa::draw()const {
	juego->getTextura(textura)->draw(juego->getRender(), *rect, RFrame);
}

void Mariposa::update() {
	rect->x -= 10;
	rect->y -= 10;
	if (rect->x <= 0 || rect->y <= 0) {
		rect->x = posIniX;
		rect->y = posIniY;
	}
	RFrame->x = (RFrame->x + RFrame->w) % anchoIMG;
}

bool Mariposa::onClick() {
	int x, y;
	bool premio = false;
	juego->getMousePos(x, y);
	if (dentro(x, y)) {
		contador--;
		rect->x = rand() % 670;
		rect->y = rand() % 420;
		posIniX = rect->x;
		posIniY = rect->y;
	}
	if (contador == 0) {
		premio = true;
		contador = 3;
		juego->newPremio(this);
	}
	return premio;
}