#ifndef DTVIDEO_H_
#define DTVIDEO_H_

#include <string>
#include "DtMultimedia.h"
#include "../DataTypes/Fecha.h"

using namespace std;

class DtVideo: public DtMultimedia {
	string video;
	string duracion;

public:

	DtVideo();
	DtVideo(int id, Fecha* fecha, string video, string duracion);

	string getVideo();
	//void setVideo(string video);

	string getDuracion();
	//void setDuracion(string duracion);
	
	~DtVideo();
	
};

#endif