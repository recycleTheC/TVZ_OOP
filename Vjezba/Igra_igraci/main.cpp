#include<iostream>
#include "Igrac.h"
#include "Igra.h"

int main() {

	Igrac igrac1("12345", true);
	Igrac igrac2("67890", false);
	Igrac igrac3("13571", false);
	Igrac igrac4("24680", true);
	Igrac igrac5("50459", false);

	cout << Igrac::brojPocetnika() << endl;

	Igra igra("Monopoly");

	try {
		igra.Dodaj(igrac1).Dodaj(igrac2);
		igra += igrac3;

		cout << "Broj igraca: " << (int)igra << endl;
		cout << igra << endl;

		igra += igrac1;
	}
	catch (IgracIznimka iznimka) {
		cout << iznimka.poruka();
	}

	return 0;
}