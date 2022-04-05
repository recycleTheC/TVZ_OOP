#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Predmet {
private:
	string _naziv;
	double _vrijednost;
public:
	Predmet() = default;
	Predmet(string naziv, double vrijed) : _naziv(naziv), _vrijednost(vrijed) {}

	void setVrijednost(double v) {
		_vrijednost = v;
	}

	double getVrijednost() const {
		return _vrijednost;
	}

	void setNaziv(string naziv) {
		_naziv = naziv;
	}

	string getNaziv() const {
		return _naziv;
	}
};

class Garaza {
private:
	int _sirina, _duljina;
	bool _automatskaVrata;
	string _lokacija;
public:
	vector<Predmet> predmeti;

	Garaza() = default;
	Garaza(int s, int d, bool autoVrata, string lokacija) : _sirina(s), _duljina(d), _automatskaVrata(autoVrata), _lokacija(lokacija) {}

	void setSirina(int s) {
		_sirina = s;
	}

	int getSirina() const {
		return _sirina;
	}

	void setDuljina(int d) {
		_duljina = d;
	}

	int getDuljina() const {
		return _duljina;
	}

	void setAutomatskaVrata(bool stanje) {
		_automatskaVrata = stanje;
	}

	int getAutomatskaVrata() const {
		return _automatskaVrata;
	}

	string getLokacija() const {
		return _lokacija;
	}

	void setLokacija(string lok) {
		_lokacija = lok;
	}
};

int main()
{
	int n = 0;
	cout << "Unesite broj garaza (N): ";
	cin >> n;

	vector<Garaza> garaze;

	for (int i = 0; i < n; i++)
	{
		int s, d; string lok, vr; bool vrata;

		cout << "Unesite velicinu, lokaciju i podatak o vratima za " << i + 1 << ". garazu: " << endl;
		cin >> s >> d;
		getline(cin >> ws, lok);
		cin >> vr;

		if (vr == "DA") vrata = true;
		else vrata = false;

		garaze.push_back(Garaza(s, d, vrata, lok));

		cout << "\n";
	}

	int m = 0;
	cout << "Unesite broj predmeta (M): ";
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int index = 0;

		cout << "Unesite redni broj garaze u koju spada " << i + 1 << ". predmet: ";
		cin >> index;

		string naziv; double vrijed;
		cout << "Unesite naziv i vrijednost predmeta: ";
		cin >> naziv >> vrijed;

		garaze[index - 1].predmeti.push_back(Predmet(naziv, vrijed));
	}

	cout << "\nIspis garaza i predmeta: " << endl;

	for (int i = 0; i < garaze.size(); i++)
	{
		cout << i + 1 << ". " << garaze[i].getLokacija() << " " << garaze[i].getSirina() << "x" << garaze[i].getDuljina() << " - predmeti: ";

		for (int j = 0; j < garaze[i].predmeti.size(); j++)
		{
			if (j > 0) cout << ", ";
			cout << garaze[i].predmeti[j].getNaziv() << " (" << garaze[i].predmeti[j].getVrijednost() << ")";
		}

		cout << endl;
	}

	return 0;
}