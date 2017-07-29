#include "Fabrica.h"
#include "../controladores/UserController.h"
#include "../controladores/ConvController.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
	if (instancia == NULL)
		instancia = new Fabrica();
	return instancia;
}

IConversacion* Fabrica::getIConversacion(){
	return ConvController::getInstancia();
}

IUsuario* Fabrica::getIUsuario(){
	return UserController::getInstancia();
}