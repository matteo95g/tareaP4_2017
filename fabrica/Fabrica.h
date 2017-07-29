#ifndef FABRICA_H_
#define FABRICA_H_

#include "../controladores/ConvController.h"
#include "../controladores/UserController.h"
#include "../interfaces/IConversacion.h"
#include "../interfaces/IUsuario.h"
#include "../interfaces/Observer.h"

class Fabrica
{
	static Fabrica* instancia;
	Fabrica();
public:
	static Fabrica* getInstancia();
	IConversacion* getIConversacion();
	IUsuario* getIUsuario();

	//~Fabrica();
	
};


#endif