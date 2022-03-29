#include<iostream>
#include<vector>

using namespace std;

class BankovniRacun {
public:
    double stanje;
    BankovniRacun(double sum) : stanje(sum){}
    BankovniRacun& dodaj(double iznos) {
        stanje += iznos;
        return *this; // vracamo referencu na postojeci objekt
    }
};

int main() {

    BankovniRacun tekuci(0);
    cout << tekuci.stanje << endl;

    /*tekuci.dodaj(100);
    tekuci.dodaj(50);
    tekuci.dodaj(-75);*/

    tekuci.dodaj(100).dodaj(50).dodaj(-75); // ulancavanje poziva

    cout << tekuci.stanje << endl;

    return 0;
}