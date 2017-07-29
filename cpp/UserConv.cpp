#include "../include/UserConv.h"

UserConv::UserConv(int id, bool archivada, Fecha* fechaIngreso, Conversacion* conversacion) {
	this->id = id;
	this->archivada = archivada;
	this->fechaIngreso = fechaIngreso;
	this->conversacion = conversacion;
}

int UserConv::getId() const {
	return id;
}

void UserConv::setId(int id) {
	this->id = id;
}

bool UserConv::getArchivada() const {
	return archivada;
}

void UserConv::setArchivada(bool archivada) {
	this->archivada = archivada;
}

Fecha* UserConv::getFechaIngreso() const {
	return fechaIngreso;
}

void UserConv::setFechaIngreso(Fecha* fechaIngreso) {
	this->fechaIngreso = fechaIngreso;
}

Conversacion* UserConv::getConversacion() const {
	return conversacion;
}

void UserConv::setConversacion(Conversacion* conversacion) {
	this->conversacion = conversacion;
}