#include<iostream>

using namespace std;

template<class T>
class Polje {
public:
	int BrElem = 0;
	T* polje;

	Polje(int n) {
		this->BrElem = n;
		this->polje = new T[n];
	}

	T& operator[](int index) {
		return polje[index];
	}

	int Sadrzi(int x) {
		for (int i = 0; i < this->BrElem; i++)
		{
			if (this->polje[i] == x) return i;
		}

		return -1;
	}

};

int main() {
	Polje<int> A(100);

	// inicijalizacija elemenata sluèajnim vrijednostima 1-100
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
		A[i] = rand() % 100 + 1; // A.polje[i] ...

	// ispiši broj elemenata
	cout << "Polje ima " << A.BrElem << " elemenata " << endl;

	// nalazi li se u polju broj x?
	int x = 58;
	int indeks = A.Sadrzi(x);

	if (indeks != -1) cout << "Broj " << x << " se nalazi u elementu s indeksom " << indeks << "!\n";
	else cout << "Broj " << x << " se ne nalazi u polju!\n";
}