#ifndef CONTACTO_H_
#define CONTACTO_H_

#include <string>

#include "Mensaje.h"

using namespace std;

class Contacto : public Mensaje
{
	string nombre;
	string numero;
public:
	Contacto();
	Contacto(int id, Fecha* fecha, Usuario* emisor, string nombre, string numero);

	string getNombre();
	void setNombre(string nombre);

	string getNumero();
	void setNumero(string numero);

	~Contacto();
};

#endif