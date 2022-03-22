#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Kompleksni {
public:
	double realni, imaginarni;
};

double Modul(Kompleksni z) {
	return pow((z.realni * z.realni + z.imaginarni * z.imaginarni), 0.5);
}

void Sortiraj(Kompleksni* niz, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		// j = 0; j < n - 1 - i
		for (int j = i + 1; j < n; j++)
		{
			if (Modul(niz[i]) > Modul(niz[j])) {
				Kompleksni tmp = niz[i];
				niz[i] = niz[j];
				niz[j] = tmp;
			}
		}
	}
}

bool usporedba(Kompleksni z1, Kompleksni z2) {
	return Modul(z1) > Modul(z2);
}

int main() {

	int n;
	//Kompleksni* niz;
	vector<Kompleksni> niz;

	cout << "N: ";
	cin >> n;

	//niz = (Kompleksni*)malloc(sizeof(Kompleksni) * n);
	//niz = new Kompleksni[n];

	for (int i = 0; i < n; i++)
	{
		Kompleksni tmp;

		cout << "niz[" << i << "].re = ";
		cin >> tmp.realni;
		cout << "niz[" << i << "].im = ";
		cin >> tmp.imaginarni;

		niz.push_back(tmp);
	}

	//Sortiraj(niz, n);

	sort(niz.begin(), niz.end(), usporedba);

	for (int i = 0; i < n; i++)
	{
		cout << "Z(" << niz[i].realni << ((niz[i].imaginarni > 0) ? "+" : "") << niz[i].imaginarni << "i) Modul: " << Modul(niz[i]) << endl;
	}

	//free(niz);
	//delete[] niz;

	return 0;
}