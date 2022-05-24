#include<iostream>
#include<vector>
#include<functional>

using namespace std;

vector<int> izdvoji(const vector<int>& vektor, function<bool(int)> kriterij) {
	vector<int> izdvojeni;

	for (int i = 0; i < vektor.size(); i++)
	{
		if (kriterij(vektor[i])) {
			izdvojeni.push_back(vektor[i]);
		}
	}

	return izdvojeni;
}

int main()
{
	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	vector<int> rez = izdvoji(brojevi, [](int a) {
			return a % 3 == 0;
		});

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 3 6 12 87 66 3 72 42

	return 0;
}