// Prosjek ocjena

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Kolegij {
public:
	string naziv;
	int ocjena = 0;

	Kolegij(string naziv, int ocjena) : naziv(naziv), ocjena(ocjena) {};
	Kolegij() = default;
};

class Student {
public:
	string imePrezime;
	vector<Kolegij> kolegiji;

	Student(string punoIme, vector<Kolegij> kolegiji) : imePrezime(punoIme), kolegiji(kolegiji) {};
};

int main() {

	int n;

	cout << "Upisi broj studenata: ";
	cin >> n;

	vector<Student> studenti;

	for (int i = 0; i < n; i++)
	{
		string ime;
		int brKolegija;

		cout << "Unesi ime i prezime " << i + 1 << ". studenta: ";
		getline(cin >> ws, ime);

		cout << "Unesi broj kolegija studenta: ";
		cin >> brKolegija;
		cout << endl;

		vector<Kolegij> kolegiji;

		for (int j = 0; j < brKolegija; j++)
		{
			Kolegij kolegij;

			cout << "Unesi naziv i ocjenu " << i + 1 << ". kolegija: ";
			cin >> kolegij.naziv;
			cin >> kolegij.ocjena;

			kolegiji.push_back(kolegij);

		}
		cout << endl;

		studenti.push_back(Student(ime, kolegiji));
	}

	string nazivKolegija;

	cout << "Unesite naziv kolegija: ";
	cin >> nazivKolegija;

	int m = 0;
	double prosjek = 0;

	for (int i = 0; i < studenti.size(); i++)
	{
		for (int j = 0; j < studenti[i].kolegiji.size(); j++)
		{
			if (studenti[i].kolegiji[j].naziv == nazivKolegija) {
				m++;
				prosjek += studenti[i].kolegiji[j].ocjena;
			}
		}
	}

	if (m == 0) {
		cout << "Nema upisanih studenata na kolegiju '" << nazivKolegija << "'" << endl;
	}
	else {
		prosjek /= m;
		cout << "Prosjek ocjena iz kolegija " << nazivKolegija << " iznosi " << prosjek << endl;
	}

	return 0;
}