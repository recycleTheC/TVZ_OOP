#include "Bubble.h"

Bubble::Bubble(string color, double radius) : r(radius), color(color) {}

void Bubble::setColor(string color) { this->color = color; }
void Bubble::setRadius(double r) { this->r = r; }

string Bubble::getColor() const { return color; }
double Bubble::getRadius() const { return r; }
double Bubble::getVolume() const { return (double)4 / 3 * pow(this->r, 3) * PI; }

Bubble Bubble::operator + (const Bubble& b) {
	double volume = this->getVolume() + b.getVolume();
	double r = pow((3 * volume) / (4 * PI), (double)1 / 3);
	string color = this->getVolume() > b.getVolume() ? this->color : b.color;

	return Bubble(color, r);
}

Bubble Bubble::operator - (const Bubble& b) {
	double volume = this->getVolume() - b.getVolume();
	if (volume < 0) volume *= -1;

	double r = pow((3 * volume) / (4 * PI), (double)1 / 3);

	return Bubble(this->color, r);
}

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