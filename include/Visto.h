#ifndef VISTO_H_
#define VISTO_H_

#include <string>
#include <list>

#include "../DataTypes/Fecha.h"

using namespace std;

class Usuario;
class UserConv;
class Conversacion;
class Mensaje;

class Visto
{
	bool visto;
	Fecha* fecha;
	Usuario* usuario;
	bool borrado;
public:
	Visto();
	Visto(bool visto, Usuario* usr);

	bool getVisto();
	void setVisto(bool visto);

	Fecha* getFecha();
	void setFecha(Fecha* fecha);

	Usuario* getUsuario();
	void setUsuario(Usuario* usr);

	bool getBorrado();
	void setBorrado(bool borrar);

	~Visto();
};

#include "Usuario.h"
#include "UserConv.h"
#include "Conversacion.h"
#include "Mensaje.h"

#endif