#pragma once

#include<iostream>

using namespace std;

class Igrac {
private:
	static inline int _instance = 0;
	static inline int _pocetnici = 0;
public:
	string id;
	bool pocetnik;

	Igrac(string id, bool pocetnik);

	static int brojPocetnika();
};

