#include "ConvController.h"

extern Fecha* fechaGeneralSistema;

ConvController* ConvController::instancia = NULL;

ConvController::ConvController(){
		this->nroConv = 0;
		this->nroMsj = 0;
}

ConvController* ConvController::getInstancia(){
	if (instancia == NULL) {
		instancia = new ConvController();
	}
	return instancia;
}

void ConvController::eliminarMensaje(int idConv, int idMsj) {
	convSis[idConv]->eliminarMensaje(idMsj);
}

void ConvController::borrarMensaje(Usuario* usr, int idConv, int idMsj) {
	Conversacion* conv = convSis[idConv];
	Mensaje* mensConv = conv->getMensajes()[idMsj];
	Visto* vistoUsr = mensConv->getVistos()[usr->getNumero()];
	vistoUsr->setBorrado(true);
}

bool ConvController::esEmisor(Usuario* usr, int idConv, int idMsj) {
	Conversacion* conv = convSis[idConv];
	Mensaje* mensConv = conv->getMensajes()[idMsj];
	return (mensConv->esEmisor(usr));
}

/*int ConvController::getNroConv(){
	return nroConv;
}

void ConvController::setNroConv(){
	nroConv++;
}*/

void ConvController::agregarAGrupo(string numero, Grupo* g){
	UserConv* ucon = new UserConv(nroConv, false, fechaGeneralSistema, g);
	UserController* uscontrol= UserController::getInstancia();
	Usuario* usr = uscontrol->getUsuarioSis()[numero];
	usr->agregarUserConv(ucon);
	map<string, Usuario*> parts = g->getParticipantes();
	parts[numero] = usr;
}

//-----------------------FALTA DESENGANCHAR EL USERCONV-----------------------//

void ConvController::quitarDeGrupo(string numero){
	Grupo *cGrup = dynamic_cast<Grupo *> (convActual);
	if (cGrup != NULL){
		map<string,Usuario*>::iterator it = cGrup->getParticipantes().find(numero);
		it->second = NULL;
		cGrup->getParticipantes().erase(numero);
	}
}

Grupo* ConvController::crearGrupo(map<string, Usuario*> usrSel, string nombre, string imagen){
	nroConv++;
	Grupo* g = new Grupo(nroConv, nombre, imagen, fechaGeneralSistema);
	g->setParticipantes(usrSel);
	convSis[g->getId()] = g;
	return g;
}

ConvSimple* ConvController::crearConversacion(Usuario* usr1, Usuario* usr2) {
	nroConv++;
	map<string, Usuario*> participantes;
	participantes[usr1->getNumero()] = usr1;
	participantes[usr2->getNumero()] = usr2;
	ConvSimple* nuevaConv = new ConvSimple(nroConv, participantes);
	convSis[nuevaConv->getId()] = nuevaConv;
	return nuevaConv;
}

Simple* ConvController::crearMensajeSimple(Usuario* emisor, string texto) {
	nroMsj++;
	Simple* nvoMsj = new Simple(nroMsj, fechaGeneralSistema, emisor, texto);
	return nvoMsj;
}

Contacto* ConvController::crearMensajeContacto(Usuario* emisor, string numero) {
	nroMsj++;
	UserController* uscontrol= UserController::getInstancia();
	string nombre = uscontrol->obtenerNombre(numero);
	Contacto* nvoMsj = new Contacto(nroMsj, fechaGeneralSistema, emisor, nombre, numero);
	return nvoMsj;
}

Video* ConvController::crearMensajeVideo(Usuario* emisor, string duracion, string URL) {
	nroMsj++;
	Video* nvoMsj = new Video(nroMsj, fechaGeneralSistema, emisor, URL, duracion);
	return nvoMsj;
}

Foto* ConvController::crearMensajeImagen(Usuario* emisor, string imagen, string texto, string formato, string tamanio) {
	nroMsj++;
	Foto* nvoMsj = new Foto(nroMsj, fechaGeneralSistema, emisor, imagen, formato, tamanio, texto);
	return nvoMsj;
}

void ConvController::enviarMensajeSimple(int idConv, string texto) {
	UserController* uscontrol= UserController::getInstancia();
	Usuario* emisor = uscontrol->getSesion();
	Simple* nvoMsjSimple = crearMensajeSimple(emisor, texto);

	Conversacion* conv = convSis[idConv];
	if (ConvSimple *cSimp = dynamic_cast<ConvSimple *> (conv)) {
		map<string, Usuario*> participantes = cSimp->getParticipantes();
		map<string, Usuario*>::iterator it = participantes.begin();
		while (it != participantes.end()) {
			if (it->first != emisor->getNumero()) {
				Visto* nvoVisto = new Visto(false, it->second);
				nvoMsjSimple->agregarVisto(it->first, nvoVisto);
			}
			it++;
		}
	} else if (Grupo *cGrup = dynamic_cast<Grupo *> (conv)) {
		map<string, Usuario*> participantes = cGrup->getParticipantes();
		map<string, Usuario*>::iterator it = participantes.begin();
		while (it != participantes.end()) {
			if (it->first != emisor->getNumero()) {
				Visto* nvoVisto = new Visto(false, it->second);
				nvoMsjSimple->agregarVisto(it->first, nvoVisto);
			}
			it++;
		}
	}

	convSis[idConv]->agregarMensaje(nvoMsjSimple);
}

void ConvController::enviarMensajeContacto(int idConv, string numero) {
	UserController* uscontrol= UserController::getInstancia();
	Usuario* emisor = uscontrol->getSesion();
	Contacto* nvoMsjContacto = crearMensajeContacto(emisor, numero);

	Conversacion* conv = convSis[idConv];
	if (ConvSimple *cSimp = dynamic_cast<ConvSimple *> (conv)) {
		map<string, Usuario*> participantes = cSimp->getParticipantes();
		map<string, Usuario*>::iterator it = participantes.begin();
		while (it != participantes.end()) {
			if (it->first != emisor->getNumero()) {
				Visto* nvoVisto = new Visto(false, it->second);
				nvoMsjContacto->agregarVisto(it->first, nvoVisto);
			}
			it++;
		}
	} else if (Grupo *cGrup = dynamic_cast<Grupo *> (conv)) {
		map<string, Usuario*> participantes = cGrup->getParticipantes();
		map<string, Usuario*>::iterator it = participantes.begin();
		while (it != participantes.end()) {
			if (it->first != emisor->getNumero()) {
				Visto* nvoVisto = new Visto(false, it->second);
				nvoMsjContacto->agregarVisto(it->first, nvoVisto);
			}
			it++;
		}
	}

	convSis[idConv]->agregarMensaje(nvoMsjContacto);
}

void ConvController::enviarMensajeVideo(int idConv, string duracion, string URL) {
	UserController* uscontrol= UserController::getInstancia();
	Usuario* emisor = uscontrol->getSesion();
	Video* nvoMsjVideo = crearMensajeVideo(emisor, duracion, URL);

	Conversacion* conv = convSis[idConv];
	if (ConvSimple *cSimp = dynamic_cast<ConvSimple *> (conv)) {
		map<string, Usuario*> participantes = cSimp->getParticipantes();
		map<string, Usuario*>::iterator it = participantes.begin();
		while (it != participantes.end()) {
			if (it->first != emisor->getNumero()) {
				Visto* nvoVisto = new Visto(false, it->second);
				nvoMsjVideo->agregarVisto(it->first, nvoVisto);
			}
			it++;
		}
	} else if (Grupo *cGrup = dynamic_cast<Grupo *> (conv)) {
		map<string, Usuario*> participantes = cGrup->getParticipantes();
		map<string, Usuario*>::iterator it = participantes.begin();
		while (it != participantes.end()) {
			if (it->first != emisor->getNumero()) {
				Visto* nvoVisto = new Visto(false, it->second);
				nvoMsjVideo->agregarVisto(it->first, nvoVisto);
			}
			it++;
		}
	}

	convSis[idConv]->agregarMensaje(nvoMsjVideo);
}


void ConvController::enviarMensajeImagen(int idConv, string imagen, string texto, string formato, string tamanio) {
	UserController* uscontrol= UserController::getInstancia();
	Usuario* emisor = uscontrol->getSesion();
	Foto* nvoMsjImagen = crearMensajeImagen(emisor, imagen, texto, formato, tamanio);

	Conversacion* conv = convSis[idConv];
	if (ConvSimple *cSimp = dynamic_cast<ConvSimple *> (conv)) {
		map<string, Usuario*> participantes = cSimp->getParticipantes();
		map<string, Usuario*>::iterator it = participantes.begin();
		while (it != participantes.end()) {
			if (it->first != emisor->getNumero()) {
				Visto* nvoVisto = new Visto(false, it->second);
				nvoMsjImagen->agregarVisto(it->first, nvoVisto);
			}
			it++;
		}
	} else if (Grupo *cGrup = dynamic_cast<Grupo *> (conv)) {
		map<string, Usuario*> participantes = cGrup->getParticipantes();
		map<string, Usuario*>::iterator it = participantes.begin();
		while (it != participantes.end()) {
			if (it->first != emisor->getNumero()) {
				Visto* nvoVisto = new Visto(false, it->second);
				nvoMsjImagen->agregarVisto(it->first, nvoVisto);
			}
			it++;
		}
	}

	convSis[idConv]->agregarMensaje(nvoMsjImagen);
}

list<DtMensaje*> ConvController::mostrarMensajes(int id){
	//echa por el teo que es un crack
	//obtengo la fecha de registro del flaco
	UserController* uCont = UserController::getInstancia();
	//UserConv* uConv = uCont->getSesion()->getConversaciones()[id];
	//Fecha* fechaReg = uConv->getFechaIngreso();
	//obtengo las conv del flaco
	Conversacion* conv = convSis[id];
	map<int,Mensaje*> msjs = conv->getMensajes();
	map<int,Mensaje*>::iterator it = msjs.begin();
	//creo una lista de mensajes
	list<DtMensaje*> res;
	while (it != msjs.end()){
		if ((esEmisor(uCont->getSesion(), id, it->first)) || (!(it->second->getVistos()[uCont->getSesion()->getNumero()]->getBorrado()))) {
			if (Simple *s = dynamic_cast<Simple *> (it->second)){
				//if (fechaReg <= s->getFecha()){
					DtSimple* dtS = new DtSimple(s->getId(),s->getFecha(),s->getTexto());
					res.push_back(dtS);
				//}
			}
			if (Foto *f = dynamic_cast<Foto *> (it->second)){
				//if (fechaReg <= f->getFecha()){
					DtFoto* dtf = new DtFoto(f->getId(),f->getFecha(),f->getImagen(),f->getFormato(), f->getTamanio(), f->getTexto());
					res.push_back(dtf);
				//}
			}
			if (Video *v = dynamic_cast<Video *> (it->second)){
				//if (fechaReg <= v->getFecha()){
					DtVideo* dtv = new DtVideo(v->getId(),v->getFecha(),v->getVideo(),v->getDuracion());
					res.push_back(dtv);
				//} 
			}
			if (Contacto *c = dynamic_cast<Contacto *> (it->second)){
				//if (fechaReg <= c->getFecha()){
					DtContacto* dtc = new DtContacto(c->getId(),c->getFecha(),c->getNombre(),c->getNumero());
					res.push_back(dtc);
				//}
			}
			if ((!esEmisor(uCont->getSesion(), id, it->first)) && (!(it->second->getVistos()[uCont->getSesion()->getNumero()]->getVisto()))) {
				it->second->getVistos()[uCont->getSesion()->getNumero()]->setVisto(true);
				it->second->getVistos()[uCont->getSesion()->getNumero()]->setFecha(fechaGeneralSistema);
			}
		}
		it++;
	}
	return res;
}

list<DtInfoAdicional*> ConvController::verInfoAdicional(int codigo, int idConv) {
	list<DtInfoAdicional*> listaInfo;
	Conversacion* conv = convSis[idConv];
	Mensaje* msj = conv->getMensajes()[codigo];

	map<string,Visto*> listaVistos = msj->getVistos();
	map<string,Visto*>::iterator it = listaVistos.begin();

	while (it != listaVistos.end()) {
		if (it->second->getVisto()) {
			DtInfoAdicional* info = new DtInfoAdicional(it->first, it->second->getUsuario()->getNombre(), it->second->getFecha());
			listaInfo.push_back(info);
		} 
		it++;
	}
	return listaInfo;
}


ConvController::~ConvController(){}