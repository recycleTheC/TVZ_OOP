#include <iostream>
#include <vector>

using namespace std;

class Racunalo {
protected:
	string os;
public:
	Racunalo() = default;
	Racunalo(string os) : os(os) {}

	virtual string getTip() const { return "racunalo"; }
	virtual string getOS() const final { return os; }
};

class Tablet : public Racunalo {
public:
	Tablet(string os) : Racunalo(os) {}

	string getTip() const override { return "tablet"; }
};

class Laptop : public Racunalo {
public:
	Laptop(string os) : Racunalo(os) {}

	string getTip() const override { return "laptop"; }
};

void AnalizaUcionice(const vector<Racunalo*> ucionica, int* tableti, int* laptopi, int* android, int* windows, int* linux) {
	*tableti = 0;
	*laptopi = 0;
	*android = 0;
	*windows = 0;
	*linux = 0;

	for (int i = 0; i < ucionica.size(); i++)
	{
		string os = ucionica[i]->getOS();
		string tip = ucionica[i]->getTip();

		if (os == "Windows") *windows += 1;
		else if (os == "Android") *android += 1;
		else if (os == "Linux") *linux += 1;

		if (tip == "laptop") *laptopi += 1;
		else if (tip == "tablet") *tableti += 1;
	}
}

int main() {
	int brTableta, brLaptopa;
	int brAndroida, brWindowsa, brLinuxa;

	Tablet Acer("Android"), Prestigio("Windows");
	Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

	vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
	AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);

	/* u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

	U ucionici se nalazi 5 racunala
	Broj tablet racunala : 2
	Broj laptop racunala : 3
	Android OS : 1
	Windows OS : 3
	Linux OS : 1
	*/

	cout << "U ucionici se nalazi " << Ucionica1.size() << " racunala" << endl;
	cout << "Broj tablet racunala: " << brTableta << endl;
	cout << "Broj laptop racunala: " << brLaptopa << endl;
	cout << "Android OS: " << brAndroida << endl;
	cout << "Windows OS: " << brWindowsa << endl;
	cout << "Linux OS: " << brLinuxa << endl;

	return 0;
}