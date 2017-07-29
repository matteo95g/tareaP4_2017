#ifndef MENSAJE_H_
#define MENSAJE_H_

#include <string>
#include <map>

#include "../DataTypes/DtInfoAdicional.h"
#include "../DataTypes/Fecha.h"

#include "Usuario.h"
#include "Visto.h"

using namespace std;

class Usuario;
class UserConv;
class Conversacion;

class Mensaje
{
	int id;
	Fecha* fecha;
	map<string,Visto*> vistos;
	Usuario* emisor;

public:
	Mensaje();
	Mensaje(int id, Fecha* fecha, Usuario* emisor);

	int getId();
	void setId(int id);	

	Fecha* getFecha();

	map<string, Visto*> getVistos();
	void setVistos(map<string, Visto*> vistos);
	void agregarVisto(string nroUsr, Visto* visto);

	list<DtInfoAdicional*> getInfoReceptoresVistos();

	bool esEmisor(Usuario* usr);
	
	void eliminarMensaje();

	virtual ~Mensaje() = 0;
};

#include "Usuario.h"
#include "UserConv.h"
#include "Conversacion.h"



#endif