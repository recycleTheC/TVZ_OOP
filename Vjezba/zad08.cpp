// Najstarija osoba
// za sada necu odvajati u .h i .cpp datoteke

#include<iostream>
#include<string>

using namespace std;

class Osoba {
private:
	string ime, prezime;
	int godinaRodjenja = 0; // postaviti neku default vrijednost ?!

	string pretvarac(const string& tekst) {
		string pretvoreni = tekst;
		pretvoreni[0] = toupper(pretvoreni[0]);

		for (int i = 1; i < pretvoreni.size(); i++)
		{
			pretvoreni[i] = tolower(pretvoreni[i]);
		}
		return pretvoreni;
	}
public:
	Osoba() = default;
	~Osoba() = default;
	Osoba(string ime, string prezime, int godRodj){
		setIme(ime);
		setPrezime(prezime);
		setGodinaRodjenja(godRodj);
	}

	string getIme() const {
		return ime;
	}

	void setIme(string ime) {
		this->ime = pretvarac(ime);
	}

	string getPrezime() const {
		return prezime;
	}

	void setPrezime(string prezime) {
		this->prezime = pretvarac(prezime);
	}

	int getGodinaRodjenja() const {
		return godinaRodjenja;
	}

	void setGodinaRodjenja(int godina) {
		if (godina > 1900) {
			this->godinaRodjenja = godina;
		}
		else {
			cout << "Neispravna godina rodjenja!\n";
		}
	}

	string toString() const {
		return ime + " " + prezime + " (" + to_string(godinaRodjenja) + ")";
	}
};

int main() {
	int n = 5;
	Osoba* osobe = new Osoba[n];

	for (int i = 0; i < n; i++)
	{
		string ime, prezime; int godina;

		cout << "Upisi podatke za " << i + 1 << ". osobu:" << endl;

		cout << "- ime: ";
		cin >> ime;

		cout << "- prezime: ";
		cin >> prezime;

		cout << "- godina rodjenja: ";
		cin >> godina;

		osobe[i] = Osoba(ime, prezime, godina);
	}

	int najstarijaOsoba = 0;

	for (int i = 1; i < n; i++)
	{
		if (osobe[najstarijaOsoba].getGodinaRodjenja() > osobe[i].getGodinaRodjenja()) {
			najstarijaOsoba = i;
		}
	}

	cout << "Najstarija osoba: ";
	cout << osobe[najstarijaOsoba].toString() << endl;

	return 0;
}