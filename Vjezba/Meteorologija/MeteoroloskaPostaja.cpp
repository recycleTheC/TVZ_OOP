#include "MeteoroloskaPostaja.h"

using namespace Meteorologija;

MeteoroloskaPostaja::MeteoroloskaPostaja() {}

MeteoroloskaPostaja::MeteoroloskaPostaja(string lokacija, int id, int temperatura, int brzinaVjetra, int vlaznost, int tlak) {
	setID(id);
	setTlakZraka(tlak);
	setVlaznost(vlaznost);
	setLokacija(lokacija);
	setTemperatura(temperatura);
	setBrzinaVjetra(brzinaVjetra);
}

MeteoroloskaPostaja::~MeteoroloskaPostaja() {}

void MeteoroloskaPostaja::setID(int id) {
	this->ID = id;
}
int MeteoroloskaPostaja::getID() const {
	return this->ID;
}

void MeteoroloskaPostaja::setTemperatura(int temp) {
	this->temperatura = temp;
}
int MeteoroloskaPostaja::getTemperatura() const {
	return this->temperatura;
}

void MeteoroloskaPostaja::setBrzinaVjetra(int brzina) {
	this->brzinaVjetra = brzina;
}
int MeteoroloskaPostaja::getBrzinaVjetra() const {
	return this->brzinaVjetra;
}

void MeteoroloskaPostaja::setVlaznost(int vlaznost) {
	this->vlaznost = vlaznost;
}
int MeteoroloskaPostaja::getVlaznost() const {
	return this->vlaznost;
}

void MeteoroloskaPostaja::setTlakZraka(int tlak) {
	this->tlak = tlak;
}
int MeteoroloskaPostaja::getTlakZraka() const {
	return this->tlak;
}

void MeteoroloskaPostaja::setLokacija(string lokacija) {
	this->lokacija = lokacija;
}
string MeteoroloskaPostaja::getLokacija() const {
	return this->lokacija;
}

string MeteoroloskaPostaja::toString() const {
	return to_string(ID) + " " + lokacija + " " + to_string(brzinaVjetra) + " " + to_string(temperatura) + " " + to_string(vlaznost) + " " + to_string(tlak);
}

int Meteorologija::MaksimalanTlak(vector<MeteoroloskaPostaja>& postaje) {
	int max = postaje[0].getTlakZraka();

	for (int i = 1; i < postaje.size(); i++)
	{
		if (postaje[i].getTlakZraka() > max) {
			max = postaje[i].getTlakZraka();
		}
	}

	return max;
}

int Meteorologija::MaksimalanTlak(vector<MeteoroloskaPostaja*>& postaje) {
	int max = postaje[0]->getTlakZraka();

	for (int i = 1; i < postaje.size(); i++)
	{
		if (postaje[i]->getTlakZraka() > max) {
			max = postaje[i]->getTlakZraka();
		}
	}

	return max;
}

double Meteorologija::ProsjecnaTemperatura(vector<MeteoroloskaPostaja>& postaje) {
	double total = 0;
	int n = postaje.size();

	for (int i = 0; i < postaje.size(); i++)
	{
		total += postaje[i].getTemperatura();
	}

	return total / n;
}