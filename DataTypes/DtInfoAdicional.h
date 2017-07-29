#ifndef DTINFOADICIONAL_H_
#define DTINFOADICIONAL_H_

using namespace std;

#include <string>
#include "Fecha.h"

class DtInfoAdicional
{
   string numero;
   string nombre;
   Fecha* fecha;
public:
   DtInfoAdicional();
   DtInfoAdicional(string numero, string nombre, Fecha* fecha);

   string getNumero();

   string getNombre();

   Fecha* getFecha();

   ~DtInfoAdicional();
   
};



#endif