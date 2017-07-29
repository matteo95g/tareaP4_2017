#ifndef VIDEO_H_
#define VIDEO_H_

#include <string>
#include "Multimedia.h"

using namespace std;

class Video : public Multimedia
{
	string video;
	string duracion;
public:
	Video();
	Video(int id, Fecha* fecha, Usuario* emisor, string video, string duracion);

	string getVideo() const;
	void setVideo(string video);

	string getDuracion() const;
	void setDuracion(string duracion);

	~Video();
};

#endif