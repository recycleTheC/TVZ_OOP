#include<iostream>
#include<vector>
#include<functional>

using namespace std;

vector<int> izdvoji(const vector<int>& v, function<bool(int)> kriterij) {
	vector<int> izdvojeni;

	for (int i = 0; i < v.size(); i++)
	{
		if (kriterij(v[i])) izdvojeni.push_back(v[i]);
	}

	return izdvojeni;
}

int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	vector<int> rez = izdvoji(brojevi, [](int a) {
		if (a >= 10 && a <= 99) return true;
		else return false;
	});

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 12 65 32 87 55 23 22 66 32 76 72 42

	return 0;
}