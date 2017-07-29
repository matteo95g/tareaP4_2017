#ifndef GRUPO_H_
#define GRUPO_H_

#include <string>
#include <map>

#include "Conversacion.h"


using namespace std;

class Grupo : public Conversacion
{
	string nombre, imagen;
	Fecha *fecha;
	map<string, Usuario*> participantes;
	map<string, Usuario*> administradores;

public:
	Grupo();
	Grupo(int id, string nombre, string imagen, Fecha* fecha);

	string getNombre() const;
	void setNombre(string nombre);

	string getImagen() const;
	void setImagen(string imagen);

	void setFecha(Fecha* fecha);
	Fecha* getFecha() const;

	map<string, Usuario*> getParticipantes() const;
	void setParticipantes(map<string, Usuario*> participantes);

	map<string, Usuario*> getAdministradores() const;
	void setAdministradores(map<string, Usuario*> administradores);

	
	~Grupo();
};


#endif 