#include "DtConvSimple.h"

DtConvSimple::DtConvSimple(){}
DtConvSimple::DtConvSimple(int id): DtConversacion(id){}
DtConvSimple::DtConvSimple(int id, map<string,DtUsuario*> participantes): DtConversacion(id){
	this->participantes = participantes;
}

map<string,DtUsuario*> DtConvSimple::getParticipantes(){
	return this->participantes;
}

DtConvSimple::~DtConvSimple(){}