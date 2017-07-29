#ifndef DTNOTIFICACION_H_
#define DTNOTIFICACION_H_

#include <string>
#include "Fecha.h"
#include "Cambios.h"

class DtNotificacion
{
	string nro;
	Fecha *fecha;
	Cambios cambio;
public:
  	DtNotificacion();
	DtNotificacion(string nro, Cambios cambio, Fecha* fecha);

	string getNumero();
	void setNumero(string nro);

	Fecha* getFecha();

	Cambios getCambio();
	void setCambio(Cambios cambio);

   ~DtNotificacion();
   
};

#endif