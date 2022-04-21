#pragma once
#include <string>
#include <vector>
#include "Cvijet.h"

using namespace std;

namespace Hortikultura {
	class Vrt {
	private:
		string vlasnik, adresa;
		double sirina = 0, duljina = 0;
		vector<Cvijet*> cvijece;

		string normalizacija(string tekst);
	public:
		Vrt();
		~Vrt();
		Vrt(string vlasnik, string adresa, double sirina, double duljina);
		Vrt(const Vrt& vrt);
		Vrt(Vrt&& vrt);

		Vrt& operator = (const Vrt& vrt);
		Vrt& operator = (Vrt&& vrt);

		string getVlasnik() const;
		string getAdresa() const;
		double getSirina() const;
		double getDuljina() const;

		void setVlasnik(string vlasnik);
		void setAdresa(string adresa);
		void setDimenzije(double sirina, double duljina);

		Vrt& dodajCvijet(Cvijet& z);
		Vrt& dodajCvijet(Cvijet&& z);
		Vrt& dodajCvijet(Cvijet* z);

		void ispisSvihCvijetova() const;

		Cvijet* nadjiCvijet(string vrsta);
	};
}