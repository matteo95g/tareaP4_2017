#include "../include/Foto.h"

#include <string>

Foto::Foto(int id, Fecha* fecha, Usuario* emisor, string imagen, string formato, string tamanio, string texto) : Multimedia(id, fecha, emisor) {
	this->imagen = imagen;
	this->formato = formato;
	this->tamanio = tamanio;
	this->texto = texto;
}

string Foto::getImagen() {
	return imagen;
}

void Foto::setImagen(string imagen) {
	this->imagen = imagen;
}

string Foto::getFormato() {
	return formato;
}

void Foto::setFormato(string formato) {
	this->formato = formato;
}

string Foto::getTamanio() {
	return tamanio;
}

void Foto::setTamanio(string tamanio) {
	this->tamanio = tamanio;
}

string Foto::getTexto() {
	return texto;
}

void Foto::setTexto(string texto) {
	this->texto = texto;
}

Foto::~Foto(){}