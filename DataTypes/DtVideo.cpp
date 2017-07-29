#include "DtVideo.h"

DtVideo::DtVideo(){}
DtVideo::DtVideo(int id, Fecha* fecha, string video, string duracion): DtMultimedia(id,fecha){
	this->video = video;
	this->duracion = duracion;
}

string DtVideo::getVideo(){
	return this->video;
}
//void setVideo(string video);

string DtVideo::getDuracion(){
	return this->duracion;
}
//void setDuracion(string duracion);
	
DtVideo::~DtVideo(){}
