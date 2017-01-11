#include "ObjetoPG.h"

ObjetoPG::ObjetoPG()
{
	rect = new SDL_Rect;
}

ObjetoPG::~ObjetoPG()
{
	delete rect;
}

bool ObjetoPG::dentro(int x, int y)const {
	return y >= rect->y && y <= rect->y + rect->h &&  x >= rect->x && x <= rect->x + rect->w;
}