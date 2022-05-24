#include<iostream>
#include<functional>

using namespace std;

int main() {

	/* 1. dio zadatka */

	function<int(int)> faktorijel = [&faktorijel](int n) {
		if (n <= 1) {
			return 1;
		}

		return n * faktorijel(n - 1);
	};

	cout << faktorijel(5) << endl;

	/* 2. dio zadatka */

	vector<int> broj = { 1, 25, 63, 12, 54, 7, 83, 77, 97 };
	int kolicina = 0;

	[&kolicina](const vector<int>& niz) {
		kolicina = 0;

		for (int i = 0; i < niz.size(); i++)
		{
			bool prim = true;

			for (int j = 2; j < niz[i] / 2 ; j++) {
				if (niz[i] % j == 0) {
					prim = false;
					break;
				}
			}

			if (prim) {
				cout << niz[i] << " ";
				kolicina++;
			}
		}
	}(broj);

	cout << "\n" << kolicina << endl;

	return 0;
}