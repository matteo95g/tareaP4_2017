#ifndef ICONVERSACION_H_
#define ICONVERSACION_H_

#include <string>
#include "../DataTypes/DtInfoAdicional.h"
#include "../include/Simple.h"
#include "../include/Video.h"
#include "../include/Foto.h"
#include "../include/Contacto.h"
#include "../include/Grupo.h"
#include "../include/ConvSimple.h"

using namespace std;

class IConversacion
{
public:
	//IConversacion();

	static IConversacion* getInstancia();

	virtual list<DtInfoAdicional*> verInfoAdicional(int codigo, int idConv) = 0;
	
	virtual void eliminarMensaje(int idConv, int idMsj) = 0;
	virtual void borrarMensaje(Usuario* usr, int idConv, int idMsj) = 0;
	
	virtual Simple* crearMensajeSimple(Usuario* emisor, string texto) = 0;
	virtual Contacto* crearMensajeContacto(Usuario* emisor, string numero) = 0;
	virtual Video* crearMensajeVideo(Usuario* emisor, string duracion, string URL) = 0;
	virtual Foto* crearMensajeImagen(Usuario* emisor, string imagen, string texto, string formato, string tamanio) = 0;

	virtual void enviarMensajeSimple(int idConv, string texto) = 0;
	virtual void enviarMensajeContacto(int idConv, string numero) = 0;
	virtual void enviarMensajeVideo(int idConv, string duracion, string URL) = 0;
	virtual void enviarMensajeImagen(int idConv, string imagen, string texto, string formato, string tamanio) = 0;
	
	virtual Grupo* crearGrupo(map<string, Usuario*> usrSel, string nombre, string imagen) = 0;
	virtual ConvSimple* crearConversacion(Usuario* usr1, Usuario* usr2) = 0;

	virtual bool esEmisor(Usuario* usr, int idConv, int idMsj) = 0;

	virtual list<DtMensaje*> mostrarMensajes(int id) = 0;

	virtual ~IConversacion(){};
};

#endif 