#ifndef SIMPLE_H_
#define SIMPLE_H_

#include <string>

#include "Mensaje.h"

using namespace std;

class Simple : public Mensaje
{
	string texto;
public:
	Simple();
	Simple(int id, Fecha* fecha, Usuario* emisor, string texto);

	string getTexto();
	void setTexto(string texto);

	~Simple();
};

#endif