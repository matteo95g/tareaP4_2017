#ifndef DTMENSAJE_H_
#define DTMENSAJE_H_

using namespace std;

#include "DtInfoAdicional.h"
#include "DtVisto.h"
#include "DtUsuario.h"
#include "Fecha.h"
#include <map>
#include <string>

class DtMensaje
{
	int id;
	Fecha* fecha;
	map<string,DtVisto*> vistos;
	DtUsuario* emisor;

public:
	DtMensaje();
	DtMensaje(int id, Fecha *fecha);
	DtMensaje(int id, Fecha *fecha, map<string,DtVisto*> vistos, DtUsuario* emisor);
	
	int getId();
	
	Fecha* getFecha();
	
	bool getVisto();

	map<string,DtVisto*> getVistos();

	DtUsuario* getEmisor();

	virtual ~DtMensaje() = 0;
};


#endif