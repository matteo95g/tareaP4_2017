#ifndef USUARIO_H_
#define USUARIO_H_

#include <string>
#include <map>


#include "../DataTypes/Fecha.h"

extern Fecha* fechaGeneralSistema;


#include "../DataTypes/DtConversacion.h"
#include "../DataTypes/DtUsuario.h"
#include "Estado.h"
#include "Notificacion.h"

#include "UserConv.h"
#include "Conversacion.h"
#include "Mensaje.h"
#include "Visto.h"

using namespace std;



class Usuario {
	string numero;
	string nombre;
	Fecha* fecha_reg;
	string imagen;
	string descripcion;
	Fecha* ult_vez;
	Estado* estado;
	
	map<string,Usuario*> contactos;
	map<string,Usuario*> suscriptores;
	map<int,UserConv*> arrayUconv;
	list<Notificacion*> notificacion;

public:
	Usuario();
	Usuario(string numero, string nombre, string imagen, string descripcion);

	string getNumero() const;
	void setNumero(string nuevoNum);

	string getNombre() const;
	void setNombre(string nuevoNom);

	Fecha* getFechaReg() const;
	void setFechaReg(Fecha* fecha);

	string getImagen() const;
	void setImagen(string nuevaImg);

	string getDescripcion() const;
	void setDescripcion(string nuevaDesc);


	Fecha* getUlt_vez() const;
	void setUlt_vez (Fecha* ultimaVez);


	Estado* getEstado() const;
	void setEstado (Estado* nuevoEstado);


	map<int,UserConv*> getConversaciones() const;
	//map<string,UserConv*> getConversacionesArchivadas();
	void setConversaciones(map<int, UserConv*> conversaciones);
	void agregarUserConv(UserConv* u);

	
	map<string,Usuario*> getContactos();
	void setContactos(map<string,Usuario*>);

    ~Usuario();

    void addContacto(Usuario *c);
    DtUsuario getInfo();
    
    map<string, Usuario*> getSuscriptores();
    void agregarSuscriptor(Usuario *susc);
    void eliminarSuscriptor(Usuario *susc);

    void notificarSuscriptores(Notificacion* noti);
    void agregarNotificacion(Notificacion* noti);
    list<Notificacion*> getNotificaciones();

    void mandarMensaje(Mensaje *msj);

    bool operator<(const Usuario& u) const;
    bool operator==(const Usuario& u) const;
};


#endif