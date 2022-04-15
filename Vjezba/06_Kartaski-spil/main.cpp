#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Igrac {
private:
	string ime;
public:

	vector<int> karte;

	Igrac() = default;
	Igrac(string ime) : ime(ime) {}

	void setIme(string ime) {
		this->ime = ime;
	}

	string getIme() const {
		return this->ime;
	}
};

class Spil {
public:
	vector<int> karte;

	Spil() {
		for (int i = 1; i <= 52; i++)
		{
			karte.push_back(i);
		}
	}

	Spil(bool mijesaj) {
		for (int i = 1; i <= 52; i++)
		{
			karte.push_back(i);
		}

		if (mijesaj) {
			random_shuffle(karte.begin(), karte.end());
		}
	}

	void PodijeliKarte(Igrac* igrac, int n = 4) {
		for (int i = 0; i < n; i++)
		{
			igrac->karte.push_back(karte[0]);
			karte.erase(karte.begin());
		}
	}
};

int main() {
	int n;

	cout << "Unesi broj igraca: ";
	cin >> n;

	vector<Igrac> igraci;
	Spil spil(true);

	for (int i = 0; i < n; i++)
	{
		string ime;

		cout << "Unesi ime " << i + 1 << ". igraca: ";
		cin >> ime;

		igraci.push_back(Igrac(ime));
		spil.PodijeliKarte(&igraci[i]);
	}

	cout << "Karte podijeljene igracima:" << endl;

	for (int i = 0; i < igraci.size(); i++)
	{
		cout << igraci[i].getIme() << ": ";

		for (int j = 0; j < igraci[i].karte.size(); j++)
		{
			cout << igraci[i].karte[j] << " ";
		}

		cout << endl;
	}

	cout << endl;

	cout << "Preostale karte u spilu:" << endl;

	for (int i = 0; i < spil.karte.size(); i++)
	{
		cout << spil.karte[i] << " ";
	}

	cout << endl;

	return 0;
}