#include<iostream>
#include<vector>
#include<functional>

using namespace std;

int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	int increment = 3;

	// lambda funkcija - jedno od mogucih rjesenja:
	[=, &brojevi]() {
		for (int i = 0; i < brojevi.size(); i++)
		{
			brojevi[i] += increment;
		}
	}();

	for (int i = 0; i < brojevi.size(); i++)
		cout << brojevi[i] << " ";
	//ispis: 4 7 8 10 6 ...

	return 0;
}