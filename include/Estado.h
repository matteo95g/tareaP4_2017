#ifndef ESTADO_H_
#define ESTADO_H_

#include <string>
#include "../DataTypes/Fecha.h"

using namespace std;

class Estado
{
	string texto;
	Fecha *fecha;
public:
	Estado();
	Estado(string texto);

	string getTexto() const;
	void setTexto(string texto);

	Fecha* getFecha() const;

	~Estado();

};

#endif /* ESTADO_H_ */