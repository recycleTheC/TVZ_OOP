#include<iostream>
#include<vector>
#include <string>

using namespace std;

class Dokument {
protected:
	string autor, datum, vrijeme, id;
public:
	Dokument(string id, string autor, string datum, string vrijeme) {
		this->id = id;
		this->autor = autor;
		this->datum = datum;
		this->vrijeme = vrijeme;
	}

	string getId() const { return this->id; }
	string getAutor() const { return this->autor; }
	string getDatum() const { return this->datum; }
	string getVrijeme() const { return this->vrijeme; }
};

class StavkaRacuna {
protected:
	string naziv;
	int kolicina = 0;
	double jedinicnaCijena = 0;
	double popust = 0;

	double koef() const { return (100.0 - popust) / 100.0; }
public:
	StavkaRacuna(string naziv, int kolicina, double cijena) {
		this->naziv = naziv;
		this->kolicina = kolicina;
		this->jedinicnaCijena = cijena;
	}

	StavkaRacuna(string naziv, int kolicina, double cijena, double popust) {
		this->naziv = naziv;
		this->kolicina = kolicina;
		this->jedinicnaCijena = cijena;
		this->popust = popust;
	}

	virtual string getNaziv() const { return this->naziv; }
	virtual int getKolicina() const { return this->kolicina; }

	virtual double getPopust() const { return this->popust; }
	virtual void setPopust(double p) { this->popust = p; }

	virtual double getJedinicnaCijena() const { return this->jedinicnaCijena; }
	virtual double getUkupanIznos() const { return (this->jedinicnaCijena * koef()) * this->kolicina; }

	virtual double getUkupanIznosSaPDV() const final { return this->getUkupanIznos() * 1.25; }
	virtual double getIznosPDV() const final { return this->getUkupanIznos() * 0.25; }
};

ostream& operator << (ostream& izlaz, const StavkaRacuna* s) {
	izlaz << s->getNaziv() << ", " << s->getKolicina() << "kom, " << s->getJedinicnaCijena() << " kn, " << s->getPopust()
		<< "% -> " << s->getUkupanIznos() << " kn, PDV: " << s->getIznosPDV() << " kn, ukupno: " << s->getUkupanIznosSaPDV() << " kn";

	return izlaz;
}

bool operator == (const StavkaRacuna& a, const StavkaRacuna& b) {
	return a.getNaziv() == b.getNaziv() && a.getJedinicnaCijena() == b.getJedinicnaCijena() && a.getKolicina() == b.getKolicina();
}

class Racun : public Dokument {
private:
	string jir, tip;
	vector<StavkaRacuna*> stavke;
public:
	Racun(string id, string autor, string datum, string vrijeme) : Dokument(id, autor, datum, vrijeme) {}

	Racun& dodajStavku(StavkaRacuna* st) {
		this->stavke.push_back(st);
		return *this;
	}

	void ukloniStavku(StavkaRacuna& st) {
		for (int i = 0; i < this->stavke.size(); i++) {
			if (*this->stavke[i] == st) {
				this->stavke.erase(this->stavke.begin() + i);
				break;
			}
		}
	}

	double ukupanIznos() const {
		double total = 0;

		for (const StavkaRacuna* st : this->stavke)
			total += st->getUkupanIznos();

		return total;
	}

	double ukupanIznosSaPDVom() const {
		double total = 0;

		for (const StavkaRacuna* st : this->stavke)
			total += st->getUkupanIznosSaPDV();

		return total;
	}

	double ukupanIznosPDVa() const {
		double total = 0;

		for (const StavkaRacuna* st : this->stavke)
			total += st->getIznosPDV();

		return total;
	}

	friend ostream& operator << (ostream& izlaz, const Racun& racun);
};

ostream& operator << (ostream& izlaz, const Racun& racun) {
	izlaz << "Racun " << racun.getId() << ", " << racun.getDatum() << " " << racun.getVrijeme() << endl;

	cout << "Stavke na racunu: " << endl;

	for (const StavkaRacuna* stavka : racun.stavke)
		izlaz << stavka << endl;

	izlaz << "----------" << endl;
	izlaz << "Osnovica: " << racun.ukupanIznos() << " kn" << endl;
	izlaz << "PDV: " << racun.ukupanIznosPDVa() << " kn" << endl;
	izlaz << "Ukupno: " << racun.ukupanIznosSaPDVom() << " kn" << endl;

	return izlaz;
}

class Cokolada : public StavkaRacuna {
public:
	Cokolada(int kolicina, double cijena, double popust) : StavkaRacuna("Dorina cokolada", kolicina, cijena, popust) {}
};

class Bombonijera : public StavkaRacuna {
private:
	string brand;
public:
	Bombonijera(string brand, int kolicina, double cijena, double popust) : StavkaRacuna("Bombonijera", kolicina, cijena, popust) {
		this->brand = brand;
	}

	string getNaziv() const override { return this->naziv + " " + this->brand; }
};

class Grickalice : public StavkaRacuna {
private:
	int masa; // masa u gramima
	string okus, vrsta;
public:
	Grickalice(string vrsta, string okus, int masa, int kolicina, double cijena, double popust) : StavkaRacuna("Grickalice", kolicina, cijena, popust) {
		this->masa = masa;
		this->vrsta = vrsta;
		this->okus = okus;
	}

	string getNaziv() const override { return this->naziv + ": " + this->vrsta + ", " + this->okus + ", " + to_string(this->masa) + "g"; }
};

int main() {

	Cokolada cokolada(5, 10, 20);
	Grickalice cips("cips", "paprika", 200, 14, 8, 5);
	Bombonijera bajadere("Bajadera", 2, 16, 20);

	Racun racun("314/1/1", "Ivana Horvatic", "31.01.2022.", "14:50");
	racun.dodajStavku(&cokolada).dodajStavku(&cips).dodajStavku(&bajadere);

	cout << racun;

	return 0;
}