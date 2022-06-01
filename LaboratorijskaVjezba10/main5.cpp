#include<iostream>
#include<vector>
#include<functional>

using namespace std;

class Student {
private:
	string _ime, _prezime, _jmbag;
public:
	Student(string ime, string prezime, string jmbag) : _ime(ime), _prezime(prezime), _jmbag(jmbag) {}

	string ime() const { return this->_ime; }
	string prezime() const { return this->_prezime; }
	string jmbag() const { return this->_jmbag; }
};

vector<Student*> nadji(vector<Student>& v, function<bool(Student*)> kriterij) {
	vector<Student*> izdvojeni;

	for (int i = 0; i < v.size(); i++)
	{
		if (kriterij(&v[i])) izdvojeni.push_back(&v[i]); // u vektor se sprema pokazivac postojeceg studenta
	}

	return izdvojeni;
}

int main() {
	vector<Student> v = { 
		Student("Pero", "Peric", "0246"),
		Student("Ivan", "Ivic", "1357"),
		Student("Ivo", "Ivic", "9013"),
		Student("Ivan", "Juric", "4650")
	};

	// naði sve studente s imenom Ivan
	vector<Student*> r = nadji(v, [](Student* s) { return s->ime() == "Ivan"; });

	/* Ispisuje
		Ivan Ivic 1357
		Ivan Juric 4650
	*/

	for (Student* s : r) {
		cout << s->ime() << " " << s->prezime() << " " << s->jmbag() << endl;
	}

	return 0;
}