#ifndef DTFOTO_H_
#define DTFOTO_H_

#include <string>
#include "DtMultimedia.h"
#include "../DataTypes/Fecha.h"

using namespace std;

class DtFoto : public DtMultimedia {
	string imagen;
	string formato;
	string tamanio;
	string texto;

public:

	DtFoto();
	DtFoto(int id, Fecha* fecha,string imagen, string formato, string tamanio, string texto);
	
	string getImagen();
	//void setImagen(string imagen);
	
	string getFormato();
	//void setFormato(string formato);
	
	string getTamanio();
	//void setTamanio(string tamanio);
	
	string getTexto();
	//void setTexto(string txt);
	
	~DtFoto();
	
};

#endif