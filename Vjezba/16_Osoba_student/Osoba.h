#pragma once

#include<iostream>
#include<string>

using namespace std;

class Osoba {
public:
	string ime, prezime, oib;

	Osoba(string oib);
	virtual void RadniStatus() const;
};