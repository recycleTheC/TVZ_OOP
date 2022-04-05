#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Student {
private:
	string _ime, _jmbag;
public:
	Student() = default;
	Student(string ime, string jmbag) : _ime(ime), _jmbag(jmbag) {}

	string getIme() const {
		return _ime;
	}

	string getJMBAG() const {
		return _jmbag;
	}
};

class Bodovi {
private: 
	int _bodovi;
public:
	Student student;

	Bodovi() = default;
	Bodovi(Student student, int bodovi) : student(student), _bodovi(bodovi) {}

	int getBodovi() const {
		return _bodovi;
	}
};

class Kolegij {
private:
	string _naziv;
public:
	vector<Bodovi> bodovi;

	Kolegij() = default;
	Kolegij(string naziv, vector<Bodovi> bodovi) : _naziv(naziv), bodovi(bodovi){}

	string getNaziv() const {
		return _naziv;
	}
};

bool usporedba(Bodovi& a, Bodovi& b) {
	return a.getBodovi() < b.getBodovi();
}

int main() {

	vector<Bodovi> OOPBodovi{
		Bodovi(Student("Ivana Ivic", "0246002475"), 25),
		Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
		Bodovi(Student("Marko Markic", "0246004234"), 32)
	};

	Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);

	/* Preko objekta OOP ispišite bodove svih studenata tog kolegija poèevši od
	   onih s najmanjim brojem bodova prema veæim. Npr.;

	   Objektno orijentirano programiranje bodovi:
	   Ivica Ivanovic  0246005654      20
	   Ivana Ivic      0246002475      25
	   Marko Markic    0246004234      32
	*/

	sort(OOP.bodovi.begin(), OOP.bodovi.end(), usporedba);

	cout << OOP.getNaziv() << " bodovi:\n";

	for (int i = 0; i < OOP.bodovi.size(); i++)
	{
		cout << OOP.bodovi[i].student.getIme() << " " << OOP.bodovi[i].student.getJMBAG() << " " << OOP.bodovi[i].getBodovi() << endl;
	}

	return 0;

}