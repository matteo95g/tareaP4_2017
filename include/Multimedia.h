#ifndef MULTIMEDIA_H_
#define MULTIMEDIA_H_

#include <string>
#include "Mensaje.h"

using namespace std;

class Multimedia : public Mensaje
{
public:
	Multimedia();
	Multimedia(int id, Fecha* fecha, Usuario* emisor);
	virtual ~Multimedia() = 0;
	
};

#endif