/*
a) napisati klasu Student (ime, prezime, položeni predmeti) i klasa Predmet (naziv, šifra, ocjena)
b) prema zadanom primjeru napraviti konstruktor koji prima ime, prezime i jedan predmet
c) napisati metodu Sortiraj u klasi Student koja æe sortirati predmete po ocjeni (od najveæe do najmanje)
d) deklarirati metodu Odlicni u klasi Student koja vraæa niz predmeta iz kojih student ima 5 i implementirati metodu izvan klase
e) globalna metoda NajboljiStudent koja prima niz studenata i mora vratiti onog koji ima najveæi prosjek ocjena.
*/

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

bool test(Predmet& a, Predmet& b) {
	return a.ocjena < b.ocjena;
}

class Student {
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