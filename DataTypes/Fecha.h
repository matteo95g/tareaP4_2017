#ifndef FECHA_H_
#define FECHA_H_

#include <string>

using namespace std;


class Fecha
{
	int anio, mes, dia, hora, minuto;
public:
	Fecha();
	Fecha(int anio,int mes,int dia,int hora,int minuto);

	void setFecha(int anio, int mes, int dia, int hora, int minuto);

	int getAnio();
	void setAnio(int anio);

	int getMes();
	void setMes(int mes);

	int getDia();
	void setDia(int dia);

	int getHora();
	void setHora(int hora);

	int getMinuto();
	void setMinuto(int minuto);

	~Fecha();
};


#endif