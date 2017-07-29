#include "DtConversacion.h"

DtConversacion::DtConversacion(){}
DtConversacion::DtConversacion(int id){
	this->id = id;
}

int DtConversacion::getId(){
	return this->id;
}
void DtConversacion::setId(int id){
	this->id = id;
}

DtConversacion::~DtConversacion(){}