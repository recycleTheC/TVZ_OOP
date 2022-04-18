#include "Slika.h"

Slika::Slika(double iznos) {
	cijena = iznos;

	_instance++;
	_total += iznos;
}

Slika::~Slika() {
	_instance--;
	_total -= cijena;
}

double Slika::ProsjecnaCijena() {
	return _total / _instance;
}