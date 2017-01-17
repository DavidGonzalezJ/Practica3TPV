#pragma once
#include <string>
//Podemos definir subclases para los errores de las distintas librerias :)
class Error
{
public:
	Error(std::string mensaje);
	~Error();
	std::string showMensaje() const;
private:
	std::string mensaje;
};

