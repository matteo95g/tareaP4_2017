#include "DtContacto.h"

DtContacto::DtContacto(){}
DtContacto::DtContacto(int id, Fecha* fecha, string nombre, string numero): DtMensaje(id, fecha){
	this->nombre = nombre;
	this->numero = numero;
}

string DtContacto::getNombre(){
	return this->nombre;
}
void DtContacto::setNombre(string nombre){
	this->nombre = nombre;
}

string DtContacto::getNumero(){
	return this->numero;
}
void DtContacto::setNumero(string numero){
	this->numero = numero;
}

	
DtContacto::~DtContacto(){}