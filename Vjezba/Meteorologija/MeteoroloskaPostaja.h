#pragma once

#include<string>
#include<vector>

using namespace std;

namespace Meteorologija {
	class MeteoroloskaPostaja {
	private:
		string lokacija;
		int ID = 0, temperatura = 0, brzinaVjetra = 0, vlaznost = 0, tlak = 0;
	public:

		MeteoroloskaPostaja();
		MeteoroloskaPostaja(string lokacija, int id, int temperatura, int brzinaVjetra, int vlaznost, int tlak);
		~MeteoroloskaPostaja();

		void setID(int id);
		int getID() const;

		void setTemperatura(int temp);
		int getTemperatura() const;

		void setBrzinaVjetra(int brzina);
		int getBrzinaVjetra() const;

		void setVlaznost(int vlaznost);
		int getVlaznost() const;

		void setTlakZraka(int tlak);
		int getTlakZraka() const;

		void setLokacija(string lokacija);
		string getLokacija() const;

		string toString() const;
	};

	int MaksimalanTlak(vector<MeteoroloskaPostaja>& postaje);
	int MaksimalanTlak(vector<MeteoroloskaPostaja*>& postaje);
	double ProsjecnaTemperatura(vector<MeteoroloskaPostaja>& postaje);
}