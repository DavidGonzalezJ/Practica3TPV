#pragma once
#include "EstadoPG.h"
#include "Boton.h"
class Pausa : public EstadoPG
{
public:
	Pausa();
	~Pausa();
	Boton* Resume;
	Boton* Menu;
	void ResumeC();
	void MenucC();
};

