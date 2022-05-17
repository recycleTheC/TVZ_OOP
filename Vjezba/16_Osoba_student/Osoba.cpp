#include "Osoba.h"

Osoba::Osoba(string oib) {
	this->oib = oib;
}

void Osoba::RadniStatus() const {
	cout << "Osoba nema radni status" << endl;
}