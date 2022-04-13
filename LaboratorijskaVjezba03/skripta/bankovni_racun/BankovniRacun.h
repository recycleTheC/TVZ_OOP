#pragma once

#include<iostream>
#include<string>

using namespace std;

class BankovniRacun
{
private:
	string brojRacuna, tipKlijenta, tipRacuna;
public:
	BankovniRacun();
	BankovniRacun(string brojRacuna, string tipKlijenta, string tipRacuna);
	~BankovniRacun();

	void setBrojRacuna(string brojRacuna);
	string getBrojRacuna() const;

	void setTipKlijenta(string tipKlijenta);
	string getTipKlijenta() const;

	void setTipRacun(string tipRacuna);
	string getTipRacuna() const;

	string toString() const;
};

