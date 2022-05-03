#include<iostream>

#define PI 3.141592653589793238462643383

using namespace std;

class Bubble {
private:
	string color;
	double r;
public:
	Bubble(string color, double radius) : r(radius), color(color) {}

	void setColor(string color) { this->color = color; }
	void setRadius(double r) { this->r = r; }

	string getColor() const { return color; }
	double getRadius() const { return r; }
	double getVolume() const { return (double)4 / 3 * pow(this->r, 3) * PI; }

	Bubble operator + (const Bubble& b) {
		double volume = this->getVolume() + b.getVolume();
		double r = pow((3*volume)/(4*PI), (double)1 / 3);
		string color = this->getVolume() > b.getVolume() ? this->color : b.color;

		return Bubble(color, r);
	}

	Bubble operator - (const Bubble& b) {
		double volume = this->getVolume() - b.getVolume();
		if (volume < 0) volume *= -1;

		double r = pow((3 * volume) / (4 * PI), (double)1 / 3);

		return Bubble(this->color, r);
	}
};

ostream& operator << (ostream& out, const Bubble& a) {
	// zbog enkapsulacije nije potrebno koristiti friend funkciju
	out << a.getColor() << ": " << a.getRadius() << endl;
	return out;
}

bool operator == (const Bubble& a, const Bubble& b) {
	double diff = a.getRadius() - b.getRadius();
	if (diff < 0) diff *= -1;

	return diff <= 0.0001 || a.getColor() == b.getColor();
}

int main() {
	Bubble a("blue", 10.4);
	Bubble b("red", 7.2);
	Bubble c("green", 18.8);

	Bubble x = a + b; //nastat æe novi bubble obujma 6275.27
	cout << x; //blue: 11.44
	Bubble y = x + c;
	cout << y; //green: 20.12

	Bubble z = y - x;
	cout << z; //green: 18.8

	if (z == c)
		cout << "OK" << endl; //OK

	return 0;
}