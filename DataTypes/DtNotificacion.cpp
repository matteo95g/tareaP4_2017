#include "DtNotificacion.h"

	DtNotificacion::DtNotificacion(string nro, Cambios cambio, Fecha* fecha) {
		this->nro = nro;
		this->cambio = cambio;
		this->fecha = fecha;
	}


	string DtNotificacion::getNumero() {
		return nro;
	}

	void DtNotificacion::setNumero(string nro) {
		this->nro = nro;
	}


	Fecha* DtNotificacion::getFecha() {
		return fecha;
	}


	Cambios DtNotificacion::getCambio() {
		return cambio;
	}

	void DtNotificacion::setCambio(Cambios cambio) {
		this->cambio = cambio;
	}