#pragma once

#include <string>
using namespace std;

class Grad {
private:
	string naziv;
	string drzava;
public:
	
	Grad(void){}
	Grad(string naziv, string drzava) :naziv(naziv), drzava(drzava){}

	string getNaziv()
	{
		return naziv;
	}

	void setNaziv(string naziv)
	{
		this->naziv = naziv;
	}
	
	string getDrzava()
	{
		return drzava;
	}
	
	void setDrzava(string drzava)
	{
		this->drzava = drzava;
	}
};