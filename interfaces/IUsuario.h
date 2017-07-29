#ifndef IUSUARIO_H_
#define IUSUARIO_H_

#include <string>
#include <map>
#include "../include/Usuario.h"
#include "../DataTypes/DtUsuario.h"
#include "../DataTypes/DtConversacion.h"
#include "../DataTypes/estadoNum.h"
#include "../DataTypes/DtNotificacion.h"

using namespace std;

class IUsuario
{
public:
	//IUsuario();

	static IUsuario* getInstancia();

	virtual bool haySesion() = 0;
	virtual bool usuarioRegistrado(string numero) = 0;
	virtual bool esContacto(string numero) = 0;
	virtual void agregarContacto(string numero) = 0;
	virtual DtUsuario* confirmarDatos(string numero) = 0;
	virtual list<DtUsuario*> listarContactos() = 0;
	virtual void archivarConversacion(int id) = 0;
	virtual void activarConversacion(int id) = 0;
	virtual list<DtConversacion*> listarConversaciones() = 0;
	virtual list<DtConversacion*> listarConversacionesArchivadas() = 0;

	//virtual Conversacion* seleccionarConversacion(string numero) = 0;
	virtual int iniciarConversacion(string numero) = 0;
	virtual int iniciarGrupo(map<string, DtUsuario*> usrSel, string nombre, string imagen) = 0;
	virtual string obtenerNombre(string numero) = 0;
	virtual estadoNum ingresarNumero(string numero) = 0;
	virtual void alta(string nombre, string URL, string descripcion) = 0;
	virtual void iniciarSesion() = 0;
	virtual void cerrarSesion() = 0;
	virtual void cancelar() = 0;
	virtual list<DtUsuario*> listarContactosRest(map<string, DtUsuario*> contSel) = 0;
	virtual Usuario* getSesion() = 0;
	virtual void suscribirse(string numero) = 0;
	virtual bool suscripto(string numero) = 0;
	virtual void eliminarMensaje(int idConv, int idMsj) = 0;

	virtual void modificarUsuario(string nombre, string imagen, string descripcion) = 0;
	virtual void modificarNombre(string nombre) = 0;
	virtual void modificarImagen(string imagen) = 0;
	virtual void modificarDescripcion(string descripcion) = 0;

	virtual void notificar(Cambios cambio, Fecha* fecha) = 0;
	virtual list<DtNotificacion*> listarNotificaciones() = 0;

	virtual string getNumSesion() = 0;

	virtual ~IUsuario(){};
};

#endif /* IUSUARIO_H_ */