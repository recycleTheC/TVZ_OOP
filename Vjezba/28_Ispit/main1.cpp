#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Datum {
private: 
	int d, m, g;
	string pretvori(int x) const { return (x < 10 ? "0" : "") + to_string(x); }
	string datum_string() const { return to_string(g) + pretvori(m) + pretvori(d); }
public:
	Datum(int dan, int mjesec, int godina) : d(dan), m(mjesec), g(godina) {}

	string toString() const { return pretvori(d) + "." + pretvori(m) + "." + to_string(g) + "."; }

	bool operator > (const Datum& a) {
		return this->datum_string() > a.datum_string();
	}
};

Datum najveci_dan(map<string, vector<Datum>>& m) {
	map<string, vector<Datum>>::iterator red = m.begin();
	int stupac = 0;

	for (auto i = m.begin(); i != m.end(); i++)
	{
		for (int j = 0; j < i->second.size(); j++) {
			if (i->second[j] > red->second[stupac]) {
				red = i;
				stupac = j;
			}
		}
	}

	return red->second[stupac];
}

ostream& operator << (ostream& izlaz, const Datum& d) {
	izlaz << d.toString() << endl;
	return izlaz;
}

int main() {
	map<string, vector<Datum>> mapa;
	
	mapa["a"] = { Datum(4, 7, 2013), Datum(18, 6, 2015), Datum(20, 7, 2016),
		Datum(20, 7, 2014), Datum(1, 7, 2015)
	};
	mapa["b"] = { Datum(11, 9, 2016), Datum(3, 10, 2016), Datum(4, 10, 2016),
		Datum(30, 10, 2016)
	};
	
	mapa["c"] = { Datum(1, 2, 2012), Datum(7, 2, 2013), Datum(12, 1, 2014),
		Datum(11, 1, 2015)
	};
	// mogu postojati i drugi kljucevi ...

	cout << "Najveci: " << najveci_dan(mapa); // ispisuje 30.10.2016.

	return 0;
}