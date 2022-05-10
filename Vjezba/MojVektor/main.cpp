#include<iostream>
#include<vector>

using namespace std;

class MojVektorException {
public:
	const char* ispis() {
		return "Navedeni indeks ne postoji!";
	}
};

class MojVektor {
private:
	vector<double> realni;
	static int _instance;
public:
	MojVektor() {
		_instance++;
	}

	~MojVektor() {
		_instance--;
	}

	static int brojac() { return _instance; }
	double getElement(int index);

	MojVektor& operator ++() {
		for (int i = 0; i < realni.size(); i++)
		{
			realni[i]++;
		}

		return *this;
	}

	MojVektor operator ++(int) {
		MojVektor tmp = *this;

		for (int i = 0; i < realni.size(); i++)
		{
			realni[i]++;
		}

		return tmp;
	}

	friend MojVektor operator + (const MojVektor& a, const MojVektor& b);
	friend ostream& operator << (ostream& izlaz, const MojVektor& v);
	friend istream& operator >> (istream& ulaz, MojVektor& v);
};

double MojVektor::getElement(int index) {
	if (index < 0 || index >= realni.size()) throw MojVektorException();
	else return realni[index];
}

MojVektor operator + (const MojVektor& a, const MojVektor& b) {
	MojVektor rez;

	for (int i = 0; i < a.realni.size(); i++)
	{
		rez.realni.push_back(a.realni[i]);
	}

	for (int i = 0; i < b.realni.size(); i++)
	{
		rez.realni.push_back(b.realni[i]);
	}

	return rez;
}

ostream& operator << (ostream& izlaz, const MojVektor& v) {
	for (int i = 0; i < v.realni.size(); i++)
	{
		izlaz << v.realni[i] << " ";
	}

	return izlaz;
}

istream& operator >> (istream& ulaz, MojVektor& v) {
	// moze biti izvedeno i drugacije

	double br;
	ulaz >> br;

	v.realni.push_back(br);

	return ulaz;
}

int MojVektor::_instance = 0;

int main() {
	MojVektor vektor1;
	MojVektor vektor2;
	MojVektor vektor3;

	cout << MojVektor::brojac() << endl;

	try {
		vektor1.getElement(-1);
	}
	catch (MojVektorException ex) {
		cout << ex.ispis() << endl;
	}

	// dodaju se 3 elementa ucitana iz konzole
	cin >> vektor1; 
	cin >> vektor1;
	cin >> vektor1;

	MojVektor vektor4 = vektor1 + vektor2;

	cout << vektor4++ << endl;
	cout << ++vektor4 << endl;

	cout << vektor4 << endl;

	return 0;
}