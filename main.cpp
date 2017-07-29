#include <set>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include <iostream>
#include <unistd.h>

#include "DataTypes/Cambios.h"
#include "DataTypes/DtContacto.h"
#include "DataTypes/DtConvSimple.h"
#include "DataTypes/DtConversacion.h"
#include "DataTypes/DtConvsArchivadas.h"
#include "DataTypes/DtFoto.h"
#include "DataTypes/DtGrupo.h"
#include "DataTypes/DtInfoAdicional.h"
#include "DataTypes/DtMensaje.h"
#include "DataTypes/DtMultimedia.h"
#include "DataTypes/DtSimple.h"
#include "DataTypes/DtUsuario.h"
#include "DataTypes/DtVideo.h"
#include "DataTypes/DtVisto.h"
#include "DataTypes/Fecha.h"
#include "DataTypes/estadoNum.h"
#include "DataTypes/DtNotificacion.h"

#include "interfaces/IUsuario.h"
#include "interfaces/IConversacion.h"
#include "fabrica/Fabrica.h"

using namespace std;

Fecha* fechaGeneralSistema = new Fecha(0,0,0,0,0);

int main() {
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* usuarios = fabrica->getIUsuario();
	IConversacion* conversaciones = fabrica->getIConversacion();

	string enter;

	bool fin = false;
	int lect;

	while (!fin) {
		
		cout << "|================================================================|" << endl;
		cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
		cout << "|================================================================|" << endl;
		cout << "|                                                                |" << endl;
		cout << "|     1 -  Abrir GuasapFING                                      |" << endl;
		cout << "|     2 -  Agregar contactos                                     |" << endl;
		cout << "|     3 -  Alta grupo                                            |" << endl;
		cout << "|     4 -  Enviar mensajes                                       |" << endl;
		cout << "|     5 -  Ver mensajes                                          |" << endl;
		cout << "|     6 -  Archivar conversaciones                               |" << endl;
		cout << "|     7 -  Modificar usuario                                     |" << endl;
		cout << "|     8 -  Eliminar mensajes                                     |" << endl;
		cout << "|     9 -  Suscribirse                                           |" << endl;
		cout << "|     10 - Cerrar GuasapFING                                     |" << endl;
		cout << "|                                                                |" << endl;
		cout << "|     11 - Consultar Fecha                                       |" << endl;
		cout << "|     12 - Modificar Fecha                                       |" << endl;
		cout << "|                                                                |" << endl;
		cout << "|     13 - CARGAR DATOS                                          |" << endl;
		cout << "|                                                                |" << endl;
		cout << "|     0 -  EXIT                                                  |" << endl;
		cout << "|                                                                |" << endl;
		cout << "|================================================================|" << endl;
		cout << "      Sesion: " << usuarios->getNumSesion() << endl;
		cout << "|================================================================|" << endl;
		cout << endl;
		cin >> lect;
		system("clear");
		switch (lect) {
			case 0: {
				fin = true;
				break;
			
			}
			case 1: {
				ingresar:
				string numero;
				cout << "Ingrese su numero: ";
				cin >> numero;
				estadoNum est = usuarios->ingresarNumero(numero);
				switch (est) {
					case 0: {
						break;
					
					}
					case 1: {
						bool quiere = true;
						int lect1;
						while (quiere) {
							cout << "|================================================================|" << endl;
							cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
							cout << "|================================================================|" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     El numero no esta registrado.                              |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     1 - Ingresar otro numero                                   |" << endl;
							cout << "|     2 - Darse de alta                                          |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     0 - EXIT                                                   |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|================================================================|" << endl;
							cout << endl;
							cin >> lect1;
							system("clear");
							switch (lect1) {
								case 0: {
									usuarios->cancelar();
									quiere = false;
									fin = true;
									break;
								
								}
								case 1: {
									goto ingresar;
									break;
								
								}
								case 2: {
									quiere = false;
									string nombre, imagen, descripcion;
									cout << "Ingrese su nombre: ";
									cin.ignore();
									getline(cin,nombre);
									cout << "Ingrese su imagen: ";
									cin >> imagen;
									cout << "Ingrese su descripcion: ";
									cin.ignore();
									getline(cin,descripcion);
									usuarios->alta(nombre, imagen, descripcion);
									usuarios->iniciarSesion();
									system("clear");
									list<DtNotificacion*> notificaciones = usuarios->listarNotificaciones();
									list<DtNotificacion*>::iterator itNoti = notificaciones.begin();
									string cambio;
									cout << "|                          NOTIFICACIONES                        |" << endl;
									if (itNoti == notificaciones.end())
										cout << "|                             Ninguna                            |" << endl << endl;
									while (itNoti != notificaciones.end()){
										switch ((*itNoti)->getCambio()) {
											case 0: cambio = "Imagen"; break;
											case 1: cambio = "Descripcion"; break;
											case 2: cambio = "Nombre"; break;
										}
										cout << "|================================================================|" << endl;
										cout << "| Numero: " << (*itNoti)->getNumero() << " - ";
										cout << "Cambio: " << cambio << endl;
										cout << "| ";
										cout << (*itNoti)->getFecha()->getDia();
										cout << "/";
										cout << (*itNoti)->getFecha()->getMes();
										cout << "/";
										cout << (*itNoti)->getFecha()->getAnio();
										cout << "   -  ";
										cout << (*itNoti)->getFecha()->getHora();
										cout << ":";				
										cout << (*itNoti)->getFecha()->getMinuto() << endl;
										cout << "|================================================================|" << endl << endl;
										itNoti++;
									}
									break;
								
								}
							
							}
						}
						break;
					}
					case 2: {
						usuarios->iniciarSesion();
						list<DtNotificacion*> notificaciones = usuarios->listarNotificaciones();
						list<DtNotificacion*>::iterator itNoti = notificaciones.begin();
						string cambio;
						cout << "|                          NOTIFICACIONES                        |" << endl;
						if (itNoti == notificaciones.end())
							cout << "|                             Ninguna                            |" << endl << endl;
						while (itNoti != notificaciones.end()){
							switch ((*itNoti)->getCambio()) {
								case 0: cambio = "Imagen"; break;
								case 1: cambio = "Descripcion"; break;
								case 2: cambio = "Nombre"; break;
							}
							cout << "|================================================================|" << endl;
							cout << "| Numero: " << (*itNoti)->getNumero() << " - ";
							cout << "Cambio: " << cambio << endl;
							cout << "| ";
							cout << (*itNoti)->getFecha()->getDia();
							cout << "/";
							cout << (*itNoti)->getFecha()->getMes();
							cout << "/";
							cout << (*itNoti)->getFecha()->getAnio();
							cout << "   -  ";
							cout << (*itNoti)->getFecha()->getHora();
							cout << ":";				
							cout << (*itNoti)->getFecha()->getMinuto() << endl;
							cout << "|================================================================|" << endl << endl;
							itNoti++;
						}
						break;
					
					}
					case 3: {
						int lect1;
						cout << "|================================================================|" << endl;
						cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
						cout << "|================================================================|" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|     La sesion esta iniciada con otro numero                    |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|     1 - Cerrar GuasapFING                                      |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|     0 - EXIT                                                   |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|================================================================|" << endl;
						cout << endl;
						cin >> lect1;
						system("clear");
						if (lect1 == 1)
							usuarios->cerrarSesion();
						else
							fin = true;
						break;
					
					}
				
				}
				break;
			
			}
			case 2: {
				if (!(usuarios->haySesion())) {
					cout << "|================================================================|" << endl;
					cout << "|                  Primero debe iniciar sesion.                  |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				} else {
					string numero;
					int lect1;
					bool quiereAgregar = true;
					while (quiereAgregar) {
						list<DtUsuario*> contactos = usuarios->listarContactos();
						list<DtUsuario*>::iterator it = contactos.begin();
						cout << "|                           CONTACTOS                            |" << endl;
						while (it != contactos.end()) {
							cout << "|================================================================|" << endl;
							cout << "| Numero: " << (*it)->getNumero() << endl;
							cout << "| Nombre: " << (*it)->getNombre() << endl;
							cout << "| Imagen: " << (*it)->getImagen() << endl;
							cout << "|================================================================|" << endl << endl;
							it++;
						}
						cout << "|================================================================|" << endl;
						cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
						cout << "|================================================================|" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|     1 - Agregar contacto                                       |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|     0 - Volver                                                 |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|================================================================|" << endl << endl;
						cin >> lect1;
						system("clear");
						if (lect1 == 1) {
							cout << "Ingrese el numero del contacto: ";
							cin >> numero;
							bool usrReg = usuarios->usuarioRegistrado(numero);
							if (usrReg) {
								bool esCont = usuarios->esContacto(numero);
								if (esCont) {
									cout << "|================================================================|" << endl;
									cout << "|             Este usuario ya es su contacto.                    |" << endl;
									cout << "|================================================================|" << endl;
									cout << " Presione ENTER para continuar...";
									cin.ignore();
									getline(cin,enter);
									system("clear");
								} else {
									int elec;
									DtUsuario* confCont = usuarios->confirmarDatos(numero);
									cout << "|================================================================|" << endl;
									cout << "| Numero: " << confCont->getNumero() << endl;
									cout << "| Nombre: " << confCont->getNombre() << endl;
									cout << "| Imagen: " << confCont->getImagen() << endl;
									cout << "| Descripcion: " << confCont->getDescripcion() << endl;
									cout << "|================================================================|" << endl << endl;
									cout << "|================================================================|" << endl;
									cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
									cout << "|================================================================|" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|     Quiere confirmar este contacto?                            |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|     1 - SI                                                     |" << endl;
									cout << "|     2 - NO                                                     |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|                                                                |" << endl;
									cout << "|================================================================|" << endl << endl;
									cin >> elec;
									system("clear");
									if (elec == 1) {
										usuarios->agregarContacto(numero);
										cout << "|================================================================|" << endl;
										cout << "|               Contacto agregado exitosamente.                  |" << endl;
										cout << "|================================================================|" << endl;
										cout << " Presione ENTER para continuar...";
										cin.ignore();
										getline(cin,enter);
										system("clear");
									}
								}
							} else {
								cout << "|================================================================|" << endl;
								cout << "|             No existe un usuario con ese numero                |" << endl;
								cout << "|================================================================|" << endl;
								cout << " Presione ENTER para continuar...";
								cin.ignore();
								getline(cin,enter);
								system("clear");
							}
						} else {
							quiereAgregar = false;
						}
					}
					break;
				}
			}
			case 3: {
				if (!(usuarios->haySesion())) {
					cout << "|================================================================|" << endl;
					cout << "|                  Primero debe iniciar sesion.                  |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				} else {
					list<DtUsuario*> l = usuarios->listarContactos();
					if (!l.empty()){
						bool quiereModificar = true;
						map<string, DtUsuario*> contSelec;
						list<DtUsuario*> contRest;
						map<string, DtUsuario*>:: iterator itm;
						list<DtUsuario*>::iterator itl;
						while (quiereModificar) {
							int lect3;
							contRest = usuarios->listarContactosRest(contSelec);
							itm = contSelec.begin();
							itl = contRest.begin();
							cout << "|                      CONTACTOS SELECCIONADOS                   |" << endl;
							if (itm == contSelec.end())
								cout << "|                             Ninguno                            |" << endl << endl;
							while(itm != contSelec.end()){
								cout << "|================================================================|" << endl;
								cout << "| Nombre: " << itm->second->getNombre() << " - ";
								cout << "Numero: " << itm->second->getNumero() << endl;
								cout << "|================================================================|" << endl << endl;
								itm++;
							}

							cout << "|                    CONTACTOS NO SELECCIONADOS                  |" << endl;
							if (itl == contRest.end())
								cout << "|                             Ninguno                            |" << endl << endl;
							while (itl != contRest.end()){
								cout << "|================================================================|" << endl;
								cout << "| Nombre: " << (*itl)->getNombre() << " - ";
								cout << "Numero: " << (*itl)->getNumero() << endl;
								cout << "|================================================================|" << endl << endl;
								itl++;
							}
							cout << "|================================================================|" << endl;
							cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
							cout << "|================================================================|" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     Que desea hacer?                                           |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     1 - Agregar participante al grupo                          |" << endl;
							cout << "|     2 - Quitar participante del grupo                          |" << endl;
							cout << "|     3 - Crear el grupo                                         |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     0 - Volver                                                 |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|================================================================|" << endl << endl;
							cin >> lect3;
							switch(lect3){
								case 0: {
									quiereModificar = false;
									system("clear");
									break;
								}
								case 1: {
									string numero;
									cout << "Ingrese el numero del contacto: ";
									cin >> numero;
									DtUsuario* dtu = usuarios->confirmarDatos(numero);
									contSelec[numero] = dtu;
									system("clear");
									break;
								}
								case 2: {
									string numero;
									cout << "Ingrese el numero del contacto: ";
									cin >> numero;
									contSelec.erase(numero);
									system("clear");
									break;
								}
								case 3: {
									if (!contSelec.empty()){
										string nombre;
										string imagen;
										cout << "Ingrese el nombre del grupo: " << endl;
										cin.ignore();
										getline(cin,nombre);
										cout << "Ingrese la imagen del grupo: " << endl;
										cin >> imagen;
										usuarios->iniciarGrupo(contSelec, nombre, imagen);
										cout << "|================================================================|" << endl;
										cout << "|                  Grupo creado exitosamente.                    |" << endl;
										cout << "|================================================================|" << endl;
										cout << " Presione ENTER para continuar...";
										cin.ignore();
										getline(cin,enter);
										system("clear");
										quiereModificar = false;
									}else {
										cout << "|================================================================|" << endl;
										cout << "|            Debe seleccionar al menos un contacto.              |" << endl;
										cout << "|================================================================|" << endl;
										cout << " Presione ENTER para continuar...";
										cin.ignore();
										getline(cin,enter);
										system("clear");
									}
									break;
								}
							}
						}
						contSelec.clear();
						contRest.clear();
					} else {
						cout << "|================================================================|" << endl;
						cout << "|               No posee contactos para agregar.                 |" << endl;
						cout << "|================================================================|" << endl;
						cout << " Presione ENTER para continuar...";
						cin.ignore();
						getline(cin,enter);
						system("clear");
					}
					break;
				}
			}
			case 4: {
				if (!(usuarios->haySesion())) {
					cout << "|================================================================|" << endl;
					cout << "|                  Primero debe iniciar sesion.                  |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				} else {
					list<DtConversacion*> convers = usuarios->listarConversaciones();
					list<DtConversacion*>::iterator it = convers.begin();
					if (it == convers.end()){
						cout << "|================================================================|" << endl;
						cout << "|                  No existen conversaciones.                    |" << endl;
						cout << "|================================================================|" << endl;
						cout << " Presione ENTER para continuar...";
						cin.ignore();
						getline(cin,enter);
						system("clear");
						break;
					}
					while (it != convers.end()) {
						if (DtConvSimple *DtCoSimp = dynamic_cast<DtConvSimple *> (*it)) {
							map<string,DtUsuario*>::iterator iter = DtCoSimp->getParticipantes().begin();
							cout << "|================================================================|" << endl;
							cout << "| Id: " << (*it)->getId() << " - " << " - "; 
							cout << "Nombre: " << iter->second->getNombre() << " - ";
							cout << "Numero: " << iter->second->getNumero() << endl;
							cout << "|================================================================|" << endl << endl;
							
						} else if (DtGrupo *DtGrup = dynamic_cast<DtGrupo *> (*it)) {
							cout << "|================================================================|" << endl;
							cout << "| Id: " << (*it)->getId() << " - "; 
							cout << "Grupo: " << DtGrup->getNombre() << endl;
							cout << "|================================================================|" << endl << endl;

						} else if (DtConvsArchivadas *DtCoArch = dynamic_cast<DtConvsArchivadas *> (*it)) {
							cout << "|================================================================|" << endl;
							cout << "| Archivadas: " << DtCoArch->getCantidad() << endl;
							cout << "|================================================================|" << endl << endl;
						}
						it++;
					}
					cout << "|================================================================|" << endl;
					cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
					cout << "|================================================================|" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     Elija una conversacion:                                    |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     1 - Seleccionar una conversacion activa                    |" << endl;
					cout << "|     2 - Ver las conversaciones archivadas                      |" << endl;
					cout << "|     3 - Iniciar nueva conversacion                             |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     0 - Volver                                                 |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|================================================================|" << endl << endl;
					int elect;
					cin >> elect;
					switch(elect){
						case 0: {
							system("clear");
							break;
						}
						case 1: {
							cout << "Ingrese el id de la conversacion: ";
							int ideConv;
							cin >> ideConv;
							system("clear");
							cout << "|================================================================|" << endl;
							cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
							cout << "|================================================================|" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     Seleccione el tipo de mensaje a enviar:                    |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     1 - Simple                                                 |" << endl;
							cout << "|     2 - Imagen                                                 |" << endl;
							cout << "|     3 - Video                                                  |" << endl;
							cout << "|     4 - Contacto                                               |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     0 - Volver                                                 |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|================================================================|" << endl << endl;
							int opt;
							cin >> opt;
							switch(opt){
								case 0: {
									break;
								}
								case 1: {
									cout << "Ingrese el texto del mensaje: " << endl;
									string txt;
									cin.ignore();
									getline(cin,txt);
									conversaciones->enviarMensajeSimple(ideConv,txt);
									system("clear");
									break;
								}
								case 2: {
									string imagen;
									string formato;
									string texto;
									string tamanio;
									cout << "Ingrese la URL de la imagen: " << endl;
									cin >> imagen;
									cout << "Ingrese el texto de la imagen: " << endl;
									cin.ignore();
									getline(cin,texto);
									cout << "Ingrese el formato de la imagen: " << endl;
									cin >> formato;
									cout << "Ingrese el tamaño de la imagen: " << endl;
									cin >> tamanio;
									conversaciones->enviarMensajeImagen(ideConv, imagen, texto, formato, tamanio);
									system("clear");
									break;
								}
								case 3: {
									string video;
									string duracion;
									cout << "Ingrese la URL del video: " << endl;
									cin >> video;
									cout << "Ingrese la duracion del video: " << endl;
									cin >> duracion;
									conversaciones->enviarMensajeVideo(ideConv, duracion, video);
									system("clear");
									break;
								}
								case 4: {
									string num;
									list<DtUsuario*> contactos = usuarios->listarContactos();
									list<DtUsuario*>::iterator it = contactos.begin();
									cout << "|                           CONTACTOS                            |" << endl;
									while (it != contactos.end()) {
										cout << "|================================================================|" << endl;
										cout << "| Numero: " << (*it)->getNumero() << endl;
										cout << "| Nombre: " << (*it)->getNombre() << endl;
										cout << "|================================================================|" << endl << endl;
										it++;
									}
									cout << "Ingrese el numero del contacto que desea enviar:" << endl;
									cin >> num;
									conversaciones->enviarMensajeContacto(ideConv, num);
									system("clear");
									break;
								}
							}
							break;
						}
						case 2: {
							list<DtConversacion*> convers = usuarios->listarConversacionesArchivadas();
							list<DtConversacion*>::iterator it = convers.begin();
							if (it == convers.end()){
								cout << "|================================================================|" << endl;
								cout << "|             No existen conversaciones archivadas.              |" << endl;
								cout << "|================================================================|" << endl;
								cout << " Presione ENTER para continuar...";
								cin.ignore();
								getline(cin,enter);
								system("clear");
								break;
							}
							while (it != convers.end()) {
								if (DtConvSimple *DtCoSimp = dynamic_cast<DtConvSimple *> (*it)) {
									map<string,DtUsuario*>::iterator iter = DtCoSimp->getParticipantes().begin();
									cout << "|================================================================|" << endl;
									cout << "| Id: " << (*it)->getId() << " - " << " - "; 
									cout << "Nombre: " << iter->second->getNombre() << " - ";
									cout << "Numero: " << iter->second->getNumero() << endl;
									cout << "|================================================================|" << endl << endl;
									
								} else if (DtGrupo *DtGrup = dynamic_cast<DtGrupo *> (*it)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << (*it)->getId() << " - "; 
									cout << "Grupo: " << DtGrup->getNombre() << endl;
									cout << "|================================================================|" << endl << endl;

								}
								it++;
							}
							cout << "Ingrese el id de la conversacion: ";
							int ideConv;
							cin >> ideConv;
							system("clear");
							cout << "|================================================================|" << endl;
							cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
							cout << "|================================================================|" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     Seleccione el tipo de mensaje a enviar:                    |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     1 - Simple                                                 |" << endl;
							cout << "|     2 - Imagen                                                 |" << endl;
							cout << "|     3 - Video                                                  |" << endl;
							cout << "|     4 - Contacto                                               |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     0 - Volver                                                 |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|================================================================|" << endl << endl;
							int opt;
							cin >> opt;
							switch(opt){
								case 0: {
									break;
								}
								case 1: {
									cout << "Ingrese el texto del mensaje: " << endl;
									string txt;
									cin.ignore();
									getline(cin,txt);
									conversaciones->enviarMensajeSimple(ideConv,txt);
									usuarios->activarConversacion(ideConv);
									system("clear");
									break;
								}
								case 2: {
									string imagen;
									string formato;
									string texto;
									string tamanio;
									cout << "Ingrese la URL de la imagen: " << endl;
									cin >> imagen;
									cout << "Ingrese el texto de la imagen: " << endl;
									cin.ignore();
									getline(cin,texto);
									cout << "Ingrese el formato de la imagen: " << endl;
									cin >> formato;
									cout << "Ingrese el tamaño de la imagen: " << endl;
									cin >> tamanio;
									conversaciones->enviarMensajeImagen(ideConv, imagen, texto, formato, tamanio);
									usuarios->activarConversacion(ideConv);
									system("clear");
									break;
								}
								case 3: {
									string video;
									string duracion;
									cout << "Ingrese la URL del video: " << endl;
									cin >> video;
									cout << "Ingrese la duracion del video: " << endl;
									cin >> duracion;
									conversaciones->enviarMensajeVideo(ideConv, duracion, video);
									usuarios->activarConversacion(ideConv);
									system("clear");
									break;
								}
								case 4: {
									string num;
									list<DtUsuario*> contactos = usuarios->listarContactos();
									list<DtUsuario*>::iterator it = contactos.begin();
									cout << "|                           CONTACTOS                            |" << endl;
									while (it != contactos.end()) {
										cout << "|================================================================|" << endl;
										cout << "| Numero: " << (*it)->getNumero() << endl;
										cout << "| Nombre: " << (*it)->getNombre() << endl;
										cout << "|================================================================|" << endl << endl;
										it++;
									}
									cout << "Ingrese el numero del contacto que desea enviar:" << endl;
									cin >> num;
									conversaciones->enviarMensajeContacto(ideConv, num);									
									usuarios->activarConversacion(ideConv);
									system("clear");
									break;
								}
							}
							break;
						}
						case 3:{
							list<DtUsuario*> contactos = usuarios->listarContactos();
							list<DtUsuario*>::iterator it = contactos.begin();
							if (it == contactos.end()){
								cout << "|================================================================|" << endl;
								cout << "|                   No tiene ningun contacto.                    |" << endl;
								cout << "|================================================================|" << endl;
								cout << " Presione ENTER para continuar...";
								cin.ignore();
								getline(cin,enter);
								system("clear");
								break;
							}
							cout << "|                            CONTACTOS                           |" << endl;
							while (it != contactos.end()) {
								cout << "|================================================================|" << endl;
								cout << "| Numero: " << (*it)->getNumero() << endl;
								cout << "| Nombre: " << (*it)->getNombre() << endl;
								cout << "| Imagen: " << (*it)->getImagen() << endl;
								cout << "|================================================================|" << endl << endl;
								it++;
							}
							string numero;
							cout << "Ingrese el numero del contacto: " << endl;
							cin >> numero;
							if (!usuarios->esContacto(numero)) {
								cout << "|================================================================|" << endl;
								cout << "|                 Ese usuario no es su contacto                  |" << endl;
								cout << "|================================================================|" << endl;
								cout << " Presione ENTER para continuar...";
								cin.ignore();
								getline(cin,enter);
								system("clear");
								break;
							}
							system("clear");
							int ideNConv = usuarios->iniciarConversacion(numero);
							cout << "|================================================================|" << endl;
							cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
							cout << "|================================================================|" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     Seleccione el tipo de mensaje a enviar:                    |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     1 - Simple                                                 |" << endl;
							cout << "|     2 - Imagen                                                 |" << endl;
							cout << "|     3 - Video                                                  |" << endl;
							cout << "|     4 - Contacto                                               |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|     0 - Volver                                                 |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|                                                                |" << endl;
							cout << "|================================================================|" << endl << endl;
							int opt;
							cin >> opt;
							switch(opt){
								case 0: {
									break;
								}
								case 1: {
									cout << "Ingrese el texto del mensaje: " << endl;
									string txt;
									cin.ignore();
									getline(cin,txt);
									conversaciones->enviarMensajeSimple(ideNConv,txt);
									system("clear");
									break;
								}
								case 2: {
									string imagen;
									string formato;
									string texto;
									string tamanio;
									cout << "Ingrese la URL de la imagen: " << endl;
									cin >> imagen;
									cout << "Ingrese el texto de la imagen: " << endl;
									cin.ignore();
									getline(cin,texto);
									cout << "Ingrese el formato de la imagen: " << endl;
									cin >> formato;
									cout << "Ingrese el tamaño de la imagen: " << endl;
									cin >> tamanio;
									conversaciones->enviarMensajeImagen(ideNConv, imagen, texto, formato, tamanio);
									system("clear");
									break;
								}
								case 3: {
									string video;
									string duracion;
									cout << "Ingrese la URL del video: " << endl;
									cin >> video;
									cout << "Ingrese la duracion del video: " << endl;
									cin >> duracion;
									conversaciones->enviarMensajeVideo(ideNConv, duracion, video);
									system("clear");
									break;
								}
								case 4: {
									string num;
									list<DtUsuario*> contactos = usuarios->listarContactos();
									list<DtUsuario*>::iterator it = contactos.begin();
									cout << "|                           CONTACTOS                            |" << endl;
									while (it != contactos.end()) {
										cout << "|================================================================|" << endl;
										cout << "| Numero: " << (*it)->getNumero() << endl;
										cout << "| Nombre: " << (*it)->getNombre() << endl;
										cout << "|================================================================|" << endl << endl;
										it++;
									}
									cout << "Ingrese el numero del contacto que desea enviar:" << endl;
									cin >> num;
									conversaciones->enviarMensajeContacto(ideNConv, num);
									system("clear");
									break;
								}
							}
							break;
						}
					}			
				}
				break;
			}
			case 5: {
				if (!(usuarios->haySesion())) {
					cout << "|================================================================|" << endl;
					cout << "|                  Primero debe iniciar sesion.                  |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				} else {
					list<DtConversacion*> convers = usuarios->listarConversaciones();
					list<DtConversacion*>::iterator it = convers.begin();
					if (it == convers.end()){
						cout << "|================================================================|" << endl;
						cout << "|                  No existen conversaciones.                    |" << endl;
						cout << "|================================================================|" << endl;
						cout << " Presione ENTER para continuar...";
						cin.ignore();
						getline(cin,enter);
						system("clear");
						break;
					}
					while (it != convers.end()) {
						if (DtConvSimple *DtCoSimp = dynamic_cast<DtConvSimple *> (*it)) {
							map<string,DtUsuario*>::iterator iter = DtCoSimp->getParticipantes().begin();
							cout << "|================================================================|" << endl;
							cout << "| Id: " << (*it)->getId() << " - " << " - "; 
							cout << "Nombre: " << iter->second->getNombre() << " - ";
							cout << "Numero: " << iter->second->getNumero() << endl;
							cout << "|================================================================|" << endl << endl;
							
						} else if (DtGrupo *DtGrup = dynamic_cast<DtGrupo *> (*it)) {
							cout << "|================================================================|" << endl;
							cout << "| Id: " << (*it)->getId() << " - "; 
							cout << "Grupo: " << DtGrup->getNombre() << endl;
							cout << "|================================================================|" << endl << endl;

						} else if (DtConvsArchivadas *DtCoArch = dynamic_cast<DtConvsArchivadas *> (*it)) {
							cout << "|================================================================|" << endl;
							cout << "| Archivadas: " << DtCoArch->getCantidad() << endl;
							cout << "|================================================================|" << endl << endl;
						}
						it++;
					}
					cout << "|================================================================|" << endl;
					cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
					cout << "|================================================================|" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     Elija una conversacion:                                    |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     1 - Seleccionar una conversacion activa                    |" << endl;
					cout << "|     2 - Ver las conversaciones archivadas                      |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     0 - Volver                                                 |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|================================================================|" << endl << endl;
					int elect;
					cin >> elect;
					switch(elect) {
						case 0: {
							system("clear");
							break;
						}
						case 1: {
							cout << "Ingrese el id de la conversacion: ";
							int idConv;
							cin >> idConv;
							system("clear");
							bool quiera = true;
							while (quiera) {
								list<DtMensaje*> msjs = conversaciones->mostrarMensajes(idConv);
								list<DtMensaje*>::iterator it = msjs.begin();
								while (it != msjs.end()) {
									if (DtSimple *DtMeSimple = dynamic_cast<DtSimple *> (*it)) {
										cout << "|================================================================|" << endl;
										cout << "| Id: " << DtMeSimple->getId() << endl; 
										cout << "| "<< DtMeSimple->getTexto() << endl;
										cout << "|================================================================|" << endl << endl;
										
									} else if (DtFoto *DtFotela = dynamic_cast<DtFoto *> (*it)) {
										cout << "|================================================================|" << endl;
										cout << "| Id: " << (*it)->getId() << endl; 
										cout << "| Imagen: " << DtFotela->getImagen() << endl;
										cout << "| Formato: " << DtFotela->getFormato() << endl;
										cout << "| Tamaño: " << DtFotela->getTamanio() << endl;
										cout << "| Texto: " << DtFotela->getTexto() << endl;
										cout << "|================================================================|" << endl << endl;

									} else if (DtVideo *DtVid = dynamic_cast<DtVideo *> (*it)) {
										cout << "|================================================================|" << endl;
										cout << "| Id: " << DtVid->getId() << endl; 
										cout << "| Video: "<< DtVid->getVideo() << endl;
										cout << "| Duracion: "<< DtVid->getDuracion() << endl;
										cout << "|================================================================|" << endl << endl;
									} else if (DtContacto *DtCont = dynamic_cast<DtContacto *> (*it)) {
										cout << "|================================================================|" << endl;
										cout << "| Id: " << DtCont->getId() << endl; 
										cout << "| Nombre: "<< DtCont->getNombre() << endl;
										cout << "| Numero: "<< DtCont->getNumero() << endl;
										cout << "|================================================================|" << endl << endl;
									}
									it++;
								}
								cout << "|================================================================|" << endl;
								cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
								cout << "|================================================================|" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|    Desea ver informacion adicional de los mensajes enviados?   |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|     1 - SI                                                     |" << endl;
								cout << "|     2 - NO                                                     |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|================================================================|" << endl << endl;
								int elec2;
								cin >> elec2;
								switch(elec2) {
									case 1: {
										cout << "Ingrese id de un mensaje enviado" << endl;
										int idmsj;
										cin >> idmsj;
										system("clear");
										list<DtInfoAdicional*> infoMsj = conversaciones->verInfoAdicional(idmsj, idConv);
										list<DtInfoAdicional*>::iterator iter = infoMsj.begin();
										cout << "|============================ID:" << idmsj << "================================|" << endl;
										if (conversaciones->esEmisor(usuarios->getSesion(),idConv, idmsj)){
											while(iter != infoMsj.end()) {
												Fecha* fechaVisto = (*iter)->getFecha();
												cout << "|================================================================|" << endl;
												cout << "| Visto:                                                         |" << endl;
												cout << "| Nombre: "<< (*iter)->getNombre() << endl;
												cout << "| Numero: "<< (*iter)->getNumero() << endl;
												cout << "| ";
												cout << fechaVisto->getDia();
												cout << "/";
												cout << fechaVisto->getMes();
												cout << "/";
												cout << fechaVisto->getAnio();
												cout << "   -  ";
												cout << fechaVisto->getHora();
												cout << ":";				
												cout << fechaVisto->getMinuto() << endl;
												cout << "|================================================================|" << endl << endl;
												iter++;
											}
										}else{
											cout << "|================================================================|" << endl;
											cout << "|                Usted no envio este mensaje.                    |" << endl;
											cout << "|================================================================|" << endl;
											cout << " Presione ENTER para continuar...";
											cin.ignore();
											getline(cin,enter);
											system("clear");
										}
										break;
									}
									case 2: {
										quiera = false;
										system("clear");
										break;
									}
								}
							}
							break;
						} 
						case 2: {
							list<DtConversacion*> convers = usuarios->listarConversacionesArchivadas();
							list<DtConversacion*>::iterator it = convers.begin();
							if (it == convers.end()){
								cout << "|================================================================|" << endl;
								cout << "|             No existen conversaciones archivadas.              |" << endl;
								cout << "|================================================================|" << endl;
								cout << " Presione ENTER para continuar...";
								cin.ignore();
								getline(cin,enter);
								system("clear");
								break;
							}
							while (it != convers.end()) {
								if (DtConvSimple *DtCoSimp = dynamic_cast<DtConvSimple *> (*it)) {
									map<string,DtUsuario*>::iterator iter = DtCoSimp->getParticipantes().begin();
									cout << "|================================================================|" << endl;
									cout << "| Id : " << (*it)->getId() << " - " << " - "; 
									cout << "Nombre : " << iter->second->getNombre() << " - ";
									cout << "Numero : " << iter->second->getNumero() << endl;
									cout << "|================================================================|" << endl << endl;
									
								} else if (DtGrupo *DtGrup = dynamic_cast<DtGrupo *> (*it)) {
									cout << "|================================================================|" << endl;
									cout << "| Id : " << (*it)->getId() << " - "; 
									cout << "Grupo : " << DtGrup->getNombre() << endl;
									cout << "|================================================================|" << endl << endl;

								}
								it++;
							}
							cout << "Ingrese el id de la conversacion: ";
							int idConv;
							cin >> idConv;
							system("clear");
							bool quiera = true;
							while (quiera) {
								list<DtMensaje*> msjs = conversaciones->mostrarMensajes(idConv);
								list<DtMensaje*>::iterator it2 = msjs.begin();
								while (it2 != msjs.end()) {
									if (DtSimple *DtMeSimple = dynamic_cast<DtSimple *> (*it2)) {
										cout << "|================================================================|" << endl;
										cout << "| Id: " << DtMeSimple->getId() << endl; 
										cout << "| "<< DtMeSimple->getTexto() << endl;
										cout << "|================================================================|" << endl << endl;
										
									} else if (DtFoto *DtFotela = dynamic_cast<DtFoto *> (*it2)) {
										cout << "|================================================================|" << endl;
										cout << "| Id: " << (*it)->getId() << endl; 
										cout << "| Imagen: " << DtFotela->getImagen() << endl;
										cout << "| Formato: " << DtFotela->getFormato() << endl;
										cout << "| Tamaño: " << DtFotela->getTamanio() << endl;
										cout << "| Texto: " << DtFotela->getTexto() << endl;
										cout << "|================================================================|" << endl << endl;

									} else if (DtVideo *DtVid = dynamic_cast<DtVideo *> (*it2)) {
										cout << "|================================================================|" << endl;
										cout << "| Id: " << DtVid->getId() << endl; 
										cout << "| Video: "<< DtVid->getVideo() << endl;
										cout << "| Duracion: "<< DtVid->getDuracion() << endl;
										cout << "|================================================================|" << endl << endl;
									} else if (DtContacto *DtCont = dynamic_cast<DtContacto *> (*it2)) {
										cout << "|================================================================|" << endl;
										cout << "| Id: " << DtCont->getId() << endl; 
										cout << "| Nombre: "<< DtCont->getNombre() << endl;
										cout << "| Numero: "<< DtCont->getNumero() << endl;
										cout << "|================================================================|" << endl << endl;
									}
									it2++;
								}
								cout << "|================================================================|" << endl;
								cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
								cout << "|================================================================|" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|    Desea ver informacion adicional de los mensajes enviados?   |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|     1 - SI                                                     |" << endl;
								cout << "|     2 - NO                                                     |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|                                                                |" << endl;
								cout << "|================================================================|" << endl << endl;
								int elec2;
								cin >> elec2;
								switch(elec2) {
									case 1: {
										cout << "Ingrese id de un mensaje enviado: " << endl;
										int idmsj;
										cin >> idmsj;
										system("clear");
										list<DtInfoAdicional*> infoMsj = conversaciones->verInfoAdicional(idmsj, idConv);
										list<DtInfoAdicional*>::iterator iter = infoMsj.begin();
										cout << "|==========================ID:" << idmsj << "=================================|" << endl;
										if (conversaciones->esEmisor(usuarios->getSesion(),idConv, idmsj)){
											while(iter != infoMsj.end()) {
												Fecha* fechaVisto = (*iter)->getFecha();
												cout << "|================================================================|" << endl;
												cout << "| Visto:                                                         |" << endl;
												cout << "| Nombre: "<< (*iter)->getNombre() << endl;
												cout << "| Numero: "<< (*iter)->getNumero() << endl;
												cout << "| ";
												cout << fechaVisto->getDia();
												cout << "/";
												cout << fechaVisto->getMes();
												cout << "/";
												cout << fechaVisto->getAnio();
												cout << "   -  ";
												cout << fechaVisto->getHora();
												cout << ":";				
												cout << fechaVisto->getMinuto() << endl;
												cout << "|================================================================|" << endl << endl;
												iter++;
											}
											cout << " Presione ENTER para continuar...";
											cin.ignore();
											getline(cin,enter);
											system("clear");
										}else{
											cout << "|================================================================|" << endl;
											cout << "|                Usted no envio este mensaje.                    |" << endl;
											cout << "|================================================================|" << endl;
											cout << " Presione ENTER para continuar...";
											cin.ignore();
											getline(cin,enter);
											system("clear");
										}
										break;
									}
									case 2: {
										quiera = false;
										system("clear");
										break;
									}
								}
							}
						break;
						}
					}
				}
				break;
			}
			case 6: {
				if (!(usuarios->haySesion())) {
					cout << "|================================================================|" << endl;
					cout << "|                  Primero debe iniciar sesion.                  |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				} else {
					bool quiere = true;
					while(quiere){
						list<DtConversacion*> convers = usuarios->listarConversaciones();
						convers.pop_back();
						list<DtConversacion*>::iterator it = convers.begin();
						if (it == convers.end()){
							cout << "|================================================================|" << endl;
							cout << "|              No existen conversaciones activas.                |" << endl;
							cout << "|================================================================|" << endl;
							cout << " Presione ENTER para continuar...";
							cin.ignore();
							getline(cin,enter);
							quiere = false;
							system("clear");
							break;
						}
						while (it != convers.end()) {
							if (DtConvSimple *DtCoSimp = dynamic_cast<DtConvSimple *> (*it)) {
								map<string,DtUsuario*>::iterator iter = DtCoSimp->getParticipantes().begin();
								cout << "|================================================================|" << endl;
								cout << "| Id: " << (*it)->getId() << " - " << " - "; 
								cout << "Nombre: " << iter->second->getNombre() << " - ";
								cout << "Numero: " << iter->second->getNumero() << endl;
								cout << "|================================================================|" << endl << endl;
								
							} else if (DtGrupo *DtGrup = dynamic_cast<DtGrupo *> (*it)) {
								cout << "|================================================================|" << endl;
								cout << "| Id: " << (*it)->getId() << " - "; 
								cout << "Grupo: " << DtGrup->getNombre() << endl;
								cout << "|================================================================|" << endl << endl;
							}
							it++;
						}
						int elec;
						cout << "|================================================================|" << endl;
						cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
						cout << "|================================================================|" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|    Que desea hacer?                                            |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|     1 - Archivar conversacion                                  |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|     0 - Cancelar                                               |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|                                                                |" << endl;
						cout << "|================================================================|" << endl << endl;
						cin >> elec;
						switch(elec){
							case 0:{
								quiere = false;
								system("clear");
								break;
							}
							case 1:{
								int nro;
								cout << "Ingrese el id de la conversacion a archivar: ";
								cin >> nro;
								usuarios->archivarConversacion(nro);
								system("clear");
								break;
							}
						}
					}
				}
				break;
			}
			case 7: {
				if (!(usuarios->haySesion())) {
					cout << "|================================================================|" << endl;
					cout << "|                  Primero debe iniciar sesion.                  |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				} else {
					cout << "|================================================================|" << endl;
					cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
					cout << "|================================================================|" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     Que quiere modificar?                                      |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     1 - Nombre                                                 |" << endl;
					cout << "|     2 - Imagen                                                 |" << endl;
					cout << "|     3 - Descripcion                                            |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     0 - Volver                                                 |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|================================================================|" << endl << endl;
					int elec3;
					cin >> elec3;
					switch (elec3) {
						case 0: {
							break;
						}
						case 1: {
							cout << "Ingrese el nuevo nombre: ";
							string nombre;
							cin.ignore();
							getline(cin,nombre);
							usuarios->modificarNombre(nombre);
							usuarios->notificar(Nombre, fechaGeneralSistema);
							system("clear");
							break;
						}
						case 2: {
							cout << "Ingrese la nueva imagen: ";
							string imagen;
							cin.ignore();
							getline(cin,imagen);
							usuarios->modificarImagen(imagen);
							usuarios->notificar(Imagen, fechaGeneralSistema);
							system("clear");
							break;
						}
						case 3: {
							cout << "Ingrese la nueva descripcion: ";
							string descripcion;
							cin.ignore();
							getline(cin,descripcion);
							usuarios->modificarDescripcion(descripcion);
							usuarios->notificar(Descripcion, fechaGeneralSistema);
							system("clear");
							break;
						}
					}
					cout << "|================================================================|" << endl;
					cout << "|                Datos modificados exitosamente.                 |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				}
			}
			case 8: {
				if (!(usuarios->haySesion())) {
					cout << "|================================================================|" << endl;
					cout << "|                  Primero debe iniciar sesion.                  |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				} else {
					list<DtConversacion*> convers = usuarios->listarConversaciones();
					list<DtConversacion*>::iterator it = convers.begin();
					if (it == convers.end()){
						cout << "|================================================================|" << endl;
						cout << "|                  No existen conversaciones.                    |" << endl;
						cout << "|================================================================|" << endl;
						cout << " Presione ENTER para continuar...";
						cin.ignore();
						getline(cin,enter);
						system("clear");
						break;
					}
					while (it != convers.end()) {
						if (DtConvSimple *DtCoSimp = dynamic_cast<DtConvSimple *> (*it)) {
							map<string,DtUsuario*>::iterator iter = DtCoSimp->getParticipantes().begin();
							cout << "|================================================================|" << endl;
							cout << "| Id: " << (*it)->getId() << " - " << " - "; 
							cout << "Nombre: " << iter->second->getNombre() << " - ";
							cout << "Numero: " << iter->second->getNumero() << endl;
							cout << "|================================================================|" << endl << endl;
							
						} else if (DtGrupo *DtGrup = dynamic_cast<DtGrupo *> (*it)) {
							cout << "|================================================================|" << endl;
							cout << "| Id: " << (*it)->getId() << " - "; 
							cout << "Grupo: " << DtGrup->getNombre() << endl;
							cout << "|================================================================|" << endl << endl;

						} else if (DtConvsArchivadas *DtCoArch = dynamic_cast<DtConvsArchivadas *> (*it)) {
							cout << "|================================================================|" << endl;
							cout << "| Archivadas: " << DtCoArch->getCantidad() << endl;
							cout << "|================================================================|" << endl << endl;
						}
						it++;
					}
					cout << "|================================================================|" << endl;
					cout << "|                    Programacion 4 - Grupo 2                    |" << endl;
					cout << "|================================================================|" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     Elija una conversacion:                                    |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     1 - Seleccionar una conversacion activa                    |" << endl;
					cout << "|     2 - Ver las conversaciones archivadas                      |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|     0 - Volver                                                 |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|                                                                |" << endl;
					cout << "|================================================================|" << endl << endl;
					int elect;
					cin >> elect;
					switch(elect) {
						case 0: {
							system("clear");
							break;
						}
						case 1: {
							cout << "Ingrese el id de la conversacion: ";
							int idConv;
							cin >> idConv;
							system("clear");
							list<DtMensaje*> msjs = conversaciones->mostrarMensajes(idConv);
							list<DtMensaje*>::iterator it = msjs.begin();
							while (it != msjs.end()) {
								if (DtSimple *DtMeSimple = dynamic_cast<DtSimple *> (*it)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << DtMeSimple->getId() << endl; 
									cout << "| "<< DtMeSimple->getTexto() << endl;
									cout << "|================================================================|" << endl << endl;
									
								} else if (DtFoto *DtFotela = dynamic_cast<DtFoto *> (*it)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << (*it)->getId() << endl; 
									cout << "| Imagen: " << DtFotela->getImagen() << endl;
									cout << "| Formato: " << DtFotela->getFormato() << endl;
									cout << "| Tamaño: " << DtFotela->getTamanio() << endl;
									cout << "| Texto: " << DtFotela->getTexto() << endl;
									cout << "|================================================================|" << endl << endl;

								} else if (DtVideo *DtVid = dynamic_cast<DtVideo *> (*it)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << DtVid->getId() << endl; 
									cout << "| Video: "<< DtVid->getVideo() << endl;
									cout << "| Duracion: "<< DtVid->getDuracion() << endl;
									cout << "|================================================================|" << endl << endl;
								} else if (DtContacto *DtCont = dynamic_cast<DtContacto *> (*it)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << DtCont->getId() << endl; 
									cout << "| Nombre: "<< DtCont->getNombre() << endl;
									cout << "| Numero: "<< DtCont->getNumero() << endl;
									cout << "|================================================================|" << endl << endl;
								}
								it++;
							}
							cout << "Ingrese el id del mensaje a eliminar: ";
							int idMens;
							cin >> idMens;
							system("clear");
							usuarios->eliminarMensaje(idConv, idMens);
							cout << "|================================================================|" << endl;
							cout << "|           El mensaje ha sido eliminado con exito.              |" << endl;
							cout << "|================================================================|" << endl;
							cout << " Presione ENTER para continuar...";
							cin.ignore();
							getline(cin,enter);
							system("clear");
							break;
						}
						case 2: {
							list<DtConversacion*> convers = usuarios->listarConversacionesArchivadas();
							list<DtConversacion*>::iterator it = convers.begin();
							if (it == convers.end()){
								cout << "|================================================================|" << endl;
								cout << "|             No existen conversaciones archivadas.              |" << endl;
								cout << "|================================================================|" << endl;
								cout << " Presione ENTER para continuar...";
								cin.ignore();
								getline(cin,enter);
								system("clear");
								break;
							}
							while (it != convers.end()) {
								if (DtConvSimple *DtCoSimp = dynamic_cast<DtConvSimple *> (*it)) {
									map<string,DtUsuario*>::iterator iter = DtCoSimp->getParticipantes().begin();
									cout << "|================================================================|" << endl;
									cout << "| Id : " << (*it)->getId() << " - " << " - "; 
									cout << "Nombre : " << iter->second->getNombre() << " - ";
									cout << "Numero : " << iter->second->getNumero() << endl;
									cout << "|================================================================|" << endl << endl;
									
								} else if (DtGrupo *DtGrup = dynamic_cast<DtGrupo *> (*it)) {
									cout << "|================================================================|" << endl;
									cout << "| Id : " << (*it)->getId() << " - "; 
									cout << "Grupo : " << DtGrup->getNombre() << endl;
									cout << "|================================================================|" << endl << endl;

								}
								it++;
							}
							cout << "Ingrese el id de la conversacion: ";
							int idConv;
							cin >> idConv;
							system("clear");
							list<DtMensaje*> msjs = conversaciones->mostrarMensajes(idConv);
							list<DtMensaje*>::iterator it2 = msjs.begin();
							while (it2 != msjs.end()) {
								if (DtSimple *DtMeSimple = dynamic_cast<DtSimple *> (*it2)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << DtMeSimple->getId() << endl; 
									cout << "| "<< DtMeSimple->getTexto() << endl;
									cout << "|================================================================|" << endl << endl;
									
								} else if (DtFoto *DtFotela = dynamic_cast<DtFoto *> (*it2)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << (*it)->getId() << endl; 
									cout << "| Imagen: " << DtFotela->getImagen() << endl;
									cout << "| Formato: " << DtFotela->getFormato() << endl;
									cout << "| Tamaño: " << DtFotela->getTamanio() << endl;
									cout << "| Texto: " << DtFotela->getTexto() << endl;
									cout << "|================================================================|" << endl << endl;

								} else if (DtVideo *DtVid = dynamic_cast<DtVideo *> (*it2)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << DtVid->getId() << endl; 
									cout << "| Video: "<< DtVid->getVideo() << endl;
									cout << "| Duracion: "<< DtVid->getDuracion() << endl;
									cout << "|================================================================|" << endl << endl;
								} else if (DtContacto *DtCont = dynamic_cast<DtContacto *> (*it2)) {
									cout << "|================================================================|" << endl;
									cout << "| Id: " << DtCont->getId() << endl; 
									cout << "| Nombre: "<< DtCont->getNombre() << endl;
									cout << "| Numero: "<< DtCont->getNumero() << endl;
									cout << "|================================================================|" << endl << endl;
								}
								it2++;
							}
							cout << "Ingrese el id del mensaje a eliminar: ";
							int idMens;
							cin >> idMens;
							system("clear");
							usuarios->eliminarMensaje(idConv, idMens);
							cout << "|================================================================|" << endl;
							cout << "|           El mensaje ha sido eliminado con exito.              |" << endl;
							cout << "|================================================================|" << endl;
							cout << " Presione ENTER para continuar...";
							cin.ignore();
							getline(cin,enter);
							system("clear");
							break;
						}
					}
					break;
				}
			}
			case 9: {
				if (!(usuarios->haySesion())) {
					cout << "|================================================================|" << endl;
					cout << "|                  Primero debe iniciar sesion.                  |" << endl;
					cout << "|================================================================|" << endl;
					cout << " Presione ENTER para continuar...";
					cin.ignore();
					getline(cin,enter);
					system("clear");
					break;
				} else {
					list<DtUsuario*> contactos = usuarios->listarContactos();
					list<DtUsuario*>::iterator it = contactos.begin();
					cout << "|                           CONTACTOS                            |" << endl;
					while (it != contactos.end()) {
						cout << "|================================================================|" << endl;
						cout << "| Numero: " << (*it)->getNumero() << endl;
						cout << "| Nombre: " << (*it)->getNombre() << endl;
						cout << "| Imagen: " << (*it)->getImagen() << endl;
						cout << "|================================================================|" << endl << endl;
						it++;
					}
					cout << "Ingrese el numero del contacto al que desea suscribirse: ";
					string cont;
					cin >> cont;
					system("clear");
					if (usuarios->esContacto(cont)) {
						if (usuarios->suscripto(cont)) {
							cout << "|================================================================|" << endl;
							cout << "|               Ya esta suscripto a este usuario.                |" << endl;
							cout << "|================================================================|" << endl;
							cout << " Presione ENTER para continuar...";
							cin.ignore();
							getline(cin,enter);
							system("clear");
						} else {
							usuarios->suscribirse(cont);
							cout << "|================================================================|" << endl;
							cout << "|                Se ha suscripto exitosamente.                   |" << endl;
							cout << "|================================================================|" << endl;
							cout << " Presione ENTER para continuar...";
							cin.ignore();
							getline(cin,enter);
							system("clear");
						}
					} else {
						cout << "|================================================================|" << endl;
						cout << "|         Este numero no pertenece a ningun contacto             |" << endl;
						cout << "|================================================================|" << endl;
						cout << " Presione ENTER para continuar...";
						cin.ignore();
						getline(cin,enter);
						system("clear");
					}
					break;
				}
			}
			case 10: {
				usuarios->cerrarSesion();
				system("clear");
				break;
			}
			case 11: {
				cout << "|================================================================|" << endl;
				cout << "|                    La fecha y hora actual es:                  |" << endl;
				cout << "|                                                                |" << endl;
				cout << "|                      ";
				cout << fechaGeneralSistema->getDia();
				cout << "/";
				cout << fechaGeneralSistema->getMes();
				cout << "/";
				cout << fechaGeneralSistema->getAnio();
				cout << "   -  ";
				cout << fechaGeneralSistema->getHora();
				cout << ":";				
				cout << fechaGeneralSistema->getMinuto();
				cout << "                      |" << endl;
				cout << "|================================================================|" << endl << endl;
				break;
			}
			case 12: {
				int anio, mes, dia, hora, minuto;
				cout << "Ingrese el año: ";
				cin >> anio;
				cout << "Ingrese el mes: ";
				cin >> mes;
				cout << "Ingrese el dia: ";
				cin >> dia;
				cout << "Ingrese la hora: ";
				cin >> hora;
				cout << "Ingrese el minuto: ";
				cin >> minuto;
				fechaGeneralSistema->setFecha(anio, mes, dia, hora, minuto);
				system("clear");
				break;
			}
			case 13: {
				usuarios->ingresarNumero("090123654");
				usuarios->alta("Juan Perez", "home/img/perfil/juan.png", "Amo usar Guasap");
				usuarios->ingresarNumero("090765432");
				usuarios->alta("Maria Fernandez", "home/img/perfil/maria.png", "Me encanta P4");
				usuarios->ingresarNumero("090246810");
				usuarios->alta("Pablo Iglesias", "home/img/perfil/pablo.png", "Me gustan los animales");
				usuarios->ingresarNumero("090666777");
				usuarios->alta("Sara Ruiz", "home/img/perfil/sara.png", "Estoy feliz!");

				usuarios->ingresarNumero("090123654");
				usuarios->iniciarSesion();
				usuarios->agregarContacto("090765432");
				usuarios->agregarContacto("090246810");
				usuarios->agregarContacto("090666777");
				usuarios->cerrarSesion();

				usuarios->ingresarNumero("090765432");
				usuarios->iniciarSesion();
				usuarios->agregarContacto("090123654");
				usuarios->agregarContacto("090246810");
				usuarios->cerrarSesion();

				usuarios->ingresarNumero("090246810");
				usuarios->iniciarSesion();
				usuarios->agregarContacto("090765432");
				usuarios->agregarContacto("090123654");
				usuarios->agregarContacto("090666777");
				usuarios->cerrarSesion();

				usuarios->ingresarNumero("090666777");
				usuarios->iniciarSesion();
				usuarios->agregarContacto("090123654");
				usuarios->agregarContacto("090246810");
				usuarios->cerrarSesion();

				usuarios->ingresarNumero("090123654");
				usuarios->iniciarSesion();
				map<string, DtUsuario*> participantes;
				DtUsuario* usr1 = usuarios->confirmarDatos("090123654");
				DtUsuario* usr2 = usuarios->confirmarDatos("090765432");
				DtUsuario* usr3 = usuarios->confirmarDatos("090246810");
				DtUsuario* usr4 = usuarios->confirmarDatos("090666777");
				participantes["090123654"] = usr1;
				participantes["090765432"] = usr2;
				participantes["090246810"] = usr3;
				participantes["090666777"] = usr4;

				fechaGeneralSistema->setFecha(2017, 05, 22, 15, 35);

				int g1 = usuarios->iniciarGrupo(participantes, "Amigos", "home/img/amigos.png");

				usuarios->ingresarNumero("090123654");
				usuarios->iniciarSesion();
				int cs2 = usuarios->iniciarConversacion("090765432");

				usuarios->ingresarNumero("090246810");
				usuarios->iniciarSesion();
				int cs3 = usuarios->iniciarConversacion("090666777");

				usuarios->ingresarNumero("090666777");
				usuarios->iniciarSesion();

				//mensajes del U4
				fechaGeneralSistema->setFecha(2017, 05, 22, 18, 04);
				conversaciones->enviarMensajeSimple(g1,  "Miren que bueno este video!");
				fechaGeneralSistema->setFecha(2017, 05, 22, 18, 05);
				conversaciones->enviarMensajeVideo(g1, "05 min" , "video/videogracioso.vid");
				fechaGeneralSistema->setFecha(2017, 05, 23, 18, 30);
				conversaciones->enviarMensajeSimple(cs3,  "Hola Pablo, como estas?");

				//mensajes de U1
				fechaGeneralSistema->setFecha(2017, 05, 22, 18, 12);
				usuarios->ingresarNumero("090123654");
				usuarios->iniciarSesion();
				conversaciones->enviarMensajeSimple(g1,  "Muy gracioso!");


				

				//conv u1 u2
				usuarios->ingresarNumero("090765432");
				usuarios->iniciarSesion();
				fechaGeneralSistema->setFecha(2017, 05, 22, 18, 23);
				conversaciones->enviarMensajeSimple(cs2,  "Hola, me pasas el contacto de Sara que no lo tengo");

				usuarios->ingresarNumero("090123654");
				usuarios->iniciarSesion();
				fechaGeneralSistema->setFecha(2017, 05, 23, 12, 25);
				conversaciones->enviarMensajeContacto(cs2, "090666777");


				usuarios->ingresarNumero("090765432");
				usuarios->iniciarSesion();
				fechaGeneralSistema->setFecha(2017, 05, 23, 12, 26);
				conversaciones->enviarMensajeSimple(cs2,  "Gracias");

				// mensajes del U3
				usuarios->ingresarNumero("090246810");
				usuarios->iniciarSesion();
				usuarios->suscribirse("090123654");

				fechaGeneralSistema->setFecha(2017, 05, 22, 18, 13);
				conversaciones->enviarMensajeSimple(g1,  "Excelente!");
				//visto por u3
				conversaciones->mostrarMensajes(g1);
				conversaciones->mostrarMensajes(cs3);

				//visto por u4
				usuarios->ingresarNumero("090666777");
				usuarios->iniciarSesion();
				conversaciones->mostrarMensajes(g1);

				//visto por u1
				usuarios->ingresarNumero("090123654");
				usuarios->iniciarSesion();
				conversaciones->mostrarMensajes(g1);
				conversaciones->mostrarMensajes(cs2);
				usuarios->suscribirse("090765432");
				

				//visto por u2
				usuarios->ingresarNumero("090765432");
				usuarios->iniciarSesion();
				conversaciones->mostrarMensajes(cs2);
				usuarios->suscribirse("090123654");

				usuarios->cerrarSesion();
				cout << "|================================================================|" << endl;
				cout << "|                 Datos cargados exitosamente.                   |" << endl;
				cout << "|================================================================|" << endl;
				cout << " Presione ENTER para continuar...";
				cin.ignore();
				getline(cin,enter);
				system("clear");
				break;
			}
		
		}
	
	}
	return 0;
}