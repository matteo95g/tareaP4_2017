#ifndef DTUSUARIO_H_
#define DTUSUARIO_H_

#include <string>
#include "Fecha.h"

using namespace std;

class DtUsuario
{
	string nombre;
	string numero;
	string imagen;
	string descripcion;
	Fecha* ult_vez;
	Fecha* fecha_reg;

public:
	DtUsuario();
	DtUsuario(string nombre, string numero, string imagen, string descripcion);
	DtUsuario(string nombre, string numero, string imagen, string descripcion, Fecha* ult_vez, Fecha* fecha_reg);


	string getNombre();

	string getNumero();

	string getDescripcion();
	
	string getImagen();

	Fecha* getUlt_vez();

	Fecha* getFecha_reg();

	~DtUsuario();
	
};

#endif