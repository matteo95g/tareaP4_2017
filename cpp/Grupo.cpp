#include "../include/Grupo.h"

Grupo::Grupo(int id, string nombre, string imagen, Fecha* fecha): Conversacion(id){
	this->nombre = nombre;
	this->imagen = imagen;
	this->fecha = fecha;
}

string Grupo::getNombre() const {
	return nombre;
}

void Grupo::setNombre(string nombre) {
	this->nombre = nombre;
}

string Grupo::getImagen() const {
	return imagen;
}

void Grupo::setImagen(string imagen) {
	this->imagen = imagen;
}

Fecha* Grupo::getFecha() const {
	return fecha;
}

void Grupo::setFecha(Fecha* fecha) {
	this->fecha = fecha;
}

map<string, Usuario*> Grupo::getParticipantes() const {
	return participantes;
}

void Grupo::setParticipantes(map<string, Usuario*> participantes) {
	this->participantes = participantes;
}

map<string, Usuario*> Grupo::getAdministradores() const {
	return administradores;
}

void Grupo::setAdministradores(map<string, Usuario*> administradores) {
	this->administradores = administradores;
}

Grupo::~Grupo(){}