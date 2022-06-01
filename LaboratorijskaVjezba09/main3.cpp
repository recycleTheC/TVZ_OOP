#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Komparator {
public:
	bool vece_ili_jednako(T& a, T& b) {
		return a <= b;
	}
};

template<class P, class K>
bool usporedi(vector<P> vektor, K komparator) {
	for (int i = 0; i < vektor.size() - 1; i++)
	{
		for (int j = i + 1; j < vektor.size(); j++)
		{
			if (komparator.vece_ili_jednako(vektor[i], vektor[j])) return false;
		}
	}

	return true;
}

int main() {

	vector<int> v = { 12, 2, 1 };

	bool r = usporedi<int>(v, Komparator<int>());
	cout << "rezultat: " << r << endl; // treba ispisati 1

	return 0;
}