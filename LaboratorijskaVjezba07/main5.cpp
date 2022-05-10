#include<iostream>
#include<vector>

using namespace std;

class Proizvod {
protected:
	string naziv;
	double cijena = 0;
public:
	Proizvod(string naziv, double cijena) {
		this->naziv = naziv;
		this->cijena = cijena;
	}

	string getNaziv() const { return this->naziv; }
	double getCijena() const { return this->cijena; }

	virtual double getKoefKvalitete() const = 0;
	virtual void print() const = 0;
};

class LegoIgracka : public Proizvod {
private:
	int kolicina = 0;
public:
	LegoIgracka(string naziv, double cijena, int kolicina) : Proizvod(naziv, cijena) {
		this->kolicina = kolicina;
	}

	int getKolicina() const { return this->kolicina; }
	double getKoefKvalitete() const override { return this->kolicina / cijena; }
	void print() const { cout << "Lego - " << this->naziv << ", " << this->cijena << " kn, " << this->kolicina << " kom, (" << this->getKoefKvalitete() << ")" << endl; }
};

class Automobil : public Proizvod {
private:
	int godinaProizvodnje;
	double maxBrzina;
public:
	Automobil(string naziv, double cijena, int godina, double max) : Proizvod(naziv, cijena) {
		this->godinaProizvodnje = godina;
		this->maxBrzina = max;
	}

	double getKoefKvalitete() const override { return 1.0 / (2015 - this->godinaProizvodnje) * this->maxBrzina / 100.0 * this->cijena / 100000.0; }
	void print() const {
		cout << "Automobil - " << this->naziv << ", " << this->cijena << " kn, " << this->godinaProizvodnje << ". (" << this->getKoefKvalitete() << ")" << endl;
	}
};

int main()
{
	vector<Proizvod*> vp = {
		new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = br. komada
		new Automobil("BMW", 51230, 2013, 207.34), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = god. proizvodnje, 4. parametar = max brzina
		new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
		new Automobil("Yugo 45", 14500, 1988, 127.88),
	};

	for (int i = 0; i < 4; i++) {
		vp[i]->print();
	}

	/*
	Dodati kod za pronalazak proizvoda s najveæim koeficijentom i ispis tog proizvoda i odgovarajuæeg koeficijenta.
	*/

	int max = 0;

	for (int i = 0; i < 4; i++)
	{
		if (vp[i]->getKoefKvalitete() > vp[max]->getKoefKvalitete()) {
			max = i;
		}
	}

	cout << "\nProizvod s najvecim koeficijentom: ";
	vp[max]->print();

	return 0;
}