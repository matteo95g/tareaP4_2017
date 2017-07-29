
#include "../include/Conversacion.h"

Conversacion::Conversacion(int id) {
	this->id = id;
	map<int, Mensaje*> mensajes;
}

int Conversacion::getId() {
	return id;
}

void Conversacion::setId(int id) {
	this->id = id;
}

map<int, Mensaje*> Conversacion::getMensajes() {
	return mensajes;
}

void Conversacion::setMensajes(map<int, Mensaje*> mensajes) {
	this->mensajes = mensajes;
}

void Conversacion::agregarMensaje(Mensaje* msj) {
	mensajes[msj->getId()] = msj;
}

void Conversacion::eliminarMensaje(int idMsj) {
	mensajes[idMsj]->eliminarMensaje();
	mensajes.erase(idMsj);
}

Conversacion::~Conversacion(){}