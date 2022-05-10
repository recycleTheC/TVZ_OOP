#include<iostream>
#include<vector>

using namespace std;

class Racunalo {
protected:
    string operacijski_sustav;
public:
    Racunalo() = default;
    Racunalo(string os) : operacijski_sustav(os) {}
    virtual string getOperacijskiSustav() const = 0;
    virtual string getTipRacunala() const = 0;
};

class Tablet : public Racunalo {
public:
    Tablet(string os) : Racunalo(os) {}
    string getOperacijskiSustav() const { return this->operacijski_sustav; }
    string getTipRacunala() const { return "tablet"; }
};

class Laptop : public Racunalo {
public:
    Laptop(string os) : Racunalo(os) {}

    string getOperacijskiSustav() const { return this->operacijski_sustav; }
    string getTipRacunala() const { return "laptop"; }
};

void AnalizaUcionice(vector<Racunalo*>& popis, int* tableti, int* laptopi, int* android, int* windows, int* linux) {
    *tableti = 0;
    *laptopi = 0;

    *android = 0;
    *windows = 0;
    *linux = 0;

    for (int i = 0; i < popis.size(); i++)
    {
        string tip = popis[i]->getTipRacunala();
        if (tip == "tablet") (*tableti)++;
        else if (tip == "laptop") (*laptopi)++;

        string os = popis[i]->getOperacijskiSustav();
        if (os == "Windows") (*windows)++;
        else if (os == "Android") (*android)++;
        else if (os == "Linux") (*linux)++;
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