#include<iostream>
#include <map>

using namespace std;

int main() {

	map<string, int> ime;

	int n;
	cout << "Unesite N: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string tmp;

		cout << "Unesite ime: ";
		cin >> tmp;
		ime[tmp]++; // ime["Ante"]++;
	}

	//map<string, int>::iterator max = ime.begin(); // iterator
	auto max = ime.begin(); // kraci zapis, kompajler ce sam odrediti tip

	for (auto it = ime.begin(); it != ime.end(); it++)
	{
		if (it->second > max->second) {
			max = it;
		}
	}

	cout << "Najvise pojavljivanja: " << max->first << ", " << max->second;

	return 0;
}