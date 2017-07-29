#ifndef FOTO_H_
#define FOTO_H_

#include <string>
#include "Multimedia.h"

using namespace std;

class Foto : public Multimedia
{
	string imagen;
	string formato;
	string tamanio;
	string texto;
public:
	Foto();
	Foto(int id, Fecha* fecha, Usuario* emisor, string imagen, string formato, string tamanio, string texto);
	
	string getImagen();
	void setImagen(string imagen);

	string getFormato();
	void setFormato(string formato);

	string getTamanio();
	void setTamanio(string tamanio);

	string getTexto();
	void setTexto(string texto);

	~Foto();

};

#endif