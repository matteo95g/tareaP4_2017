#ifndef DTCONVSIMPLE_H_
#define DTCONVSIMPLE_H_

#include "DtUsuario.h"
#include "DtConversacion.h"
#include <map>

class DtConvSimple : public DtConversacion {
	map<string,DtUsuario*> participantes;
public:
	DtConvSimple();
	DtConvSimple(int id);
	DtConvSimple(int id, map<string,DtUsuario*> participantes);

	map<string,DtUsuario*> getParticipantes();

	~DtConvSimple();
};


#endif /* DTCONVSIMPLE_H_ */