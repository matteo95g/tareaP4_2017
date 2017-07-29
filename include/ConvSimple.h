#ifndef CONVSIMPLE_H_
#define CONVSIMPLE_H_

#include <string>
#include <map>

#include "Conversacion.h"
#include "Usuario.h"


class ConvSimple : public Conversacion
{
	map<string,Usuario*> participantes;
public:
	ConvSimple();
	ConvSimple(int id, map<string,Usuario*> participantes);

	map<string, Usuario*> getParticipantes();
	void setParticipantes(map<string,Usuario*> participantes);

	~ConvSimple();
};


#endif /* CONVSIMPLE */