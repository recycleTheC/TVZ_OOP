#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Niz {
private:
	vector<T> polje;
public:
	Niz(const vector<T>& polje) {
		this->polje = polje;
	}

	T& operator[] (int index) const {
		return this->polje[index];
	}

	bool manje_od(const Niz& t) const {
		int n = t.polje.size() <= this->polje.size() ? t.polje.size() : this->polje.size();

		for (int i = 0; i < n; i++)
		{
			if (this->polje[i] > t.polje[i]) return false;
		}

		return true;
	}
};

template<class T>
bool operator < (const Niz<T>& a, const Niz<T>& b) {
	return a.manje_od(b);
}

template<class T>
bool operator >= (const Niz<T>& a, const Niz<T>& b) {
	return !a.manje_od(b);
}

template<class T>
class Niz2 {
private:
	vector<T> polje;
public:
	Niz2(const vector<T>& polje) {
		this->polje = polje;
	}

	T& operator[] (int index) {
		return this->polje[index];
	}

	bool operator < (const Niz2& t) const {
		int n = t.polje.size() <= this->polje.size() ? t.polje.size() : this->polje.size();

		for (int i = 0; i < n; i++)
		{
			if (this->polje[i] > t.polje[i]) return false;
		}

		return true;
	}
};

int main() {
	vector<int> v1 = { 1, 2, 3 };
	vector<int> v2 = { 11, 0, 13 };

	Niz<int> p1(v1);
	Niz<int> p2(v2);

	cout << "p1 < p2: " << p1.manje_od(p2) << endl;
	cout << "p1 < p2: " << (p1 < p2) << endl;
	cout << "p1 >= p2: " << (p1 >= p2) << endl;

	Niz2<int> p3(v1);
	Niz2<int> p4(v2);

	cout << "p3 < p4: " << (p3 < p4) << endl;

	return 0;
}