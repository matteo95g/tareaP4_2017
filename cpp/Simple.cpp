#include "../include/Simple.h"

Simple::Simple(int id, Fecha* fecha, Usuario* emisor, string texto) : Mensaje(id, fecha, emisor) {
	this->texto = texto;
}

string Simple::getTexto() {
	return texto;
}

void Simple::setTexto(string texto) {
	this->texto = texto;
}

Simple::~Simple(){}