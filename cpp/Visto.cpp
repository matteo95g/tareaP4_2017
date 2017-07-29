#include "../include/Visto.h"

Visto::Visto(bool visto, Usuario* usr) {
	this->visto = visto;
	this->usuario = usr;
	this->borrado = false;
}

bool Visto::getVisto() {
	return visto;
}

void Visto::setVisto(bool visto) {
	this->visto = visto;
}

Fecha* Visto::getFecha() {
	return fecha;
}

void Visto::setFecha(Fecha* fecha) {
	this->fecha = fecha;
}

Usuario* Visto::getUsuario() {
	return usuario;
}

void Visto::setUsuario(Usuario* usr) {
	this->usuario = usr;
}

bool Visto::getBorrado(){
	return this->borrado;
}
	
void Visto::setBorrado(bool borrar){
	this->borrado = borrar;
}

Visto::~Visto(){}