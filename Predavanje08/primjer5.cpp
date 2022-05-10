#include<iostream>

using namespace std;

template<class T>
class Polje {
public:
	T* p;
	int brElem;

	Polje(int brEl) : brElem(brEl), p(new T[brEl]) {}
	~Polje() {
		delete[] p;
	}

	T& operator[] (int index) { return p[index]; }
	int trazi(T v) {
		for (int i = 0; i < brElem; i++)
		{
			if (p[i] == v) return i;
		}

		return -1;
	}
};

int main() {

	Polje<int> p(10);

	p[0] = 10;
	cout << p[0] << endl;
	cout << p.trazi(10) << endl;

	return 0;
}