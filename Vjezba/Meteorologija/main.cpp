#include<iostream>
#include<vector>
#include"MeteoroloskaPostaja.h"

using namespace std;
using namespace Meteorologija;

int main() {

	int n;
	cout << "Upisi broj postaja: ";
	cin >> n;

	vector<MeteoroloskaPostaja> postaje;

	cout << "Upisi ID, lokaciju, brzinu vjetra, temperaturu, vlaznost i tlak: " << endl;

	for (int i = 0; i < n; i++)
	{
		string lokacija;
		int id, brzina, temp, vlaga, tlak;

		cout << i + 1 << ": ";
		cin >> id >> lokacija >> brzina >> temp >> vlaga >> tlak;

		postaje.push_back(MeteoroloskaPostaja(lokacija, id, temp, brzina, vlaga, tlak));
	}

	double prosjecnaTemp = ProsjecnaTemperatura(postaje);
	vector<MeteoroloskaPostaja*> postajeIspodProsjeka; // vektor adresa postaja

	for (int i = 0; i < postaje.size(); i++)
	{
		if (postaje[i].getTemperatura() < prosjecnaTemp) {
			postajeIspodProsjeka.push_back(&postaje[i]); // sprema se samo adresa postaje
			cout << postaje[i].toString() << endl;
		}
	}

	int maxTlak = MaksimalanTlak(postajeIspodProsjeka);

	cout << "\nNajvisi tlak:" << endl;

	for (int i = 0; i < postajeIspodProsjeka.size(); i++)
	{
		if (postajeIspodProsjeka[i]->getTlakZraka() == maxTlak) {
			cout << postajeIspodProsjeka[i]->toString() << endl;
		}
	}

}