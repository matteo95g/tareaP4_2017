#include "DtFoto.h"

DtFoto::DtFoto(){}
DtFoto::DtFoto(int id, Fecha* fecha,string imagen, string formato, string tamanio, string texto): DtMultimedia(id, fecha){
	this->imagen = imagen;
	this->formato = formato;
	this->tamanio = tamanio;
	this->texto = texto;
}
	
string DtFoto::getImagen(){
	return this->imagen;
}
//void setImagen(string imagen);
	
string DtFoto::getFormato(){
	return this->formato;
}
//void setFormato(string formato);
	
string DtFoto::getTamanio(){
	return this->tamanio;
}
//void setTamanio(string tamanio);
	
string DtFoto::getTexto(){
	return this->texto;
}
//void setTexto(string txt);
	
DtFoto::~DtFoto(){}