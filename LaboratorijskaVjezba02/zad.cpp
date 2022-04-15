#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Predmet {
public:
	string naziv;
	int sifra = 0;
	int ocjena = 0;

	Predmet() {}
	~Predmet() {}
	Predmet(int sifra, string naziv, int ocjena) : naziv(naziv), sifra(sifra), ocjena(ocjena) {}
};
class Student {
private:
	static bool test(Predmet& a, Predmet& b) {
		return a.ocjena < b.ocjena;
	}
public:
	string ime, prezime;
	vector<Predmet> predmeti;

	Student() {}
	~Student() {}
	Student(string ime, string prezime, Predmet predmet) {
		this->ime = ime;
		this->prezime = prezime;
		this->predmeti.push_back(predmet);
	}

	vector<Predmet> Odlican();

	void Sortiraj() {
		sort(predmeti.begin(), predmeti.end(), test);
	}

	double Prosjek() const {
		if (predmeti.size() < 1) return -1;

		double total = 0;

		for (int i = 0; i < predmeti.size(); i++)
		{
			total += predmeti[i].ocjena;
		}

		return total / (double)predmeti.size();
	}
};

vector<Predmet> Student::Odlican() {
	vector<Predmet> odlicni;

	for (int i = 0; i < predmeti.size(); i++)
	{
		if (predmeti[i].ocjena == 5) {
			odlicni.push_back(predmeti[i]);
		}
	}

	return odlicni;
}

Student NajboljiStudent(vector<Student> studenti) {
	int najbolji = 0;

	for (int i = 1; i < studenti.size(); i++)
	{
		if (studenti[i].Prosjek() > studenti[najbolji].Prosjek()) {
			najbolji = i;
		}
	}

	return studenti[najbolji];
}

int main() {
	Predmet Matematika(1260, "Matematika", 5); // zadani primjer
	Student Ivica("Ivica", "Ivic", Matematika);

	return 0;
}