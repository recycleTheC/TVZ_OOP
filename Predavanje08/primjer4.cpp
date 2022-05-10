#include<iostream>

using namespace std;

class IntPolje {
public:
	int* p;
	int brElem;

	IntPolje(int brEl) : brElem(brEl) , p(new int[brEl]) {}
	~IntPolje() {
		delete[] p;
	}

	int& operator[] (int index) { return p[index]; }
	int trazi(int v) {
		for (int i = 0; i < brElem; i++)
		{
			if (p[i] == v) return i;
		}

		return -1;
	}
};

int main() {

	IntPolje p(10);

	p[0] = 10;
	cout << p[0] << endl;
	cout << p.trazi(10) << endl;

	return 0;
}