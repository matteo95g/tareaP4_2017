#ifndef DTGRUPO_H_
#define DTGRUPO_H_

#include "DtConversacion.h"
#include <string>

using namespace std;

class DtGrupo : public DtConversacion {
	string nombre;
public:
	DtGrupo();
	DtGrupo(int id, string nombre);

	string getNombre();

	~DtGrupo();
};

#endif /* DTGRUPO_H_ */