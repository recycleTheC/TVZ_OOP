#include "Vrt.h"

namespace Hortikultura {
	string Vrt::normalizacija(string tekst) {
		for (int i = 0; i < tekst.size(); i++)
		{
			if (i == 0) tekst[0] = toupper(tekst[0]);
			else if (tekst[i - 1] == ' ') tekst[i] = toupper(tekst[i]);
			else tekst[i] = tolower(tekst[i]);
		}

		return tekst;
	}

	Vrt::Vrt() {}
	Vrt::~Vrt() {
		for (int i = 0; i < this->cvijece.size(); i++)
		{
			delete this->cvijece[i];
		}
	}
	Vrt::Vrt(string vlasnik, string adresa, double sirina, double duljina) {
		setVlasnik(vlasnik);
		setAdresa(adresa);
		setDimenzije(sirina, duljina);
	}

	Vrt::Vrt(const Vrt& vrt) {
		this->vlasnik = vrt.vlasnik;
		this->adresa = vrt.adresa;
		this->duljina = vrt.duljina;
		this->sirina = vrt.sirina;

		for (int i = 0; i < vrt.cvijece.size(); i++)
		{
			this->cvijece.push_back(new Cvijet(*vrt.cvijece[i]));
		}
	}

	Vrt::Vrt(Vrt&& vrt) {
		this->vlasnik = vrt.vlasnik;
		this->adresa = vrt.adresa;
		this->duljina = vrt.duljina;
		this->sirina = vrt.sirina;

		for (int i = 0; i < this->cvijece.size(); i++)
		{
			delete this->cvijece[i];
		}

		this->cvijece.clear();

		int n = vrt.cvijece.size();

		for (int i = 0; i < n; i++)
		{
			this->cvijece.push_back(vrt.cvijece[i]);
			vrt.cvijece.erase(vrt.cvijece.begin());
		}
	}

	Vrt& Vrt::operator = (const Vrt& vrt) {
		if (this != &vrt) {
			this->vlasnik = vrt.vlasnik;
			this->adresa = vrt.adresa;
			this->duljina = vrt.duljina;
			this->sirina = vrt.sirina;

			for (int i = 0; i < this->cvijece.size(); i++)
			{
				delete this->cvijece[i];
			}

			this->cvijece.clear();

			for (int i = 0; i < vrt.cvijece.size(); i++)
			{
				this->cvijece.push_back(new Cvijet(*vrt.cvijece[i]));
			}
		}
		return *this;
	}

	Vrt& Vrt::operator = (Vrt&& vrt) {

		if (this != &vrt) {

			this->vlasnik = vrt.vlasnik;
			this->adresa = vrt.adresa;
			this->duljina = vrt.duljina;
			this->sirina = vrt.sirina;

			for (int i = 0; i < this->cvijece.size(); i++)
			{
				delete this->cvijece[i];
			}

			this->cvijece.clear();

			int n = vrt.cvijece.size();

			for (int i = 0; i < n; i++)
			{
				this->cvijece.push_back(vrt.cvijece[i]);
				vrt.cvijece.erase(vrt.cvijece.begin());
			}
		}
		return *this;
	}

	string Vrt::getVlasnik() const { return this->vlasnik; }
	string Vrt::getAdresa() const { return this->adresa; }
	double Vrt::getSirina() const { return this->sirina; }
	double Vrt::getDuljina() const { return this->duljina; }

	void Vrt::setVlasnik(string vlasnik) {
		this->vlasnik = normalizacija(vlasnik);
	}

	void Vrt::setAdresa(string adresa) {
		this->adresa = adresa;
	}

	void Vrt::setDimenzije(double sirina, double duljina) {
		double povrsina = sirina * duljina;

		if (povrsina < 10) throw "Povrsina vrta je premalena!";
		else {
			this->sirina = sirina;
			this->duljina = duljina;
		}
	}

	Vrt& Vrt::dodajCvijet(Cvijet& z) {
		cvijece.push_back(new Cvijet(z));
		return *this;
	}

	Vrt& Vrt::dodajCvijet(Cvijet&& z) {
		cvijece.push_back(new Cvijet(z));
		return *this;
	}

	Vrt& Vrt::dodajCvijet(Cvijet* z) {
		cvijece.push_back(new Cvijet(*z));
		return *this;
	}

	void Vrt::ispisSvihCvijetova() const {
		for (int i = 0; i < cvijece.size(); i++)
		{
			cout << cvijece[i]->toString() << endl;
		}

		cout << endl;
	}

	Cvijet* Vrt::nadjiCvijet(string vrsta) {
		for (int i = 0; i < cvijece.size(); i++)
		{
			if (cvijece[i]->getVrsta() == vrsta) {
				return cvijece[i];
			}
		}

		return NULL;
	}
}