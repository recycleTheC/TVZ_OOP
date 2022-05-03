#pragma once

#include<vector>
#include "Igrac.h"
#include "IgracIznimka.h"

using namespace std;

class Igra {
public:
	vector<Igrac> igraci;
	string naziv;

	Igra(string ime);

	Igra& Dodaj(Igrac i) throw(IgracIznimka);
	void operator += (Igrac ig) throw(IgracIznimka);
	operator int();
};

ostream& operator << (ostream& izlaz, const Igra& igra);