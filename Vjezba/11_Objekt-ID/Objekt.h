#pragma once
class Objekt {
private:
	static inline int _instance = 0; // C++ 17 standard
	static inline int _zadnjiID = 0;
public:

	int ID;

	Objekt();
	~Objekt();

	static int BrojInstanci();
};

