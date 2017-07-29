#include "DtConvsArchivadas.h"

DtConvsArchivadas::DtConvsArchivadas(){}
DtConvsArchivadas::DtConvsArchivadas(int cantidad){
	this->cantidad = cantidad;
}

int DtConvsArchivadas::getCantidad(){
	return this->cantidad;
}

DtConvsArchivadas::~DtConvsArchivadas(){}