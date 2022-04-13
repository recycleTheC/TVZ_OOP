#include "BankovniRacun.h"

BankovniRacun::BankovniRacun() {}
BankovniRacun::~BankovniRacun() {}
BankovniRacun::BankovniRacun(string brojRacuna, string tipKlijenta, string tipRacuna) {
	setBrojRacuna(brojRacuna);
	setTipKlijenta(tipKlijenta);
	setTipRacun(tipRacuna);
}

void BankovniRacun::setBrojRacuna(string brojRacuna) {
	if (brojRacuna.size() == 8 && brojRacuna[0] == '0') {
		this->brojRacuna = brojRacuna;
	}
	else {
		cout << "Broj racuna nije ispravan!" << endl;
		exit(1);
	}
}

void BankovniRacun::setTipKlijenta(string tipKlijenta) {
	if (tipKlijenta == "fizicka" || tipKlijenta == "pravna") {
		this->tipKlijenta = tipKlijenta;
	}
	else {
		cout << "Tip klijenta nije ispravan!" << endl;
		exit(1);
	}
}

void BankovniRacun::setTipRacun(string tipRacuna) {
	if (tipRacuna == "ziro" || tipRacuna == "tekuci" || tipRacuna == "devizni") {
		this->tipRacuna = tipRacuna;
	}
	else {
		cout << "Tip racuna nije ispravan!" << endl;
		exit(1);
	}
}

string BankovniRacun::getBrojRacuna() const { return brojRacuna; }
string BankovniRacun::getTipKlijenta() const { return tipKlijenta; }
string BankovniRacun::getTipRacuna() const { return tipRacuna; }
string BankovniRacun::toString() const { return "Racun: " + tipRacuna + " - " + brojRacuna + ", " + tipKlijenta;  }