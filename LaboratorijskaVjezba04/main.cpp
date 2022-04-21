#include<iostream>
#include<vector>

using namespace std;

class Putnik {
private:
	string ime, prezime, destinacija;
	double cijenaPutovanja = 0;

public:
	Putnik() = default;
	Putnik(string ime, string prezime, string destinacija, double cijena)
		: ime(ime), prezime(prezime), destinacija(destinacija) {
		setCijenaPutovanja(cijena);
	}

	string getIme() const { return ime; }
	string getPrezime() const { return prezime; }
	string getDestinacija() const { return destinacija; }
	double getCijenaPutovanja() const { return cijenaPutovanja; }

	void setIme(string ime) { this->ime = ime; }
	void setPrezime(string prezime) { this->prezime = prezime; }
	void setDestinacija(string destinacija) { this->destinacija = destinacija; }
	void setCijenaPutovanja(double cijena) {
		if (cijena >= 0 && cijena <= 25000) {
			this->cijenaPutovanja = cijena;
		}
		else {
			cout << "Cijena putovanja nije ispravna!" << endl;
		}
	}
};

class Agencija {
public:
	string naziv, adresa;
	vector<Putnik*> putnici;

	Agencija() = default;

	Agencija(string naziv, string adresa) : naziv(naziv), adresa(adresa) {}

	Agencija(const Agencija& ag) {
		this->naziv = ag.naziv;
		this->adresa = ag.adresa;

		for (int i = 0; i < ag.putnici.size(); i++)
		{
			this->putnici.push_back(new Putnik(*ag.putnici[i]));
		}
	}

	Agencija(Agencija&& ag) {
		this->naziv = ag.naziv;
		this->adresa = ag.adresa;

		int n = ag.putnici.size();

		for (int i = 0; i < n; i++)
		{
			this->putnici.push_back(ag.putnici[0]);
			ag.putnici.erase(ag.putnici.begin());
		}
	}

	Agencija& operator = (Agencija&& ag) {
		if (this != &ag) {
			this->naziv = ag.naziv;
			this->adresa = ag.adresa;

			for (int i = 0; i < this->putnici.size(); i++)
			{
				delete this->putnici[i];
			}

			this->putnici.clear();

			int n = ag.putnici.size();

			for (int i = 0; i < n; i++)
			{
				this->putnici.push_back(ag.putnici[0]);
				ag.putnici.erase(ag.putnici.begin());
			}
		}

		return *this;
	}

	~Agencija() {
		for (int i = 0; i < putnici.size(); i++)
		{
			if (putnici[i] != NULL) delete putnici[i];
		}
	}
};

int main() {

	Agencija agencija1("AgentTours", "Frankopanska 1");
	agencija1.putnici.push_back(new Putnik("Mario", "Kopjar", "Havaji", 25000));

	Agencija agencija2(agencija1); // kopirni konstruktor
	agencija2.putnici.push_back(new Putnik("Marko", "Markic", "New York", 18000));

	Agencija agencija3(move(Agencija("Putnicka Agencija", "Teslina 2"))); // prijenosni konstruktor
	agencija3.putnici.push_back(new Putnik("Pero", "Peric", "Amsterdam", 15000));

	Agencija agencija4;
	agencija4 = move(agencija3); // operator pridruivanja sa semantikom prijenosa

	return 0;
}