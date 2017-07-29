#ifndef DTVISTO_H_
#define DTVISTO_H_

#include "Fecha.h"

using namespace std;

class DtVisto
{
   Fecha* fecha;
   bool visto;
public:
   DtVisto();
   DtVisto(Fecha* fecha, bool visto);

   Fecha* getFecha();
   
   bool getVisto();

   ~DtVisto();

   
};

#endif