#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Igracka {
protected:
	string naziv;
public:
	Igracka(string naziv) : naziv(naziv) {}
	virtual ~Igracka() {
		cout << "Igracka destruktor" << endl;
	}

	virtual string GetNaziv() const { return this->naziv; }
	virtual double GetCijena() const = 0;
	virtual string GetMatIzrade() const { return "mijesani materijali"; }
};

class Autic : public Igracka {
public:
	Autic(string naziv) : Igracka(naziv) {}
	~Autic() {
		cout << "Autic destruktor" << endl;
	}

	double GetCijena() const { return 12.0; }
	string GetMatIzrade() const { return "metal i plastika"; }
};

class Kocka : public Igracka {
public:
	Kocka(string naziv) : Igracka(naziv) {}

	virtual double GetCijena() const { return 45; }
	string GetMatIzrade() const { return "plastika"; }
};

class LegoKocka : public Kocka {
public:
	LegoKocka() : Kocka("Lego kocke") {}
	LegoKocka(string naziv) : Kocka(naziv) {}

	double GetCijena() const final { return 100; }
};

double ProsjecnaCijena(vector<Igracka*>& ducan) {
	double total = 0;

	for (Igracka* igr : ducan)
		total += igr->GetCijena();

	return total / ducan.size();
}

int main() {

	Kocka kocka1("Rubikova kocka");
	LegoKocka lego1;
	Autic autic1("Ferrari");

	cout << kocka1.GetNaziv() << ", " << kocka1.GetCijena() << ", " << kocka1.GetMatIzrade() << endl;
	cout << lego1.GetNaziv() << ", " << lego1.GetCijena() << ", " << lego1.GetMatIzrade() << endl;
	cout << autic1.GetNaziv() << ", " << autic1.GetCijena() << ", " << autic1.GetMatIzrade() << endl;

	vector<Igracka*> igracke = { &kocka1, &lego1, &autic1 };
	cout << "Prosjecna cijena: " << ProsjecnaCijena(igracke) << endl;

	Igracka* ig = new Autic("BMW");
	delete ig;

	return 0;
}