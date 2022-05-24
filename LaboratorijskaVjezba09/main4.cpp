#include<iostream>
#include<vector>
#include <functional>

using namespace std;

vector<int> izdvoji(const vector<int>& vektor, function<bool(int, int)> kriterij) {
	vector<int> izdvojeni;

	for (int i = 0; i < vektor.size(); i++)
	{
		if (kriterij(vektor[i], i)) {
			izdvojeni.push_back(vektor[i]);
		}
	}

	return izdvojeni;
}

int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };
	vector<int> rez = izdvoji(brojevi, [](int a, int index) {
		index++;
		if (a % index == 0) return true;
		else return false;
	});

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " "; //ispis: 1 4 6

	return 0;
}