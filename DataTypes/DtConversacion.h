#ifndef DTCONVERSACION_H_
#define DTCONVERSACION_H_

#include "DtMensaje.h"
#include <list>
#include <string>

class DtConversacion
{
	int id;
public:
	DtConversacion();
	DtConversacion(int id);

	int getId();
	void setId(int id);

	virtual ~DtConversacion() = 0;
};


#endif /* DTCONVERSACION_H_ */