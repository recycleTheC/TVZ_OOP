#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class KompleksniBroj {
private:
	double realni, imaginarni;

public:

	KompleksniBroj(double re, double im) {
		this->realni = re;
		this->imaginarni = im;
	}

	KompleksniBroj() : realni(0), imaginarni(0) {}

	double getRealniDio() const {
		return realni;
	}

	void setRealniDio(double r) {
		this->realni = r;
	}

	double getImaginarniDio() const {
		return this->imaginarni;
	}

	void setImaginarniDio(double im) {
		this->imaginarni = im;
	}

	double Modul() const {
		return sqrt((realni * realni) + (imaginarni * imaginarni)); // vraca double vrijednost
	}

	string toString() const {
		string text = "Z(" + to_string(realni);

		if (imaginarni < 0) {
			text += to_string(imaginarni);
		}
		else {
			text += "+" + to_string(imaginarni);
		}

		text += "i)";

		return text;
	}
};

bool compare(KompleksniBroj& a, KompleksniBroj& b) {
	return a.Modul() < b.Modul();
}

int main() {
	int n;

	cout << "Unesi N: ";
	cin >> n;

	vector<KompleksniBroj> kompleksni;

	for (int i = 0; i < n; i++)
	{
		KompleksniBroj tmp;
		double val;

		cout << "niz[" << i << "].re = ";
		cin >> val;
		tmp.setRealniDio(val);
		cout << "niz[" << i << "].im = ";
		cin >> val;
		tmp.setImaginarniDio(val);

		kompleksni.push_back(tmp);
	}

	sort(kompleksni.begin(), kompleksni.end(), compare);

	for (int i = 0; i < kompleksni.size(); i++)
	{
		cout << kompleksni[i].toString() << " Modul: " << kompleksni[i].Modul() << endl;
	}

	return 0;
}