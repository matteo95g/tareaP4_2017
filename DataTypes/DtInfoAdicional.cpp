#include "DtInfoAdicional.h"

DtInfoAdicional::DtInfoAdicional(){}
DtInfoAdicional::DtInfoAdicional(string numero, string nombre, Fecha* fecha){
	this->numero = numero;
	this->nombre = nombre;
	this->fecha = fecha;
}

string DtInfoAdicional::getNumero(){
	return this->numero;
}

string DtInfoAdicional::getNombre(){
	return this->nombre;
}

Fecha* DtInfoAdicional::getFecha(){
	return this->fecha;
}

DtInfoAdicional::~DtInfoAdicional(){}