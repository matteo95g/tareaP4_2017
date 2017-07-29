#include "DtVisto.h"

DtVisto::DtVisto(){}
DtVisto::DtVisto(Fecha* fecha, bool visto){
	this->fecha = fecha;
	this->visto = visto;
}

Fecha* DtVisto::getFecha(){
	return this->fecha;
}
   
bool DtVisto::getVisto(){
	return this->visto;
}

DtVisto::~DtVisto(){}
