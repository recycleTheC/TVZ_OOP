#include<iostream>

#include"Ekipa.h"
#include"Igrac.h"

using namespace std;

int main() {

    Ekipa ekipa;
    ekipa.setNaziv("Tim raketa");

    Igrac i1("Luka", "Modric");
    i1.setBrojDresa(10);
    i1.setTrzisnaCijena(50000000);
    ekipa.dodajIgraca(i1);

    Igrac i2("Mario", "Mandzukic");
    i2.setBrojDresa(9);
    i2.setTrzisnaCijena(27000000);
    ekipa.dodajIgraca(i2);

    Igrac i3("Darijo", "Srna");
    i3.setBrojDresa(11);
    i3.setTrzisnaCijena(14500000);
    ekipa.dodajIgraca(i3);

    ekipa.ispisi();

    //Igrac najskuplji = ekipa.getNajskuplji();
    //najskuplji.ispisi();

    cout << "Najskuplji igrac: " << ekipa.getNajskuplji().ispisi() << endl;

    cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;
    cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;

    return 0;
}