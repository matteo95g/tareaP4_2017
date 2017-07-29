#ifndef CONVCONTROLLER_H_
#define CONVCONTROLLER_H_

#include <string>
#include <map>
#include <list>
#include "../include/Usuario.h"
#include "../include/Conversacion.h"
#include "../include/Mensaje.h"
#include "../include/Grupo.h"
#include "../include/ConvSimple.h"
#include "../include/Foto.h"

#include "../interfaces/IConversacion.h"
#include "../DataTypes/DtInfoAdicional.h"

#include "../DataTypes/DtSimple.h"
#include "../DataTypes/DtContacto.h"
#include "../DataTypes/DtVideo.h"
#include "../DataTypes/DtFoto.h"


#include "UserController.h"

using namespace std;

class ConvController : public IConversacion
{
	static ConvController* instancia;
	ConvController();
	int nroConv;
	int nroMsj;
	map<int, Conversacion*> convSis;
	Conversacion* convActual;

public:
	static ConvController* getInstancia();	
	
	void eliminarMensaje(int idConv, int idMsj);
	void borrarMensaje(Usuario* usr, int idConv, int idMsj);
	
	Simple* crearMensajeSimple(Usuario* emisor, string texto);
	Contacto* crearMensajeContacto(Usuario* emisor, string numero);
	Video* crearMensajeVideo(Usuario* emisor, string duracion, string URL);
	Foto* crearMensajeImagen(Usuario* emisor, string imagen, string texto, string formato, string tamanio);

	void enviarMensajeSimple(int idConv, string texto);
	void enviarMensajeContacto(int idConv, string numero);
	void enviarMensajeVideo(int idConv, string duracion, string URL);
	void enviarMensajeImagen(int idConv, string imagen, string texto, string formato, string tamanio);

	
	Grupo* crearGrupo(map<string, Usuario*> usrSel, string nombre, string imagen);
	ConvSimple* crearConversacion(Usuario* usr1, Usuario* usr2);
	
	void agregarAGrupo(string numero,Grupo* g );
	void quitarDeGrupo(string numero);
	
	list<DtMensaje*> mostrarMensajes(int id);
	list<DtInfoAdicional*> verInfoAdicional(int codigo, int idConv);

	bool esEmisor(Usuario* usr, int idConv, int idMsj);


	//int getNroConv();
	//void setNroConv();

	~ConvController();
};

#endif