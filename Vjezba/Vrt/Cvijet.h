#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Hortikultura {
	class Cvijet {
	private:
		string vrsta, boja;
		int kolicina;
	public:

		Cvijet(string vrsta, string boja, int kolicina);
		~Cvijet();

		string getVrsta() const;
		string getBoja() const;
		string toString() const;
		int getKolicina() const;

		void setVrsta(string vrsta);
		void setBoja(string boja);
		void setKolicina(int kolicina);
	};
}