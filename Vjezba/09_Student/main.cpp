#include<iostream>

using namespace std;

class Student {
private:
	char* jmbag = NULL;
public:
	Student() {}

	Student(const char* jmbag) {
		this->jmbag = new char[11];
		strcpy_s(this->jmbag, 11, jmbag);
	}

	~Student() {
		delete[] jmbag;
	}

	Student(const Student& st) {
		//kopirni konstruktor & duboko kopiranje
		this->jmbag = new char[11];
		strcpy_s(this->jmbag, 11, st.jmbag);
	}

	Student& operator = (const Student& st) {
		// operator pridruzivanja & duboko kopiranje
		if (this != &st) {
			delete[] this->jmbag;
			this->jmbag = new char[11];
			strcpy_s(this->jmbag, 11, st.jmbag);
		}
		return *this;
	}

	Student(Student&& st) {
		//konstruktor prijenosa
		this->jmbag = st.jmbag;
		st.jmbag = NULL;
	}

	Student& operator = (Student&& st) {
		// operator pridruzivanja & prijenos
		delete[] this->jmbag;
		this->jmbag = st.jmbag;
		st.jmbag = NULL;

		return *this;
	}

	char* GetJMBAG() const {
		return jmbag;
	}

	void SetJMBAG(const char* noviJMBAG) {
		if (this->jmbag == NULL) {
			this->jmbag = new char[11]; // alokacija memorije za novi jmbag
		}

		strcpy_s(this->jmbag, 11, noviJMBAG);
	}

};

int main() {
	Student Ante("1122334455");
	Student Ivica = Ante;

	Ante.SetJMBAG("6677889900");

	cout << Ante.GetJMBAG() << endl; // 6677889900
	cout << Ivica.GetJMBAG() << endl; // 1122334455

	Student Marko;
	Marko = Ante;

	Marko.SetJMBAG("1234567890");

	cout << Marko.GetJMBAG() << endl; // 1234567890
	cout << Ante.GetJMBAG() << endl; // 6677889900 

	return 0;
}