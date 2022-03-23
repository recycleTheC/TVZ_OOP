#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Datum {
public:
	int dan, mjesec, godina;

	Datum(int d, int m, int g) : dan(d), mjesec(m), godina(g) {
		if ((d < 1 || d > 31) || (m < 1 || m > 12) || (g < 1799)) {
			// ovako cemo odradjivati iznimke - za sada
			cout << "-- greska u validaciji!" << endl;
			exit(0);
		}
	};
	Datum() : dan(1), mjesec(1), godina(1900) {};

	string dm_2zn(int n) { // pretvara broj sa 1 znamenkom u string sa vodećom nulom -> 00
		string s = to_string(n);

		if (s.size() == 1) {
			return "0" + s;
		}
		else return s;
	}

	int usporedba(Datum d) {
		string s1 = to_string(godina) + dm_2zn(mjesec) + dm_2zn(dan); //YYYYMMDD
		string s2 = to_string(d.godina) + dm_2zn(d.mjesec) + dm_2zn(d.dan);

		if (s1 == s2) return 0; // usporedivanje stringova
		else if (s1 < s2) return -1;
		else return 1;
	}

	string tekst() {
		return dm_2zn(dan) + "." + dm_2zn(mjesec) + "." + to_string(godina);
	}

	bool vece_od(Datum d) {
		if (this->usporedba(d) == 1) return true;
		else return false;
	}

	bool manje_od(Datum d) {
		if (this->usporedba(d) == -1) return true;
		else return false;
	}
};

int main() {
	Datum d1(4, 11, 2028);
	Datum d2(7, 12, 2021);

	cout << "d1: " << d1.tekst() << endl;
	cout << "d2: " << d2.tekst() << endl;
	cout << "d1 > d2: " << d1.vece_od(d2) << endl;
	cout << "d1 < d2: " << d1.manje_od(d2) << endl << endl;

	Datum d3; // koristenje defaultnog konstruktora
	cout << "d3: " << d3.tekst() << endl << endl;

	vector<Datum> v{ d1, d2, d3 }; // koristenje objekata u vektoru

	for (int i = 0; i < v.size(); i++)
	{
		cout << "v[" << i << "]: " << v[i].tekst() << endl;
	}

	return 0;
}