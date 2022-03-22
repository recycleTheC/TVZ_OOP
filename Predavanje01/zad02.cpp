#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Student {
public:
	string jmbag, imePrezime;

	Student(string imePrezime, string jmbag) {
		this->imePrezime = imePrezime;
		this->jmbag = jmbag;
	}
};

class Bodovi {
public:
	Student student;
	int bod;

	Bodovi(Student stud, int bodovi) : student(stud), bod(bodovi) {};
};

class Kolegij {
public:
	string naziv;
	vector<Bodovi> bodovi;

	Kolegij(string _naziv, vector<Bodovi> _bodovi) : naziv(_naziv), bodovi(_bodovi) {};
};

bool usporedba(Bodovi A, Bodovi B) {
	return A.bod < B.bod;
}

int main() {

	vector<Bodovi> OOPBodovi{
		Bodovi(Student("Pero Peric", "0246101010"), 75),
		Bodovi(Student("Marta Matic", "0246101010"), 24),
		Bodovi(Student("Ivo Ivic", "0246101010"), 34),
	};

	Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);

	sort(OOP.bodovi.begin(), OOP.bodovi.end(), usporedba);

	for (int i = 0; i < OOP.bodovi.size(); i++)
	{
		cout << OOP.bodovi[i].student.imePrezime << ": " << OOP.bodovi[i].bod << endl;
	}

	return 0;
}