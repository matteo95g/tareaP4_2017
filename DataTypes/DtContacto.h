#ifndef DTCONTACTO_H_
#define DTCONTACTO_H_

#include <string>
#include "../DataTypes/Fecha.h"
#include "DtMensaje.h"

using namespace std;

class DtContacto: public DtMensaje {
	string nombre;
	string numero;
public:

	DtContacto();
	DtContacto(int id, Fecha* fecha, string nombre, string numero);

	string getNombre();
	void setNombre(string nombre);

	string getNumero();
	void setNumero(string numero);
	
	~DtContacto();
	
};

#endif