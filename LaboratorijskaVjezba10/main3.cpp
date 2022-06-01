#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Red {
private:
	vector<T> elementi;
public:
	void Dodaj(T el) {
		this->elementi.push_back(el);
	}
	
	void Brisi() {
		//this->elementi.erase(this->elementi.end() - 1);
		this->elementi.pop_back();
	}

	int BrojElemenata() const { return this->elementi.size(); }

	T& operator[] (int index) {
		return this->elementi[index];
	}
};

int main() {
	Red<int> red;

	red.Dodaj(1);
	red.Dodaj(2);
	red.Dodaj(3);

	/* 1 2 3 */
	for (int i = 0; i < red.BrojElemenata(); i++)
		cout << red[i] << " ";
	cout << endl;

	red.Brisi();
	/* 1 2 */
	for (int i = 0; i < red.BrojElemenata(); i++)
		cout << red[i] << " ";
	cout << endl;

	red.Brisi();
	/* 1 */
	for (int i = 0; i < red.BrojElemenata(); i++)
		cout << red[i] << " ";
	cout << endl;

	return 0;
}