#include "../include/Video.h"

Video::Video(int id, Fecha* fecha, Usuario* emisor, string video, string duracion) : Multimedia(id, fecha, emisor) {
	this->video = video;
	this->duracion = duracion;
}

string Video::getVideo() const {
	return video;
}

void Video::setVideo(string video) {
	this->video = video;
}

string Video::getDuracion() const {
	return duracion;
}

void Video::setDuracion(string duracion) {
	this->duracion = duracion;
}

Video::~Video(){}