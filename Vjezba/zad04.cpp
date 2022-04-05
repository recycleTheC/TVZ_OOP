// Racun i artikli

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Artikl {
public:
	string naziv;
	int kolicina;
	double jedinicnaCijena;

	Artikl(string naziv, int kolicina, double jedCijena) : naziv(naziv), kolicina(kolicina), jedinicnaCijena(jedCijena) {}
};

class Racun {
public:
	int redniBroj;
	vector<Artikl> artikli;
	double ukupnaCijena = 0;

	Racun(int redniBr) : redniBroj(redniBr) {}

	void dodaj(Artikl artikl) {
		artikli.push_back(artikl);
		ukupnaCijena += artikl.jedinicnaCijena * artikl.kolicina;
	}
};

class Kupac {
public:
	Racun racun;
	Kupac(Racun racun) : racun(racun) {}
};

int main() {

	Kupac Ante(Racun(1)); // Ante ima raèun broj 1
	Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
	Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn
																	
	/* U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio (naziv i ukupna cijena).
	Npr. Najskuplje placeni artikl je Coca cola 2l (20kn)
	*/

	int max = 0;
	double iznosMax = Ante.racun.artikli[max].jedinicnaCijena * Ante.racun.artikli[max].kolicina;

	for (int i = 1; i < Ante.racun.artikli.size(); i++)
	{
		double iznosTrenutni = Ante.racun.artikli[i].jedinicnaCijena * Ante.racun.artikli[i].kolicina;

		if (iznosTrenutni > iznosMax) {
			max = i;
			iznosMax = Ante.racun.artikli[i].jedinicnaCijena * Ante.racun.artikli[i].kolicina;
		}
	}

	cout << "Najskuplje placeni artikl je " << Ante.racun.artikli[max].naziv << " (" << iznosMax << " kn)" << endl;

	return 0;
}