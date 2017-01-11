#pragma once
#include <string>
//Podemos definir subclases para los errores de las distintas librerias :)
class Error
{
public:
	Error(std::string mensaje);
	~Error();
	const std::string mensaje();
private:
	std::string mensaje;
};

