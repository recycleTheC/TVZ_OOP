#include "Matematika.h"

using namespace Matematika;

Operacija::Operacija(short a, short b, char operacija) : operand1(a), operand2(b), operacija(operacija) {}

short Operacija::rezultat() const {
	short rezultat = 0;

	if (operacija == '/') {
		if (operand2 == 0) {
			throw operand1; // baca se 1. operand zbog ispisa poruke: "Broj x se ne moze dijeliti s 0!"
		}
	}
	if (operacija == '+') rezultat = operand1 + operand2;
	if (operacija == '-') rezultat = operand1 - operand2;
	if (operacija == '*') rezultat = operand1 * operand2;
	if (operacija == '/') rezultat = operand1 / operand2;
	if (operand1 > 0 && operand2 > 0 && rezultat < 0) throw "Integer overflow!";

	return rezultat;
}