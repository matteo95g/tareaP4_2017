#ifndef USERCONTROLLER_H_
#define USERCONTROLLER_H_

#include <string>
#include <map>
#include <list>
#include "../include/Usuario.h"
#include "../include/Mensaje.h"
#include "../interfaces/IUsuario.h"
#include "ConvController.h"
#include "../include/Conversacion.h"
#include "../include/ConvSimple.h"
#include "../include/Grupo.h"
#include "../include/Notificacion.h"
#include "../DataTypes/DtGrupo.h"
#include "../DataTypes/DtContacto.h"
#include "../DataTypes/DtConvSimple.h"
#include "../DataTypes/DtConvsArchivadas.h"

class UserController : public IUsuario
{
	static UserController* instancia;
	Usuario* sesion;
	map<string,Usuario*> usuarioSis;
	UserController();
	string numeroIngresado;
public:
	static UserController* getInstancia();

	bool haySesion();
	bool usuarioRegistrado(string numero);
	bool esContacto(string numero);
	void agregarContacto(string numero);
	DtUsuario* confirmarDatos(string numero);
	list<DtUsuario*> listarContactos();
	void archivarConversacion(int id);
	void activarConversacion(int id);
	list<DtConversacion*> listarConversaciones();
	list<DtConversacion*> listarConversacionesArchivadas();
	//Conversacion* seleccionarConversacion(string numero);
	int iniciarConversacion(string numero);
	int iniciarGrupo(map<string, DtUsuario*> usrSel, string nombre, string imagen);
	string obtenerNombre(string numero);
	estadoNum ingresarNumero(string numero);
	void alta(string nombre, string URL, string descripcion);
	void iniciarSesion();
	void cerrarSesion();
	void cancelar();
	void setNumeroIngresado(string numero);
	string getNumeroIngresado();
	list<DtUsuario*> listarContactosRest(map<string, DtUsuario*> contSel);
	map<string, Usuario*> getUsuarioSis();

	Usuario* getSesion();

	string getNumSesion();

	void modificarUsuario(string nombre, string imagen, string descripcion);
	void modificarNombre(string nombre);
	void modificarImagen(string imagen);
	void modificarDescripcion(string descripcion);

	void notificar(Cambios cambio, Fecha* fecha);
	list<DtNotificacion*> listarNotificaciones();

	void suscribirse(string numero);
	bool suscripto(string numero);

	void eliminarMensaje(int idConv, int idMsj);

	~UserController();
};

#endif