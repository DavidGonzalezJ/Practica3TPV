#pragma once
#include "ObjetoPG.h"
typedef void CallBack_t(JuegoPG* jg);
class Boton : public ObjetoPG
{
public:
	Boton(CallBack_t* callback);
	~Boton();
	CallBack_t * cb;
	
};

