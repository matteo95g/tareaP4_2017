#ifndef CONVERSACION_H_
#define CONVERSACION_H_

#include <string>
#include <map>

#include "Mensaje.h"
#include "Visto.h"

using namespace std;

class Usuario;
class UserConv;

class Conversacion
{
	int id;
	map<int,Mensaje*> mensajes;

public:
	Conversacion();
	Conversacion(int id);

	virtual int getId();
	virtual void setId(int id);

	virtual map<int,Mensaje*> getMensajes();
	virtual void setMensajes(map<int,Mensaje*> mensajes);
	
	virtual void agregarMensaje(Mensaje* msj);
	virtual void eliminarMensaje(int idMsj);

	virtual ~Conversacion() = 0;
	
};

#include "Usuario.h"
#include "UserConv.h"

#endif