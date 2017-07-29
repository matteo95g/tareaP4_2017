#include "../include/Estado.h"
#include "../DataTypes/Fecha.h"

#include <string>

using namespace std;

Estado::Estado(string txt){
	this->texto = txt;
}

string Estado::getTexto() const{
	return texto;
}

Fecha* Estado::getFecha() const{
	return fecha;
}

void Estado::setTexto(string txt){
	this->texto = txt;
}

