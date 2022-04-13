#include<iostream>
#include"BankovniRacun.h"

int main() {
	string brojRacuna, tipKlijenta, tipRacuna;

	cout << "Upisite broj racuna: ";
	cin >> brojRacuna;

	cout << "Upisite tip klijenta (pravna / fizicka): ";
	cin >> tipKlijenta;

	cout << "Upisite tip racuna (tekuci / ziro / devizni): ";
	cin >> tipRacuna;

	BankovniRacun racun(brojRacuna, tipKlijenta, tipRacuna);

	cout << racun.toString() << endl;

	return 0;
}