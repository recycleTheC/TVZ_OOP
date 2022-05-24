#include<iostream>
#include<vector>
#include<functional>

using namespace std;

vector<int> izdvoji(const vector<int>& v, function<bool(int)> uvjet) {
	vector<int> izdvojeni;

	for (int i = 0; i < v.size(); i++)
	{
		if (uvjet(v[i])) {
			izdvojeni.push_back(v[i]);
		}
	}

	return izdvojeni;
}

int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	vector<int> rez = izdvoji(brojevi, [](int br) {
			int zn1 = br % 10;
			int zn2 = (br / 10) % 10;

			if (zn1 % 2 != 0 && zn2 % 2 != 0) return true;
			else return false;
		});

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 55 433 433

	return 0;
}