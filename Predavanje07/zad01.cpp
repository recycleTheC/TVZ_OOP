#include<iostream>
#include <vector>

using namespace std;

class Artikl {
public:
    int kolicina;
    Artikl(int kol) : kolicina(kol) {}
    virtual double getCijena() = 0;
};

class Kruh : public Artikl {
public:
    Kruh(int kol) : Artikl(kol){}
    double getCijena() override { return 10 * kolicina; }
};

class Jabuka : public Artikl {
public:
    Jabuka(int kol) : Artikl(kol) {}
    double getCijena() override { return 8 * kolicina; }
};

double UkupnaCijena(vector<Artikl*> v) {
    double suma = 0;

    for (int i = 0; i < v.size(); i++)
    {
        suma += v[i]->getCijena();
    }

    return suma;
}

int main() {
    Kruh BijeliKruh(2);		// 2 kom, 10 kn/kom  (20 kn)
    Jabuka IdaredJabuke(3); 	// 3 kg,  8 kn/kg 	 (24 kn)
    vector<Artikl*> racun = { &BijeliKruh, &IdaredJabuke }; // pretvorba "na vise"
    cout << UkupnaCijena(racun) << endl; // 44
    return 0;
}
