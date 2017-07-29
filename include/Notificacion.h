#ifndef NOTIFICACION_H_
#define NOTIFICACION_H_

#include <string>
#include "../DataTypes/Fecha.h"
#include "../DataTypes/Cambios.h"

using namespace std;

class Notificacion
{
	string nro;
	Fecha *fecha;
	Cambios cambio;
public:
	Notificacion();
	Notificacion(string nro, Cambios cambio, Fecha* fecha);

	string getNumero();
	void setNumero(string nro);

	Fecha* getFecha();

	Cambios getCambio();
	void setCambio(Cambios cambio);

	~Notificacion();

};


#endif