#ifndef DTCONVSARCHIVADAS_H_
#define DTCONVSARCHIVADAS_H_

#include "DtConversacion.h"

class DtConvsArchivadas : public DtConversacion {
	int cantidad;
public:
	DtConvsArchivadas();
	DtConvsArchivadas(int cantidad);

	int getCantidad();

	~DtConvsArchivadas();
};


#endif /* DTCONVSARCHIVADAS_H_ */