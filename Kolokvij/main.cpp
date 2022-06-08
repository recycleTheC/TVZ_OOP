#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>

using namespace std;

class IznimkaCijena {
private:
	static int redni_broj;
	double cijena;
public:
	IznimkaCijena(double cijena) : cijena(cijena) {
		redni_broj++;
	}

	string what() const {
		return "Iznimka " + to_string(redni_broj) + ": Cijena od " + to_string(cijena) + " kn nije ispravna!";
	}
};

class Sirovina {
private:
	string naziv;
	double kolicina;
	double cijena;
public:
	Sirovina(string naziv, double kolicina, double cijena) {
		this->kolicina = kolicina;
		this->naziv = naziv;
		setCijena(cijena);
	}

	void setCijena(double cijena) {
		if (cijena >= 3 && cijena <= 100) this->cijena = cijena;
		else throw(IznimkaCijena(cijena));
	}

	double getCijena() const { return this->cijena; }
	double getKolicina() const { return this->kolicina; }
	string getNaziv() const { return this->naziv; }
};

class Nalaziste {
protected:
	string naziv, lokacija;
	vector<Sirovina> sirovine;
public:
	Nalaziste(string naziv, string lokacija) : naziv(naziv), lokacija(lokacija) {}

	template<class... T>
	Nalaziste(string naziv, string lokacija, T... sirovine);

	virtual double cijena_sirovina() const = 0;

	void sortiraj() {
		sort(this->sirovine.begin(), this->sirovine.end(), [](Sirovina& a, Sirovina& b) {
			return a.getCijena() < b.getCijena();
			});
	}

	friend ostream& operator << (ostream& izlaz, Nalaziste& n);
};

template<class... T>
Nalaziste::Nalaziste(string naziv, string lokacija, T... sirovina) : sirovine({ sirovina... }) {
	this->naziv = naziv;
	this->lokacija = lokacija;
}

ostream& operator << (ostream& izlaz, Nalaziste& n) {
	n.sortiraj();

	for (int i = 0; i < n.sirovine.size(); i++)
	{
		cout << n.sirovine[i].getNaziv() << ", " << n.sirovine[i].getKolicina() << " kg, " << n.sirovine[i].getCijena() << " kn" << endl;
	}

	return izlaz;
}

class PrimarnoNalaziste : public Nalaziste {
public:

	PrimarnoNalaziste(string naziv, string lokacija) : Nalaziste(naziv, lokacija) {}

	template<class... T>
	PrimarnoNalaziste(string naziv, string lokacija, T... sirovine) : Nalaziste(naziv, lokacija, sirovine...) {}

	virtual double cijena_sirovina() const {
		double total = 0;

		for (int i = 0; i < this->sirovine.size(); i++)
		{
			total += this->sirovine[i].getKolicina() * this->sirovine[i].getCijena() + this->sirovine[i].getKolicina() * 0.4;
		}

		return total;
	}
};

class SekundarnoNalaziste : public Nalaziste {
public:

	SekundarnoNalaziste(string naziv, string lokacija) : Nalaziste(naziv, lokacija) {}

	template<class... T>
	SekundarnoNalaziste(string naziv, string lokacija, T... sirovine) : Nalaziste(naziv, lokacija, sirovine...) {}

	virtual double cijena_sirovina() const {
		double total = 0;

		for (int i = 0; i < this->sirovine.size(); i++)
		{
			total += this->sirovine[i].getKolicina() * this->sirovine[i].getCijena() + this->sirovine[i].getKolicina() * 0.85;
		}

		return total;
	}
};

double UkupnaCijenaSirovina(vector<Nalaziste*>& nalazista) {
	double total = 0;

	for (int i = 0; i < nalazista.size(); i++)
	{
		total += nalazista[i]->cijena_sirovina();
	}

	return total;
}

class TerminalSirovina {
private:
	vector<Sirovina*> sirovine;

public:
	TerminalSirovina() = default;

	~TerminalSirovina() {
		for (int i = 0; i < this->sirovine.size(); i++)
		{
			delete this->sirovine[i];
		}
		this->sirovine.clear();
	}

	// prijenosni konstruktor

	TerminalSirovina(TerminalSirovina&& t) {
		this->sirovine = t.sirovine;
		t.sirovine.clear();
	}

	// operator pridruzivanja sa kopiranjem

	TerminalSirovina& operator= (TerminalSirovina& t) {
		if (this != &t) {
			for (int i = 0; i < this->sirovine.size(); i++)
			{
				delete this->sirovine[i];
			}

			this->sirovine.clear();

			for (int i = 0; i < t.sirovine.size(); i++)
			{
				this->sirovine.push_back(new Sirovina(*t.sirovine[i]));
			}
		}

		return *this;
	}
};

int IznimkaCijena::redni_broj = 0;

int main() {
	Sirovina s1("bakar", 100, 12);
	Sirovina s2("srebro", 12, 99);

	try {
		Sirovina s3("bakar", 100, 500);
	}
	catch (IznimkaCijena& izn) {
		cout << izn.what() << endl;
	}

	PrimarnoNalaziste n1("Metalac", "Jastrebarsko", s1, s2);
	SekundarnoNalaziste n2("Metalac 2", "Jastrebarsko", s1, s2);

	cout << n1 << endl;

	vector<Nalaziste*> nalazista = { &n1, &n2 };

	cout << UkupnaCijenaSirovina(nalazista) << " kn" << endl;

	/*TerminalSirovina t1, t2;
	t2 = t1;

	TerminalSirovina t3 = move(TerminalSirovina());*/

	return 0;
}