#include "DtGrupo.h"

DtGrupo::DtGrupo(){}
DtGrupo::DtGrupo(int id, string nombre): DtConversacion(id){
	this->nombre = nombre;
}

string DtGrupo::getNombre(){
	return this->nombre;
}

DtGrupo::~DtGrupo(){}