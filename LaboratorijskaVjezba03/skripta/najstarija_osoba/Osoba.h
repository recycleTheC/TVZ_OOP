#pragma once

#include<string>

using namespace std;

namespace Vjezba3 {
	class Osoba
	{
	private:
		string ime, prezime;
		int godina;

		string normaliziraj(const string tekst);
	public:
		Osoba(string ime, string prezime, int gr); // ne mora se staviti naziv parametra
		~Osoba() {}

		void setIme(string ime);
		string getIme() const;

		void setPrezime(string prezime);
		string getPrezime() const;

		void setGodinaRodjenja(int godina);
		int getGodinaRodjenja() const;
	};

	void ispisiOsobu(Osoba* o);
}

