#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Complex {
private:
	double _real, _im;

public:

	Complex(double re, double im) {
		this->_real = re;
		this->_im = im;
	}

	Complex() : _real(0), _im(0) {}

	double getRealPart() const {
		return _real;
	}

	void setRealPart(double r) {
		this->_real = r;
	}

	double getImPart() const {
		return this->_im;
	}

	void setImPart(double im) {
		this->_im = im;
	}

	double Module() const {
		return sqrt((_real * _real) + (_im * _im)); // vraca double vrijednost
	}

	string toString() const {
		string text = "Z(" + to_string(_real);

		if (_im < 0) {
			text += to_string(_im);
		}
		else {
			text += "+" + to_string(_im);
		}

		text += "i)";

		return text;
	}
};

bool compare(Complex& a, Complex& b) {
	return a.Module() < b.Module();
}

int main() {
	int n;

	cout << "Unesi N: ";
	cin >> n;

	vector<Complex> kompleksni;

	for (int i = 0; i < n; i++)
	{
		Complex tmp;
		double val;

		cout << "niz[" << i << "].re = ";
		cin >> val;
		tmp.setRealPart(val);
		cout << "niz[" << i << "].im = ";
		cin >> val;
		tmp.setImPart(val);

		kompleksni.push_back(tmp);
	}

	sort(kompleksni.begin(), kompleksni.end(), compare);

	for (int i = 0; i < kompleksni.size(); i++)
	{
		cout << kompleksni[i].toString() << " Modul: " << kompleksni[i].Module() << endl;
	}

	return 0;
}