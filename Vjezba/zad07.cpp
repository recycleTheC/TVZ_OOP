#include<iostream>
#include<string>

using namespace std;

class BankovniRacun {
private:
	string brojRacuna;
	string tipKlijenta;
	string tipRacuna;
public:

	BankovniRacun() = default; // defaultni konstruktor
	~BankovniRacun() = default; // defaultni destruktor
	BankovniRacun(string brojRacuna, string tipKlijenta, string tipRacuna) {
		setBrojRacuna(brojRacuna);
		setTipKlijenta(tipKlijenta);
		setTipRacuna(tipRacuna);
	}

	string getBrojRacuna() const {
		return brojRacuna;
	}

	void setBrojRacuna(string brojRacuna) {
		if (brojRacuna.length() != 8) {
			cout << "Neispravna duljina broja racuna!" << endl;
			return;
		}
		else if (brojRacuna[0] != '0') {
			cout << "Neispravan pocetak broja racuna!" << endl;
			return;
		}
		else {
			this->brojRacuna = brojRacuna;
		}
	}

	string getTipKlijenta() const {
		return tipKlijenta;
	}

	void setTipKlijenta(string tipKlijenta) {
		if (tipKlijenta == "fizicka osoba") {
			this->tipKlijenta = tipKlijenta;
		}
		else if (tipKlijenta != "pravna osoba") {
			this->tipKlijenta = tipKlijenta;
		}
		else {
			cout << "Neispravan tip klijenta!" << endl;
			return;
		}
	}

	string getTipRacuna() const {
		return tipRacuna;
	}

	void setTipRacuna(string tipRacuna) {
		if (tipRacuna == "tekuci") {
			this->tipRacuna = tipRacuna;
		}
		else if (tipRacuna == "ziro") {
			this->tipRacuna = tipRacuna;
		}
		else if (tipRacuna == "devizni") {
			this->tipRacuna = tipRacuna;
		}
		else {
			cout << "Neispravan tip racuna!" << endl;
			return;
		}
	}
};

int main() {
	string brojRacuna, klijent, tipRacuna;

	BankovniRacun racun;

	cout << "Upisi broj racuna: ";
	cin >> brojRacuna;

	racun.setBrojRacuna(brojRacuna);

	cout << "Upisi tip klijenta: ";
	getline(cin >> ws, klijent);

	racun.setTipKlijenta(klijent);

	cout << "Upisi tip racuna: ";
	getline(cin >> ws, tipRacuna);

	racun.setTipRacuna(tipRacuna);

	return 0;
}