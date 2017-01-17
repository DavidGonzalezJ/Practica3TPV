#pragma once
#include "ObjetoPG.h"

class Boton : public ObjetoPG
{
public:
	typedef void CallBack_t(JuegoPG* jg);
	Boton(CallBack_t* callback);
	~Boton();

protected:
	CallBack_t * cb;
	
};

