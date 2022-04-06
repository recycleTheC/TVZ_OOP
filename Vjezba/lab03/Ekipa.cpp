#include"Ekipa.h"

Ekipa::Ekipa() {}
Ekipa::~Ekipa() {}

string Ekipa::getNaziv() const {
	return naziv;
}

Igrac& Ekipa::getIgrac(int i) {
	return igraci[i];
}

Igrac& Ekipa::getNajskuplji() {
	int max = 0;

	for (int i = 0; i < igraci.size(); i++)
	{
		if (igraci[max].getTrzisnaCijena() < igraci[i].getTrzisnaCijena()) {
			max = i;
		}
	}

	return igraci[max];
}

bool test(Igrac& a, Igrac& b) {
	return a.getBrojDresa() < b.getBrojDresa();
}

void Ekipa::ispisi() {
	sort(igraci.begin(), igraci.end(), test);

	cout << "Ekipa: '" << naziv << "'" << endl;

	for (int i = 0; i < igraci.size(); i++)
	{
		cout << igraci[i].ispisi() << endl;
	}

	cout << endl;
}

double Ekipa::ukupnaCijena() const {
	double total = 0;

	for (int i = 0; i < igraci.size(); i++)
	{
		total += igraci[i].getTrzisnaCijena();
	}

	return total;
}

double Ekipa::prosjecnaCijena() const {
	int n = igraci.size();

	if (n != 0) {
		double vrijednost = 0;

		for (int i = 0; i < n; i++)
		{
			vrijednost += igraci[i].getTrzisnaCijena();
		}

		return vrijednost / n;
	}
	else {
		return 0;
	}
}

void Ekipa::dodajIgraca(Igrac igrac) {
	igraci.push_back(igrac);
}

void Ekipa::setNaziv(string naziv) {
	this->naziv = naziv;
}