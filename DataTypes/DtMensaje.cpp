#include "DtMensaje.h"

DtMensaje::DtMensaje(){}

DtMensaje::DtMensaje(int id, Fecha *fecha){
	this->id = id;
	this->fecha = fecha;
}

DtMensaje::DtMensaje(int id, Fecha *fecha, map<string,DtVisto*> vistos, DtUsuario* emisor){
	this->id = id;
	this->fecha = fecha;
	this->vistos = vistos;
	this->emisor = emisor;
}
	
int DtMensaje::getId(){
	return this->id;
}
	
Fecha* DtMensaje::getFecha(){
	return this->fecha;
}
	
map<string,DtVisto*> DtMensaje::getVistos(){
	return this->vistos;
}

DtUsuario* DtMensaje::getEmisor(){
	return this->emisor;
}

DtMensaje::~DtMensaje(){}