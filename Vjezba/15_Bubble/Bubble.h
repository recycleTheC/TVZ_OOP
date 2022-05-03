#pragma once

#include<iostream>

#define PI 3.141592653589793238462643383

using namespace std;

class Bubble {
private:
	string color;
	double r;
public:
	Bubble(string color, double radius);

	void setColor(string color);
	void setRadius(double r);

	string getColor() const;
	double getRadius() const;
	double getVolume() const;

	Bubble operator + (const Bubble& b);
	Bubble operator - (const Bubble& b);
};

ostream& operator << (ostream& out, const Bubble& a);
bool operator == (const Bubble& a, const Bubble& b);