#include "DtSimple.h"

DtSimple::DtSimple(){}
DtSimple::DtSimple(int id, Fecha* fecha, string txt): DtMensaje(id, fecha){
	this->texto = txt;
}
	
string DtSimple::getTexto(){
	return this->texto;
}

void DtSimple::setTexto(string txt){
	this-> texto = txt;
}

DtSimple::~DtSimple(){}