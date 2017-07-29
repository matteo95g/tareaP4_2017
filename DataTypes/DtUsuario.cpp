#include "DtUsuario.h"

DtUsuario::DtUsuario(){}
DtUsuario::DtUsuario(string nombre, string numero, string imagen, string descripcion){
	this->nombre = nombre;
	this->numero = numero;
	this->imagen = imagen;
	this->descripcion = descripcion;
}
DtUsuario::DtUsuario(string nombre, string numero, string imagen, string descripcion, Fecha* ult_vez, Fecha* fecha_reg){
	this->nombre = nombre;
	this->numero = numero;
	this->imagen = imagen;
	this->descripcion = descripcion;
	this->ult_vez = ult_vez;
	this->fecha_reg = fecha_reg;
}


string DtUsuario::getNombre(){
	return this->nombre;
}

string DtUsuario::getNumero(){
	return this->numero;
}

string DtUsuario::getDescripcion(){
	return this->descripcion;
}
	
string DtUsuario::getImagen(){
	return this->imagen;
}

Fecha* DtUsuario::getUlt_vez(){
	return this->ult_vez;
}

Fecha* DtUsuario::getFecha_reg(){
	return this->fecha_reg;
}

DtUsuario::~DtUsuario(){}