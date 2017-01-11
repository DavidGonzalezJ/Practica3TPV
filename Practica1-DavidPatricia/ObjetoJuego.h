#ifndef H_ObjetoJuego_H
#define H_ObjetoJuego_H
#include "checkML.h"
class ObjetoJuego
{

public:

	ObjetoJuego()
	{
	}

	virtual ~ObjetoJuego()
	{
	}

	virtual void draw()const = 0;
	virtual void update() = 0;
	virtual bool onClick() = 0;
};
#endif