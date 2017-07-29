#ifndef DTSIMPLE_H_
#define DTSIMPLE_H_

#include <string>
#include "DtMensaje.h"
#include "../DataTypes/Fecha.h"

using namespace std;

class DtSimple : public DtMensaje
{
	string texto;
public:
	DtSimple();
	DtSimple(int id, Fecha* fecha, string txt);
	
	string getTexto();
	void setTexto(string txt);

	~DtSimple();
};

#endif