#include <iostream>
#include <string>
#include "Osoba.h"

using namespace std;

class Klub {
private:
	string naziv, adresa;
	Osoba* trener;
public:
	Klub();
	Klub(string naziv, string adresa);
	~Klub();
	Klub(const Klub& klub);
	Klub& operator = (const Klub& klub);

	string getNaziv() const;
	string getAdresa() const;
	Osoba* getTrener() const;

	void setNaziv(string naziv);
	void setAdresa(string adresa);
	void setTrener(Osoba& trener);
};

