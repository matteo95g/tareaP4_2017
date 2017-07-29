#include "Fecha.h"

Fecha::Fecha() {}

Fecha::Fecha(int anio,int mes,int dia,int hora,int minuto) {
	this->anio = anio;
	this->mes = mes;
	this->dia = dia;
	this->hora = hora;
	this->minuto = minuto;
}

void Fecha::setFecha(int anio, int mes, int dia, int hora, int minuto) {
	this->anio = anio;
	this->mes = mes;
	this->dia = dia;
	this->hora = hora;
	this->minuto = minuto;
}

int Fecha::getAnio() {
	return this->anio;
}
void Fecha::setAnio(int anio) {
	this->anio = anio;
}

int Fecha::getMes() {
	return this->mes;
}
void Fecha::setMes(int mes) {
	this->mes= mes;
}

int Fecha::getDia() {
	return this->dia;
}
void Fecha::setDia(int dia) {
	this->dia= dia;
}

int Fecha::getHora() {
	return this->hora;
}
void Fecha::setHora(int hora) {
	this->hora = hora;
}

int Fecha::getMinuto() {
	return this->minuto;
}
void Fecha::setMinuto(int minuto) {
	this->minuto = minuto;
}

Fecha::~Fecha() {}