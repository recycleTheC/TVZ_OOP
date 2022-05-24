#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>

using namespace std;

int main() {
	// 1. zadatak
	// umjesto ? napisati funkcijski objekt a zatim i lambda izraz kojim se vektor
	// v sortira od najmanje vrijednosti prema veæoj
	vector<int> v = { 3, -1, 0, 4, 1 };
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 2. zadatak
	// neka postoje cjelobrojne varijable x, y i umnozak. pomoæu barem 3 razlièite
	// lambda funkcije prikažite da je umnožak = x * y
	int x = 2, y = 3, umnozak;

	umnozak = [](int a, int b) { return a * b; }(x, y);
	umnozak = [x, y]() { return x * y; }();
	umnozak = [=]() { return x * y; }();
	umnozak = [&]() { return x * y; }();

	// 3. zadatak
	// napišite rekurzivnu lambda funkciju koja vraæa n-ti èlan fibonaccijevog niza
	// upotrebom delegata proizvoljnog imena

	function<int(int)> n_fibonacci = [&n_fibonacci](int n) {
		if (n <= 1) return n;

		return n_fibonacci(n - 1) + n_fibonacci(n - 2);
	};

	int n = 0;
	cout << "Upisi n: ";
	cin >> n;

	cout << n << ". clan Fibonaccijevog niza: " << n_fibonacci(n) << endl;

	return 0;
}