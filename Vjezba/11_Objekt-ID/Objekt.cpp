#include "Objekt.h"

Objekt::Objekt() {
	_instance++;
	_zadnjiID++;

	ID = _zadnjiID;
}

Objekt::~Objekt() {
	_instance--;
}

int Objekt::BrojInstanci() {
	return _instance;
}