#include<iostream>
#include<vector>

using namespace std;

class Zaposlenik {
protected:
	string ime, prezime;
public:
	Zaposlenik(string ime, string prezime) : ime(ime), prezime(prezime) {}
	virtual ~Zaposlenik() {
		cout << "Zaposlenik destruktor" << endl;
	}

	virtual string getRadnoMjesto() const { return "Unutar tvrtke"; }
	virtual double getPlaca() const = 0;
};

class Sef : public Zaposlenik {
public:
	Sef(string ime, string prezime) : Zaposlenik(ime, prezime) {}

	string getRadnoMjesto() const override { return "Tvrtka - vlastiti ured"; }
	double getPlaca() const override { return 10000.0; }
};

class Programer : public Zaposlenik {
public:
	Programer(string ime, string prezime) : Zaposlenik(ime, prezime) {}
	~Programer() {
		cout << "Programer destruktor" << endl;
	}

	string getRadnoMjesto() const override { return "Tvrtka - zajednicki ured"; }
	double getPlaca() const override { return 7000.0; }
};

class ProgramerVSS : public Programer{
public:
	ProgramerVSS(string ime, string prezime) : Programer(ime, prezime) {}
	double getPlaca() const override { return 8000.0; }
};

double ProsjecnaPlaca(const vector<Zaposlenik*>& tvrtka) {
	double total = 0;

	for (Zaposlenik* z : tvrtka)
		total += z->getPlaca();

	return total / tvrtka.size();
}

int main() {
	Programer programer1("Augusta", "King");
	ProgramerVSS programer2("Paul", "Allen");
	ProgramerVSS programer3("Bill", "Gates");
	Programer programer4("Melinda", "French");

	vector<Zaposlenik*> zaposlenici = { &programer1, &programer2, &programer3, &programer4 };

	cout << "Prosjecna placa: " << ProsjecnaPlaca(zaposlenici) << endl;

	Zaposlenik* z = new Programer("Caroline", "Turing");
	delete z;

	return 0;
}