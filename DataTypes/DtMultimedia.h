#ifndef DTMULTIMEDIA_H_
#define DTMULTIMEDIA_H_

#include "DtMultimedia.h"
#include "DtMensaje.h"
#include "Fecha.h"



class DtMultimedia: public DtMensaje
{
public:
	DtMultimedia();
	DtMultimedia(int id, Fecha* fecha);
	virtual ~DtMultimedia() = 0;	
};

#endif