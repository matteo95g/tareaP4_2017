#include "../include/Usuario.h"

Usuario::Usuario(string numero, string nombre, string imagen, string descripcion){
	this->numero = numero;
	this->nombre = nombre;
	this->imagen = imagen;
	this->descripcion = descripcion;
	this->fecha_reg = fechaGeneralSistema;
	map<string, Usuario*> contactos;
	map<string, Usuario*> suscriptores;
	map<string, UserConv*> arrayUconv;
	map<string, Notificacion*> notificacion;
}

string Usuario::getNumero() const{
	return this->numero;
}

void Usuario::setNumero(string nuevoNum){
	this->numero = nuevoNum;
}

string Usuario::getNombre() const{
	return this->nombre;
}

void Usuario::setNombre(string nuevoNom){
	this->nombre = nuevoNom;
}

Fecha* Usuario::getFechaReg() const{
	return this->fecha_reg;
}

string Usuario::getImagen() const{
	return this->imagen;
}

void Usuario::setImagen(string nuevaImg){
	this->imagen = nuevaImg;
}

string Usuario::getDescripcion() const{
	return this->descripcion;
}

void Usuario::setDescripcion(string nuevaDesc){
	this->descripcion = nuevaDesc;
}

Fecha* Usuario::getUlt_vez() const{
	return this->ult_vez;
}

void Usuario::setUlt_vez (Fecha* ultimaVez){
	this->ult_vez = ultimaVez;
}

Estado* Usuario::getEstado() const{
	return this->estado;
}

void Usuario::setEstado (Estado* nuevoEstado){
	this->estado = nuevoEstado;
}

map<int, UserConv*> Usuario::getConversaciones() const{
	return this->arrayUconv;
}

void Usuario::setConversaciones(map<int, UserConv*> conversaciones){
	
	
}
void Usuario::agregarUserConv(UserConv* u){
	arrayUconv[u->getId()]=u;
}


/*set<UserConv*> Usuario::getConversacionesArchivadas(){
	set<UserConv*> convsArchi;
	set<UserConv*>::iterator it = this->arrayUconv.begin();
	for (it; it!= arrayUconv.end(); it++) {
		if ((*it)->getArchivada()) {
			UserConv* nuevoNodo = new UserConv((*it)->getId(), (*it)->getArchivada(), (*it)->getFechaIngreso(), (*it)->getConversacion()); 
			convsArchi.insert(nuevoNodo);	
		}
	}
	return convsArchi;
}*/

void Usuario::setContactos(map<string, Usuario*> contactos){
	this->contactos = contactos;
}

map<string, Usuario*> Usuario::getContactos() {
	return this->contactos;
}

void Usuario::addContacto(Usuario *c){
	contactos[c->numero] = c;
}

/*DtUsuario Usuario::getInfo(){

}   */ 

map<string, Usuario*> Usuario::getSuscriptores() {
	return this->suscriptores;
}

void Usuario::agregarSuscriptor(Usuario *susc) {
	suscriptores[susc->numero] = susc;
}

void Usuario::eliminarSuscriptor(Usuario *susc) {

}

void Usuario::notificarSuscriptores(Notificacion* noti) {
	map<string, Usuario*>::iterator it = suscriptores.begin();
	while (it != suscriptores.end()) {
		it->second->agregarNotificacion(noti);
		it++;
	}
}

void Usuario::agregarNotificacion(Notificacion* noti){
	notificacion.push_back(noti);
}


list<Notificacion*> Usuario::getNotificaciones() {
	return notificacion;
}

void Usuario::mandarMensaje(Mensaje *msj){

}
bool Usuario::operator<(const Usuario& u) const {
	bool menor = false;
	if (numero.compare(u.numero) <0) {
		menor = true;
	}
	return menor;
}

bool Usuario::operator==(const Usuario& u) const{
	bool igual = false;
	if (numero.compare(u.numero) ==0 ) {
		igual = true;
	}
	return igual;
}
struct find_by_numero {
    find_by_numero(const string & numero) : numero(numero) {}
    bool operator()(const Usuario & usuario) {
        return this->numero == numero;
    }
private:
    string numero;
};

