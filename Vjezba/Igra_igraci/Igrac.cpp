#include "Igrac.h"

Igrac::Igrac(string id, bool pocetnik) {
	this->id = id;
	this->pocetnik = pocetnik;

	_instance++;
	if (pocetnik) _pocetnici++;
}

int Igrac::brojPocetnika() {
	return _pocetnici;
}