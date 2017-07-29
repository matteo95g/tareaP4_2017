#include "../include/Mensaje.h"

Mensaje::Mensaje(int id, Fecha* fecha, Usuario* emisor) {
	this->id = id;
	this->fecha = fecha;
	this->emisor = emisor;
	map<string, Visto*> vistos;
}

int Mensaje::getId() {
	return id;
}

void Mensaje::setId(int id) {
	this->id = id;
}

Fecha* Mensaje::getFecha() {
	return fecha;
}

map<string, Visto*> Mensaje::getVistos() {
	return vistos;
}

void Mensaje::setVistos(map<string, Visto*> vistos) {
	this->vistos = vistos;
}

void Mensaje::agregarVisto(string nroUsr, Visto* visto) {
	vistos[nroUsr] = visto;
}

bool Mensaje::esEmisor(Usuario* usr) {
	return (usr->getNumero() == emisor->getNumero());
}

void Mensaje::eliminarMensaje() {
	fecha = NULL;
	emisor = NULL;
	map<string, Visto*>::iterator it = vistos.begin();
	while (it != vistos.end()) {
		delete (it->second);
		it++;
	}
}

Mensaje::~Mensaje(){}