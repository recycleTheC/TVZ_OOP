#include<iostream>
#include<map>

using namespace std;

class Recenica {
private:
	string spremnik;
public:
	Recenica(string rec) : spremnik(rec) {}

	operator string () {
		return this->spremnik;
	}

	bool operator == (const Recenica& r) {
		return this->spremnik == r.spremnik;
	}

	friend void izdvoji_rijeci(map<string, int>&, const Recenica&);
};

void izdvoji_rijeci(map<string, int>& rijeci, const Recenica& r) {
	string rijec;

	for (int i = 0; i < r.spremnik.size(); i++)
	{
		if (r.spremnik[i] != ' ') {
			rijec += r.spremnik[i];
		}
		else {
			if (rijec.size() != 0) rijeci[rijec] += 1;
			rijec = "";
		}
	}

	if (rijec.size() != 0) rijeci[rijec] += 1;
}

bool iste_rijeci(const Recenica& a, const Recenica& b) {
	map<string, int> rijeci;

	izdvoji_rijeci(rijeci, a);
	izdvoji_rijeci(rijeci, b);

	for (auto r : rijeci) {
		if (r.second != 2) return false;
	}

	return true;
}

double razlika(const Recenica& a, const Recenica& b) {
	map<string, int> rijeci;

	izdvoji_rijeci(rijeci, a);
	izdvoji_rijeci(rijeci, b);

	double razlicito = 0;

	for (auto r : rijeci) {
		if (r.second != 2) razlicito++;
	}

	return razlicito;
}

int main() {

	Recenica r1("ne znam koliko je sati");
	Recenica r2("sutra je praznik");
	Recenica r3("koliko je sati ne znam");
	Recenica r4("ne znam koliko je sati");
	Recenica r5("sutra je slavlje");

	// ispisuje "sutra je praznik"
	string recenica = r2;
	cout << recenica << endl;

	// ispisuje "recenice imaju iste rijeci"
	if (iste_rijeci(r4, r3)) {
		cout << "recenice imaju iste rijeci\n";
	}
	else {
		cout << "recenice nemaju iste rijeci\n";
	}

	// ispisuje "nisu iste recenice"
	if (r1 == r2) {
		cout << "iste recenice\n";
	}
	else {
		cout << "nisu iste recenice\n";
	}

	// ispisuje 0
	double razlika1 = razlika(r1, r4);
	cout << razlika1 << endl;

	//// ispisuje 6
	double razlika2 = razlika(r1, r2);
	cout << razlika2 << endl;

	//// ispisuje 2
	double razlika3 = razlika(r2, r5);
	cout << razlika3 << endl;

	return 0;
}