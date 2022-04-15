// Evidencija garaza

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Predmet {
public:
	string naziv;
	double vrijednost;

	Predmet(string naziv, double vrijednost) : naziv(naziv), vrijednost(vrijednost) {};
	Predmet() = default;
};

class Garaza {
public:
	int sirina, duljina;
	bool automatskaVrata;
	string lokacija;
	vector<Predmet> predmeti;
};

int main() {

	vector<Garaza> garaze;
	int n;

	cout << "Upisite broj garaza: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		Garaza garaza;

		cout << endl;
		cout << "Unesite velicinu, lokaciju i podatak o vratima za " << i + 1 << ". garazu:" << endl;
		cin >> garaza.duljina >> garaza.sirina;

		getline(cin >> ws, garaza.lokacija);

		cin >> tmp;

		if (tmp == "DA") garaza.automatskaVrata = true;
		else garaza.automatskaVrata = false;

		garaze.push_back(garaza);
	}

	int m;
	cout << endl << "Unesite broj predmeta: ";
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int index = 0; string naziv; double vrijednost;

		cout << "Unesite redni broj garaze u koju spada " << i + 1 << ". predmet: ";
		cin >> index;

		cout << "Unesite naziv i vrijednost predmeta: ";
		cin >> naziv >> vrijednost;

		if (index < 0 || index > garaze.size()) {
			cout << "Greska pri unosu!";
			exit(1);
		}

		garaze[index - 1].predmeti.push_back(Predmet(naziv, vrijednost));
	}

	cout << endl << "Ispis garaza i predmeta:" << endl;

	for (int i = 0; i < garaze.size(); i++)
	{
		cout << i + 1 << ". " << garaze[i].lokacija << " ";
		cout << garaze[i].duljina << "x" << garaze[i].sirina << " - predmeti: ";

		for (int j = 0; j < garaze[i].predmeti.size(); j++)
		{
			if (j > 0) cout << ", ";
			cout << garaze[i].predmeti[j].naziv << "(" << garaze[i].predmeti[j].vrijednost << ")";
		}

		cout << endl;
	}

	return 0;
}