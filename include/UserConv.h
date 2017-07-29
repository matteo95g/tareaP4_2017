#ifndef USERCONV_H_
#define USERCONV_H_

#include <string>
#include <list>

#include "../DataTypes/Fecha.h"

#include "Conversacion.h"
#include "Mensaje.h"
#include "Visto.h"

class Usuario;

using namespace std;


class UserConv
{
	int id;
	bool archivada;
	Fecha *fechaIngreso;
	Conversacion* conversacion;

public:
	UserConv();
	UserConv(int id, bool archivada, Fecha* fechaIngreso, Conversacion* conversacion);

	int getId() const;
	void setId(int id);

	bool getArchivada() const;
	void setArchivada(bool archivada);

	Fecha* getFechaIngreso() const;
	void setFechaIngreso(Fecha* fechaIngreso);

	Conversacion* getConversacion() const;
	void setConversacion(Conversacion* conversacion);

	~UserConv();
};


#include "Usuario.h"

#endif