#include "UserController.h"

extern Fecha* fechaGeneralSistema;

UserController* UserController::instancia = NULL;

UserController::UserController(){
	this->sesion = NULL;
}

UserController* UserController::getInstancia(){
	if (instancia == NULL)
		instancia = new UserController();
	return instancia;
}

bool UserController::haySesion() {
	return (sesion != NULL);
}

bool UserController::usuarioRegistrado(string numero) {
	if (!usuarioSis.empty()) {
		map<string, Usuario*>::iterator it;
		it = usuarioSis.find(numero);
		return (it != usuarioSis.end());
	} else {
		return (false);
	}
}

bool UserController::esContacto(string numero) {
	map<string, Usuario*> c = sesion->getContactos();
	if (!c.empty()) {
		map<string, Usuario*>::iterator it;
		it = c.find(numero);
		return (it != c.end());
	} else {
		return (false);
	}
}

void UserController::agregarContacto(string numero){
	Usuario* it = usuarioSis[numero];
	sesion->addContacto(it);
}

DtUsuario* UserController::confirmarDatos(string numero){
	Usuario* contacto = usuarioSis[numero];
	DtUsuario* datos = new DtUsuario(contacto->getNombre(), contacto->getNumero(), contacto->getImagen(), contacto->getDescripcion());
	return datos;
}

list<DtUsuario*> UserController::listarContactos(){
	map<string,Usuario*> lCont = sesion->getContactos();
	map<string,Usuario*>::iterator it = lCont.begin();
	list<DtUsuario*> lDtU;
	if (!lCont.empty()) {
		while (it != lCont.end()){
			DtUsuario* cont = new DtUsuario(it->second->getNombre(), it->second->getNumero(), it->second->getImagen(), it->second->getDescripcion());
			lDtU.push_back(cont);
			it++;
		}
	}
	return lDtU;
}

void UserController::archivarConversacion(int id) {
	map<int,UserConv*> convs = sesion->getConversaciones();
	convs[id]->setArchivada(true);
}

void UserController::activarConversacion(int id){
	map<int,UserConv*> convs = sesion->getConversaciones();
	convs[id]->setArchivada(false);
}
 
list<DtConversacion*> UserController::listarConversaciones(){
	map<int, UserConv*> lConv = sesion->getConversaciones();
	map<int, UserConv*>::iterator it = lConv.begin();
	list<DtConversacion*> lDtConv;
	int contadorA = 0;
	while (it != lConv.end()) {
		Conversacion* conv = it->second->getConversacion();
		if (ConvSimple *cSimp = dynamic_cast<ConvSimple *> (conv)) {
			if (!(it->second->getArchivada())) {
				map<string, Usuario*> lPart = cSimp->getParticipantes();
				map<string, Usuario*>::iterator iter = lPart.begin();
				if (iter->first == sesion->getNumero()) {
					iter++;
				}
				DtUsuario* usr2 = new DtUsuario(iter->second->getNombre(), iter->first, iter->second->getImagen(), iter->second->getDescripcion());
				map<string, DtUsuario*> participantes;
				participantes[usr2->getNumero()] = usr2;
				DtConvSimple* DtCSimp = new DtConvSimple(cSimp->getId(), participantes);
				lDtConv.push_back(DtCSimp);
			} else {
				contadorA++;
			}
		} else if (Grupo *cGrup = dynamic_cast<Grupo *> (conv)) {
			if (!(it->second->getArchivada())) {
				DtGrupo* DtGrup = new DtGrupo(cGrup->getId(), cGrup->getNombre());
				lDtConv.push_back(DtGrup);
			} else {
				contadorA++;
			}
		}
		it++;
	}
	DtConvsArchivadas* DtCArch = new DtConvsArchivadas(contadorA);
	lDtConv.push_back(DtCArch);
	return lDtConv;
}


list<DtConversacion*> UserController::listarConversacionesArchivadas(){
	map<int, UserConv*> lConv = sesion->getConversaciones();
	map<int, UserConv*>::iterator it = lConv.begin();
	list<DtConversacion*> lDtConv;
	while (it != lConv.end()) {
		Conversacion* conv = it->second->getConversacion();
		if (ConvSimple *cSimp = dynamic_cast<ConvSimple *> (conv)) {
			if ((it->second->getArchivada())) {
				map<string, Usuario*> lPart = cSimp->getParticipantes();
				map<string, Usuario*>::iterator iter = lPart.begin();
				if (iter->first == sesion->getNumero()) {
					iter++;
				}
				DtUsuario* usr2 = new DtUsuario(iter->second->getNombre(), iter->first, iter->second->getImagen(), iter->second->getDescripcion());
				map<string, DtUsuario*> participantes;
				participantes[usr2->getNumero()] = usr2;
				DtConvSimple* DtCSimp = new DtConvSimple(cSimp->getId(), participantes);
				lDtConv.push_back(DtCSimp);
			} 
		} else if (Grupo *cGrup = dynamic_cast<Grupo *> (conv)) {
			if ((it->second->getArchivada())) {
				DtGrupo* DtGrup = new DtGrupo(cGrup->getId(), cGrup->getNombre());
				lDtConv.push_back(DtGrup);
			} 
		}
		it++;
	}
	return lDtConv;
}

/*Conversacion* UserController::seleccionarConversacion(string id){

}*/

int UserController::iniciarConversacion(string numero){
	Usuario* usr2 = sesion->getContactos()[numero];
	ConvController* convControl = ConvController::getInstancia();
	ConvSimple* nuevaConv = convControl->crearConversacion(sesion, usr2);
	UserConv* usrConv1 = new UserConv(nuevaConv->getId(), false, fechaGeneralSistema, nuevaConv);
	UserConv* usrConv2 = new UserConv(nuevaConv->getId(), false, fechaGeneralSistema, nuevaConv);
	sesion->agregarUserConv(usrConv1);
	usr2->agregarUserConv(usrConv2);
	return nuevaConv->getId();
}

int UserController::iniciarGrupo(map<string, DtUsuario*> usrSel, string nombre, string imagen) {
	map<string, DtUsuario*>::iterator it = usrSel.begin();
	map<string, Usuario*> usrGrp;
	while (it != usrSel.end()) {
		usrGrp[it->first] = usuarioSis[it->first];
		it++;
	}
	usrGrp[sesion->getNumero()] = sesion;
	ConvController* convControl = ConvController::getInstancia();
	Grupo* nuevoGrp = convControl->crearGrupo(usrGrp, nombre, imagen);
	map<string, Usuario*>::iterator it2 = usrGrp.begin();
	while (it2 != usrGrp.end()) {
		UserConv* usrConv = new UserConv(nuevoGrp->getId(), false, fechaGeneralSistema, nuevoGrp);
		it2->second->agregarUserConv(usrConv);
		it2++;
	}
	map<string, Usuario*> admins;
	admins[sesion->getNumero()] = sesion;
	nuevoGrp->setAdministradores(admins);
	return nuevoGrp->getId();
}

string UserController::obtenerNombre(string numero){
	string nombre = usuarioSis[numero]->getNombre();
	return nombre;
}

estadoNum UserController::ingresarNumero(string numero){
	Usuario* usr = sesion;
	this->numeroIngresado = numero;
	if (usr != NULL) {
		if (usr->getNumero() == numero) {
			return RegistradoEIniciado;
		}else{
			return IniciadoOtroNum;
		}
	} else {
		map<string,Usuario*>::iterator it = usuarioSis.find(numero);
		if (it != usuarioSis.end())
			return RegistradoNoIniciado;
		else
			return NoRegistrado;
	}
}

void UserController::alta(string nombre, string URL, string descripcion){
	string numero= numeroIngresado;
	Usuario* usr = new Usuario(getNumeroIngresado(),nombre, URL, descripcion);
	usuarioSis[numero]= usr;
}


void UserController::iniciarSesion(){
	map<string,Usuario*>::iterator it = usuarioSis.find(numeroIngresado);
	this->sesion = it->second;
	it->second->setUlt_vez(fechaGeneralSistema);
}

void UserController::setNumeroIngresado(string numero){
	this->numeroIngresado = numero;
}
string UserController::getNumeroIngresado(){
	return this->numeroIngresado;
}
void UserController::cancelar(){
	numeroIngresado = "0";
}

void UserController::cerrarSesion(){
	sesion->setUlt_vez(fechaGeneralSistema);
	sesion = NULL;
}

string UserController::getNumSesion(){
	if (sesion == NULL) {
		return "No hay sesion iniciada";
	}else{
		return sesion->getNumero();
	}
}

list<DtUsuario*> UserController::listarContactosRest(map<string, DtUsuario*> contSel){
	map<string, Usuario*>::iterator it;
	map<string, Usuario*> Contacts = sesion->getContactos();
	it = Contacts.begin();
	list<DtUsuario*> res;
	while (it!= Contacts.end()){
		if (contSel.find(it->first) == contSel.end()){
			DtUsuario* usr = new DtUsuario(it->second->getNombre(), it->second->getNumero(), it->second->getImagen(), it->second->getDescripcion());
			res.push_back(usr);
		}
		it++;
	}
	return res;
}

map<string, Usuario*> UserController::getUsuarioSis(){
	return usuarioSis;
}


void UserController::modificarUsuario(string nombre, string imagen, string descripcion){
	sesion->setNombre(nombre);
	sesion->setImagen(imagen);
	sesion->setDescripcion(descripcion);
}

void UserController::modificarNombre(string nombre) {
	sesion->setNombre(nombre);
}

void UserController::modificarImagen(string imagen) {
	sesion->setImagen(imagen);
}

void UserController::modificarDescripcion(string descripcion) {
	sesion->setDescripcion(descripcion);
}

void UserController::notificar(Cambios cambio, Fecha* fecha) {
	Notificacion* nuevaNoti = new Notificacion(sesion->getNumero(), cambio, fecha);
	sesion->notificarSuscriptores(nuevaNoti);
}

list<DtNotificacion*> UserController::listarNotificaciones() {
	list<Notificacion*> noti = sesion->getNotificaciones();
	list<Notificacion*>::iterator it = noti.begin();
	list<DtNotificacion*> notiList;
	while (it != noti.end()) {
		DtNotificacion* DtNoti = new DtNotificacion((*it)->getNumero(), (*it)->getCambio(), (*it)->getFecha());
		notiList.push_back(DtNoti);
		it++;
	}
	return notiList;
}

Usuario* UserController::getSesion() {
	return sesion;
}

void UserController::suscribirse(string numero) {
	Usuario* usr = usuarioSis[numero];
	usr->agregarSuscriptor(sesion);
}

bool UserController::suscripto(string numero) {
	map<string, Usuario*> suscriptores = usuarioSis[numero]->getSuscriptores();
	return (suscriptores.find(sesion->getNumero()) != suscriptores.end());
}

void UserController::eliminarMensaje(int idConv, int idMsj) {
	ConvController* convControl = ConvController::getInstancia();
	bool emisor = convControl->esEmisor(sesion, idConv, idMsj);
	if (emisor) {
		convControl->eliminarMensaje(idConv, idMsj);
	} else {
		convControl->borrarMensaje(sesion, idConv, idMsj);
	}
}

UserController::~UserController(){}