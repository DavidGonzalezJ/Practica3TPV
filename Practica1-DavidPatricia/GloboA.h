#ifndef H_GlobosA_H
#define H_GlobosA_H
#include <SDL.h>
#include "GlobosPG.h"
#include "checkML.h"
class GloboA: public GlobosPG
{
public:
	GloboA(int px, int py, JuegoPG* game);
	~GloboA();

	virtual void update();
};
#endif