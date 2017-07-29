#include "../include/Notificacion.h"


	Notificacion::Notificacion(string nro, Cambios cambio, Fecha* fecha) {
		this->nro = nro;
		this->cambio = cambio;
		this->fecha = fecha;
	}


	string Notificacion::getNumero() {
		return nro;
	}

	void Notificacion::setNumero(string nro) {
		this->nro = nro;
	}


	Fecha* Notificacion::getFecha() {
		return fecha;
	}


	Cambios Notificacion::getCambio() {
		return cambio;
	}

	void Notificacion::setCambio(Cambios cambio) {
		this->cambio = cambio;
	}