#include "../include/Contacto.h"

#include <string>

Contacto::Contacto(int id, Fecha* fecha, Usuario* emisor, string nombre, string numero) : Mensaje(id, fecha, emisor) {
	this->nombre = nombre;
	this->numero = numero;
}

string Contacto::getNombre() {
	return nombre;
}

void Contacto::setNombre(string nombre) {
	this->nombre = nombre;
}

string Contacto::getNumero() {
	return numero;
}

void Contacto::setNumero(string numero) {
	this->numero = numero;
}

Contacto::~Contacto(){}