#include<iostream>
#include<map>

using namespace std;

int main() {

	int n = 0;
	cout << "Upisite broj imena: ";
	cin >> n;

	map<string, int> imena;

	for (int i = 0; i < n; i++)
	{
		string ime;
		cout << "Upisite " << i + 1 << ". ime: ";
		cin >> ime;

		imena[ime]++;
	}

	map<string, int>::iterator max = imena.begin();

	for (auto it = ++imena.begin(); it != imena.end(); it++)
	{	// ++imena.begin() -> preskacemo prvi za koji pretpostavljamo da se najvise pojavljuje

		if (it->second > max-> second) {
			max = it;
		}
	}

	cout << "Najcesce ime: " << max->first << " (" << max->second << ")" << endl;

	return 0;
}