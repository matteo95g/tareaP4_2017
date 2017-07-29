#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>
#include "../include/Usuario.h"

using namespace std;

class Observer: public Usuario
{
public:
	Observer();
	~Observer();
	void notificar();
	
};

#endif