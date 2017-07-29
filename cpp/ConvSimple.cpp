
#include <iostream>

#include "../include/ConvSimple.h"
#include "../include/Conversacion.h"
#include "../include/Usuario.h"

ConvSimple::ConvSimple(int id, map<string, Usuario*> participantes) : Conversacion(id){
	this->participantes = participantes;
}

map<string, Usuario*> ConvSimple::getParticipantes() {
	return participantes;
}

void ConvSimple::setParticipantes(map<string, Usuario*> participantes) {
	this->participantes = participantes;
}

ConvSimple::~ConvSimple(){}