#include<iostream>
#include<vector>

using namespace std;

template<class T1, class T2>
class Par {
private:
	T1 k; T2 v;
public:
	Par(T1 k, T2 el) : k(k), v(el) {}

	bool operator == (const Par& p) {
		return this->k == p.k && this->v == p.v;
	}

	T1& kljuc() { return this->k; }
	T2& vrijednost() { return this->v; }
};

class KolekcijaException {
public:
	const char* what() {
		return "Trazeni element ne postoji!";
	}
};

template<class T>
class Kolekcija {
private:
	vector<T> elementi;
public:
	Kolekcija() = default;

	void dodaj(T& el) {
		this->elementi.push_back(el);
	}

	T* nadji(T el) {
		for (int i = 0; i < elementi.size(); i++)
		{
			if (el == elementi[i]) return &elementi[i];
		}

		throw(KolekcijaException());
	}
};

int main() {

	Par<string, string> dok1("a", "test1");
	Par<string, string> dok2("b", "test2");

	Kolekcija<Par<string, string>> kol_str;

	kol_str.dodaj(dok1);
	kol_str.dodaj(dok2);

	// ispisuje b:test2
	try {
		Par<string, string>* x = kol_str.nadji(Par<string, string>("b", "test2"));
		cout << x->kljuc() << ":" << x->vrijednost() << endl;
	}
	catch (KolekcijaException& e) {
		cout << e.what();
	}
	// ispisuje "trazeni element ne postoji"
	try {
		Par<string, string>* y = kol_str.nadji(Par<string, string>("X", "TEST"));
		cout << y->kljuc() << ":" << y->vrijednost() << endl;
	}
	catch (KolekcijaException& e) {
		cout << e.what();
	}

	return 0;
}