#pragma once

#include<iostream>

using namespace std;

class Kompleksni {
private:
	double re, im;
public:
	Kompleksni(double realni, double imaginarni);

	Kompleksni& operator = (const Kompleksni& z);
	Kompleksni operator + (Kompleksni& z);
	Kompleksni operator - (Kompleksni& z);
	Kompleksni operator * (Kompleksni& z);

	Kompleksni operator ++ (int);
	Kompleksni& operator ++ ();

	friend ostream& operator << (ostream& izlaz, const Kompleksni& Z);
	friend Kompleksni operator - (Kompleksni z, double br);
	friend Kompleksni operator - (double br, Kompleksni z);
};