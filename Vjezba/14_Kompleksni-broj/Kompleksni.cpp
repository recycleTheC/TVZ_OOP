#include "Kompleksni.h"

Kompleksni::Kompleksni(double realni, double imaginarni) : re(realni), im(imaginarni) {}

Kompleksni& Kompleksni::operator = (const Kompleksni& z) {
	this->re = z.re;
	this->im = z.im;

	return *this;
}

Kompleksni Kompleksni::operator + (Kompleksni& z) {
	return Kompleksni(this->re + z.re, this->im + z.im);
}

Kompleksni Kompleksni::operator - (Kompleksni& z) {
	return Kompleksni(this->re - z.re, this->im - z.im);
}

Kompleksni Kompleksni::operator * (Kompleksni& z) {
	double realni = this->re * z.re + this->im * z.im;
	double imaginarni = this->re * z.im + this->im * z.re;

	return Kompleksni(realni, imaginarni);
}

Kompleksni& Kompleksni::operator ++() {
	// prefiks
	++re;
	++im;
	return *this;
}

Kompleksni Kompleksni::operator ++(int) {
	// postfiks
	Kompleksni tmp = *this;
	re++;
	im++;
	return tmp;
}

// ne-èlanske operatorske funkcije:

Kompleksni operator - (Kompleksni z, double br) {
	return Kompleksni(z.re - br, z.im);
}

Kompleksni operator - (double br, const Kompleksni z) {
	return Kompleksni(br - z.re, z.im);
}