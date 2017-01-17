#pragma once
class EstadoJuego
{
public:

	EstadoJuego()
	{
	}

	virtual ~EstadoJuego()
	{
	}

	virtual void draw()const = 0;
	virtual void onClick() = 0;
	virtual void update() = 0;
};

