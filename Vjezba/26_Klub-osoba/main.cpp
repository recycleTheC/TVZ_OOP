#include <iostream>
#include "Klub.h"

using namespace std;

void ispisOsobe(const Osoba& o) {
	cout << o.ime << " " << o.prezime << endl;
}

int main() {
	Klub* k1 = new Klub("TVZ", "Vrbik 8"); // dinamicki objekti
	Osoba* o1 = new Osoba("Marko", "Markic");
	
	k1->setTrener(*o1);

	Klub k2(*k1);
	k2.getTrener()->setIme("Ivo");

	cout << "k1: " << k1->getNaziv() << ", " << k1->getAdresa() << ", "; ispisOsobe(*k1->getTrener());
	cout << "k2: " << k2.getNaziv() << ", " << k2.getAdresa() << ", "; ispisOsobe(*k2.getTrener());
	
	delete o1;
	delete k1;

	return 0;
}