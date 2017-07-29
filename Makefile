tarea6: main.o
	g++ obj/*.o main.o -o tarea6
main.o: main.cpp DataTypes.o Clases.o Controladores.o Interfaces.o Fabrica.o
	g++ -c main.cpp -Wall
DataTypes.o: DataTypes/Cambios.h DataTypes/DtNotificacion.h DataTypes/DtContacto.h DataTypes/DtContacto.cpp DataTypes/DtConvSimple.h DataTypes/DtConvSimple.cpp DataTypes/DtConversacion.h DataTypes/DtConversacion.cpp DataTypes/DtConvsArchivadas.h DataTypes/DtConvsArchivadas.cpp DataTypes/DtFoto.h DataTypes/DtFoto.cpp DataTypes/DtGrupo.h DataTypes/DtGrupo.cpp DataTypes/DtInfoAdicional.h DataTypes/DtInfoAdicional.cpp DataTypes/DtMensaje.h DataTypes/DtMensaje.cpp DataTypes/DtMultimedia.h DataTypes/DtMultimedia.cpp DataTypes/DtSimple.h DataTypes/DtSimple.cpp DataTypes/DtUsuario.h DataTypes/DtUsuario.cpp DataTypes/DtVideo.h DataTypes/DtVideo.cpp DataTypes/DtVisto.h DataTypes/DtVisto.cpp DataTypes/Fecha.h DataTypes/Fecha.cpp DataTypes/estadoNum.h
	g++ -c DataTypes/Cambios.h -Wall
	g++ -c DataTypes/DtNotificacion.cpp -o obj/DtNotificacion.o -Wall
	g++ -c DataTypes/DtContacto.cpp -o obj/DtContacto.o -Wall
	g++ -c DataTypes/DtConvSimple.cpp -o obj/DtConvSimple.o -Wall
	g++ -c DataTypes/DtConversacion.cpp -o obj/DtConversacion.o -Wall
	g++ -c DataTypes/DtConvsArchivadas.cpp -o obj/DtConvsArchivadas.o -Wall
	g++ -c DataTypes/DtFoto.cpp -o obj/DtFoto.o -Wall
	g++ -c DataTypes/DtGrupo.cpp -o obj/DtGrupo.o -Wall
	g++ -c DataTypes/DtInfoAdicional.cpp -o obj/DtInfoAdicional.o -Wall
	g++ -c DataTypes/DtMensaje.cpp -o obj/DtMensaje.o -Wall
	g++ -c DataTypes/DtMultimedia.cpp -o obj/DtMultimedia.o -Wall
	g++ -c DataTypes/DtSimple.cpp -o obj/DtSimple.o -Wall
	g++ -c DataTypes/DtUsuario.cpp -o obj/DtUsuario.o -Wall
	g++ -c DataTypes/DtVideo.cpp -o obj/DtVideo.o -Wall
	g++ -c DataTypes/DtVisto.cpp -o obj/DtVisto.o -Wall
	g++ -c DataTypes/Fecha.cpp -o obj/Fecha.o -Wall
	g++ -c DataTypes/estadoNum.h -Wall
Clases.o: include/Contacto.h cpp/Contacto.cpp include/Conversacion.h cpp/Conversacion.cpp include/ConvSimple.h cpp/ConvSimple.cpp include/Estado.h cpp/Estado.cpp include/Foto.h cpp/Foto.cpp include/Grupo.h cpp/Grupo.cpp include/Mensaje.h cpp/Mensaje.cpp include/Multimedia.h cpp/Multimedia.cpp include/Notificacion.h cpp/Notificacion.cpp include/Simple.h cpp/Simple.cpp include/UserConv.h cpp/UserConv.cpp include/Usuario.h cpp/Usuario.cpp include/Video.h cpp/Video.cpp include/Visto.h cpp/Visto.cpp DataTypes.o
	g++ -c cpp/Contacto.cpp -o obj/Contacto.o -Wall
	g++ -c cpp/Conversacion.cpp -o obj/Conversacion.o -Wall
	g++ -c cpp/ConvSimple.cpp -o obj/ConvSimple.o -Wall
	g++ -c cpp/Estado.cpp -o obj/Estado.o -Wall
	g++ -c cpp/Foto.cpp -o obj/Foto.o -Wall
	g++ -c cpp/Grupo.cpp -o obj/Grupo.o -Wall
	g++ -c cpp/Mensaje.cpp -o obj/Mensaje.o -Wall
	g++ -c cpp/Multimedia.cpp -o obj/Multimedia.o -Wall
	g++ -c cpp/Notificacion.cpp -o obj/Notificacion.o -Wall
	g++ -c cpp/Simple.cpp -o obj/Simple.o -Wall
	g++ -c cpp/UserConv.cpp -o obj/UserConv.o -Wall
	g++ -c cpp/Usuario.cpp -o obj/Usuario.o -Wall
	g++ -c cpp/Video.cpp -o obj/Video.o -Wall
	g++ -c cpp/Visto.cpp -o obj/Visto.o -Wall
Interfaces.o: interfaces/*.h Clases.o DataTypes.o
	g++ -c interfaces/*.h
Controladores.o: controladores/ConvController.h controladores/ConvController.cpp controladores/UserController.h controladores/UserController.cpp Interfaces.o Clases.o DataTypes.o
	g++ -c controladores/ConvController.cpp -o obj/ConvController.o -Wall
	g++ -c controladores/UserController.cpp -o obj/UserController.o -Wall
Fabrica.o: fabrica/Fabrica.h fabrica/Fabrica.cpp Interfaces.o Controladores.o Clases.o DataTypes.o
	g++ -c fabrica/Fabrica.cpp -o obj/Fabrica.o
clean:
	-rm -f main.o
	-rm -f *.o
	-rm -f obj/*.o
	-rm -f DataTypes/*.o
	-rm -f DataTypes/*.gch
	-rm -f interfaces/*.gch
rebuild:
	make clean
	make
