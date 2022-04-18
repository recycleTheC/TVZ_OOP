#pragma once
class Slika {
private:
	static inline double _total = 0; // C++ 17
	static inline int _instance = 0;

	double cijena;

public:

	Slika(double iznos);
	~Slika();

	static double ProsjecnaCijena();
};

